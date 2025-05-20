//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DATA_SIZE 1024
#define MAX_CLIENTS 10
#define QOS_THRESHOLD 100

struct client {
    int sock;
    char name[10];
    int score;
};

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock, 10);

    struct client clients[MAX_CLIENTS];
    int num_clients = 0;

    while (1) {
        int new_sock = accept(server_sock, NULL, NULL);
        if (new_sock == -1) {
            perror("accept");
            exit(1);
        }

        if (num_clients >= MAX_CLIENTS) {
            send(new_sock, "Server is full\n", 15, 0);
            close(new_sock);
            continue;
        }

        char name[10];
        recv(new_sock, name, 10, 0);
        strcpy(clients[num_clients].name, name);
        clients[num_clients].sock = new_sock;
        clients[num_clients].score = 0;
        num_clients++;

        printf("New client %s connected\n", name);
    }
}