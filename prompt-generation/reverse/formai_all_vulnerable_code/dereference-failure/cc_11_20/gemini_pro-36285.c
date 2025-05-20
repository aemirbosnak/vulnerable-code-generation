//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip address> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a login command
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "USER anonymous\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return 1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }
    if (strncmp(buffer, "331", 3) != 0) {
        printf("Login failed: %s", buffer);
        return 1;
    }

    sprintf(buffer, "PASS anonymous@example.com\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return 1;
    }
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }
    if (strncmp(buffer, "230", 3) != 0) {
        printf("Login failed: %s", buffer);
        return 1;
    }

    // Send a list command
    sprintf(buffer, "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the list of files
    while (1) {
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
            perror("recv");
            return 1;
        }
        if (strncmp(buffer, "226", 3) == 0) {
            break;
        }
        printf("%s", buffer);
    }

    // Close the connection
    close(sockfd);

    return 0;
}