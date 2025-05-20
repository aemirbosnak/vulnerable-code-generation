//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define PORT 110
#define MAX_LINE 1024
#define TIMEOUT 5

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in server_addr, cli_addr;
    char buffer[MAX_LINE], command[MAX_LINE], response[MAX_LINE], *token;
    int n, wait_status;
    struct hostent *server;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr,
         (char *) &server_addr.sin_addr.s_addr,
         server->h_length);
    portno = atoi(argv[1]);

    server_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to POP3 server.\n");

    write(sockfd, "USER ", 5);
    write(sockfd, argv[2], strlen(argv[2]));
    write(sockfd, "\r\n", 2);

    bzero(buffer, MAX_LINE);
    n = read(sockfd, buffer, MAX_LINE);

    if (strstr(buffer, "+OK") == NULL) {
        fprintf(stderr, "Invalid username or password.\n");
        close(sockfd);
        exit(1);
    }

    write(sockfd, "PASS ", 5);
    write(sockfd, argv[3], strlen(argv[3]));
    write(sockfd, "\r\n", 2);

    bzero(buffer, MAX_LINE);
    n = read(sockfd, buffer, MAX_LINE);

    if (strstr(buffer, "+OK") == NULL) {
        fprintf(stderr, "Invalid username or password.\n");
        close(sockfd);
        exit(1);
    }

    write(sockfd, "LIST\r\n", 5);

    while (1) {
        bzero(buffer, MAX_LINE);
        n = read(sockfd, buffer, MAX_LINE);

        if (n > 0) {
            printf("%s", buffer);

            token = strtok(buffer, "\r\n");

            if (strcmp(token, ".") == 0) {
                break;
            }
        } else {
            perror("Error reading from socket");
            close(sockfd);
            exit(1);
        }
    }

    write(sockfd, "QUIT\r\n", 5);

    bzero(buffer, MAX_LINE);
    n = read(sockfd, buffer, MAX_LINE);

    if (strstr(buffer, "+OK") == NULL) {
        perror("Error during quit process");
        close(sockfd);
        exit(1);
    }

    close(sockfd);
    return 0;
}