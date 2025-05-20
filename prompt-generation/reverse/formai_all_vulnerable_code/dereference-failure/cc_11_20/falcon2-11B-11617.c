//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Store the server name
    server = gethostbyname("ftp.example.com");

    // Set up the address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(21);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Send a username
    char username[100];
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);

    // Send a password
    char password[100];
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    // Send a FTP command to login
    n = write(sockfd, username, strlen(username));
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }
    n = write(sockfd, "\r\n", 2);
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }
    n = write(sockfd, password, strlen(password));
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }
    n = write(sockfd, "\r\n", 2);
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    // Send a FTP command to list files
    n = write(sockfd, "LIST\r\n", 6);
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    // Read and display the list of files
    char buffer[1024];
    while (1) {
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }
        if (n == 0) {
            break;
        }
        printf("%s", buffer);
    }

    // Close the socket
    close(sockfd);

    return 0;
}