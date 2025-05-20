//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];

    printf("Enter server address: ");
    memset(buffer, 0, BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    server = gethostbyname(buffer);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    printf("Enter server port: ");
    memset(buffer, 0, BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    portno = atoi(buffer);

    printf("Enter username: ");
    memset(username, 0, BUFFER_SIZE);
    fgets(username, BUFFER_SIZE - 1, stdin);

    printf("Enter password: ");
    memset(password, 0, BUFFER_SIZE);
    fgets(password, BUFFER_SIZE - 1, stdin);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: can't open socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: can't connect to server\n");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: can't read from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE - 1, "USER %s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: can't write to socket\n");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: can't read from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE - 1, "PASS %s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: can't write to socket\n");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: can't read from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE - 1, "STAT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: can't write to socket\n");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: can't read from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE - 1, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: can't write to socket\n");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: can't read from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    close(sockfd);
    return 0;
}