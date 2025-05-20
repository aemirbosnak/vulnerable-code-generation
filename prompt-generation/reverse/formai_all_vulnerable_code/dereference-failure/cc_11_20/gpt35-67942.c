//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LENGTH 1024

int main(int argc , char *argv[]) {

    // Variables for socket, port, IP address and command input
    int socket_desc;
    struct sockaddr_in server;
    char command[MAX_LENGTH];
    char response[MAX_LENGTH];
    char *ip = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        printf("Error: Could not create socket");
        return 1;
    }

    // Set server address properties
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
        printf("Error: Could not connect to server");
        return 1;
    }

    printf("Connected to FTP server\n");

    // Get response from server
    if (recv(socket_desc, response, sizeof(response), 0) < 0) {
        printf("Error: Could not receive response from server");
        return 1;
    }

    // Print server's welcome message
    printf("%s", response);

    // Loop to handle user input
    while (1) {

        printf("ftp> ");
        fgets(command, MAX_LENGTH, stdin);

        // Remove trailing newline from command
        strtok(command, "\n");

        // Send command to server
        if (send(socket_desc, command, strlen(command) + 1, 0) == -1) {
            printf("Error: Could not send command to server");
            return 1;
        }

        // Check if command is 'quit'
        if (strcmp(command, "quit") == 0) {
            printf("Closing connection\n");
            close(socket_desc); // Close socket connection
            return 0;
        }

        // Receive response from server
        if (recv(socket_desc, response, sizeof(response), 0) < 0) {
            printf("Error: Could not receive response from server");
            return 1;
        }

        // Print server's response
        printf("%s", response);

        // If command is 'get'
        if (strstr(command, "get") != NULL) {
            char filename[MAX_LENGTH];
            sscanf(command, "get %s", filename);

            // Open file to write response to
            int file_desc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
            if (file_desc == -1) {
                printf("Error: Could not create file\n");
                return 1;
            }

            // Write server's response to file
            if (write(file_desc, response, strlen(response)) == -1) {
                printf("Error: Could not write to file\n");
                return 1;
            }

            printf("File '%s' received successfully\n", filename);
            close(file_desc); // Close file connection
        }

        // If command is 'put'
        if (strstr(command, "put") != NULL) {
            char filename[MAX_LENGTH];
            sscanf(command, "put %s", filename);

            // Open file to read from
            int file_desc = open(filename, O_RDONLY);
            if (file_desc == -1) {
                printf("Error: Could not open file\n");
                return 1;
            }

            // Read from file and send to server
            int read_size;
            char buffer[MAX_LENGTH] = {0};
            while ((read_size = read(file_desc, buffer, sizeof(buffer))) > 0) {
                if (send(socket_desc, buffer, read_size, 0) == -1) {
                    printf("Error: Could not send data to server\n");
                    return 1;
                }
            }

            printf("File '%s' sent successfully\n", filename);
            close(file_desc); // Close file connection
        }
    }

    return 0;
}