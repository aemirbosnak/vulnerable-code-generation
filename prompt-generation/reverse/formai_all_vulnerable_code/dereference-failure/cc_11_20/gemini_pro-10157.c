//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>

#define PORT 5555
#define BACKLOG 5
#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

// Structure to store client information
typedef struct client_info {
    int sockfd;
    char *username;
    char *password;
    int authorized;
} client_info;

// Global variables
int server_sockfd;
int client_count = 0;
client_info clients[MAX_CLIENTS];

// Function to handle client connections
void *handle_client(void *arg) {
    int client_sockfd = *((int *)arg);
    free(arg);

    // Receive the client's username and password
    char username[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];
    if (recv(client_sockfd, username, MAX_BUFFER_SIZE, 0) == -1) {
        perror("recv");
        close(client_sockfd);
        pthread_exit(NULL);
    }
    if (recv(client_sockfd, password, MAX_BUFFER_SIZE, 0) == -1) {
        perror("recv");
        close(client_sockfd);
        pthread_exit(NULL);
    }

    // Check if the client is authorized
    int authorized = 0;
    for (int i = 0; i < client_count; i++) {
        if (strcmp(username, clients[i].username) == 0 && strcmp(password, clients[i].password) == 0) {
            authorized = 1;
            break;
        }
    }

    // Send the authorization status to the client
    if (send(client_sockfd, &authorized, sizeof(int), 0) == -1) {
        perror("send");
        close(client_sockfd);
        pthread_exit(NULL);
    }

    // If the client is authorized, handle their requests
    if (authorized) {
        while (1) {
            // Receive the client's request
            char request[MAX_BUFFER_SIZE];
            if (recv(client_sockfd, request, MAX_BUFFER_SIZE, 0) == -1) {
                perror("recv");
                close(client_sockfd);
                pthread_exit(NULL);
            }

            // Handle the client's request
            if (strcmp(request, "turn on lights") == 0) {
                // Send the command to turn on the lights
                if (send(client_sockfd, "lights on", strlen("lights on") + 1, 0) == -1) {
                    perror("send");
                    close(client_sockfd);
                    pthread_exit(NULL);
                }
            } else if (strcmp(request, "turn off lights") == 0) {
                // Send the command to turn off the lights
                if (send(client_sockfd, "lights off", strlen("lights off") + 1, 0) == -1) {
                    perror("send");
                    close(client_sockfd);
                    pthread_exit(NULL);
                }
            } else if (strcmp(request, "get temperature") == 0) {
                // Get the temperature from the sensor
                float temperature = 20.0; // Replace this with the actual temperature reading

                // Send the temperature to the client
                if (send(client_sockfd, &temperature, sizeof(float), 0) == -1) {
                    perror("send");
                    close(client_sockfd);
                    pthread_exit(NULL);
                }
            } else if (strcmp(request, "quit") == 0) {
                // Close the client's connection
                close(client_sockfd);
                pthread_exit(NULL);
            }
        }
    }

    // Close the client's connection
    close(client_sockfd);
    pthread_exit(NULL);
}

int main() {
    // Create a socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Bind the socket to an address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        // Accept a new connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client
        pthread_t thread;
        int *arg = malloc(sizeof(int));
        *arg = client_sockfd;
        if (pthread_create(&thread, NULL, handle_client, arg) != 0) {
            perror("pthread_create");
            close(client_sockfd);
            continue;
        }

        // Increment the client count
        client_count++;
    }

    // Close the server socket
    close(server_sockfd);

    return 0;
}