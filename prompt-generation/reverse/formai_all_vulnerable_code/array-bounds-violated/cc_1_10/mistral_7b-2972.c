//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024
#define USER_AGENT "POP3-SHOCKER/1.0"

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];
    char cmd[50];

    printf("\x1b[2J"); // Clear terminal screen
    printf("\033[1;1H"); // Move cursor to top left corner
    printf("\x1b[31m"); // Set text color to red

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    printf("Connecting to %s:%d...\n", "mail.example.com", SERVER_PORT);

    portno = SERVER_PORT;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(portno);
    inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected.\n");

    send(sockfd, USER_AGENT, strlen(USER_AGENT), 0);

    // SEND USER <username> COMMAND
    printf("\nEnter your username: ");
    bzero(cmd, sizeof(cmd));
    fgets(cmd, sizeof(cmd), stdin);
    cmd[strlen(cmd) - 1] = '\0';
    write(sockfd, cmd, strlen(cmd));

    // RECEIVE +OK USER <username>
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("\n%s", buffer);

    // SEND PASS <password> COMMAND
    printf("\nEnter your password: ");
    bzero(cmd, sizeof(cmd));
    fgets(cmd, sizeof(cmd), stdin);
    cmd[strlen(cmd) - 1] = '\0';
    write(sockfd, "PASS ", 4);
    write(sockfd, cmd, strlen(cmd));

    // RECEIVE +OK PASS <password>
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("\n%s", buffer);

    // RETR <message number> COMMAND
    printf("\nEnter message number to retrieve: ");
    bzero(cmd, sizeof(cmd));
    fgets(cmd, sizeof(cmd), stdin);
    cmd[strlen(cmd) - 1] = '\0';
    write(sockfd, "RETR ", 4);
    write(sockfd, cmd, strlen(cmd));

    // RECEIVE MESSAGE DATA
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n > 0) {
        printf("\n%s\n", buffer);
    }

    close(sockfd);
    printf("\nConnection closed.\n");
    exit(0);
}