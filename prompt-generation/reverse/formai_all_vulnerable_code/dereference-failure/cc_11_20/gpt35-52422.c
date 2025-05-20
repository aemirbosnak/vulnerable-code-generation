//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define HOSTNAME "imap.gmail.com"
#define PORT 993
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE] = {0};

    // create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    printf("Socket created!\n");

    // set sockaddr_in variables
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(HOSTNAME);
    server.sin_port = htons(PORT);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
    printf("Connected to server!\n");

    // receive greeting message
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // send login command
    char login_command[BUFFER_SIZE];
    sprintf(login_command, "login %s %s\r\n", argv[1], argv[2]);
    if (send(sock, login_command, strlen(login_command), 0) == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive login response
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // send select command
    char select_command[] = "select inbox\r\n";
    if (send(sock, select_command, strlen(select_command), 0) == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive select response
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // send fetch command
    char fetch_command[BUFFER_SIZE];
    sprintf(fetch_command, "fetch 1:* full\r\n");
    if (send(sock, fetch_command, strlen(fetch_command), 0) == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive fetch response
    while (recv(sock, buffer, BUFFER_SIZE, 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    // send logout command
    char logout_command[] = "logout\r\n";
    if (send(sock, logout_command, strlen(logout_command), 0) == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive logout response
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // close socket
    if (close(sock) == -1) {
        perror("close failed");
        exit(EXIT_FAILURE);
    }
    printf("Socket closed!\n");

    return 0;
}