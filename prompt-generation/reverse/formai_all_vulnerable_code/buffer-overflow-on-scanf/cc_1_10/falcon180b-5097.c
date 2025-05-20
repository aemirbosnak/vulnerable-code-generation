//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21
#define MAX_LINE 1024
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE];
    char username[20];
    char password[20];
    char command[MAX_LINE];
    char response[MAX_LINE];
    FILE *fp;

    printf("Enter the FTP server IP address: ");
    scanf("%s", &buffer);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, buffer, &server_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Enter the username: ");
    scanf("%s", username);
    printf("Enter the password: ");
    scanf("%s", password);

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    recv(sockfd, response, MAX_LINE, 0);

    if (strstr(response, "230")!= NULL) {
        printf("Login successful!\n");
    } else {
        printf("Login failed!\n");
        close(sockfd);
        return 0;
    }

    while (1) {
        printf("Enter the command: ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            send(sockfd, command, strlen(command), 0);
            recv(sockfd, response, MAX_LINE, 0);
            printf("Server response: %s\n", response);
            close(sockfd);
            return 0;
        } else if (strcmp(command, "list") == 0) {
            send(sockfd, command, strlen(command), 0);
            recv(sockfd, response, MAX_LINE, 0);
            printf("Server response: %s\n", response);
        } else if (strcmp(command, "get") == 0) {
            printf("Enter the filename: ");
            scanf("%s", buffer);
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, response, MAX_LINE, 0);
            printf("Server response: %s\n", response);
        } else if (strcmp(command, "put") == 0) {
            printf("Enter the filename: ");
            scanf("%s", buffer);
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, response, MAX_LINE, 0);
            printf("Server response: %s\n", response);
        }
    }

    close(sockfd);
    return 0;
}