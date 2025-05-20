//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 5

void *ping_client(void *client_socket);
void handle_ping_response(int ping_time, int client_num);

int main() {
    int server_fd, new_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    pthread_t threads[MAX_CLIENTS];
    int client_count = 0;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
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

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Ping server started on port %d\n", PORT);
    
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        if (client_count >= MAX_CLIENTS) {
            printf("Max clients reached. Connection refused.\n");
            close(new_socket);
            continue;
        }
        
        client_socket[client_count] = new_socket;
        printf("Client %d connected.\n", client_count + 1);
        
        pthread_create(&threads[client_count], NULL, ping_client, (void *)&client_socket[client_count]);
        client_count++;
    }
    
    for (int i = 0; i < client_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *ping_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    
    while (1) {
        snprintf(buffer, sizeof(buffer), "PING");
        send(sock, buffer, strlen(buffer), 0);
        
        int start_time = clock();
        
        // Wait for PING response
        int valread = recv(sock, buffer, BUFFER_SIZE, 0);
        int end_time = clock();
        
        if (valread <= 0) {
            perror("Client disconnected or error in receiving");
            break;
        }

        buffer[valread] = '\0';
        int ping_time = ((end_time - start_time) * 1000) / CLOCKS_PER_SEC;
        
        handle_ping_response(ping_time, *((int *)client_socket));
    }
    
    close(sock);
    printf("Client connection closed.\n");
    return NULL;
}

void handle_ping_response(int ping_time, int client_num) {
    if (ping_time < 100) {
        printf("Client %d: Response time: %d ms (Good)\n", client_num, ping_time);
    } else if (ping_time < 300) {
        printf("Client %d: Response time: %d ms (Average)\n", client_num, ping_time);
    } else {
        printf("Client %d: Response time: %d ms (Poor)\n", client_num, ping_time);
    }
}