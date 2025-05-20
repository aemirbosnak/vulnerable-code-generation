//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_address;
    struct hostent *server;

    // Check if the user provided enough arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Resolve the server name into an IP address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: Could not resolve hostname.\n");
        exit(1);
    }

    // Create a TCP socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        fprintf(stderr, "ERROR: Could not create socket.\n");
        exit(1);
    }

    // Configure the server address
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "ERROR: Could not connect to server.\n");
        exit(1);
    }

    // Receive the greeting from the server
    bzero(buffer, MAX_BUFFER_SIZE);
    recv(client_socket, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    // Prepare the message to be sent
    char sender[MAX_BUFFER_SIZE];
    char recipient[MAX_BUFFER_SIZE];
    char message[MAX_BUFFER_SIZE * 10];
    printf("\nEnter Sender Email: ");
    scanf("%s", sender);
    printf("Enter Recipient Email: ");
    scanf("%s", recipient);
    printf("Enter Message: ");
    getchar();
    fgets(message, sizeof(message), stdin);

    // Send the message to the server
    bzero(buffer, MAX_BUFFER_SIZE);
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "MAIL FROM:<%s>\r\n", sender);
    send(client_socket, buffer, strlen(buffer), 0);
    bzero(buffer, MAX_BUFFER_SIZE);
    recv(client_socket, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    bzero(buffer, MAX_BUFFER_SIZE);
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "RCPT TO:<%s>\r\n", recipient);
    send(client_socket, buffer, strlen(buffer), 0);
    bzero(buffer, MAX_BUFFER_SIZE);
    recv(client_socket, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    bzero(buffer, MAX_BUFFER_SIZE);
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "DATA\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    bzero(buffer, MAX_BUFFER_SIZE);
    recv(client_socket, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    bzero(buffer, MAX_BUFFER_SIZE);
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "Subject: Test Email\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_BUFFER_SIZE);
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "From: <%s>\r\n", sender);
    send(client_socket, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_BUFFER_SIZE);
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "To: <%s>\r\n", recipient);
    send(client_socket, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_BUFFER_SIZE);
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "\r\n%s", message);
    send(client_socket, buffer, strlen(buffer), 0);

    // Notify the server that we're done sending the message
    bzero(buffer, MAX_BUFFER_SIZE);
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "\r\n.\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    bzero(buffer, MAX_BUFFER_SIZE);
    recv(client_socket, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    // Disconnect from the server
    bzero(buffer, MAX_BUFFER_SIZE);
    snprintf(buffer, MAX_BUFFER_SIZE - 1, "QUIT\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    bzero(buffer, MAX_BUFFER_SIZE);
    recv(client_socket, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);
    close(client_socket);

    return 0;
}