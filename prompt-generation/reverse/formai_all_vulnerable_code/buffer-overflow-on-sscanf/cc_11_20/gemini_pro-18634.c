//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Drone state
struct drone_state {
    int x;
    int y;
    int z;
    int roll;
    int pitch;
    int yaw;
} state;

// Control commands
enum command {
    TAKEOFF,
    LAND,
    MOVE_FORWARD,
    MOVE_BACKWARD,
    MOVE_LEFT,
    MOVE_RIGHT,
    ROTATE_LEFT,
    ROTATE_RIGHT,
    FLIP_FORWARD,
    FLIP_BACKWARD,
    FLIP_LEFT,
    FLIP_RIGHT
};

// Remote control thread
void *remote_control(void *arg) {
    int sockfd = *(int *)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        // Receive command from client
        int n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        // Parse command
        int command;
        sscanf(buffer, "%d", &command);

        // Execute command
        switch (command) {
            case TAKEOFF:
                printf("Taking off...\n");
                state.z = 1;
                break;

            case LAND:
                printf("Landing...\n");
                state.z = 0;
                break;

            case MOVE_FORWARD:
                printf("Moving forward...\n");
                state.x += 1;
                break;

            case MOVE_BACKWARD:
                printf("Moving backward...\n");
                state.x -= 1;
                break;

            case MOVE_LEFT:
                printf("Moving left...\n");
                state.y += 1;
                break;

            case MOVE_RIGHT:
                printf("Moving right...\n");
                state.y -= 1;
                break;

            case ROTATE_LEFT:
                printf("Rotating left...\n");
                state.yaw += 1;
                break;

            case ROTATE_RIGHT:
                printf("Rotating right...\n");
                state.yaw -= 1;
                break;

            case FLIP_FORWARD:
                printf("Flipping forward...\n");
                state.pitch = 1;
                break;

            case FLIP_BACKWARD:
                printf("Flipping backward...\n");
                state.pitch = -1;
                break;

            case FLIP_LEFT:
                printf("Flipping left...\n");
                state.roll = -1;
                break;

            case FLIP_RIGHT:
                printf("Flipping right...\n");
                state.roll = 1;
                break;
        }
    }

    return NULL;
}

// Main function
int main() {
    // Create server socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind server socket to address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Create thread for remote control
    pthread_t thread;
    pthread_create(&thread, NULL, remote_control, &sockfd);

    // Serve client requests
    while (1) {
        // Accept client connection
        int clientfd = accept(sockfd, NULL, NULL);
        if (clientfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Send drone state to client
        char buffer[BUFFER_SIZE];
        snprintf(buffer, BUFFER_SIZE, "%d %d %d %d %d %d\n", state.x, state.y, state.z, state.roll, state.pitch, state.yaw);
        if (send(clientfd, buffer, BUFFER_SIZE, 0) < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        // Close client connection
        close(clientfd);
    }

    // Close server socket
    close(sockfd);

    return 0;
}