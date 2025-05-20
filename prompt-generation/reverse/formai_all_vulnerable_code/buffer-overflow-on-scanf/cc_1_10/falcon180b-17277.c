//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char hostname[256];
    char username[256];
    char password[256];
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int n;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    snprintf(command, BUFFER_SIZE, "USER %s", username);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);

    if (n == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    response[n] = '\0';

    if (strncmp(response, "+OK", 3)!= 0) {
        printf("Authentication failed\n");
        exit(1);
    }

    snprintf(command, BUFFER_SIZE, "PASS %s", password);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);

    if (n == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    response[n] = '\0';

    if (strncmp(response, "+OK", 3)!= 0) {
        printf("Authentication failed\n");
        exit(1);
    }

    snprintf(command, BUFFER_SIZE, "STAT");
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);

    if (n == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    response[n] = '\0';

    printf("Server response: %s\n", response);

    close(sockfd);

    return 0;
}