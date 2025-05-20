//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DEFAULT_PORT 21
#define BUFFER_SIZE 1024

void die(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    char hostname[256];
    strcpy(hostname, argv[1]);

    char username[256];
    strcpy(username, argv[2]);

    char password[256];
    strcpy(password, argv[3]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        die("socket");

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(DEFAULT_PORT);
    inet_pton(AF_INET, hostname, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1)
        die("connect");

    char login_command[MAX_COMMAND_LENGTH];
    snprintf(login_command, MAX_COMMAND_LENGTH, "USER %s\r\n", username);
    send(sock, login_command, strlen(login_command), 0);

    char password_command[MAX_COMMAND_LENGTH];
    snprintf(password_command, MAX_COMMAND_LENGTH, "PASS %s\r\n", password);
    send(sock, password_command, strlen(password_command), 0);

    char welcome_message[BUFFER_SIZE];
    int bytes_received = recv(sock, welcome_message, BUFFER_SIZE, 0);
    if (bytes_received <= 0)
        die("recv");

    printf("FTP server response:\n%s", welcome_message);

    return 0;
}