//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25 // SMTP port number

int main(int argc, char *argv[]) {

    // Check command-line arguments
    if(argc != 3) {
        printf("Usage: %s <from_email> <to_email>\n", argv[0]);
        exit(1);
    }

    // Get hostname and IP address of server
    struct hostent *server = gethostbyname("smtp.gmail.com");
    char *host = inet_ntoa(*((struct in_addr *)server->h_addr_list[0]));
    printf("Connecting to server %s...\n", host);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error creating socket!\n");
        exit(1);        
    }

    // Set up socket address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server!\n");
        exit(1);        
    } else {
        printf("Connected to server %s:%d\n", host, PORT);
    }

    // Receive greeting message from server
    char buffer[100];
    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error receiving greeting message from server!\n");
        exit(1);        
    } else {
        printf("Received greeting message: %s\n", buffer);
    }

    // Send HELO message
    char *helo_msg = "HELO localhost\r\n";
    if(send(sockfd, helo_msg, strlen(helo_msg), 0) < 0) {
        printf("Error sending HELO message to server!\n");
        exit(1);        
    } else {
        printf("Sent HELO message: %s\n", helo_msg);
    }

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error receiving response from server!\n");
        exit(1);        
    } else {
        printf("Received response from server: %s\n", buffer);
    }

    // Send MAIL FROM message
    char *mail_from = argv[1];
    char mail_from_msg[100];
    sprintf(mail_from_msg, "MAIL FROM:<%s>\r\n", mail_from);
    if(send(sockfd, mail_from_msg, strlen(mail_from_msg), 0) < 0) {
        printf("Error sending MAIL FROM message to server!\n");
        exit(1);        
    } else {
        printf("Sent MAIL FROM message: %s\n", mail_from_msg);
    }

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error receiving response from server!\n");
        exit(1);        
    } else {
        printf("Received response from server: %s\n", buffer);
    }

    // Send RCPT TO message
    char *rcpt_to = argv[2];
    char rcpt_to_msg[100];
    sprintf(rcpt_to_msg, "RCPT TO:<%s>\r\n", rcpt_to);
    if(send(sockfd, rcpt_to_msg, strlen(rcpt_to_msg), 0) < 0) {
        printf("Error sending RCPT TO message to server!\n");
        exit(1);
    } else {
        printf("Sent RCPT TO message: %s\n", rcpt_to_msg);
    }

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error receiving response from server!\n");
        exit(1);        
    } else {
        printf("Received response from server: %s\n", buffer);
    }

    // Send DATA message
    char *data_msg = "DATA\r\n";
    if(send(sockfd, data_msg, strlen(data_msg), 0) < 0) {
        printf("Error sending DATA message to server!\n");
        exit(1);
    } else {
        printf("Sent DATA message: %s\n", data_msg);
    }

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error receiving response from server!\n");
        exit(1);        
    } else {
        printf("Received response from server: %s\n", buffer);
    }

    // Send message body
    char *msg_body = "Subject: SMTP Client Example\r\nHello World!\r\n.\r\n";
    if(send(sockfd, msg_body, strlen(msg_body), 0) < 0) {
        printf("Error sending message body to server!\n");
        exit(1);
    } else {
        printf("Sent message body: %s\n", msg_body);
    }

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error receiving response from server!\n");
        exit(1);        
    } else {
        printf("Received response from server: %s\n", buffer);
    }

    // Send QUIT message
    char *quit_msg = "QUIT\r\n";
    if(send(sockfd, quit_msg, strlen(quit_msg), 0) < 0) {
        printf("Error sending QUIT message to server!\n");
        exit(1);
    } else {
        printf("Sent QUIT message: %s\n", quit_msg);
    }

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("Error receiving response from server!\n");
        exit(1);        
    } else {
        printf("Received response from server: %s\n", buffer);
    }

    // Close socket
    close(sockfd);

    printf("Email sent successfully!\n");
    
    return 0;
}