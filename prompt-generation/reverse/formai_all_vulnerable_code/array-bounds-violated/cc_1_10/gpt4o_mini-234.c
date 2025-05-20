//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 587
#define BUFFER_SIZE 1024

void error(const char *msg) 
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket() 
{
    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) 
    {
        error("Failed to create socket");
    }
    return sock;
}

void connect_to_server(int sock, const char *hostname) 
{
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, hostname, &server_address.sin_addr) <= 0) 
    {
        error("Invalid address / Address not supported");
    }
    
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    {
        error("Connection to the server failed");
    }
}

void send_command(int sock, const char *command) 
{
    send(sock, command, strlen(command), 0);
}

void read_response(int sock) 
{
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received > 0) 
    {
        buffer[bytes_received] = '\0';
        printf("%s\n", buffer);
    }
    else if (bytes_received < 0) 
    {
        error("Error receiving response");
    }
}

void smtp_mail(int sock, const char *from) 
{
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "MAIL FROM:<%s>\r\n", from);
    send_command(sock, command);
    read_response(sock);
}

void smtp_rcpt(int sock, const char *to) 
{
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "RCPT TO:<%s>\r\n", to);
    send_command(sock, command);
    read_response(sock);
}

void smtp_data(int sock, const char *subject, const char *body) 
{
    send_command(sock, "DATA\r\n");
    read_response(sock);

    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sock, command);
    read_response(sock);
}

void smtp_quit(int sock) 
{
    send_command(sock, "QUIT\r\n");
    read_response(sock);
}

int main(int argc, char *argv[]) 
{
    if (argc != 5) 
    {
        fprintf(stderr, "Usage: %s <hostname> <from> <to> <subject> <body>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *from = argv[2];
    const char *to = argv[3];
    const char *subject = argv[4];
    const char *body = argv[5];

    int sock = create_socket();
    connect_to_server(sock, hostname);
    read_response(sock);

    send_command(sock, "EHLO localhost\r\n");
    read_response(sock);
    
    smtp_mail(sock, from);
    smtp_rcpt(sock, to);
    smtp_data(sock, subject, body);
    smtp_quit(sock);

    close(sock);
    return 0;
}