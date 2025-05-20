//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int len;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send data to server
    char *message = "Hello, world!";
    send(sockfd, message, strlen(message), 0);

    // Receive data from server
    while (1) {
        len = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (len <= 0) {
            printf("Error receiving data\n");
            break;
        }
        buffer[len] = '\0';
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}