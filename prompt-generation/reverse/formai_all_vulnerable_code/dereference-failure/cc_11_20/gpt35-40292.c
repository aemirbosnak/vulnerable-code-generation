//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
 
int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    const char *hostname = "mail.example.com"; // specify your SMTP server hostname here
    portno = 25; // port 25 is the default SMTP port
 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }
 
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        return -1;
    }
 
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
 
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return -1;
    }
 
    // send HELO or EHLO command to the server
    snprintf(buffer, sizeof(buffer), "EHLO %s\r\n", hostname);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }
 
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s", buffer);
 
    // send MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<youremail@example.com>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }
 
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s", buffer);
 
    // send RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO:<recipient@example.com>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }
 
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s", buffer);
 
    // send DATA command
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }
 
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s", buffer);
 
    // send message body
    snprintf(buffer, sizeof(buffer), "From: <youremail@example.com>\r\nTo: <recipient@example.com>\r\nSubject: Test Message\r\n\r\nThis is a test email.\r\n.\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }
 
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s", buffer);
 
    // send QUIT command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }
 
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s", buffer);
 
    close(sockfd);
    return 0;
}