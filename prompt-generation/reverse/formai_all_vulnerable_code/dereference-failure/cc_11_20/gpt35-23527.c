//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 110 // POP3 Port

int main(int argc, char *argv[]) {

    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[2048];

    // Check for command line argument
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname username\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Get host by name
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    // Set server address
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Read initial server response
    memset(buffer, 0, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        perror("Error reading from server");
        exit(1);
    }

    // Check if the server is ready
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Server is not ready\n");
        exit(1);
    }

    // Send username
    sprintf(buffer, "USER %s\r\n", argv[2]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending username");
        exit(1);
    }

    // Read server response
    memset(buffer, 0, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        perror("Error reading from server");
        exit(1);
    }

    // Check if the username is accepted
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Username not accepted\n");
        exit(1);
    }

    // Get password
    char *password = getpass("Password: ");

    // Send password
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending password");
        exit(1);
    }

    // Read server response
    memset(buffer, 0, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        perror("Error reading from server");
        exit(1);
    }

    // Check if the password is accepted
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Password not accepted\n");
        exit(1);
    }

    // Send command to list emails
    sprintf(buffer, "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending command");
        exit(1);
    }

    // Read server response
    memset(buffer, 0, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        perror("Error reading from server");
        exit(1);
    }

    // Print email list
    printf("Email List:\n%s\n", buffer);

    // Send command to quit
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending command");
        exit(1);
    }

    // Read server response
    memset(buffer, 0, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        perror("Error reading from server");
        exit(1);
    }

    // Close socket
    close(sockfd);

    // End program
    return 0;
}