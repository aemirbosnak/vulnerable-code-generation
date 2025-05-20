//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    int socket_fd, port_number, n;
    struct sockaddr_in server_address;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    if (argc < 3) 
    {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    port_number = atoi(argv[2]);
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0) 
    {
        printf("Socket creation failed.\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) 
    {
        printf("No such host found.\n");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port_number);

    if (connect(socket_fd, (const struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    {
        printf("Connection failed.\n");
        exit(1);
    }

    printf("Connection established to %s:%d. Sending email...\n", argv[1], port_number);

    // Sending SMTP commands
    n = recv(socket_fd, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) 
    {
        printf("Error in reading from socket.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("Server response: %s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "HELO client\r\n");
    n = send(socket_fd, buffer, strlen(buffer), 0);
    if (n < 0) 
    {
        printf("Error in writing to socket.\n");
        exit(1);
    }

    n = recv(socket_fd, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) 
    {
        printf("Error in reading from socket.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("Server response: %s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "MAIL FROM:<%s>\r\n", "sender@example.com");
    n = send(socket_fd, buffer, strlen(buffer), 0);
    if (n < 0) 
    {
        printf("Error in writing to socket.\n");
        exit(1);
    }

    n = recv(socket_fd, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) 
    {
        printf("Error in reading from socket.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("Server response: %s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "RCPT TO:<%s>\r\n", "receiver@example.com");
    n = send(socket_fd, buffer, strlen(buffer), 0);
    if (n < 0) 
    {
        printf("Error in writing to socket.\n");
        exit(1);
    }

    n = recv(socket_fd, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) 
    {
        printf("Error in reading from socket.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("Server response: %s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "DATA\r\n");
    n = send(socket_fd, buffer, strlen(buffer), 0);
    if (n < 0) 
    {
        printf("Error in writing to socket.\n");
        exit(1);
    }

    n = recv(socket_fd, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) 
    {
        printf("Error in reading from socket.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("Server response: %s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "Subject: SMTP Client Test\r\nHello there,\n\nThis is a test email from an SMTP client.\n\nRegards,\nSMTP Client\r\n.\r\n");
    n = send(socket_fd, buffer, strlen(buffer), 0);
    if (n < 0) 
    {
        printf("Error in writing to socket.\n");
        exit(1);
    }

    n = recv(socket_fd, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) 
    {
        printf("Error in reading from socket.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("Server response: %s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "QUIT\r\n");
    n = send(socket_fd, buffer, strlen(buffer), 0);
    if (n < 0) 
    {
        printf("Error in writing to socket.\n");
        exit(1);
    }

    n = recv(socket_fd, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) 
    {
        printf("Error in reading from socket.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("Server response: %s", buffer);

    close(socket_fd);
    printf("Email sent successfully!\n");

    return 0;
}