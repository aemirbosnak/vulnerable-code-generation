//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define POP3_PORT 110

int main(int argc, char **argv) {
    char *server_address = "pop.example.com";
    char *username = "your_username";
    char *password = "your_password";
    
    struct hostent *server = gethostbyname(server_address);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve host address\n");
        return EXIT_FAILURE;
    }
    
    struct sockaddr_in server_address_struct;
    bzero((char *) &server_address_struct, sizeof(server_address_struct));
    server_address_struct.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address_struct.sin_addr.s_addr, server->h_length);
    server_address_struct.sin_port = htons(POP3_PORT);
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        return EXIT_FAILURE;
    }
    
    if (connect(sockfd,(struct sockaddr *)&server_address_struct,sizeof(server_address_struct)) < 0) {
        fprintf(stderr, "Error: could not connect to server\n");
        return EXIT_FAILURE;
    }
    
    char buffer[256];
    bzero(buffer, 256);
    int n = read(sockfd, buffer, 255);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);
    
    sprintf(buffer, "USER %s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        return EXIT_FAILURE;
    }
    
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);
    
    sprintf(buffer, "PASS %s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        return EXIT_FAILURE;
    }
    
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);
    
    // Retrieve the number of emails in the mailbox
    sprintf(buffer, "STAT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        return EXIT_FAILURE;
    }
    
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);
    
    // Retrieve the first email in the mailbox
    sprintf(buffer, "RETR 1\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        return EXIT_FAILURE;
    }
    
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);
    
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        return EXIT_FAILURE;
    }
    
    close(sockfd);
    
    return EXIT_SUCCESS;
}