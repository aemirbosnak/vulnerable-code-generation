//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUF_SIZE 1024

int main()
{
    int sock_fd, n;
    char buffer[MAX_BUF_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Prompt user to input server hostname and port number
    char server_hostname[50], port_num[10];
    printf("Enter server hostname: ");
    scanf("%s", server_hostname);
    printf("Enter server port number: ");
    scanf("%s", port_num);
    getchar();  // Consume trailing newline character

    // Get server information
    server = gethostbyname(server_hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: could not retrieve server information.\n");
        exit(1);
    }

    // Create socket file descriptor
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        fprintf(stderr, "Error: could not create socket.\n");
        exit(1);
    }

    // Populate server address struct
    bzero((char*) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(atoi(port_num));

    // Connect to server
    if (connect(sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: could not connect to server.\n");
        exit(1);
    }

    // Read greeting message from server
    bzero(buffer, MAX_BUF_SIZE);
    n = read(sock_fd, buffer, MAX_BUF_SIZE);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket.\n");
        exit(1);
    }
    printf("%s", buffer);  // Display greeting message

    // Send user authentication credentials
    char username[50], password[50];
    printf("Enter username: ");
    fgets(username, 50, stdin);
    printf("Enter password: ");
    fgets(password, 50, stdin);
    sprintf(buffer, "USER %sPASS %s", username, password);
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket.\n");
        exit(1);
    }

    // Wait for response from server
    bzero(buffer, MAX_BUF_SIZE);
    n = read(sock_fd, buffer, MAX_BUF_SIZE);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Send command to retrieve number of messages
    sprintf(buffer, "STAT");
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket.\n");
        exit(1);
    }

    // Wait for response from server
    bzero(buffer, MAX_BUF_SIZE);
    n = read(sock_fd, buffer, MAX_BUF_SIZE);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Send command to retrieve list of messages
    sprintf(buffer, "LIST");
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket.\n");
        exit(1);
    }

    // Wait for response from server
    bzero(buffer, MAX_BUF_SIZE);
    n = read(sock_fd, buffer, MAX_BUF_SIZE);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Close socket
    close(sock_fd);

    return 0;
}