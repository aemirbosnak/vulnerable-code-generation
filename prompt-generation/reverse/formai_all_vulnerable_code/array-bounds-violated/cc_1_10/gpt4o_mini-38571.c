//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFSIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFSIZE];
    int n;

    // This hilarious server does stand-up comedy
    const char *jokes[] = {
        "Why do C programmers have it easy? Because they can’t C#!",
        "Did you hear about the mathematician who's afraid of negative numbers? He'll stop at nothing to avoid them!",
        "Why don’t programmers like nature? It has too many bugs!",
        "Why did the programmer quit his job? Because he didn't get arrays!",
        "Why do programmers prefer dark mode? Because light attracts bugs!"
    };

    srand(time(NULL));
    int joke_count = sizeof(jokes) / sizeof(jokes[0]);

    while (1) {
        // Send a joke to the client
        int joke_index = rand() % joke_count;
        send(client_socket, jokes[joke_index], strlen(jokes[joke_index]), 0);
        
        // Wait for a response (which will probably be a groan)
        n = recv(client_socket, buffer, BUFSIZE, 0);
        if (n <= 0) {
            printf("Client has left. Bye bye!\n");
            break;
        }

        buffer[n] = '\0'; // Null-terminate received string
        printf("Client: %s\n", buffer);
        
        if (strcmp(buffer, "groan") == 0) {
            printf("Server: Tough crowd!\n");
        } else if (strcmp(buffer, "great") == 0) {
            printf("Server: Wow! I have an admirer!\n");
        } else {
            printf("Server: I’ll stick to code, thank you!\n");
        }

        sleep(2); // Give them some time to laugh (or groan)
    }
    close(client_socket);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Bind
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server is ready to tell jokes on port %d\n", PORT);
    
    while ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
        printf("Accepted a new client! Time to make them laugh!\n");
        handle_client(client_socket);
    }
    
    if (client_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}