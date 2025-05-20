//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 21

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server_address> <username>\n", argv[0]);
        return 1;
    }

    char *server_address = argv[1];
    char *username = argv[2];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    recv(sock, response, BUFFER_SIZE, 0);
    printf("Server response: %s\n", response);

    char command[BUFFER_SIZE];
    while (1) {
        printf("Enter command (quit to exit): ");
        scanf("%s", command);
        if (strcmp(command, "quit") == 0) {
            break;
        }

        strcat(command, "\r\n");
        send(sock, command, strlen(command), 0);

        memset(response, 0, BUFFER_SIZE);
        recv(sock, response, BUFFER_SIZE, 0);
        printf("Server response: %s\n", response);
    }

    close(sock);
    return 0;
}