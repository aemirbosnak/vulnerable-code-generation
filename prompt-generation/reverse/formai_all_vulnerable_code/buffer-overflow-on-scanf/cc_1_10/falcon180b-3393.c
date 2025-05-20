//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 110
#define BUFFER_SIZE 1024

void process_response(char *response);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char response[BUFFER_SIZE];
    int i, n;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    if (send(sockfd, username, strlen(username), 0) == -1) {
        printf("Error sending username\n");
        exit(1);
    }

    if (send(sockfd, password, strlen(password), 0) == -1) {
        printf("Error sending password\n");
        exit(1);
    }

    while (1) {
        memset(response, 0, BUFFER_SIZE);

        if (recv(sockfd, response, BUFFER_SIZE, 0) == 0) {
            printf("Server disconnected\n");
            exit(1);
        }

        process_response(response);
    }

    close(sockfd);
    return 0;
}

void process_response(char *response) {
    printf("%s", response);
}