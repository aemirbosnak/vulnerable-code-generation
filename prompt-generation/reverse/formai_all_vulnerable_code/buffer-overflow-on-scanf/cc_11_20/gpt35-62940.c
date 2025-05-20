//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s hostname portnumber email\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    const char *portnumber = argv[2];
    const char *email = argv[3];

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Get the IP address of the host
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error getting IP address of the host: %s\n", strerror(errno));
        return 1;
    }

    // Construct server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(portnumber));
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    // Receive welcome message from server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error receiving message from server: %s\n", strerror(errno));
        return 1;
    }
    printf("Server message: %s", buffer);
    
    // Send username to server
    char username[BUFFER_SIZE];
    printf("Enter username: ");
    scanf("%s", username);
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "USER %s\r\n", username);
    if (send(sockfd, command, strlen(command), 0) < 0) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return 1;
    }
    
    // Receive confirmation from server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error receiving message from server: %s\n", strerror(errno));
        return 1;
    }
    printf("Server message: %s", buffer);
    
    // Send password to server
    char password[BUFFER_SIZE];
    printf("Enter password: ");
    scanf("%s", password);
    memset(command, 0, BUFFER_SIZE);
    snprintf(command, BUFFER_SIZE, "PASS %s\r\n", password);
    if (send(sockfd, command, strlen(command), 0) < 0) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return 1;
    }
    
    // Receive confirmation from server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error receiving message from server: %s\n", strerror(errno));
        return 1;
    }
    printf("Server message: %s", buffer);
    
    // Send command to retrieve number of emails in mailbox
    memset(command, 0, BUFFER_SIZE);
    snprintf(command, BUFFER_SIZE, "STAT\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return 1;
    }
    
    // Receive number of emails from server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error receiving message from server: %s\n", strerror(errno));
        return 1;
    }
    int num_emails;
    sscanf(buffer, "+OK %d", &num_emails);
    printf("Number of emails in mailbox: %d\n", num_emails);
    
    // Send command to retrieve header of first email
    memset(command, 0, BUFFER_SIZE);
    snprintf(command, BUFFER_SIZE, "TOP 1 0\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return 1;
    }
    
    // Receive header of first email from server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error receiving message from server: %s\n", strerror(errno));
        return 1;
    }
    printf("Header of first email:\n%s\n", buffer);
    
    // Send command to retrieve body of first email
    memset(command, 0, BUFFER_SIZE);
    snprintf(command, BUFFER_SIZE, "RETR 1\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return 1;
    }
    
    // Receive body of first email from server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error receiving message from server: %s\n", strerror(errno));
        return 1;
    }
    printf("Body of first email:\n%s\n", buffer);

    // Send quit command to server
    memset(command, 0, BUFFER_SIZE);
    snprintf(command, BUFFER_SIZE, "QUIT\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return 1;
    }
    
    // Receive goodbye message from server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error receiving message from server: %s\n", strerror(errno));
        return 1;
    }
    printf("Server message: %s", buffer);

    close(sockfd);
    
    return 0;
}