//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 5

void *handle_client(void *client_socket);
void send_email(const char *message);
void receive_email(int sock);
void show_menu();

int main() {
    int server_socket, client_socket, addr_len;
    struct sockaddr_in address;
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting the address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Email client server running on port %d\n", PORT);
    
    while (1) {
        addr_len = sizeof(address);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_t thread;
        printf("Accepted new connection\n");

        // Create a new thread for the client
        if (pthread_create(&thread, NULL, handle_client, (void *)&client_socket) != 0) {
            perror("Thread creation failed");
            close(client_socket);
        }
        pthread_detach(thread);  // Detach thread to avoid memory leaks
    }

    // Close the server socket
    close(server_socket);
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Display menu
    show_menu();

    // Wait for client operations
    while ((bytes_read = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_read] = '\0';

        if (strcmp(buffer, "1") == 0) {
            send_email("Sample email message!");
        } else if (strcmp(buffer, "2") == 0) {
            receive_email(sock);
        } else if (strcmp(buffer, "3") == 0) {
            printf("Client disconnected.\n");
            close(sock);
            pthread_exit(NULL);
        } else {
            printf("Invalid option. Please try again.\n");
        }
        show_menu();
    }

    if (bytes_read == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("recv failed");
    }

    close(sock);
    return NULL;
}

void send_email(const char *message) {
    printf("Sending email: %s\n", message);
    // Simulate sending an email with a sleep
    sleep(1);
    printf("Email sent!\n");
}

void receive_email(int sock) {
    char buffer[BUFFER_SIZE];
    
    printf("Receiving emails...\n");
    // Simulated emails
    char *emails[] = {
        "Email 1: Welcome to our service!",
        "Email 2: Your order has been shipped.",
        "Email 3: How are you doing?",
        NULL
    };

    for (int i = 0; emails[i] != NULL; i++) {
        sprintf(buffer, "Sending to client: %s\n", emails[i]);
        send(sock, buffer, strlen(buffer), 0);
    }
    printf("All emails sent to client.\n");
}

void show_menu() {
    printf("Menu:\n");
    printf("1. Send Email\n");
    printf("2. Receive Emails\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}