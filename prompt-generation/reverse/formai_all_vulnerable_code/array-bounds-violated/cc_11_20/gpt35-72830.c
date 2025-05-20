//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MESSAGE_LENGTH 1024
#define SERVER_IP_ADDRESS "127.0.0.1"
#define SERVER_PORT 25

int main()
{
    // Variable declarations...
    int client_socket, message_length, bytes_sent, bytes_received;
    char message[MAX_MESSAGE_LENGTH], server_response[MAX_MESSAGE_LENGTH];
    struct sockaddr_in server_address;

    // Create a socket...
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize the server address structure...
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS);
    server_address.sin_port = htons(SERVER_PORT);

    // Connect to the server...
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    // Receive the server's greeting...
    bytes_received = recv(client_socket, server_response, MAX_MESSAGE_LENGTH, 0);
    if (bytes_received == -1)
    {
        perror("Receiving server greeting failed");
        exit(EXIT_FAILURE);
    }
    server_response[bytes_received] = '\0';
    printf("%s", server_response);

    // Send HELO message to the server...
    memset(message, 0, MAX_MESSAGE_LENGTH);
    message_length = sprintf(message, "HELO %s\r\n", SERVER_IP_ADDRESS);
    bytes_sent = send(client_socket, message, message_length, 0);
    if (bytes_sent == -1)
    {
        perror("Sending HELO message failed");
        exit(EXIT_FAILURE);
    }

    // Receive the server's response to the HELO message...
    bytes_received = recv(client_socket, server_response, MAX_MESSAGE_LENGTH, 0);
    if (bytes_received == -1)
    {
        perror("Receiving server response to HELO message failed");
        exit(EXIT_FAILURE);
    }
    server_response[bytes_received] = '\0';
    printf("%s", server_response);

    // Send MAIL FROM message to the server...
    memset(message, 0, MAX_MESSAGE_LENGTH);
    message_length = sprintf(message, "MAIL FROM: <sender@example.com>\r\n");
    bytes_sent = send(client_socket, message, message_length, 0);
    if (bytes_sent == -1)
    {
        perror("Sending MAIL FROM message failed");
        exit(EXIT_FAILURE);
    }

    // Receive the server's response to the MAIL FROM message...
    bytes_received = recv(client_socket, server_response, MAX_MESSAGE_LENGTH, 0);
    if (bytes_received == -1)
    {
        perror("Receiving server response to MAIL FROM message failed");
        exit(EXIT_FAILURE);
    }
    server_response[bytes_received] = '\0';
    printf("%s", server_response);

    // Send RCPT TO message to the server...
    memset(message, 0, MAX_MESSAGE_LENGTH);
    message_length = sprintf(message, "RCPT TO: <receiver@example.com>\r\n");
    bytes_sent = send(client_socket, message, message_length, 0);
    if (bytes_sent == -1)
    {
        perror("Sending RCPT TO message failed");
        exit(EXIT_FAILURE);
    }

    // Receive the server's response to the RCPT TO message...
    bytes_received = recv(client_socket, server_response, MAX_MESSAGE_LENGTH, 0);
    if (bytes_received == -1)
    {
        perror("Receiving server response to RCPT TO message failed");
        exit(EXIT_FAILURE);
    }
    server_response[bytes_received] = '\0';
    printf("%s", server_response);

    // Send DATA message to the server...
    memset(message, 0, MAX_MESSAGE_LENGTH);
    message_length = sprintf(message, "DATA\r\n");
    bytes_sent = send(client_socket, message, message_length, 0);
    if (bytes_sent == -1)
    {
        perror("Sending DATA message failed");
        exit(EXIT_FAILURE);
    }

    // Receive the server's response to the DATA message...
    bytes_received = recv(client_socket, server_response, MAX_MESSAGE_LENGTH, 0);
    if (bytes_received == -1)
    {
        perror("Receiving server response to DATA message failed");
        exit(EXIT_FAILURE);
    }
    server_response[bytes_received] = '\0';
    printf("%s", server_response);

    // Send message body to the server...
    memset(message, 0, MAX_MESSAGE_LENGTH);
    message_length = sprintf(message, "Subject: Example subject\r\nFrom: sender@example.com\r\nTo: receiver@example.com\r\n\r\nThis is an example message.\r\n.\r\n");
    bytes_sent = send(client_socket, message, message_length, 0);
    if (bytes_sent == -1)
    {
        perror("Sending message body failed");
        exit(EXIT_FAILURE);
    }

    // Receive the server's response to the message...
    bytes_received = recv(client_socket, server_response, MAX_MESSAGE_LENGTH, 0);
    if (bytes_received == -1)
    {
        perror("Receiving server response to message failed");
        exit(EXIT_FAILURE);
    }
    server_response[bytes_received] = '\0';
    printf("%s", server_response);

    // Send QUIT message to the server...
    memset(message, 0, MAX_MESSAGE_LENGTH);
    message_length = sprintf(message, "QUIT\r\n");
    bytes_sent = send(client_socket, message, message_length, 0);
    if (bytes_sent == -1)
    {
        perror("Sending QUIT message failed");
        exit(EXIT_FAILURE);
    }

    // Receive the server's farewell...
    bytes_received = recv(client_socket, server_response, MAX_MESSAGE_LENGTH, 0);
    if (bytes_received == -1)
    {
        perror("Receiving server farewell failed");
        exit(EXIT_FAILURE);
    }
    server_response[bytes_received] = '\0';
    printf("%s", server_response);

    // Close the socket...
    close(client_socket);

    return EXIT_SUCCESS;
}