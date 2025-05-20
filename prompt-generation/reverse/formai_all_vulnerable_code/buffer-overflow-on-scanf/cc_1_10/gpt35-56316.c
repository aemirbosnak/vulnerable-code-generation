//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: happy
#include <stdio.h>     // C library for standard I/O operations
#include <stdlib.h>    // C library for general-purpose functions
#include <unistd.h>    // C library for various consts and types used in system calls
#include <string.h>    // C library for string operations
#include <sys/socket.h>// C library for socket operations
#include <arpa/inet.h> // C library for Internet protocol (IP) operations

#define PORT 21 // FTP port number

int main(int argc, char **argv) {

    int client_socket;
    struct sockaddr_in server_address;
    char buffer[1024];
    char user[50];
    char password[50];
    char commands[100][50];
    char response[1024];
    int n_commands = 3;
    int i = 0;

    client_socket = socket(AF_INET, SOCK_STREAM, 0); // Create client socket

    if(client_socket < 0) {
        perror("Error creating the socket");
        return 1;
    }

    server_address.sin_family = AF_INET;  // Set the protocol family
    server_address.sin_port = htons(PORT);// Set the port
    server_address.sin_addr.s_addr = inet_addr(argv[1]);// Set the IP address

    // Connect the socket
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to the server");
        return 1;
    }

    // Get the username and password
    printf("Please enter the username: ");
    scanf("%s", user);
    printf("Please enter the password: ");
    scanf("%s", password);

    // Send the user command and get the response
    strcpy(buffer, "USER ");
    strcat(buffer, user);
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, response, sizeof(response), 0);
    printf("%s", response);

    // Send the password command and get the response
    strcpy(buffer, "PASS ");
    strcat(buffer, password);
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, response, sizeof(response), 0);
    printf("%s", response);

    // Set up the list of commands
    strcpy(commands[0], "PWD");
    strcpy(commands[1], "LIST");
    strcpy(commands[2], "QUIT");

    while(i < n_commands) {

        // Send a command and get the response
        strcpy(buffer, commands[i]);
        send(client_socket, buffer, strlen(buffer), 0);
        recv(client_socket, response, sizeof(response), 0);
        printf("%s", response);

        // Update the counter
        i++;
    }

    // Close the socket
    close(client_socket);

    return 0;

}