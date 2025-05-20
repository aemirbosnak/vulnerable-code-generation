//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: irregular
// POP3 Client example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_LINE_SIZE 1024
#define MAX_COMMAND_SIZE 256

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *host;
    int port;
    char *username;
    char *password;
    char command[MAX_COMMAND_SIZE];
    char line[MAX_LINE_SIZE];
    int i;

    if (argc < 4) {
        printf("Usage: %s <host> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        return 1;
    }

    snprintf(command, MAX_COMMAND_SIZE, "USER %s\r\n", username);
    send(sock, command, strlen(command), 0);

    recv(sock, line, MAX_LINE_SIZE, 0);
    printf("%s\n", line);

    snprintf(command, MAX_COMMAND_SIZE, "PASS %s\r\n", password);
    send(sock, command, strlen(command), 0);

    recv(sock, line, MAX_LINE_SIZE, 0);
    printf("%s\n", line);

    snprintf(command, MAX_COMMAND_SIZE, "STAT\r\n");
    send(sock, command, strlen(command), 0);

    recv(sock, line, MAX_LINE_SIZE, 0);
    printf("%s\n", line);

    snprintf(command, MAX_COMMAND_SIZE, "RETR 1\r\n");
    send(sock, command, strlen(command), 0);

    recv(sock, line, MAX_LINE_SIZE, 0);
    printf("%s\n", line);

    snprintf(command, MAX_COMMAND_SIZE, "QUIT\r\n");
    send(sock, command, strlen(command), 0);

    recv(sock, line, MAX_LINE_SIZE, 0);
    printf("%s\n", line);

    close(sock);

    return 0;
}