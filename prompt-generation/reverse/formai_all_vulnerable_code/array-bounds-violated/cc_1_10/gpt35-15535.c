//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 993    // IMAP port number
#define MAXSIZE 1024

struct sockaddr_in server_address;  // Server address structure
int sockfd; // Socket file descriptor

void connect_to_server(char server_ip[]);
void send_recv(char send_buffer[], char recv_buffer[]);

int main()
{
    char server_ip[20]; // IP address of server
    char send_buffer[MAXSIZE], recv_buffer[MAXSIZE];

    // Get server IP address from user
    printf("Enter server IP address: ");
    fgets(server_ip, 20, stdin);
    server_ip[strlen(server_ip)-1] = '\0'; // Remove newline character

    // Connect to server
    connect_to_server(server_ip);

    // Send and receive messages in multiplayer style
    while (1)
    {
        // Player 1 sends a message
        printf("Player 1: ");
        fgets(send_buffer, MAXSIZE, stdin);
        send_recv(send_buffer, recv_buffer);

        // Player 2 receives the message
        printf("Player 2: %s", recv_buffer);
        memset(recv_buffer, 0, MAXSIZE);

        // Player 2 sends a message
        printf("Player 2: ");
        fgets(send_buffer, MAXSIZE, stdin);
        send_recv(send_buffer, recv_buffer);

        // Player 1 receives the message
        printf("Player 1: %s", recv_buffer);
        memset(recv_buffer, 0, MAXSIZE);
    }

    return 0;
}

void connect_to_server(char server_ip[])
{
    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        exit(1);
    }

    // Initialize server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0)
    {
        perror("Invalid server IP address");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Connection failed");
        exit(1);
    }

    // Receive welcome message from server
    char recv_buffer[MAXSIZE];
    recv(sockfd, recv_buffer, MAXSIZE, 0);
    printf("%s\n", recv_buffer);
}

void send_recv(char send_buffer[], char recv_buffer[])
{
    // Send message to server
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    // Receive message from server
    recv(sockfd, recv_buffer, MAXSIZE, 0);
}