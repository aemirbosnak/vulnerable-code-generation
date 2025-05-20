//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define SERVER_PORT 143
// 1. Establish a connection with the IMAP server
// 2. Send login credentials to the server
// 3. Send the SELECT command to the server to select a mailbox
// 4. Send the FETCH command to the server to retrieve emails
// 5. Parse the returned data and display it

int main(int argc, char **argv) {
    int sock_fd = 0, num_rcvd = 0, num_total = 0;
    char buffer[1024];
    struct sockaddr_in server_addr;
    char *server_ip, *user, *pass, *mailbox;
    server_ip = "127.0.0.1";
    user = "user";
    pass = "password";
    mailbox = "INBOX";
    memset(buffer, 0, sizeof(buffer));  // Clear the buffer

    sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP); // Create a new socket
    if (sock_fd == -1) {
        perror("[Error] Unable to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));  // Clear the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // Convert the server IP address from text to binary
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("[Error] Invalid server IP address");
        exit(EXIT_FAILURE);
    }

    // Establish a connection with the IMAP server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("[Error] Unable to connect to server");
        exit(EXIT_FAILURE);
    }

    // Send login credentials to the server
    sprintf(buffer, ". LOGIN %s %s\r\n", user, pass);
    send(sock_fd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));  // Clear the buffer

    // Read the server response to the login command
    num_rcvd = recv(sock_fd, buffer, sizeof(buffer), 0);
    num_total += num_rcvd;
    printf("%s", buffer);
    memset(buffer, 0, sizeof(buffer));  // Clear the buffer

    // Send the SELECT command to the server to select a mailbox
    sprintf(buffer, ". SELECT %s\r\n", mailbox);
    send(sock_fd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));  // Clear the buffer

    // Read the server response to the SELECT command
    num_rcvd = recv(sock_fd, buffer, sizeof(buffer), 0);
    num_total += num_rcvd;
    printf("%s", buffer);
    memset(buffer, 0, sizeof(buffer));  // Clear the buffer

    // Send the FETCH command to the server to retrieve emails
    sprintf(buffer, ". FETCH 1:* FULL\r\n");
    send(sock_fd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));  // Clear the buffer

    // Read the server response to the FETCH command
    num_rcvd = recv(sock_fd, buffer, sizeof(buffer), 0);
    num_total += num_rcvd;
    printf("%s", buffer);
    memset(buffer, 0, sizeof(buffer));  // Clear the buffer

    // Close the connection
    close(sock_fd);

    return 0;
}