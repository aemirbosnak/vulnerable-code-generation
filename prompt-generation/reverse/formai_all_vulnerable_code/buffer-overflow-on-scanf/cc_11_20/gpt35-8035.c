//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
/* FTP Client Example program in C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    // Check if command line arguments are correct
    if (argc < 3) {
       fprintf(stderr,"Please provide hostname and port.\n");
       exit(1);
    }

    portno = atoi(argv[2]); // Convert portno to integer

    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket.");
        exit(1);
    }

    // Get server details
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host.\n");
        exit(1);
    }

    // Set server details
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting to server.");
        exit(1);
    }

    // Prompt user to enter username and password
    char user[50], pass[50];
    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", pass);

    // Send username to server
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "USER %s\r\n", user);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket.");
        exit(1);
    }

    // Read server response
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading from socket.");
        exit(1);
    }

    // Print server response
    printf("%s", buffer);

    // Send password to server
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "PASS %s\r\n", pass);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket.");
        exit(1);
    }

    // Read server response
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading from socket.");
        exit(1);
    }

    // Print server response
    printf("%s", buffer);

    // Send PASV command to server to get passive mode details
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "PASV\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket.");
        exit(1);
    }

    // Read server response
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading from socket.");
        exit(1);
    }

    // Parse server response to get passive mode details
    int h1, h2, h3, h4, p1, p2;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)",
        &h1, &h2, &h3, &h4, &p1, &p2);
    struct sockaddr_in pasv_addr;
    bzero((char *) &pasv_addr, sizeof(pasv_addr));
    pasv_addr.sin_family = AF_INET;
    pasv_addr.sin_addr.s_addr = htonl((h1 << 24) | (h2 << 16) | (h3 << 8) | h4);
    pasv_addr.sin_port = htons((p1 << 8) | p2);

    // Connect to passive mode address
    int pasv_sockfd;
    pasv_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (pasv_sockfd < 0) {
        perror("Error opening socket.");
        exit(1);
    }
    if (connect(pasv_sockfd,(struct sockaddr *) &pasv_addr,sizeof(pasv_addr)) < 0) {
        perror("Error connecting to server.");
        exit(1);
    }

    // Send LIST command to server to get directory listing
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket.");
        exit(1);
    }

    // Read server response with directory listing
    bzero(buffer, BUFFER_SIZE);
    n = read(pasv_sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading from socket.");
        exit(1);
    }

    // Print directory listing    
    printf("Directory listing:\n%s", buffer);

    // Close passive mode socket and FTP connection
    close(pasv_sockfd);
    close(sockfd);

    return 0;
}