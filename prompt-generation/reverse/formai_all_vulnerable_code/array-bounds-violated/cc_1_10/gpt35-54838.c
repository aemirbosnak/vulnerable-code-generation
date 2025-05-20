//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 21
#define BUFFER_SIZE 1024

// helper function to send FTP commands to the server
void sendFTPCommand(int socket_fd, char *command) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s\r\n", command);

    if (send(socket_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending command");
        exit(EXIT_FAILURE);
    }

    printf("> %s\n", command);
}

// helper function to receive responses from the server
void receiveFTPResponse(int socket_fd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if ((bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0)) == -1) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0';
    printf("< %s", buffer);
}

int main() {
    int socket_fd;
    struct sockaddr_in server_address;

    // create TCP socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    // connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to FTP server at %s:%d\n", SERVER_ADDRESS, SERVER_PORT);

    // receive welcome message from server
    receiveFTPResponse(socket_fd);

    // send user name to server
    sendFTPCommand(socket_fd, "user anonymous");

    // receive response from server
    receiveFTPResponse(socket_fd);

    // send password to server
    sendFTPCommand(socket_fd, "pass email@example.com");

    // receive response from server
    receiveFTPResponse(socket_fd);

    // send PASV command to server to enter passive mode
    sendFTPCommand(socket_fd, "pasv");

    // receive response from server
    receiveFTPResponse(socket_fd);

    // send RETR command to retrieve file from server
    sendFTPCommand(socket_fd, "retr file.txt");

    // receive response from server
    receiveFTPResponse(socket_fd);

    // close socket connection
    close(socket_fd);

    // exit program
    return 0;
}