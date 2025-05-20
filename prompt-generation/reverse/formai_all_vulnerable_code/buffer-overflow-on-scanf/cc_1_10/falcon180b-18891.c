//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    char hostname[100];
    int port;

    printf("Enter POP3 server hostname: ");
    scanf("%s", hostname);

    printf("Enter POP3 server port: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to POP3 server\n");

    char username[100];
    char password[100];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    char auth_string[100];
    sprintf(auth_string, "USER %s\r\n", username);

    send(sockfd, auth_string, strlen(auth_string), 0);

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    n = recv(sockfd, response, BUFFER_SIZE, 0);

    if (n <= 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    printf("Response from server: %s\n", response);

    char pass_string[100];
    sprintf(pass_string, "PASS %s\r\n", password);

    send(sockfd, pass_string, strlen(pass_string), 0);

    memset(response, 0, BUFFER_SIZE);

    n = recv(sockfd, response, BUFFER_SIZE, 0);

    if (n <= 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    printf("Response from server: %s\n", response);

    char quit_string[10];
    sprintf(quit_string, "QUIT\r\n");

    send(sockfd, quit_string, strlen(quit_string), 0);

    close(sockfd);

    return 0;
}