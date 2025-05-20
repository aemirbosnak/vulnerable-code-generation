//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char server[MAX_LENGTH];
    int port = 110;
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server_info;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s username password server\n", argv[0]);
        exit(1);
    }

    strcpy(username, argv[1]);
    strcpy(password, argv[2]);
    strcpy(server, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server_info = gethostbyname(server);
    if (server_info == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, server_info->h_addr_list[0], server_info->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    char buffer[MAX_LENGTH];
    memset(buffer, 0, MAX_LENGTH);

    n = read(sockfd, buffer, MAX_LENGTH - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    char command[MAX_LENGTH];

    sprintf(command, "USER %s\r\n", username);
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    memset(buffer, 0, MAX_LENGTH);

    n = read(sockfd, buffer, MAX_LENGTH - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    memset(command, 0, MAX_LENGTH);
    sprintf(command, "PASS %s\r\n", password);
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    memset(buffer, 0, MAX_LENGTH);
    n = read(sockfd, buffer, MAX_LENGTH - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    memset(command, 0, MAX_LENGTH);
    sprintf(command, "LIST\r\n");
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    memset(buffer, 0, MAX_LENGTH);
    int count = 0;
    while (1) {
        n = read(sockfd, buffer + count, 1);
        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        if (buffer[count] == '\n') {
            buffer[count] = '\0';
            break;
        } else {
            count++;
        }
    }

    printf("%s\n", buffer);

    memset(buffer, 0, MAX_LENGTH);
    while (1) {
        n = read(sockfd, buffer, MAX_LENGTH - 1);
        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        if (n == 0) {
            break;
        }

        printf("%s", buffer);
        memset(buffer, 0, MAX_LENGTH);
    }

    close(sockfd);

    return 0;
}