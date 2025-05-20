//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_LEN 1024

int main() {
    char hostname[MAX_LEN], mailfrom[MAX_LEN], rcptto[MAX_LEN], subject[MAX_LEN], message[MAX_LEN];
    printf("Enter the SMTP server IP address or hostname: ");
    scanf("%s", hostname);
    
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_LEN];
    portno = 25;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket");
        return 1;
    }
    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error, no such host");
        return 1;
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting");
        return 1;
    }
    read(sockfd, buffer, MAX_LEN);
    printf("%s\n", buffer);
    bzero(buffer, MAX_LEN);
    
    printf("Enter mail from address: ");
    scanf("%s", mailfrom);
    sprintf(buffer, "MAIL FROM:<%s>\r\n", mailfrom);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket");
        return 1;
    }
    bzero(buffer, MAX_LEN);
    read(sockfd, buffer, MAX_LEN);
    printf("%s\n", buffer);
    bzero(buffer, MAX_LEN);
    
    printf("Enter rcpt to address: ");
    scanf("%s", rcptto);
    sprintf(buffer, "RCPT TO:<%s>\r\n", rcptto);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket");
        return 1;
    }
    bzero(buffer, MAX_LEN);
    read(sockfd, buffer, MAX_LEN);
    printf("%s\n", buffer);
    bzero(buffer, MAX_LEN);
    
    printf("Enter mail subject: ");
    scanf("%s", subject);
    printf("Enter mail body message: ");
    scanf("%s", message);
    sprintf(buffer, "DATA\nSubject: %s\n%s\n.\r\n", subject, message);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket");
        return 1;
    }
    bzero(buffer, MAX_LEN);
    read(sockfd, buffer, MAX_LEN);
    printf("%s\n", buffer);
    bzero(buffer, MAX_LEN);
    
    n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    if (n < 0) {
        printf("Error writing to socket");
        return 1;
    }
    read(sockfd, buffer, MAX_LEN);
    printf("%s\n", buffer);
    bzero(buffer, MAX_LEN);
    
    close(sockfd);
    return 0;
}