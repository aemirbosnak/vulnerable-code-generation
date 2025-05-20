//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10

void *handle_request(void *arg);

int main() {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Medieval Web Server is ready to serve on port %d\n", PORT);

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_request, (void*)&client_socket);
        pthread_detach(thread_id);
    }

    close(listen_socket);
    return 0;
}

void *handle_request(void *arg) {
    int client_socket = *((int*) arg);
    char buffer[1024];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received request: %s\n", buffer);

        char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n";
        response[strlen(response)-2] = '\0'; // Remove last \r\n

        send(client_socket, response, strlen(response), 0);
    }

    close(client_socket);
    return NULL;
}