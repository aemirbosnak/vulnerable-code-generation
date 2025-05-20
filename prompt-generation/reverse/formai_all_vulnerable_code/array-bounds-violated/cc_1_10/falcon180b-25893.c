//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 1024
#define BUFFER_SIZE 1024
#define PORT 110

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char command[MAX_COMMAND_LENGTH];
    char buffer[BUFFER_SIZE];
    int n;

    printf("Enter POP3 server address: ");
    scanf("%s", inet_ntoa(server_addr.sin_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("Server response: %s", buffer);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("Server response: %s", buffer);

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\r\n")] = '\0';

        if (strcmp(command, "LIST\r\n") == 0) {
            send(sockfd, command, strlen(command), 0);
            n = recv(sockfd, buffer, BUFFER_SIZE, 0);
            buffer[n] = '\0';
            printf("Server response: %s", buffer);
        } else if (strcmp(command, "RETR 1\r\n") == 0) {
            send(sockfd, command, strlen(command), 0);
            n = recv(sockfd, buffer, BUFFER_SIZE, 0);
            buffer[n] = '\0';
            printf("Server response: %s", buffer);
        } else if (strcmp(command, "DELE 1\r\n") == 0) {
            send(sockfd, command, strlen(command), 0);
            n = recv(sockfd, buffer, BUFFER_SIZE, 0);
            buffer[n] = '\0';
            printf("Server response: %s", buffer);
        } else if (strcmp(command, "QUIT\r\n") == 0) {
            send(sockfd, command, strlen(command), 0);
            n = recv(sockfd, buffer, BUFFER_SIZE, 0);
            buffer[n] = '\0';
            printf("Server response: %s", buffer);
            break;
        }
    }

    close(sockfd);

    return 0;
}