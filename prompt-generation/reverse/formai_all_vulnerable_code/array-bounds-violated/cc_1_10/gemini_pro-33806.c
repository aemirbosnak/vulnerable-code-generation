//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int fd;
    char name[MAX_BUFFER_SIZE];
    int score;
} client;

client clients[MAX_CLIENTS];
int num_clients = 0;

void send_message(int fd, char *message) {
    int len = strlen(message);
    if (send(fd, &len, sizeof(int), 0) == -1) {
        perror("send");
        return;
    }
    if (send(fd, message, len, 0) == -1) {
        perror("send");
        return;
    }
}

void broadcast_message(char *message) {
    for (int i = 0; i < num_clients; i++) {
        send_message(clients[i].fd, message);
    }
}

void handle_client(int fd) {
    char buffer[MAX_BUFFER_SIZE];
    int len;
    while ((len = recv(fd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        buffer[len] = '\0';
        if (strcmp(buffer, "join") == 0) {
            printf("New client joined: %s\n", buffer);
            strcpy(clients[num_clients].name, buffer);
            clients[num_clients].fd = fd;
            clients[num_clients].score = 0;
            num_clients++;
            send_message(fd, "Welcome to the server!");
            broadcast_message(buffer);
        } else if (strcmp(buffer, "leave") == 0) {
            printf("Client left: %s\n", buffer);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i].fd == fd) {
                    clients[i] = clients[num_clients - 1];
                    num_clients--;
                    break;
                }
            }
            broadcast_message(buffer);
        } else if (strcmp(buffer, "score") == 0) {
            char message[MAX_BUFFER_SIZE];
            sprintf(message, "%s: %d", clients[fd].name, clients[fd].score);
            send_message(fd, message);
        } else {
            broadcast_message(buffer);
        }
    }
    if (len == 0) {
        printf("Client disconnected: %s\n", clients[fd].name);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].fd == fd) {
                clients[i] = clients[num_clients - 1];
                num_clients--;
                break;
            }
        }
        broadcast_message(clients[fd].name);
    }
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(1234);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    printf("Server listening on port 1234\n");

    while (1) {
        client_addr_len = sizeof(client_addr);
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) == -1) {
            perror("accept");
            continue;
        }

        printf("New client connected: %s\n", inet_ntoa(client_addr.sin_addr));

        handle_client(client_fd);
    }

    close(server_fd);
    return EXIT_SUCCESS;
}