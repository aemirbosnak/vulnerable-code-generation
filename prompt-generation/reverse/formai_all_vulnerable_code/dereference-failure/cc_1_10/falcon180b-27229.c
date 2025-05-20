//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define FTP_PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *command = (char *)malloc(MAX_COMMAND_LENGTH);
    char buffer[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(FTP_PORT);

    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    sprintf(command, "USER %s\r\n", argv[2]);
    send(sock, command, strlen(command), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);

    sprintf(command, "PASS %s\r\n", argv[3]);
    send(sock, command, strlen(command), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);

    close(sock);
    free(command);
    return 0;
}