//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 587
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    int client_socket;
    struct sockaddr_in server_address;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    // Create the client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the server address
    server = gethostbyname("smtp.example.com");

    if (server == NULL) {
        perror("Failed to resolve server address");
        exit(EXIT_FAILURE);
    }

    // Fill out the server address struct
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, server->h_addr, &server_address.sin_addr);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // Receive the welcome message from the server
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", buffer);

    // Send the EHLO command to the server
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "EHLO client.example.com\r\n");

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", buffer);

    // Send the MAIL FROM command to the server
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "MAIL FROM: <sender@example.com>\r\n");

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", buffer);

    // Send the RCPT TO command to the server
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "RCPT TO: <recipient@example.com>\r\n");

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", buffer);

    // Send the DATA command to the server
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "DATA\r\n");

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive message from server");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", buffer);

    // Send the message body to the server
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "Subject: Test Message\r\n\r\nThis is a test message.\r\n");

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    // Send the QUIT command to the server
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "QUIT\r\n");

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to server");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(client_socket);

    return 0;
}