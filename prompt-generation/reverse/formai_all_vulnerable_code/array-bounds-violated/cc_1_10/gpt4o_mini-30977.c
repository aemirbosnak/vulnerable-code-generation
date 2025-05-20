//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void print_menu() {
    printf("Welcome to the POP3 Client!\n");
    printf("Choose an option:\n");
    printf("1. Connect to server\n");
    printf("2. Retrieve messages\n");
    printf("3. Quit\n");
}

void send_command(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
}

void receive_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Server: %s", buffer);
    } else {
        printf("Error receiving response from server.\n");
    }
}

int main() {
    int socket_fd;
    struct sockaddr_in server_address;

    char server_ip[16];
    int option;
    
    // Initialize the POP3 client
    print_menu();
    
    while (1) {
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: // Connect to server
                printf("Enter server IP address: ");
                scanf("%s", server_ip);

                // Create socket
                socket_fd = socket(AF_INET, SOCK_STREAM, 0);
                if (socket_fd < 0) {
                    perror("Socket creation failed");
                    exit(EXIT_FAILURE);
                }

                // Setup server address structure
                server_address.sin_family = AF_INET;
                server_address.sin_port = htons(PORT);
                inet_pton(AF_INET, server_ip, &server_address.sin_addr);

                // Connect to server
                if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
                    perror("Connection to server failed");
                    exit(EXIT_FAILURE);
                }

                printf("Connected to the POP3 server at %s\n", server_ip);
                receive_response(socket_fd);
                break;

            case 2: // Retrieve messages
                if (socket_fd < 0) {
                    printf("Please connect to a server first.\n");
                    break;
                }

                send_command(socket_fd, "USER myusername\r\n");
                receive_response(socket_fd);
                
                send_command(socket_fd, "PASS mypassword\r\n");
                receive_response(socket_fd);
                
                send_command(socket_fd, "LIST\r\n");
                receive_response(socket_fd);
                
                send_command(socket_fd, "QUIT\r\n");
                receive_response(socket_fd);
                
                close(socket_fd);
                socket_fd = -1; // Reset socket_fd after disconnection
                break;

            case 3: // Quit
                printf("Thank you for using the POP3 Client. Goodbye!\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }

        print_menu();
    }

    return 0;
}