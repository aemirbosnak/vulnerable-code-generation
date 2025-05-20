//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define COMMAND_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./ftp_client <IP> <port>\n");
        return 0;
    }
    // Initiate the socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Socket creation failed!\n");
        return 0;
    }
    // Connect to the server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) != 1) {
        printf("Invalid IP address!\n");
        close(client_socket);
        return 0;
    }
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Connection failed!\n");
        close(client_socket);
        return 0;
    }
    // Main loop
    char command[COMMAND_SIZE];
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while (1) {
        printf("ftp_client> ");
        fgets(command, COMMAND_SIZE, stdin);
        if (strlen(command) == 0) {
            continue;
        }
        command[strlen(command) - 1] = '\0';
        if (strncmp("cd ", command, 3) == 0) {
            // Send the cd command to the server
            send(client_socket, command, strlen(command), 0);
        } else if (strncmp("ls", command, 2) == 0) {
            // Send the ls command to the server
            send(client_socket, command, strlen(command), 0);
            // Receive the file list from the server
            while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
                printf("%s", buffer);
            }
        } else if (strncmp("get ", command, 4) == 0) {
            // Send the get command to the server
            send(client_socket, command, strlen(command), 0);
            // Receive the file from the server
            char filename[COMMAND_SIZE - 4];
            strncpy(filename, command + 4, COMMAND_SIZE - 4);
            FILE *file = fopen(filename, "wb");
            if (file == NULL) {
                printf("Failed to open file %s!\n", filename);
                continue;
            }
            while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
                fwrite(buffer, 1, bytes_received, file);
            }
            fclose(file);
            printf("File %s downloaded successfully.\n", filename);
        } else if (strncmp("put ", command, 4) == 0) {
            // Send the put command to the server
            send(client_socket, command, strlen(command), 0);
            // Send the file to the server
            char filename[COMMAND_SIZE - 4];
            strncpy(filename, command + 4, COMMAND_SIZE - 4);
            FILE *file = fopen(filename, "rb");
            if (file == NULL) {
                printf("Failed to open file %s!\n", filename);
                continue;
            }
            while ((bytes_received = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
                send(client_socket, buffer, bytes_received, 0);
            }
            fclose(file);
            printf("File %s uploaded successfully.\n", filename);
        } else if (strncmp("quit", command, 4) == 0) {
            // Send the quit command to the server
            send(client_socket, command, strlen(command), 0);
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
    }
    // Close the socket
    close(client_socket);
    return 0;
}