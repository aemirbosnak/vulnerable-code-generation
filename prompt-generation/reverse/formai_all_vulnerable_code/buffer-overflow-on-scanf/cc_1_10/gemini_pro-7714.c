//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error resolving hostname: %s\n", argv[1]);
        return 1;
    }

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Connect to the FTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *(struct in_addr *) host->h_addr;

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send the username and password to the server
    char username[MAX_BUFFER_SIZE];
    printf("Enter username: ");
    scanf("%s", username);
    write(sockfd, username, strlen(username) + 1);

    char password[MAX_BUFFER_SIZE];
    printf("Enter password: ");
    scanf("%s", password);
    write(sockfd, password, strlen(password) + 1);

    // Read the welcome message from the server
    char welcome_msg[MAX_BUFFER_SIZE];
    int bytes_received = read(sockfd, welcome_msg, MAX_BUFFER_SIZE);
    if (bytes_received == -1) {
        printf("Error reading welcome message\n");
        return 1;
    }
    printf("%s\n", welcome_msg);

    // Send a command to the server
    char command[MAX_BUFFER_SIZE];
    printf("Enter command: ");
    scanf("%s", command);
    write(sockfd, command, strlen(command) + 1);

    // Read the response from the server
    char response[MAX_BUFFER_SIZE];
    bytes_received = read(sockfd, response, MAX_BUFFER_SIZE);
    if (bytes_received == -1) {
        printf("Error reading response\n");
        return 1;
    }
    printf("%s\n", response);

    // Close the connection
    close(sockfd);

    return 0;
}