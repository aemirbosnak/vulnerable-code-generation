//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define COMMAND_SIZE 100

/* Function to retrieve the response from the server */
void get_response(int sock, char* response) {
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);
    int bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    strcpy(response, buffer);
    printf("%s", response);
}

/* Function to send a command to the server */
void send_command(int sock, char* command) {
    int command_length = strlen(command);
    if (send(sock, command, command_length, 0) != command_length) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <Server address> <Username> <Password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create the TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Set the server connection details
    char* server_address = argv[1];
    int server_port = 110;
    struct sockaddr_in server_address_in;
    memset(&server_address_in, 0, sizeof(server_address_in));
    server_address_in.sin_family = AF_INET;
    server_address_in.sin_addr.s_addr = inet_addr(server_address);
    server_address_in.sin_port = htons(server_port);

    // Connect to the server
    if (connect(sock, (struct sockaddr*) &server_address_in, sizeof(server_address_in)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // Get the server response
    char response[BUFFER_SIZE];
    get_response(sock, response);

    // Authenticate with the server
    char username[COMMAND_SIZE];
    char password[COMMAND_SIZE];
    sprintf(username, "USER %s\r\n", argv[2]);
    sprintf(password, "PASS %s\r\n", argv[3]);
    send_command(sock, username);
    get_response(sock, response);
    send_command(sock, password);
    get_response(sock, response);

    // List the messages
    send_command(sock, "LIST\r\n");
    get_response(sock, response);

    // Retrieve the first message
    char command[COMMAND_SIZE];
    sprintf(command, "RETR %d\r\n", 1);
    send_command(sock, command);
    get_response(sock, response);

    // Close the socket
    close(sock);
    exit(EXIT_SUCCESS);
}