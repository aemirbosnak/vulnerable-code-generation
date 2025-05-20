//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>

// Define the maximum number of lights that can be controlled
#define MAX_LIGHTS 10

// Define the port number that the server will listen on
#define PORT 5555

// Define the maximum length of a message that can be received from a client
#define MAX_MSG_LEN 100

// Create a structure to represent a light
typedef struct {
    int id;
    char name[32];
    bool on;
} light;

// Create an array of lights
light lights[MAX_LIGHTS];

// Create a socket descriptor
int sockfd;

// Create a sockaddr_in structure to represent the server's address
struct sockaddr_in server_addr;

// Create a sockaddr_in structure to represent the client's address
struct sockaddr_in client_addr;

// Create a buffer to store the received message
char msg[MAX_MSG_LEN];

// Create a buffer to store the response message
char response[MAX_MSG_LEN];

// Main function
int main() {
    // Initialize the lights
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i;
        sprintf(lights[i].name, "Light %d", i);
        lights[i].on = false;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server's address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the server's address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Main loop
    while (true) {
        // Accept an incoming connection
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Receive a message from the client
        int n = recv(client_sockfd, msg, MAX_MSG_LEN, 0);
        if (n == -1) {
            perror("recv");
            close(client_sockfd);
            continue;
        }

        // Parse the message
        char *cmd = strtok(msg, " ");
        char *arg1 = strtok(NULL, " ");
        char *arg2 = strtok(NULL, " ");

        // Check the command
        if (strcmp(cmd, "on") == 0) {
            // Turn on the light
            int light_id = atoi(arg1);
            if (light_id >= 0 && light_id < MAX_LIGHTS) {
                lights[light_id].on = true;
                sprintf(response, "Light %d turned on", light_id);
                send(client_sockfd, response, strlen(response), 0);
            } else {
                sprintf(response, "Invalid light ID");
                send(client_sockfd, response, strlen(response), 0);
            }
        } else if (strcmp(cmd, "off") == 0) {
            // Turn off the light
            int light_id = atoi(arg1);
            if (light_id >= 0 && light_id < MAX_LIGHTS) {
                lights[light_id].on = false;
                sprintf(response, "Light %d turned off", light_id);
                send(client_sockfd, response, strlen(response), 0);
            } else {
                sprintf(response, "Invalid light ID");
                send(client_sockfd, response, strlen(response), 0);
            }
        } else if (strcmp(cmd, "status") == 0) {
            // Get the status of the light
            int light_id = atoi(arg1);
            if (light_id >= 0 && light_id < MAX_LIGHTS) {
                sprintf(response, "Light %d is %s", light_id, lights[light_id].on ? "on" : "off");
                send(client_sockfd, response, strlen(response), 0);
            } else {
                sprintf(response, "Invalid light ID");
                send(client_sockfd, response, strlen(response), 0);
            }
        } else {
            // Invalid command
            sprintf(response, "Invalid command");
            send(client_sockfd, response, strlen(response), 0);
        }

        // Close the client socket
        close(client_sockfd);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}