//Falcon-180B DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

struct client {
    int sock;
    char name[50];
};

int main(int argc, char *argv[]) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    send(server_sock, name, strlen(name), 0);

    char msg[MAX_MSG_SIZE];
    while (1) {
        memset(msg, 0, MAX_MSG_SIZE);
        int n = recv(server_sock, msg, MAX_MSG_SIZE, 0);
        if (n <= 0) {
            printf("Connection closed by server.\n");
            close(server_sock);
            exit(0);
        }
        msg[n] = '\0';
        printf("%s\n", msg);
    }

    return 0;
}