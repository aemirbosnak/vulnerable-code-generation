//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFERSIZE 1024

void die(char *msg) {
    perror(msg);
    exit(1);
}

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFERSIZE];
    int bytes_received = 0;

    while ((bytes_received = recv(client_socket, buffer + bytes_received, BUFFERSIZE - bytes_received, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent: %s\n", client_socket, buffer);
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        die("socket failed");

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        die("setsockopt");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        die("bind failed");

    if (listen(server_socket, BACKLOG) < 0)
        die("listen");

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen)) < 0)
            die("accept");

        printf("Client %d connected\n", client_socket);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket);
    }

    return 0;
}