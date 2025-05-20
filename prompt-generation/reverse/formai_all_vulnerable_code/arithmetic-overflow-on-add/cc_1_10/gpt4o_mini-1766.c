//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define JOKES_COUNT 5

const char *jokes[JOKES_COUNT] = {
    "Why did the scarecrow win an award? Because he was outstanding in his field!",
    "I told my computer I needed a break, and now it won't stop sending me beach wallpapers.",
    "Why don't programmers like nature? It has too many bugs.",
    "Why do Java developers wear glasses? Because they don’t see sharp.",
    "I would tell you a UDP joke, but you might not get it."
};

void handle_client(int client_socket) {
    srand(time(NULL) + client_socket); // Seed randomness for each client
    int joke_index = rand() % JOKES_COUNT; // Select a random joke
    send(client_socket, jokes[joke_index], strlen(jokes[joke_index]), 0);
    printf("Sent joke to client: %s\n", jokes[joke_index]);
    close(client_socket);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1, addrlen = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Define server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Joke Server is running on port %d\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }
        printf("New client connected!\n");
        
        // Handle the client
        handle_client(client_socket);
    }

    // Close the server socket (although this point is never reached)
    close(server_fd);
    return 0;
}