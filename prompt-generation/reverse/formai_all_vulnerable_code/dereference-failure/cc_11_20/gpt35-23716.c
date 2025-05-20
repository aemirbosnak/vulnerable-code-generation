//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char* argv[])
{
    if(argc != 4) {
        printf("Usage: ./pop3client hostname port username\n");
        exit(1);
    }

    char* hostname = argv[1];
    int port = atoi(argv[2]);
    char* username = argv[3];

    // Create a socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0) {
        perror("Error creating socket\n");
        exit(1);
    }

    // Get the IP address of the server
    struct hostent* host = gethostbyname(hostname);
    if(!host) {
        perror("Error getting IP address\n");
        exit(1);
    }

    // Fill in the server's address information
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr = *((struct in_addr*)host->h_addr);

    // Connect to the server
    if(connect(sock_fd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error connecting to server\n");
        exit(1);
    }

    // Read the welcome message from the server
    char buffer[BUFSIZE];
    if(read(sock_fd, buffer, BUFSIZE) < 0) {
        perror("Error reading from server\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the username to the server
    char username_msg[BUFSIZE];
    sprintf(username_msg, "USER %s\r\n", username);
    if(write(sock_fd, username_msg, strlen(username_msg)) < 0) {
        perror("Error sending username\n");
        exit(1);
    }

    // Read the response from the server
    if(read(sock_fd, buffer, BUFSIZE) < 0) {
        perror("Error reading from server\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Prompt for the password and send it to the server
    char password[BUFSIZE];
    printf("Password: ");
    fgets(password, BUFSIZE, stdin);
    password[strlen(password) - 1] = '\0';
    char password_msg[BUFSIZE];
    sprintf(password_msg, "PASS %s\r\n", password);
    if(write(sock_fd, password_msg, strlen(password_msg)) < 0) {
        perror("Error sending password\n");
        exit(1);
    }

    // Read the response from the server
    if(read(sock_fd, buffer, BUFSIZE) < 0) {
        perror("Error reading from server\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the quit message to the server
    char quit_msg[BUFSIZE];
    sprintf(quit_msg, "QUIT\r\n");
    if(write(sock_fd, quit_msg, strlen(quit_msg)) < 0) {
        perror("Error sending quit message\n");
        exit(1);
    }

    // Read the response from the server
    if(read(sock_fd, buffer, BUFSIZE) < 0) {
        perror("Error reading from server\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Close the socket
    close(sock_fd);

    return 0;
}