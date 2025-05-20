//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int client_socket, bytes_sent;
    struct sockaddr_in server_address;
    struct hostent *server;

    // Check for correct number of arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Get server information
    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "Error: no such host '%s'\n", argv[1]);
        exit(1);
    }

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0)
    {
        perror("Error: could not create socket");
        exit(1);
    }

    // Zero out server_address struct and set values
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error: could not connect to server");
        exit(1);
    }

    // Read greeting from server
    char buffer[1024];
    bzero(buffer, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error: could not receive greeting from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send HELO command to server
    char helo_command[128];
    sprintf(helo_command, "HELO %s\r\n", argv[1]);
    bytes_sent = send(client_socket, helo_command, strlen(helo_command), 0);
    if (bytes_sent < 0)
    {
        perror("Error: could not send HELO command to server");
        exit(1);
    }

    // Read response from server
    bzero(buffer, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error: could not receive response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send MAIL command to server
    char mail_command[128];
    sprintf(mail_command, "MAIL FROM:<%s>\r\n", "sender@example.com");
    bytes_sent = send(client_socket, mail_command, strlen(mail_command), 0);
    if (bytes_sent < 0)
    {
        perror("Error: could not send MAIL command to server");
        exit(1);
    }

    // Read response from server
    bzero(buffer, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error: could not receive response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send RCPT command to server
    char rcpt_command[128];
    sprintf(rcpt_command, "RCPT TO:<%s>\r\n", "recipient@example.com");
    bytes_sent = send(client_socket, rcpt_command, strlen(rcpt_command), 0);
    if (bytes_sent < 0)
    {
        perror("Error: could not send RCPT command to server");
        exit(1);
    }

    // Read response from server
    bzero(buffer, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error: could not receive response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send DATA command to server
    char data_command[128];
    sprintf(data_command, "DATA\r\n");
    bytes_sent = send(client_socket, data_command, strlen(data_command), 0);
    if (bytes_sent < 0)
    {
        perror("Error: could not send DATA command to server");
        exit(1);
    }

    // Read response from server
    bzero(buffer, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error: could not receive response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send message to server
    char message[1024];
    sprintf(message, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test message\r\n\r\nHello, this is a test message.\r\n.\r\n");
    bytes_sent = send(client_socket, message, strlen(message), 0);
    if (bytes_sent < 0)
    {
        perror("Error: could not send message to server");
        exit(1);
    }

    // Read response from server
    bzero(buffer, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error: could not receive response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send QUIT command to server
    char quit_command[128];
    sprintf(quit_command, "QUIT\r\n");
    bytes_sent = send(client_socket, quit_command, strlen(quit_command), 0);
    if (bytes_sent < 0)
    {
        perror("Error: could not send QUIT command to server");
        exit(1);
    }

    // Read response from server
    bzero(buffer, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error: could not receive response from server");
        exit(1);
    }
    printf("%s", buffer);

    // Close socket
    close(client_socket);

    return 0;
}