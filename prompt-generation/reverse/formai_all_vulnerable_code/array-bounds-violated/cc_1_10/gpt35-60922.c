//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to display error messages
void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    // Check if the user entered the server and port number
    if(argc < 3) {
        printf("Usage: %s <Server Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    char *server_address = argv[1];
    int port_number = atoi(argv[2]);

    // Create a Socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_fd < 0) {
        error("Error creating Socket!");
    }

    printf("\nSocket created successfully!\n");

    // Set server details and connect to the server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(port_number);

    if(connect(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Error connecting to server!");
    }

    printf("\nConnected to the server successfully!\n");

    // User login details
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];

    printf("Enter your username: ");
    fgets(username, BUFFER_SIZE, stdin);

    printf("Enter your password: ");
    fgets(password, BUFFER_SIZE, stdin);

    // Remove the extra newline character from the input strings
    username[strlen(username)-1] = '\0';
    password[strlen(password)-1] = '\0';

    // Send the user login details to the server
    char buffer[BUFFER_SIZE] = {0};
    sprintf(buffer, "%s:%s", username, password);
    send(socket_fd, buffer, strlen(buffer), 0);

    // Receive confirmation from the server
    memset(buffer, 0, BUFFER_SIZE);
    recv(socket_fd, buffer, BUFFER_SIZE, 0);

    if(strcmp(buffer, "Success") != 0) {
        printf("Invalid Credentials!\n");
        exit(1);
    }

    printf("Successfully logged in as %s!\n", username);

    // Show the available files on the server
    printf("\n\n---- Available Files on Server ----\n\n");
    memset(buffer, 0, BUFFER_SIZE);
    recv(socket_fd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // User Input Loop
    while(1) {
        printf("\nEnter the name of the file you want to download (or type 'quit' to exit): ");
        char file_name[BUFFER_SIZE];
        fgets(file_name, BUFFER_SIZE, stdin);

        // Remove the extra newline character from the input string
        file_name[strlen(file_name)-1] = '\0';

        // Exit the program if the user types 'quit'
        if(strcmp(file_name, "quit") == 0) {
            printf("Exiting...\n");
            close(socket_fd);
            exit(0);
        }

        // Send the requested file name to the server
        send(socket_fd, file_name, BUFFER_SIZE, 0);

        // Receive the file size from the server
        int file_size = 0;
        recv(socket_fd, &file_size, sizeof(file_size), 0);

        if(file_size == -1) {
            printf("The requested file does not exist!\n");
            continue;
        }

        printf("The size of the file %s is %d bytes. Do you want to download it? (Y/n): ", file_name, file_size);

        char choice;
        scanf(" %c", &choice);

        if(choice == 'Y' || choice == 'y') {
            // Receive the file contents
            char file_contents[file_size];
            int bytes_received = recv(socket_fd, file_contents, file_size, 0);

            if(bytes_received == file_size) {
                printf("Downloading %s...\n", file_name);

                // Save the downloaded file in the local machine
                FILE *downloaded_file = fopen(file_name, "wb");
                fwrite(file_contents, 1, file_size, downloaded_file);
                fclose(downloaded_file);

                printf("The file %s has been downloaded successfully!\n", file_name);
            }
            else {
                printf("Error occurred while downloading the file!\n");
                break;
            }
        }
    }

    // Close the socket and exit the program
    close(socket_fd);
    return 0;
}