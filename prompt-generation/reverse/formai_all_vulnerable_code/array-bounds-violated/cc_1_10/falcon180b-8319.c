//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 2048

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char username[64];
    char password[64];
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int n;

    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(username, argv[2]);
    strcpy(password, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Unable to connect to server\n");
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
    response[n] = '\0';
    printf("RESPONSE: %s\n", response);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
    response[n] = '\0';
    printf("RESPONSE: %s\n", response);

    while (1) {
        printf("Enter POP3 command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        n = send(sockfd, command, strlen(command), 0);

        memset(response, 0, MAX_RESPONSE_LENGTH);
        n = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
        response[n] = '\0';

        printf("RESPONSE: %s\n", response);

        if (strstr(response, ".")!= NULL) {
            break;
        }
    }

    close(sockfd);

    return 0;
}