//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOST_NAME 256
#define MAX_DATAGRAM_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    int opt = 1;
    int addrlen;
    char hostname[MAX_HOST_NAME];
    char datagram[MAX_DATAGRAM_SIZE];
    int retval;
    int i;

    // Check if correct number of arguments are provided
    if (argc!= 4) {
        printf("Usage: %s <hostname> <port> <datagram>\n", argv[0]);
        return 1;
    }

    // Copy hostname and port from command line arguments
    strcpy(hostname, argv[1]);
    int port = atoi(argv[2]);

    // Create socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set socket options
    retval = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (retval == -1) {
        printf("Error setting socket options\n");
        return 1;
    }

    // Resolve hostname
    struct hostent *host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        printf("Error resolving hostname\n");
        return 1;
    }

    // Copy IP address to server_addr
    memcpy(&server_addr.sin_addr, host_entry->h_addr, host_entry->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Send datagram
    strcpy(datagram, argv[3]);
    sendto(sock, datagram, strlen(datagram), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Receive response
    addrlen = sizeof(server_addr);
    retval = recvfrom(sock, datagram, MAX_DATAGRAM_SIZE, 0, (struct sockaddr *)&server_addr, &addrlen);
    if (retval == -1) {
        printf("Error receiving response\n");
        return 1;
    }

    // Print response
    printf("Response: %s\n", datagram);

    close(sock);
    return 0;
}