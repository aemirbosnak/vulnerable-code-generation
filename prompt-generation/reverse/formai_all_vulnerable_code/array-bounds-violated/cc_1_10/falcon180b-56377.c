//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define USERNAME "anonymous"
#define PASSWORD "anonymous@example.com"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *cmd;
    char buffer[BUFFER_SIZE];
    int len;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "ftp.example.com", &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    cmd = "USER ";
    len = strlen(cmd);
    send(sock, cmd, len, 0);
    len = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[len] = '\0';
    printf("Server response: %s\n", buffer);

    cmd = "PASS ";
    len = strlen(cmd);
    send(sock, cmd, len, 0);
    len = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[len] = '\0';
    printf("Server response: %s\n", buffer);

    cmd = "LIST";
    len = strlen(cmd);
    send(sock, cmd, len, 0);
    len = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[len] = '\0';
    printf("Server response: %s\n", buffer);

    close(sock);
    return 0;
}