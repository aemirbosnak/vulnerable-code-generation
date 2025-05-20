//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 10

typedef struct connection {
    int sock;
    struct sockaddr_in address;
} connection_t;

connection_t connections[MAX_CONNECTIONS];
int num_connections = 0;

void handle_connection(int sock) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Received message from %s:%d: %s\n", inet_ntoa(connections[sock].address.sin_addr), ntohs(connections[sock].address.sin_port), buffer);
    }
    close(sock);
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_sock, MAX_CONNECTIONS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        printf("Waiting for connections...\n");
        socklen_t addr_size = sizeof(struct sockaddr_in);
        int client_sock = accept(server_sock, (struct sockaddr *)&connections[num_connections].address, &addr_size);
        if (client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        num_connections++;
        printf("Connection accepted from %s:%d\n", inet_ntoa(connections[num_connections - 1].address.sin_addr), ntohs(connections[num_connections - 1].address.sin_port));
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_connection, (void *)&connections[num_connections - 1]);
    }

    return 0;
}