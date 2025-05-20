//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        printf("Usage: %s <host> <username> <password>\n", argv[0]);
        return 1;
    }

    char* host = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket");
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, host, &server.sin_addr);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == -1) {
        error("connect");
    }

    char login[100];
    sprintf(login, "USER %s\r\n", username);
    send(sock, login, strlen(login), 0);

    char password_login[100];
    sprintf(password_login, "PASS %s\r\n", password);
    send(sock, password_login, strlen(password_login), 0);

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}