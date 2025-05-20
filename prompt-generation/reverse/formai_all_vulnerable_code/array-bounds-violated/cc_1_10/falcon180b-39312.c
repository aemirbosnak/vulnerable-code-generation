//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define TRUE 1
#define FALSE 0
#define QOS_PORT 5000
#define MAX_DATAGRAM_SIZE 1024
#define MAX_CLIENTS 10

typedef struct {
    int sock;
    struct sockaddr_in addr;
    int is_connected;
} client_info;

client_info clients[MAX_CLIENTS];
int num_clients = 0;

void handle_client(int index) {
    char buffer[MAX_DATAGRAM_SIZE];
    int bytes_received;

    while (TRUE) {
        bytes_received = recv(clients[index].sock, buffer, MAX_DATAGRAM_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Client %d sent: %s\n", index, buffer);
    }

    close(clients[index].sock);
    clients[index].is_connected = FALSE;
    num_clients--;
}

void accept_connections() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(QOS_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_sock, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", QOS_PORT);

    while (TRUE) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int new_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len);

        if (new_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            close(new_sock);
            printf("Server is full. Cannot accept more connections.\n");
            continue;
        }

        clients[num_clients].sock = new_sock;
        clients[num_clients].addr = client_addr;
        clients[num_clients].is_connected = TRUE;
        num_clients++;

        printf("Client %d connected\n", num_clients - 1);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)&num_clients);
    }

    close(server_sock);
}

int main() {
    accept_connections();

    return 0;
}