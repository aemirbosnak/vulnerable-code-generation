//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Client thread function
void *client_thread(void *arg) {
    int sock = (int) arg;
    char buffer[BUFFER_SIZE];

    // Receive and print the message from the server
    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("Received from server: %s\n", buffer);

    // Close the socket
    close(sock);

    return NULL;
}

// Server thread function
void *server_thread(void *arg) {
    int sock = (int) arg;
    char buffer[BUFFER_SIZE];

    // Receive the message from the client
    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        exit(1);
    }
    buffer[bytes_received] = '\0';

    // Convert the message to uppercase
    for (int i = 0; i < strlen(buffer); i++) {
        buffer[i] = toupper(buffer[i]);
    }

    // Send the message back to the client
    int bytes_sent = send(sock, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(sock);

    return NULL;
}

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to the server address
    if (bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections and create threads for each client
    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        pthread_t client_thread_id;
        if (pthread_create(&client_thread_id, NULL, client_thread, (void *) client_sock) != 0) {
            perror("pthread_create");
            continue;
        }

        pthread_t server_thread_id;
        if (pthread_create(&server_thread_id, NULL, server_thread, (void *) client_sock) != 0) {
            perror("pthread_create");
            continue;
        }
    }

    // Close the socket
    close(sock);

    return 0;
}