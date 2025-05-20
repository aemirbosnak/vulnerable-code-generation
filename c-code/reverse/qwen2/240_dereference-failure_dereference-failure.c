#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5

void* handle_client(void* arg) {
    int client_socket = *(int*)arg;
    free(arg);

    char buffer[1024] = {0};
    while (1) {
        int valread = read(client_socket, buffer, sizeof(buffer));
        if (valread <= 0) {
            printf("Client disconnected\n");
            close(client_socket);
            return NULL;
        }
        send(client_socket, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
    }

    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    pthread_t thread_id[MAX_CLIENTS];

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    int client_count = 0;

    while (client_count < MAX_CLIENTS) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            continue;
        }

        int* client_socket_ptr = malloc(sizeof(int));
        *client_socket_ptr = new_socket;

        if (pthread_create(&thread_id[client_count], NULL, handle_client, (void*)client_socket_ptr) != 0) {
            perror("pthread_create");
            free(client_socket_ptr);
            close(new_socket);
        } else {
            client_count++;
        }
    }

    for (int i = 0; i < client_count; i++) {
        pthread_join(thread_id[i], NULL);
    }

    close(server_fd);
    return 0;
}
