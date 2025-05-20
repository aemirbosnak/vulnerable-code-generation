//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define USER "username"
#define PASS "password"

int main() {
    int sock;
    char hostname[100] = "localhost";
    char message[BUFFER_SIZE];
    char *response;
    int response_len;
    char *command;
    char *user_command;

    printf("Connecting to POP3 server...\n");

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    printf("Socket created successfully\n");

    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    response = (char *)malloc(BUFFER_SIZE * sizeof(char));
    response_len = 0;

    if (send(sock, USER, strlen(USER), 0) == -1) {
        printf("Error sending username\n");
        exit(1);
    }

    if (send(sock, PASS, strlen(PASS), 0) == -1) {
        printf("Error sending password\n");
        exit(1);
    }

    printf("Logged in successfully\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, BUFFER_SIZE, stdin);

        user_command = (char *)malloc(strlen(command) * sizeof(char));
        strcpy(user_command, command);

        if (send(sock, user_command, strlen(user_command), 0) == -1) {
            printf("Error sending command\n");
            exit(1);
        }

        response_len = 0;

        while (response_len < BUFFER_SIZE - 1) {
            if ((response_len = recv(sock, &response[response_len], BUFFER_SIZE - response_len, 0)) <= 0) {
                printf("Error receiving response\n");
                exit(1);
            }
        }

        printf("%s\n", response);
    }

    close(sock);

    return 0;
}