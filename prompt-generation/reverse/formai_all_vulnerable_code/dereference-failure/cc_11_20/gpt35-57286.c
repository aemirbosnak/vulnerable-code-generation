//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int ctrl_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Check if the user has passed in the right number of arguments
    if (argc != 3) {
        printf("Incorrect number of arguments. Usage: %s <server IP> <port>\n", argv[0]);
        return -1;
    }

    // Open a socket to connect to the server
    ctrl_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (ctrl_socket == -1) {
        perror("socket");
        return -1;
    }

    // Configure the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(ctrl_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return -1;
    }

    // Wait for the server to say hello
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(ctrl_socket, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        return -1;
    }
    printf("%s", buffer);

    // Send the username to the server
    char *username = "USERNAME";
    if (send(ctrl_socket, username, strlen(username), 0) == -1) {
        perror("send");
        return -1;
    }

    // Wait for the server to ask for the password
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(ctrl_socket, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        return -1;
    }

    // Send the password to the server
    char *password = "PASSWORD";
    if (send(ctrl_socket, password, strlen(password), 0) == -1) {
        perror("send");
        return -1;
    }

    // Wait for the server to acknowledge the login
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(ctrl_socket, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        return -1;
    }
    printf("%s", buffer);

    // Enter the infinite command loop
    while (1) {
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Strip the newline character
        buffer[strlen(buffer) - 1] = '\0';

        // Send the command to the server
        if (send(ctrl_socket, buffer, strlen(buffer), 0) == -1) {
            perror("send");
            return -1;
        }

        // Wait for the response from the server
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(ctrl_socket, buffer, BUFFER_SIZE, 0) == -1) {
            perror("recv");
            return -1;
        }
        printf("%s", buffer);
    }

    // Close the control socket
    close(ctrl_socket);

    return 0;
}