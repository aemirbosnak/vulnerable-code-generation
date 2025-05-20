//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *host, *port;
    int port_num;

    // Parse command line arguments
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <port> <command>\n", argv[0]);
        return 1;
    }
    host = argv[1];
    port = argv[2];
    port_num = atoi(port);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Set up server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Error converting hostname to IP address\n");
        close(sock);
        return 1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Send command
    if (send(sock, argv[3], strlen(argv[3]), 0) == -1) {
        fprintf(stderr, "Error sending command: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Receive response
    int bytes_received = 0;
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
    if (bytes_received == -1) {
        fprintf(stderr, "Error receiving response: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Close socket
    close(sock);
    return 0;
}