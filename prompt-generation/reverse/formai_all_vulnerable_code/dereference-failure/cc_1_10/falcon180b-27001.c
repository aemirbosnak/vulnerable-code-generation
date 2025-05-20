//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo server_addr;
    char username[50];
    char password[50];
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int n;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.ai_family = AF_INET;
    server_addr.ai_socktype = SOCK_STREAM;
    server_addr.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo("localhost", "110", &server_addr, NULL)!= 0) {
        printf("Error: could not connect to server.\n");
        exit(1);
    }

    sockfd = socket(server_addr.ai_family, server_addr.ai_socktype, server_addr.ai_protocol);

    if (sockfd == -1) {
        printf("Error: could not create socket.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    if (connect(sockfd, server_addr.ai_addr, server_addr.ai_addrlen) == -1) {
        printf("Error: could not connect to server.\n");
        exit(1);
    }

    printf("Authenticating...\n");

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    n = recv(sockfd, response, BUFFER_SIZE, 0);
    response[n] = '\0';
    printf("Server response: %s\n", response);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    n = recv(sockfd, response, BUFFER_SIZE, 0);
    response[n] = '\0';
    printf("Server response: %s\n", response);

    char *token = strtok(response, " ");
    if (strcmp(token, "+OK")!= 0) {
        printf("Error: could not authenticate.\n");
        exit(1);
    }

    char *capabilities = strtok(NULL, " ");
    printf("Server capabilities: %s\n", capabilities);

    char *delimiter = strtok(NULL, " ");
    if (delimiter == NULL) {
        printf("Error: missing delimiter.\n");
        exit(1);
    }

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            sprintf(command, "QUIT\r\n");
            send(sockfd, command, strlen(command), 0);
            n = recv(sockfd, response, BUFFER_SIZE, 0);
            response[n] = '\0';
            printf("Server response: %s\n", response);
            break;
        } else {
            send(sockfd, command, strlen(command), 0);
            n = recv(sockfd, response, BUFFER_SIZE, 0);
            response[n] = '\0';
            printf("Server response: %s\n", response);
        }
    }

    close(sockfd);
    return 0;
}