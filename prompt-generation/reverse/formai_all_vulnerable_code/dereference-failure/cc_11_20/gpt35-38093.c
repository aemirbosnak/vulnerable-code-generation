//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#define MAX_INPUT_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: pop3client <server_address> <port_number>\n");
        exit(1);
    }

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_INPUT_SIZE];

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket.\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: Host not found.\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    printf("Connected to %s:%d\n", argv[1], portno);

    bzero(buffer, MAX_INPUT_SIZE);
    n = read(sockfd, buffer, MAX_INPUT_SIZE - 1);
    if (n < 0) {
        printf("Error: Reading from socket.\n");
        exit(1);
    }

    printf("%s", buffer);

    char user[MAX_INPUT_SIZE];
    printf("Username: ");
    fgets(user, MAX_INPUT_SIZE, stdin);
    user[strcspn(user, "\n")] = 0;

    char pass[MAX_INPUT_SIZE];
    printf("Password: ");
    fgets(pass, MAX_INPUT_SIZE, stdin);
    pass[strcspn(pass, "\n")] = 0;

    char login[MAX_INPUT_SIZE];
    sprintf(login, "USER %s\r\n", user);
    n = write(sockfd, login, strlen(login));
    if (n < 0) {
        printf("Error: Writing to socket.\n");
        exit(1);
    }

    bzero(buffer, MAX_INPUT_SIZE);
    n = read(sockfd, buffer, MAX_INPUT_SIZE - 1);
    if (n < 0) {
        printf("Error: Reading from socket.\n");
        exit(1);
    }

    printf("%s", buffer);

    char passw[MAX_INPUT_SIZE];
    sprintf(passw, "PASS %s\r\n", pass);
    n = write(sockfd, passw, strlen(passw));
    if (n < 0) {
        printf("Error: Writing to socket.\n");
        exit(1);
    }

    bzero(buffer, MAX_INPUT_SIZE);
    n = read(sockfd, buffer, MAX_INPUT_SIZE - 1);
    if (n < 0) {
        printf("Error: Reading from socket.\n");
        exit(1);
    }

    printf("%s", buffer);

    char quit[MAX_INPUT_SIZE] = "QUIT\r\n";
    n = write(sockfd, quit, strlen(quit));
    if (n < 0) {
        printf("Error: Writing to socket.\n");
        exit(1);
    }

    bzero(buffer, MAX_INPUT_SIZE);
    n = read(sockfd, buffer, MAX_INPUT_SIZE - 1);
    if (n < 0) {
        printf("Error: Reading from socket.\n");
        exit(1);
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}