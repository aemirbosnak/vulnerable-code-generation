//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <string.h>

#define MAX_LENGTH 1024
#define PORT 587

int main(int argc, char *argv[]) {
    int client_socket;
    char buffer[MAX_LENGTH];
    struct hostent *server;
    struct sockaddr_in server_address;
    char message[MAX_LENGTH];

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Could not create socket");
        return 1;
    }

    // Get the server's address
    server = gethostbyname("smtp.gmail.com");
    if (server == NULL) {
        perror("Could not resolve host name");
        return 1;
    }

    // Set up the server address
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(PORT);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Could not connect to server");
        return 1;
    }

    // Receive the server's greeting
    bzero(buffer, MAX_LENGTH);
    if (recv(client_socket, buffer, MAX_LENGTH, 0) < 0) {
        perror("Could not receive greeting");
        return 1;
    }
    printf("%s\n", buffer);

    // Send the HELO message
    sprintf(message, "HELO %s\r\n", "localhost");
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Could not send HELO message");
        return 1;
    }

    // Receive the server's response
    bzero(buffer, MAX_LENGTH);
    if (recv(client_socket, buffer, MAX_LENGTH, 0) < 0) {
        perror("Could not receive response");
        return 1;
    }
    printf("%s\n", buffer);

    // Send the MAIL FROM message
    sprintf(message, "MAIL FROM:<%s>\r\n", "sender@gmail.com");
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Could not send MAIL FROM message");
        return 1;
    }

    // Receive the server's response
    bzero(buffer, MAX_LENGTH);
    if (recv(client_socket, buffer, MAX_LENGTH, 0) < 0) {
        perror("Could not receive response");
        return 1;
    }
    printf("%s\n", buffer);

    // Send the RCPT TO message
    sprintf(message, "RCPT TO:<%s>\r\n", "receiver@gmail.com");
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Could not send RCPT TO message");
        return 1;
    }

    // Receive the server's response
    bzero(buffer, MAX_LENGTH);
    if (recv(client_socket, buffer, MAX_LENGTH, 0) < 0) {
        perror("Could not receive response");
        return 1;
    }
    printf("%s\n", buffer);

    // Send the DATA message
    sprintf(message, "DATA\r\n");
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Could not send DATA message");
        return 1;
    }

    // Receive the server's response
    bzero(buffer, MAX_LENGTH);
    if (recv(client_socket, buffer, MAX_LENGTH, 0) < 0) {
        perror("Could not receive response");
        return 1;
    }
    printf("%s\n", buffer);

    // Send the message body
    sprintf(message, "From: %s\r\nTo: %s\r\nSubject: SMTP Test\r\n\r\nThis is a test message.\r\n.\r\n", "sender@gmail.com", "receiver@gmail.com");
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Could not send message body");
        return 1;
    }

    // Receive the server's response
    bzero(buffer, MAX_LENGTH);
    if (recv(client_socket, buffer, MAX_LENGTH, 0) < 0) {
        perror("Could not receive response");
        return 1;
    }
    printf("%s\n", buffer);

    // Send the QUIT message
    sprintf(message, "QUIT\r\n");
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Could not send QUIT message");
        return 1;
    }

    // Receive the server's response
    bzero(buffer, MAX_LENGTH);
    if (recv(client_socket, buffer, MAX_LENGTH, 0) < 0) {
        perror("Could not receive response");
        return 1;
    }
    printf("%s\n", buffer);

    // Close the connection
    close(client_socket);

    return 0;
}