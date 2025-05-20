//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

// Function to get the socket connection
int get_socket_connection(char *server_address, int server_port)
{
    int sock;
    struct sockaddr_in server_address_struct;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_address_struct, 0, sizeof(server_address_struct));
    server_address_struct.sin_family = AF_INET;
    server_address_struct.sin_port = htons(server_port);

    if (inet_pton(AF_INET, server_address, &server_address_struct.sin_addr) <= 0)
    {
        printf("Invalid address/ Address not supported\n");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&server_address_struct, sizeof(server_address_struct)) < 0)
    {
        printf("Connection Failed\n");
        exit(1);
    }

    return sock;
}

// Function to send and receive data to/from the server
void send_receive_data(int sock, char *send_message, char *receive_buffer)
{
    if (send(sock, send_message, strlen(send_message), 0) < 0)
    {
        printf("Error sending message to server\n");
        exit(1);
    }

    if (recv(sock, receive_buffer, BUFFER_SIZE, 0) < 0)
    {
        printf("Error receiving message from server\n");
        exit(1);
    }
}

// Main function
int main()
{
    int sock;
    char server_address[BUFFER_SIZE], username[BUFFER_SIZE], password[BUFFER_SIZE], receive_buffer[BUFFER_SIZE], send_message[BUFFER_SIZE];

    // Get the server address and port from user
    printf("Enter the mail server address: ");
    fgets(server_address, BUFFER_SIZE, stdin);
    server_address[strcspn(server_address, "\n")] = 0;

    int server_port;
    printf("Enter the server port number: ");
    scanf("%d", &server_port);

    // Get the username and password from user
    printf("Enter your email address: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Get the socket connection and send the IMAP commands
    sock = get_socket_connection(server_address, server_port);

    // Send the login command
    sprintf(send_message, "1 LOGIN %s %s\r\n", username, password);
    send_receive_data(sock, send_message, receive_buffer);
    printf("%s\n", receive_buffer);

    // Send the select command
    sprintf(send_message, "2 SELECT INBOX\r\n");
    send_receive_data(sock, send_message, receive_buffer);
    printf("%s\n", receive_buffer);

    // Send the fetch command to read the first email
    sprintf(send_message, "3 FETCH 1 BODY[TEXT]\r\n");
    send_receive_data(sock, send_message, receive_buffer);
    printf("%s\n", receive_buffer);

    // Send the logout command
    sprintf(send_message, "4 LOGOUT\r\n");
    send_receive_data(sock, send_message, receive_buffer);
    printf("%s\n", receive_buffer);

    // Close the socket connection
    close(sock);

    return 0;
}