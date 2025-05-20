//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server address> <server port> <recipient email>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Step 1: Create a socket for the SMTP client
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Step 2: Connect to the server
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        herror("Error getting server");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr,
          (char *) &server_address.sin_addr.s_addr,
          server->h_length);
    server_address.sin_port = htons(atoi(argv[2]));

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);

    // Receive initial message from server
    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Print message from server
    printf("%s", buffer);

    // Step 3: Send HELO message to server
    sprintf(buffer, "HELO %s\r\n", argv[1]);

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    memset(buffer, 0, MAX_BUFFER);

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Print response from server
    printf("%s", buffer);

    // Step 4: Send MAIL FROM message to server
    sprintf(buffer, "MAIL FROM:<%s>\r\n", "sender@example.com");

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    memset(buffer, 0, MAX_BUFFER);

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Print response from server
    printf("%s", buffer);

    // Step 5: Send RCPT TO message to server
    sprintf(buffer, "RCPT TO:<%s>\r\n", argv[3]);

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    memset(buffer, 0, MAX_BUFFER);

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Print response from server
    printf("%s", buffer);

    // Step 6: Send DATA message to server
    sprintf(buffer, "DATA\r\n");

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    memset(buffer, 0, MAX_BUFFER);

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Print response from server
    printf("%s", buffer);

    // Step 7: Send email message to server
    sprintf(buffer, "From: %s\r\nTo: %s\r\nSubject: Test Email\r\n\r\nThis is a test email.\r\n.\r\n", "sender@example.com", argv[3]);

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    memset(buffer, 0, MAX_BUFFER);

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Print response from server
    printf("%s", buffer);

    // Step 8: Send QUIT message to server
    sprintf(buffer, "QUIT\r\n");

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    memset(buffer, 0, MAX_BUFFER);

    if (recv(client_socket, buffer, MAX_BUFFER, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Print response from server
    printf("%s", buffer);

    // Close connection
    close(client_socket);

    return 0;
}