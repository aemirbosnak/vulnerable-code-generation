//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int port = 25;
    char *server_address = "smtp.example.com";
    char *from_address = "sender@example.com";
    char *to_address = "recipient@example.com";
    char *subject = "Hello from SMTP client";
    char *message = "This is a test message sent from SMTP client";
    
    int sockfd, numbytes;
    struct hostent *he;
    struct sockaddr_in their_addr;
    char buffer[BUFFER_SIZE];
    
    if ((he = gethostbyname(server_address)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(port);
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(their_addr.sin_zero), '\0', 8);
    
    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }
    
    numbytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    
    sprintf(buffer, "HELO myclient.example.com\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from_address);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    
    sprintf(buffer, "RCPT TO:<%s>\r\n", to_address);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    
    sprintf(buffer, "From: <%s>\r\n", from_address);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }
    
    sprintf(buffer, "To: <%s>\r\n", to_address);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }
    
    sprintf(buffer, "Subject: %s\r\n", subject);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }
    
    sprintf(buffer, "\r\n%s\r\n.\r\n", message);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }
    numbytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
    
    close(sockfd);
    
    return 0;
}