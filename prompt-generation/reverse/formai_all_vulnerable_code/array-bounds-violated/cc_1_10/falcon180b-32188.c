//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char hostname[50] = "localhost";
    int port = 110;
    char username[50] = "user";
    char password[50] = "pass";
    char buffer[MAX_LINE];
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    if (send(sock, username, strlen(username), 0) == -1) {
        printf("Error sending username\n");
        return 1;
    }

    if (send(sock, password, strlen(password), 0) == -1) {
        printf("Error sending password\n");
        return 1;
    }

    while ((n = recv(sock, buffer, MAX_LINE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}