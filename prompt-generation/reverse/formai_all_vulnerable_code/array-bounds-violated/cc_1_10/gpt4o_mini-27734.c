//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define SERVER "imap.example.com"  // Replace with your IMAP server
#define PORT 993  // IMAP over SSL port
#define BUFFER_SIZE 2048

void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Function to establish a connection to the server
int connect_to_server(const char *server, int port) {
    struct sockaddr_in server_addr;
    int sock;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        error("Invalid address/Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to the server failed");
    }

    return sock;
}

// Function to send data to the server and receive a response
void send_receive(int sock, const char *send_msg) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    // Send the command to the server
    if (send(sock, send_msg, strlen(send_msg), 0) < 0) {
        error("Failed to send message");
    }

    // Receive a response from the server
    int valread = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (valread < 0) {
        error("Failed to receive response");
    }

    buffer[valread] = '\0';  // Null terminate the received data
    printf("Response: %s\n", buffer);
}

// Main function to interact with the IMAP server
int main() {
    int sock;
    char input[BUFFER_SIZE];

    // Establish connection to the IMAP server
    sock = connect_to_server(SERVER, PORT);

    // Send the login command
    sprintf(input, "A001 LOGIN your_username your_password\r\n");  // Replace with your credentials
    send_receive(sock, input);

    // Send the select command to choose mailbox
    sprintf(input, "A002 SELECT INBOX\r\n");
    send_receive(sock, input);

    // Send the fetch command to get the list of emails
    sprintf(input, "A003 FETCH 1:* BODY[HEADER]\r\n");
    send_receive(sock, input);

    // Send the logout command to disconnect
    sprintf(input, "A004 LOGOUT\r\n");
    send_receive(sock, input);

    // Close the socket
    close(sock);
    return 0;
}