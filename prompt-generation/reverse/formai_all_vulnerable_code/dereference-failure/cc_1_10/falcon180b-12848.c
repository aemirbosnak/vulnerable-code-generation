//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_info {
    int sock;
    char ip[INET_ADDRSTRLEN];
    char port[6];
};

void *monitor_thread(void *arg) {
    struct client_info *client = (struct client_info *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Client %s:%s disconnected.\n", client->ip, client->port);
            close(client->sock);
            exit(0);
        }

        printf("Client %s:%s sent: %s\n", client->ip, client->port, buffer);
    }
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_sock, MAX_CLIENTS);

    printf("Server started on port 8080.\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addr_size);

        inet_ntop(AF_INET, &client_addr.sin_addr, (char *) &((struct client_info *) malloc(sizeof(struct client_info)))->ip, INET_ADDRSTRLEN);
        snprintf(((struct client_info *) malloc(sizeof(struct client_info)))->port, 6, "%d", ntohs(client_addr.sin_port));

        ((struct client_info *) malloc(sizeof(struct client_info)))->sock = client_sock;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, monitor_thread, (void *) ((struct client_info *) malloc(sizeof(struct client_info))));
    }

    return 0;
}