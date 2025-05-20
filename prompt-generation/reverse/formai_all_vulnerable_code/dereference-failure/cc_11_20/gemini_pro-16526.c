//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Maximum number of clients
#define MAX_CLIENTS 10

// Port number
#define PORT 8080

// Structure to store client information
typedef struct client {
    int socket;
    char name[50];
    int bill;
} client;

// Array of clients
client clients[MAX_CLIENTS];

// Main function
int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("[-] Error creating socket");
        exit(1);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("[-] Error setting socket options");
        exit(1);
    }

    // Bind the socket to the port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("[-] Error binding socket to port");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("[-] Error listening for incoming connections");
        exit(1);
    }

    // Accept incoming connections and handle them in a loop
    while (1) {
        // Accept an incoming connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("[-] Error accepting incoming connection");
            continue;
        }

        // Add the client to the array of clients
        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket == 0) {
                clients[i].socket = client_socket;
                strcpy(clients[i].name, "");
                clients[i].bill = 0;
                break;
            }
        }

        // Fork a new process to handle the client
        int pid = fork();
        if (pid == -1) {
            perror("[-] Error forking process");
            close(client_socket);
            continue;
        } else if (pid == 0) {
            // Child process
            close(server_socket);

            // Handle the client
            char buffer[1024];
            while (1) {
                // Receive a message from the client
                int len = recv(client_socket, buffer, sizeof(buffer), 0);
                if (len == 0) {
                    // Client has disconnected
                    close(client_socket);
                    exit(0);
                } else if (len == -1) {
                    perror("[-] Error receiving message from client");
                    close(client_socket);
                    exit(1);
                }

                // Parse the message
                char *command = strtok(buffer, " ");
                char *arg = strtok(NULL, " ");

                // Handle the command
                if (strcmp(command, "name") == 0) {
                    // Set the client's name
                    strcpy(clients[i].name, arg);
                    send(client_socket, "Name set successfully", strlen("Name set successfully") + 1, 0);
                } else if (strcmp(command, "order") == 0) {
                    // Add the item to the client's bill
                    int price = atoi(arg);
                    clients[i].bill += price;
                    send(client_socket, "Item added to bill successfully", strlen("Item added to bill successfully") + 1, 0);
                } else if (strcmp(command, "bill") == 0) {
                    // Send the client their bill
                    char bill[1024];
                    sprintf(bill, "Your bill is: %d", clients[i].bill);
                    send(client_socket, bill, strlen(bill) + 1, 0);
                } else if (strcmp(command, "exit") == 0) {
                    // Close the client's connection
                    close(client_socket);
                    exit(0);
                }
            }
        } else {
            // Parent process
            close(client_socket);
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}