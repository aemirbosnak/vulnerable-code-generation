//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {

    int sockfd;
    struct sockaddr_in servaddr;
    
    char buf[BUF_SIZE];
    char from[128];
    char to[128];
    char subject[128];
    char message[BUF_SIZE];
    
    printf("Enter your email address: ");
    scanf("%s", from);
    printf("Enter the recipient email address: ");
    scanf("%s", to);
    printf("Enter the subject line: ");
    scanf("%s", subject);
    
    printf("Enter your message:\n");
    fgets(message, BUF_SIZE, stdin);
    
    // Create a socket for the SMTP client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }
    
    // Setup the server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);
    servaddr.sin_addr.s_addr = inet_addr("192.168.1.1"); // Set the actual IP address of the SMTP server here
    
    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        return 1;
    }
    
    // Read the server response
    read(sockfd, buf, BUF_SIZE);
    printf("%s", buf);
    
    // Send the HELO message
    snprintf(buf, BUF_SIZE, "HELO client\n");
    write(sockfd, buf, strlen(buf));
    
    // Read the server response
    read(sockfd, buf, BUF_SIZE);
    printf("%s", buf);
    
    // Send the MAIL FROM message
    snprintf(buf, BUF_SIZE, "MAIL FROM:<%s>\n", from);
    write(sockfd, buf, strlen(buf));
    
    // Read the server response
    read(sockfd, buf, BUF_SIZE);
    printf("%s", buf);
    
    // Send the RCPT TO message
    snprintf(buf, BUF_SIZE, "RCPT TO:<%s>\n", to);
    write(sockfd, buf, strlen(buf));
    
    // Read the server response
    read(sockfd, buf, BUF_SIZE);
    printf("%s", buf);
    
    // Send the DATA message
    snprintf(buf, BUF_SIZE, "DATA\n");
    write(sockfd, buf, strlen(buf));
    
    // Read the server response
    read(sockfd, buf, BUF_SIZE);
    printf("%s", buf);
    
    // Send the message headers and body
    snprintf(buf, BUF_SIZE, "From: %s\nTo: %s\nSubject: %s\n\n%s\n.\n", from, to, subject, message);
    write(sockfd, buf, strlen(buf));
    
    // Read the server response
    read(sockfd, buf, BUF_SIZE);
    printf("%s", buf);
    
    // Send the QUIT message
    snprintf(buf, BUF_SIZE, "QUIT\n");
    write(sockfd, buf, strlen(buf));
    
    // Read the server response
    read(sockfd, buf, BUF_SIZE);
    printf("%s", buf);
    
    // Close the socket
    close(sockfd);
    
    return 0;
}