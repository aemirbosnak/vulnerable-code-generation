//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

typedef struct {
    int id;
    int socket;
    char name[50];
    int position_x;
    int position_y;
} Drone;

Drone drones[MAX_CLIENTS];
int drone_count = 0;

void* client_handler(void* arg) {
    int client_socket = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int id;
    
    // Get drone id
    recv(client_socket, &id, sizeof(int), 0);
    printf("Drone %d connected.\n", id);
    
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        
        if (bytes_received <= 0) {
            printf("Drone %d disconnected.\n", id);
            break;
        }

        int command_x, command_y;
        sscanf(buffer, "%d %d", &command_x, &command_y);
        drones[id].position_x += command_x;
        drones[id].position_y += command_y;

        printf("Drone %d moved to position (%d, %d)\n", id, drones[id].position_x, drones[id].position_y);
        
        // Send back the drone's current position
        sprintf(buffer, "Position: (%d, %d)", drones[id].position_x, drones[id].position_y);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create socket");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return EXIT_FAILURE;
    }

    listen(server_socket, MAX_CLIENTS);
    printf("Drone control server started on port %d\n", PORT);
    
    while (drone_count < MAX_CLIENTS) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Set up the drone
        drones[drone_count].id = drone_count;
        drones[drone_count].socket = client_socket;
        drones[drone_count].position_x = 0;
        drones[drone_count].position_y = 0;

        // Send ID to the drone
        send(client_socket, &drones[drone_count].id, sizeof(int), 0);
        
        // Create a new thread for the drone
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, client_handler, (void*)&client_socket);
        drone_count++;
    }

    close(server_socket);
    return EXIT_SUCCESS;
}