//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 110
#define USERNAME "username"
#define PASSWORD "password"

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    char buffer[1024];
    char username[64];
    char password[64];
    strcpy(username, USERNAME);
    strcpy(password, PASSWORD);
    sprintf(buffer, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);

    char command[64];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        memset(command, 0, sizeof(command));
        printf("Enter command: ");
        scanf("%s", command);
        strcat(buffer, command);
        strcat(buffer, "\r\n");
        send(sock, buffer, strlen(buffer), 0);
        recv(sock, buffer, sizeof(buffer), 0);
        printf("Server response: %s\n", buffer);
    }

    close(sock);
    return 0;
}