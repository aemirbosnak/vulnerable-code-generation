//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    
    // What's this? A SMTP client? What a wonderful surprise!
    
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024];
    
    // Wait, I need a host and a port, right?
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }
    
    // Creating the socket, so I can talk to the server.
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }
    
    // Setting up the server address.
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(1);
    }
    
    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connection failed");
        exit(1);
    }
    
    // Let's say hello to the server.
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(1);
    }
    
    // Receiving the server's response.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv failed");
        exit(1);
    }
    
    // What's this? The server's greeting!
    printf("%s", buffer);
    
    // Sending the MAIL FROM command.
    sprintf(buffer, "MAIL FROM: <%s>\r\n", "sender@example.com");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(1);
    }
    
    // Receiving the server's response.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv failed");
        exit(1);
    }
    
    // What's this? The server is asking for the recipient.
    printf("%s", buffer);
    
    // Sending the RCPT TO command.
    sprintf(buffer, "RCPT TO: <%s>\r\n", "receiver@example.com");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(1);
    }
    
    // Receiving the server's response.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv failed");
        exit(1);
    }
    
    // What's this? The server is ready for the data.
    printf("%s", buffer);
    
    // Sending the DATA command.
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(1);
    }
    
    // Receiving the server's response.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv failed");
        exit(1);
    }
    
    // What's this? The server is ready for the email body.
    printf("%s", buffer);
    
    // Sending the email body.
    sprintf(buffer, "Subject: Hello World!\r\n\r\nThis is a test email.\r\n.\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(1);
    }
    
    // Receiving the server's response.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv failed");
        exit(1);
    }
    
    // What's this? The server is saying goodbye!
    printf("%s", buffer);
    
    // Closing the socket.
    close(sockfd);
    
    // Yahoo! We sent an email!
    return 0;
}