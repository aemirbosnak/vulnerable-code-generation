//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER "localhost"
#define PORT 110
#define BUFFER_SIZE 1024
#define USER "your_username"
#define PASS "your_password"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *message = "CAPA\r\n";
    char buffer[BUFFER_SIZE];
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    send(sock, message, strlen(message), 0);

    while ((n = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);

    return 0;
}