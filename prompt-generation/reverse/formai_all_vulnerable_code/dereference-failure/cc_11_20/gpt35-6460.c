//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    char user[50];
    char password[50];

    // Check correct number of arguments
    if (argc != 3) {
        fprintf(stderr,"usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Get server by hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    // Set server address information
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Read initial greeting
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n",buffer);

    // Send user
    printf("Username: ");
    bzero(user,50);
    fgets(user,50,stdin);
    n = write(sockfd,user,strlen(user));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Send password
    printf("Password: ");
    bzero(password,50);
    fgets(password,50,stdin);
    n = write(sockfd,password,strlen(password));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read login confirmation
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n",buffer);

    // Send STAT command
    char *command = "STAT\r\n";
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read response
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}