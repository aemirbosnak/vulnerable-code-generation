//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define IMAP_PORT 993

void login(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    char username[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];
    char login_command[MAX_BUFFER_SIZE];
    char *response;
    int len;

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    sprintf(login_command, "LOGIN %s %s", username, password);
    send(sockfd, login_command, strlen(login_command), 0);

    len = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    buffer[len] = '\0';

    response = strstr(buffer, "OK");
    if (!response) {
        printf("Login failed.\n");
        exit(EXIT_FAILURE);
    }
}

void logout(int sockfd) {
    char logout_command[] = "LOGOUT";
    char buffer[MAX_BUFFER_SIZE];
    char *response;
    int len;

    send(sockfd, logout_command, strlen(logout_command), 0);

    len = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    buffer[len] = '\0';

    response = strstr(buffer, "BYE");
    if (!response) {
        printf("Logout failed.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    int sockfd, len;
    char buffer[MAX_BUFFER_SIZE];
    char command[MAX_BUFFER_SIZE];
    char *response;
    struct sockaddr_in server;

    if (argc < 2) {
        printf("Usage: imap_client <server_address>\n");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(IMAP_PORT);

    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    len = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    buffer[len] = '\0';

    response = strstr(buffer, "OK");
    if (!response) {
        printf("Connection failed.\n");
        exit(EXIT_FAILURE);
    }

    login(sockfd);

    sprintf(command, "LIST");
    send(sockfd, command, strlen(command), 0);

    len = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    buffer[len] = '\0';

    response = strstr(buffer, "OK");
    if (!response) {
        printf("Command failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("List of mailboxes:\n");
    printf("-------------------\n");
    printf("%s", buffer);

    logout(sockfd);

    close(sockfd);

    return 0;
}