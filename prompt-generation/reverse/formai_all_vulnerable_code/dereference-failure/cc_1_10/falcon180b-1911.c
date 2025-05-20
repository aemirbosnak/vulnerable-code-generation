//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

void *thread_function(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("Received message from client: %s\n", buffer);
    }

    if (bytes_received == 0) {
        printf("Client disconnected\n");
    } else {
        printf("Error receiving message: %s\n", strerror(errno));
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        error_handling("socket failed");

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        error_handling("setsockopt");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error_handling("bind failed");

    if (listen(server_socket, 5) < 0)
        error_handling("listen");

    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0)
            error_handling("accept");

        printf("New client connected\n");

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread_function, (void *)&new_socket);
    }

    return 0;
}