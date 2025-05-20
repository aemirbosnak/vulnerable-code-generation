//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE];

    // Check the number of command line arguments
    if(argc != 4) {
        printf("Usage: %s <server_address> <server_port> <email_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a TCP socket
    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize the server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if(inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        printf("Invalid server address\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Read the welcome message
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send the HELO command
    sprintf(buffer, "HELO %s\r\n", argv[3]);
    if(send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Read the response
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send the MAIL FROM command
    printf("Enter the sender email address: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    sprintf(buffer, "MAIL FROM:<%s>\r\n", buffer);
    if(send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Read the response
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send the RCPT TO command
    printf("Enter the recipient email address: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    sprintf(buffer, "RCPT TO:<%s>\r\n", buffer);
    if(send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Read the response
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    if(send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Read the response
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send the message body
    printf("Enter the message body: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    if(send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    if(send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Read the response
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("receive failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Close the socket
    close(client_socket);

    return EXIT_SUCCESS;
}