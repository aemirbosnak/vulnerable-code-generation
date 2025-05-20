//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <pthread.h>

#define BUF_LEN 1024
#define MAX_CLIENTS 10

typedef struct {
    int sock;
    char ip[16];
    int port;
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    client_t *client = (client_t *) arg;
    char buf[BUF_LEN];

    while (1) {
        memset(buf, 0, BUF_LEN);
        int len = recv(client->sock, buf, BUF_LEN, 0);
        if (len <= 0) {
            break;
        }
        buf[len] = '\0';
        printf("%s: %s\n", client->ip, buf);
        send(client->sock, buf, strlen(buf), 0);
    }

    close(client->sock);
    num_clients--;
}

int main() {
    int server_sock, new_sock;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(54000);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port 54000\n");

    while (1) {
        addrlen = sizeof(client_addr);
        new_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addrlen);

        if (new_sock == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        inet_ntop(AF_INET, &client_addr.sin_addr, clients[num_clients].ip, 16);
        clients[num_clients].port = ntohs(client_addr.sin_port);
        clients[num_clients].sock = new_sock;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &clients[num_clients - 1]);
    }

    return 0;
}