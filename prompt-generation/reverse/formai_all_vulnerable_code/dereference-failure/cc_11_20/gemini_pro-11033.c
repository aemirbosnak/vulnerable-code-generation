//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: random
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Client-side FTP program
int main(int argc, char** argv) {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[1024];
    char command[1024];
    char filename[1024];
    char file_buffer[1024];
    int file_size;
    int bytes_received;
    int bytes_sent;

    // Create a client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receive the welcome message from the server
    bytes_received = recv(client_socket, buffer, 1024, 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Main loop
    while (1) {
        // Get the command from the user
        printf("ftp> ");
        fgets(command, 1024, stdin);

        // Parse the command
        if (strcmp(command, "quit\n") == 0) {
            // Quit the program
            break;
        } else if (strcmp(command, "get\n") == 0) {
            // Get a file from the server
            printf("Enter the filename: ");
            fgets(filename, 1024, stdin);

            // Send the GET command to the server
            bytes_sent = send(client_socket, command, strlen(command), 0);
            if (bytes_sent == -1) {
                perror("send");
                exit(1);
            }

            // Receive the file size from the server
            bytes_received = recv(client_socket, buffer, 1024, 0);
            if (bytes_received == -1) {
                perror("recv");
                exit(1);
            }
            file_size = atoi(buffer);

            // Receive the file from the server
            bytes_received = recv(client_socket, file_buffer, file_size, 0);
            if (bytes_received == -1) {
                perror("recv");
                exit(1);
            }

            // Write the file to the local disk
            FILE *file = fopen(filename, "w");
            if (file == NULL) {
                perror("fopen");
                exit(1);
            }
            fwrite(file_buffer, 1, file_size, file);
            fclose(file);

            // Print the success message
            printf("File received successfully.\n");
        } else if (strcmp(command, "put\n") == 0) {
            // Put a file to the server
            printf("Enter the filename: ");
            fgets(filename, 1024, stdin);

            // Send the PUT command to the server
            bytes_sent = send(client_socket, command, strlen(command), 0);
            if (bytes_sent == -1) {
                perror("send");
                exit(1);
            }

            // Get the file size
            FILE *file = fopen(filename, "r");
            if (file == NULL) {
                perror("fopen");
                exit(1);
            }
            fseek(file, 0, SEEK_END);
            file_size = ftell(file);
            rewind(file);

            // Send the file size to the server
            sprintf(buffer, "%d", file_size);
            bytes_sent = send(client_socket, buffer, strlen(buffer), 0);
            if (bytes_sent == -1) {
                perror("send");
                exit(1);
            }

            // Send the file to the server
            bytes_sent = send(client_socket, file_buffer, file_size, 0);
            if (bytes_sent == -1) {
                perror("send");
                exit(1);
            }

            // Print the success message
            printf("File sent successfully.\n");
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }
    }

    // Close the client socket
    close(client_socket);

    return 0;
}