//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_RESPONSE_LENGTH 1000
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *server;
    char username[MAX_COMMAND_LENGTH];
    char password[MAX_COMMAND_LENGTH];
    char server_response[MAX_RESPONSE_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    int n;

    printf("Enter POP3 server name: ");
    scanf("%s", server_response);

    server = gethostbyname(server_response);
    if (server == NULL) {
        printf("Error: invalid server name\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    recv(sockfd, server_response, MAX_RESPONSE_LENGTH, 0);
    printf("Server response: %s", server_response);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    recv(sockfd, server_response, MAX_RESPONSE_LENGTH, 0);
    printf("Server response: %s", server_response);

    close(sockfd);

    return 0;
}