//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    char *hostname = "www.example.com";
    int port = 80;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Get server address
    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error getting hostname\n");
        exit(1);
    }

    // Fill in server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send HTTP request
    char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    // Receive HTTP response
    char buffer[1024];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}