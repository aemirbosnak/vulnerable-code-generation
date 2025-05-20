//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 110
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        close(sockfd);
        return 1;
    }

    // Authenticate with server
    send(sockfd, "USER myusername\r\n", 18, 0);
    send(sockfd, "PASS mypassword\r\n", 19, 0);

    // Receive server response
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error: Failed to receive server response\n");
        close(sockfd);
        return 1;
    }
    buffer[n] = '\0';
    printf("Server response: %s", buffer);

    // Send POP3 commands
    send(sockfd, "STAT\r\n", 6, 0);
    send(sockfd, "LIST\r\n", 6, 0);
    send(sockfd, "RETR 1\r\n", 10, 0);

    // Receive and display server responses
    while (1) {
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error: Failed to receive server response\n");
            close(sockfd);
            return 1;
        }
        buffer[n] = '\0';
        printf("Server response: %s", buffer);
    }

    close(sockfd);
    return 0;
}