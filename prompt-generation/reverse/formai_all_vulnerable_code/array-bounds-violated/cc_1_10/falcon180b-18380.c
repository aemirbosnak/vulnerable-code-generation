//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER "localhost"
#define PORT 110
#define USER "romeo"
#define PASS "juliet"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[1024];
    char *ptr;
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to %s:%d\n", SERVER, PORT);

    send(sock, "USER ", 5, 0);
    n = recv(sock, buffer, sizeof(buffer), 0);
    buffer[n] = '\0';
    ptr = strstr(buffer, "+OK");
    if (ptr == NULL) {
        printf("Error: Invalid response from server\n");
        exit(1);
    }

    send(sock, "PASS ", 5, 0);
    send(sock, PASS, strlen(PASS), 0);
    n = recv(sock, buffer, sizeof(buffer), 0);
    buffer[n] = '\0';
    ptr = strstr(buffer, "+OK");
    if (ptr == NULL) {
        printf("Error: Invalid response from server\n");
        exit(1);
    }

    printf("Logged in as %s\n", USER);

    while (1) {
        printf("Enter command (quit to exit): ");
        fgets(buffer, sizeof(buffer), stdin);
        n = strlen(buffer);
        if (n > 0 && buffer[n-1] == '\n') {
            buffer[n-1] = '\0';
            n--;
        }
        if (strcmp(buffer, "quit") == 0) {
            break;
        }
        send(sock, buffer, n, 0);
        n = recv(sock, buffer, sizeof(buffer), 0);
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}