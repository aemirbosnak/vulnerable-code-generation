//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netdb.h>

#define MAX_BACKLOG 10
#define MAX_CLIENTS 100
#define MAX_DATA_SIZE 1024

typedef struct client_data {
    int sock;
    struct sockaddr_in addr;
    char name[INET_ADDRSTRLEN];
} client_data;

typedef struct packet_data {
    char data[MAX_DATA_SIZE];
    int len;
} packet_data;

client_data clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    client_data *client = (client_data *) arg;
    packet_data packet;

    while (1) {
        memset(&packet, 0, sizeof(packet_data));
        int len = recv(client->sock, packet.data, MAX_DATA_SIZE, 0);

        if (len <= 0) {
            break;
        }

        packet.len = len;
        printf("Received packet from %s: %.*s\n", client->name, len, packet.data);
    }

    close(client->sock);
    free(client);
}

void accept_connections(int listen_sock) {
    while (1) {
        client_data *client = malloc(sizeof(client_data));

        if (num_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached.\n");
            continue;
        }

        socklen_t addr_len = sizeof(client->addr);
        client->sock = accept(listen_sock, (struct sockaddr *) &client->addr, &addr_len);

        if (client->sock == -1) {
            printf("Error accepting connection.\n");
            free(client);
            continue;
        }

        inet_ntop(AF_INET, &client->addr.sin_addr, client->name, INET_ADDRSTRLEN);
        printf("Accepted connection from %s\n", client->name);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, client);

        num_clients++;
    }
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8000);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket.\n");
        return 1;
    }

    if (listen(server_sock, MAX_BACKLOG) == -1) {
        printf("Error listening on socket.\n");
        return 1;
    }

    printf("Server started on port 8000.\n");

    accept_connections(server_sock);

    return 0;
}