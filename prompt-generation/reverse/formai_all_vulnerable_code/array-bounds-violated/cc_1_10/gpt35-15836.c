//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define SERVER_PORT 25     // SMTP server port number
#define MAX_COMMAND_LEN 1024   // Maximum command length

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    char command[MAX_COMMAND_LEN];  // buffer for user commands
    char response[MAX_COMMAND_LEN]; // buffer for server responses
    int response_size;  // actual size of server response

    if (argc != 2) { // Check for correct usage
        printf("Usage: %s <server name>\n", argv[0]);
        exit(0);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get server IP address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: no such host %s\n", argv[1]);
        exit(1);
    }

    // Set up server address
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Get initial greeting from server
    response_size = recv(sockfd, response, MAX_COMMAND_LEN-1, 0);
    response[response_size] = '\0';
    printf("%s", response);

    // Send initial command to server
    printf("Enter command: ");
    fgets(command, MAX_COMMAND_LEN-1, stdin);
    send(sockfd, command, strlen(command), 0);

    // Receive response from server
    response_size = recv(sockfd, response, MAX_COMMAND_LEN-1, 0);
    response[response_size] = '\0';
    printf("%s", response);

    // Close the socket
    close(sockfd);
    return 0;
}