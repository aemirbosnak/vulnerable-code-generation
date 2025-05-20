//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_SUBSCRIBERS 100

char *subscribers[MAX_SUBSCRIBERS];
int subscriber_count = 0;

void save_subscriber(const char *email) {
    FILE *file = fopen("subscribers.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s\n", email);
        fclose(file);
    }
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    
    // Receive email from client
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        
        // Save email to the mailing list
        if (subscriber_count < MAX_SUBSCRIBERS) {
            subscribers[subscriber_count] = strdup(buffer);
            subscriber_count++;
            save_subscriber(buffer);
            send(client_socket, "Subscribed successfully!", 24, 0);
        } else {
            send(client_socket, "Subscriber limit reached!", 24, 0);
        }
    }
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    listen(server_socket, 3);
    printf("Mailing list server is running on port %d\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Client accept failed");
            continue;
        }
        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}