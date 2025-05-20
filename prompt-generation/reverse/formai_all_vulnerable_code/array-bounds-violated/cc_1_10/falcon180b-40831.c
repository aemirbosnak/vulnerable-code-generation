//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send request
    char request[100] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    bytes_received = send(sockfd, request, strlen(request), 0);
    if (bytes_received == -1) {
        printf("Error sending request\n");
        exit(1);
    }

    // Receive response
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    buffer[bytes_received] = '\0';
    printf("Response: %s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}