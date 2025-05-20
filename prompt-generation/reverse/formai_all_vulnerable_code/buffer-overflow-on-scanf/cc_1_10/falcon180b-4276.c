//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE 1024
#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char hostname[64];
    char username[64];
    char password[64];
    char command[MAX_LINE];
    char response[BUFFER_SIZE];
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the username: ");
    scanf("%s", username);

    printf("Enter the password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket");
        exit(1);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: No such host");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to host");
        exit(1);
    }

    printf("Connected to host\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_LINE, stdin);
        if (strncmp(command, "quit", 4) == 0) {
            break;
        }
        n = send(sockfd, command, strlen(command), 0);
        if (n < 0) {
            printf("Error sending command");
            exit(1);
        }
        memset(response, 0, BUFFER_SIZE);
        n = recv(sockfd, response, BUFFER_SIZE, 0);
        if (n < 0) {
            printf("Error receiving response");
            exit(1);
        }
        printf("Response: %s", response);
    }

    close(sockfd);
    return 0;
}