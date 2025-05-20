//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);

    // Resolve IP address
    host = gethostbyname(ip_address);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        return 1;
    }

    // Copy IP address to server address structure
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send request to server
    char request[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", ip_address);

    if (send(sockfd, request, strlen(request), 0) == -1) {
        printf("Error sending request\n");
        return 1;
    }

    // Receive response from server
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    if (bytes_received == -1) {
        printf("Error receiving response\n");
        return 1;
    }

    // Close socket
    close(sockfd);

    return 0;
}