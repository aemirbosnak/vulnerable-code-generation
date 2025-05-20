//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char buffer[BUFFER_SIZE];
    int n;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Authenticate with server
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    if ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) == -1) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';

    while (strncmp(buffer, "+OK", 4)!= 0) {
        snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        if ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) == -1) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        buffer[n] = '\0';
    }

    // Get number of messages
    snprintf(buffer, BUFFER_SIZE, "STAT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    if ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) == -1) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';

    printf("Number of messages: %s\n", buffer);

    // Get message headers
    snprintf(buffer, BUFFER_SIZE, "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}