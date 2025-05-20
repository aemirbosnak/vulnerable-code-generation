//FormAI DATASET v1.0 Category: Chat server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080

int client_count = 0;
int client_sockets[10];

void *client_handler(void *client_socket) {
    int sock = *(int*)client_socket;
    char msg[1024];
    int read_size;

    while ((read_size = recv(sock, msg, 1024, 0)) > 0) {
        msg[read_size] = '\0';
        printf("Received message from %d: %s", sock, msg);
        
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != sock) {
                send(client_sockets[i], msg, strlen(msg), 0);
            }
        }
    }

    if (read_size == 0) {
        client_count--;
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] == sock) {
                while (i < client_count) {
                    client_sockets[i] = client_sockets[i + 1];
                    i++;
                }
                break;
            }
        }
        printf("Client disconnected: %d\n", sock);
    } else {
        perror("recv() failed");
    }

    close(sock);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        printf("New client connected: %d\n", new_socket);

        client_sockets[client_count++] = new_socket;

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void*)&new_socket) < 0) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }
        if (client_count == 10) {
            break;
        }
    }

    return 0;
}