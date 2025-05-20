//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// The FTP Client
int main() {
    char server_response[BUFFER_SIZE];
    char user_input[BUFFER_SIZE];

    // Create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect the socket to the specified address
    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (connection_status == -1) {
        printf("There was an error connecting to the FTP server.\n");
        return -1;
    }

    // Receive a welcome message from the server
    memset(server_response, 0, sizeof(server_response));
    recv(network_socket, &server_response, sizeof(server_response), 0);
    printf("%s", server_response);

    // Send the username
    printf("Username: ");
    fgets(user_input, BUFFER_SIZE, stdin);
    char *username = strtok(user_input, "\n");
    char username_command[BUFFER_SIZE];
    sprintf(username_command, "USER %s\r\n", username);
    send(network_socket, username_command, strlen(username_command), 0);

    // Receive a response from the server
    memset(server_response, 0, sizeof(server_response));
    recv(network_socket, &server_response, sizeof(server_response), 0);
    printf("%s", server_response);

    // Send the password
    printf("Password: ");
    fgets(user_input, BUFFER_SIZE, stdin);
    char *password = strtok(user_input, "\n");
    char password_command[BUFFER_SIZE];
    sprintf(password_command, "PASS %s\r\n", password);
    send(network_socket, password_command, strlen(password_command), 0);

    // Receive a response from the server
    memset(server_response, 0, sizeof(server_response));
    recv(network_socket, &server_response, sizeof(server_response), 0);
    printf("%s", server_response);

    // Print the welcome message
    printf("\nWelcome to the FTP client. You can now use the following commands:\n");
    printf("    - ls: list the contents of the current directory\n");
    printf("    - mkdir: create a new directory\n");
    printf("    - cd: change the current directory\n");
    printf("    - get: download a file from the server\n");
    printf("    - put: upload a file to the server\n");
    printf("    - quit: exit the FTP client\n\n");

    // Loop to read and process user commands
    while (1) {
        // Get the user command
        printf("Enter a command: ");
        fgets(user_input, BUFFER_SIZE, stdin);
        char *command = strtok(user_input, " \n");

        // Handle the user command
        if (strcmp(command, "ls") == 0) {
            char ls_command[] = "LIST\r\n";
            send(network_socket, ls_command, strlen(ls_command), 0);

            // Receive and print the response from the server
            memset(server_response, 0, sizeof(server_response));
            recv(network_socket, &server_response, sizeof(server_response), 0);
            printf("%s", server_response);
        } else if (strcmp(command, "mkdir") == 0) {
            // Get the directory name from the user
            char *directory_name = strtok(NULL, " \n");

            // Send the command to the server
            char mkdir_command[BUFFER_SIZE];
            sprintf(mkdir_command, "MKD %s\r\n", directory_name);
            send(network_socket, mkdir_command, strlen(mkdir_command), 0);

            // Receive and print the response from the server
            memset(server_response, 0, sizeof(server_response));
            recv(network_socket, &server_response, sizeof(server_response), 0);
            printf("%s", server_response);
        } else if (strcmp(command, "cd") == 0) {
            // Get the directory name from the user
            char *directory_name = strtok(NULL, " \n");

            // Send the command to the server
            char cd_command[BUFFER_SIZE];
            sprintf(cd_command, "CWD %s\r\n", directory_name);
            send(network_socket, cd_command, strlen(cd_command), 0);

            // Receive and print the response from the server
            memset(server_response, 0, sizeof(server_response));
            recv(network_socket, &server_response, sizeof(server_response), 0);
            printf("%s", server_response);
        } else if (strcmp(command, "get") == 0) {
            // Get the filename from the user
            char *filename = strtok(NULL, " \n");

            // Send the command to the server
            char get_command[BUFFER_SIZE];
            sprintf(get_command, "RETR %s\r\n", filename);
            send(network_socket, get_command, strlen(get_command), 0);

            // Open the local file for writing
            FILE *local_file = fopen(filename, "w");

            // Receive and write the data from the server to the local file
            char buffer[BUFFER_SIZE];
            int bytes_received = 0;
            while ((bytes_received = recv(network_socket, buffer, BUFFER_SIZE, 0)) > 0) {
                fwrite(buffer, bytes_received, 1, local_file);
            }

            // Close the local file
            fclose(local_file);

            // Receive and print the response from the server
            memset(server_response, 0, sizeof(server_response));
            recv(network_socket, &server_response, sizeof(server_response), 0);
            printf("%s", server_response);
        } else if (strcmp(command, "put") == 0) {
            // Get the filename from the user
            char *filename = strtok(NULL, " \n");

            // Open the local file for reading
            FILE *local_file = fopen(filename, "r");
            if (local_file == NULL) {
                printf("Error: unable to open local file '%s'\n", filename);
                continue;
            }

            // Send the command to the server
            char put_command[BUFFER_SIZE];
            sprintf(put_command, "STOR %s\r\n", filename);
            send(network_socket, put_command, strlen(put_command), 0);

            // Read and send the data from the local file to the server
            char buffer[BUFFER_SIZE];
            int bytes_read = 0;
            while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, local_file)) > 0) {
                send(network_socket, buffer, bytes_read, 0);
            }

            // Close the local file
            fclose(local_file);

            // Receive and print the response from the server
            memset(server_response, 0, sizeof(server_response));
            recv(network_socket, &server_response, sizeof(server_response), 0);
            printf("%s", server_response);
        } else if (strcmp(command, "quit") == 0) {
            // Send the quit command
            char quit_command[] = "QUIT\r\n";
            send(network_socket, quit_command, strlen(quit_command), 0);

            // Receive and print the response from the server
            memset(server_response, 0, sizeof(server_response));
            recv(network_socket, &server_response, sizeof(server_response), 0);
            printf("%s", server_response);

            break;
        } else {
            printf("Unknown command.\n");
        }
    }

    // Close the socket
    close(network_socket);

    return 0;
}