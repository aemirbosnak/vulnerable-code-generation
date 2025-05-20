//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 5

void *client_handler(void *socket_desc);
void respond_to_client(int client_socket, const char *message);

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // Accept clients in a continuous loop
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        printf("New connection from %s:%d\n",
               inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void*)&new_socket) < 0) {
            perror("could not create thread");
            return 1;
        }

        // Detach the thread to avoid memory leak
        pthread_detach(thread_id);
    }

    if (new_socket < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void *client_handler(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Communication with the client
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null terminate the received string
        printf("Received from client: %s\n", buffer);

        // Respond based on message size
        respond_to_client(sock, buffer);
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    close(sock);
    return 0;
}

void respond_to_client(int client_socket, const char *message) {
    char response[BUFFER_SIZE];

    if (strlen(message) <= 20) {
        snprintf(response, sizeof(response), "Hey, short and sweet! I got your message: %s", message);
    } else {
        snprintf(response, sizeof(response), "Hmm, thoughtful message! You said: %s", message);
    }

    send(client_socket, response, strlen(response), 0);
}