#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *arg) {
    int client_socket = (int)arg;
    char buffer[BUFFER_SIZE];

    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("Received: %s\n", buffer);

    // Dereference failure vulnerability: improperly casting thread argument
    int *dereferenced_arg = (int *)client_socket;
    *dereferenced_arg = 42;

    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
    }

    close(server_socket);
    return 0;
}
