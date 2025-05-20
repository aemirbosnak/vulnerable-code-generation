//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 143
#define TIMEOUT 10

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[100];
    char password[100];
    char command[100];
    char *token;
    int status;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    status = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (status == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    sprintf(command, "LOGIN %s %s", username, password);
    send(sock, command, strlen(command), 0);

    memset(buffer, 0, BUFFER_SIZE);
    status = recv(sock, buffer, BUFFER_SIZE, 0);
    if (status == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Server response: %s\n", buffer);

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        send(sock, command, strlen(command), 0);

        memset(buffer, 0, BUFFER_SIZE);
        status = recv(sock, buffer, BUFFER_SIZE, 0);
        if (status == -1) {
            printf("Error receiving response\n");
            exit(1);
        }

        printf("Server response: %s\n", buffer);

        token = strtok(buffer, " ");
        while (token!= NULL) {
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }
    }

    close(sock);
    return 0;
}