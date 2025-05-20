//Falcon-180B DATASET v1.0 Category: Chat server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 512
#define DELIMITER " "

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_clients = 0;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    char *token;
    time_t current_time;

    srand(time(NULL));

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for connections
    if (listen(server_socket, 3) < 0) {
        printf("Error listening\n");
        exit(1);
    }

    while (1) {
        printf("Waiting for client to connect...\n");

        // Accept connection
        if ((client_socket[max_clients] = accept(server_socket, (struct sockaddr *)&client_addr[max_clients], sizeof(client_addr[max_clients]))) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        max_clients++;
        printf("Client connected: %s:%d\n", inet_ntoa(client_addr[max_clients-1].sin_addr), ntohs(client_addr[max_clients-1].sin_port));

        send(client_socket[max_clients-1], "Welcome to the chat server!\n", strlen("Welcome to the chat server!\n"), 0);

        // Send current date and time
        current_time = time(NULL);
        strftime(buffer, BUFFER_SIZE, "Current date and time: %Y-%m-%d %H:%M:%S\n", localtime(&current_time));
        send(client_socket[max_clients-1], buffer, strlen(buffer), 0);
    }

    return 0;
}