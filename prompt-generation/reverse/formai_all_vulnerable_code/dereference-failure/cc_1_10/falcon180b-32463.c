//Falcon-180B DATASET v1.0 Category: Chat server ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client {
    int sock;
    char name[20];
};

void broadcast(int sock, char message[], struct client clients[], int num_clients) {
    for (int i = 0; i < num_clients; i++) {
        send(clients[i].sock, message, strlen(message), 0);
    }
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock, MAX_CLIENTS);

    struct client clients[MAX_CLIENTS];
    memset(clients, 0, sizeof(clients));

    int num_clients = 0;

    while (1) {
        socklen_t addr_size = sizeof(struct sockaddr_in);
        int client_sock = accept(server_sock, (struct sockaddr *)&server_addr, &addr_size);

        if (num_clients == MAX_CLIENTS) {
            send(client_sock, "Server full", strlen("Server full"), 0);
            close(client_sock);
            continue;
        }

        clients[num_clients].sock = client_sock;
        strcpy(clients[num_clients].name, inet_ntoa(server_addr.sin_addr));
        num_clients++;

        printf("Client %s connected\n", clients[num_clients-1].name);

        char message[BUFFER_SIZE];
        while (1) {
            bzero(message, BUFFER_SIZE);
            int bytes_received = recv(client_sock, message, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                break;
            }

            message[bytes_received] = '\0';

            if (strcmp(message, "exit") == 0) {
                close(client_sock);
                printf("Client %s disconnected\n", clients[num_clients-1].name);
                num_clients--;
                break;
            }

            broadcast(client_sock, message, clients, num_clients);
        }
    }

    close(server_sock);
    return 0;
}