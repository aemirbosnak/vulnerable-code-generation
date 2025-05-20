//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[20];
    char password[20];
    char buffer[BUFFER_SIZE];
    char *token;
    int n;

    // Get username and password from user
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Connect to POP3 server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket creation failed\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    // Authenticate with server
    send(sockfd, "USER ", 5, 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (strncmp(buffer, "+OK", 3)!= 0) {
        printf("Error: authentication failed\n");
        close(sockfd);
        return 1;
    }

    send(sockfd, "PASS ", 5, 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (strncmp(buffer, "+OK", 3)!= 0) {
        printf("Error: authentication failed\n");
        close(sockfd);
        return 1;
    }

    // Get number of messages
    send(sockfd, "STAT\r\n", 6, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    n = atoi(buffer);

    // Loop through messages
    for (int i = 1; i <= n; i++) {
        // Get message size
        send(sockfd, "LIST\r\n", 6, 0);

        recv(sockfd, buffer, BUFFER_SIZE, 0);
        token = strtok(buffer, " ");
        int message_size = atoi(token);

        // Get message
        char message[message_size + 1];
        memset(message, 0, message_size + 1);

        recv(sockfd, message, message_size, 0);
        printf("Message %d:\n%s", i, message);
    }

    // Close connection
    close(sockfd);
    return 0;
}