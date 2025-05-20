//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUF_SIZE 1024

struct client_info {
    int sock;
    char ip[16];
    char username[32];
    char password[32];
};

struct client_info clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_sock = *(int *) arg;
    char buf[BUF_SIZE];
    int n;

    while ((n = recv(client_sock, buf, BUF_SIZE, 0)) > 0) {
        buf[n] = '\0';
        printf("Client %s sent: %s\n", clients[client_sock].ip, buf);
    }

    close(client_sock);
    return NULL;
}

int main() {
    int server_sock, new_sock;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        if ((new_sock = accept(server_sock, (struct sockaddr *) &client_addr, (socklen_t*) &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if (num_clients >= MAX_CLIENTS) {
            send(new_sock, "Server is full.\r\n", 17, 0);
            close(new_sock);
            continue;
        }

        getpeername(new_sock, (struct sockaddr *) &client_addr, (socklen_t*) &addrlen);
        inet_ntop(AF_INET, &client_addr.sin_addr, clients[num_clients].ip, 16);

        clients[num_clients].sock = new_sock;
        strcpy(clients[num_clients].username, "");
        strcpy(clients[num_clients].password, "");

        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &new_sock);
    }

    return 0;
}