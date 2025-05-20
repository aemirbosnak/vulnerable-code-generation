//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    
    printf("Connected to SMTP server\n");
    printf("------------------------\n");
    
    // Send HELO command to server
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "HELO example.com\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Response: %s\n", buffer);
    
    // Send MAIL FROM command to server
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "MAIL FROM:<sender@example.com>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Response: %s\n", buffer);
    
    // Send RCPT TO command to server
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "RCPT TO:<recipient@example.com>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Response: %s\n", buffer);
    
    // Send DATA command to server
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Response: %s\n", buffer);
    
    // Send message body to server
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "Subject: Test Email\r\n\r\nThis is a test email.\r\n.\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Response: %s\n", buffer);

    // Send QUIT command to server
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Response: %s\n", buffer);
    
    close(sockfd);
    return 0;
}