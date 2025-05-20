//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *server_ip = "localhost";
    int server_port = 143;
    char buffer[BUF_SIZE];
    int n;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    printf("Connecting to server...\n");
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    // Login
    char login_command[] = "LOGIN \"user\" \"password\"\r\n";
    send(sock, login_command, strlen(login_command), 0);

    // Select inbox
    char select_command[] = "SELECT INBOX\r\n";
    send(sock, select_command, strlen(select_command), 0);

    // Fetch messages
    char fetch_command[] = "FETCH 1:* (BODY.PEEK[])\r\n";
    send(sock, fetch_command, strlen(fetch_command), 0);

    while ((n = recv(sock, buffer, BUF_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}