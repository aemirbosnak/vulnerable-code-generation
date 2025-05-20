//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_ADDR "smtp.gmail.com"   // SMTP Server DNS or IP Address
#define SERVER_PORT 465                // SMTP Server Port

int main() {

    int sockfd, n;
    char recv_buffer[1024], send_buffer[1024];
    struct sockaddr_in server_address;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Get SMTP server by DNS or IP Address
    server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    // Configure server address struct
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(SERVER_PORT);

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) != 0) {
        perror("ERROR connecting to SMTP server");
        exit(1);
    }

    //Receive Welcome message from SMTP server
    n = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);
    if (n < 0) {
        perror("ERROR receiving message from SMTP server");
        exit(1);
    }
    recv_buffer[n] = '\0';
    printf("%s", recv_buffer);

    // Send EHLO command to SMTP server
    sprintf(send_buffer, "EHLO example.com\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        perror("ERROR sending message to SMTP server");
        exit(1);
    }

    //Receive response for EHLO command from SMTP server
    n = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);
    if (n < 0) {
        perror("ERROR receiving message from SMTP server");
        exit(1);
    }
    recv_buffer[n] = '\0';
    printf("%s", recv_buffer);

    // Send AUTH LOGIN command to SMTP server
    sprintf(send_buffer, "AUTH LOGIN\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        perror("ERROR sending message to SMTP server");
        exit(1);
    }

    //Receive response for AUTH LOGIN command from SMTP server
    n = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);
    if (n < 0) {
        perror("ERROR receiving message from SMTP server");
        exit(1);
    }
    recv_buffer[n] = '\0';
    printf("%s", recv_buffer);

    // Send base64 encoded login credentials to SMTP server
    sprintf(send_buffer, "<base64 encoded username>\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        perror("ERROR sending message to SMTP server");
        exit(1);
    }

    //Receive response for username from SMTP server
    n = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);
    if (n < 0) {
        perror("ERROR receiving message from SMTP server");
        exit(1);
    }
    recv_buffer[n] = '\0';
    printf("%s", recv_buffer);

    // Send base64 encoded password to SMTP server
    sprintf(send_buffer, "<base64 encoded password>\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        perror("ERROR sending message to SMTP server");
        exit(1);
    }

    //Receive response for password from SMTP server
    n = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);
    if (n < 0) {
        perror("ERROR receiving message from SMTP server");
        exit(1);
    }
    recv_buffer[n] = '\0';
    printf("%s", recv_buffer);

    // Send MAIL FROM command to SMTP server
    sprintf(send_buffer, "MAIL FROM:<youremail@example.com>\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        perror("ERROR sending message to SMTP server");
        exit(1);
    }

    //Receive response for MAIL FROM command from SMTP server
    n = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);
    if (n < 0) {
        perror("ERROR receiving message from SMTP server");
        exit(1);
    }
    recv_buffer[n] = '\0';
    printf("%s", recv_buffer);

    // Send RCPT TO command to SMTP server
    sprintf(send_buffer, "RCPT TO:<recipient@example.com>\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        perror("ERROR sending message to SMTP server");
        exit(1);
    }

    //Receive response for RCPT TO command from SMTP server
    n = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);
    if (n < 0) {
        perror("ERROR receiving message from SMTP server");
        exit(1);
    }
    recv_buffer[n] = '\0';
    printf("%s", recv_buffer);

    // Send DATA command to SMTP server
    sprintf(send_buffer, "DATA\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        perror("ERROR sending message to SMTP server");
        exit(1);
    }

    //Receive response for DATA command from SMTP server
    n = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);
    if (n < 0) {
        perror("ERROR receiving message from SMTP server");
        exit(1);
    }
    recv_buffer[n] = '\0';
    printf("%s", recv_buffer);

    // Send email message to SMTP server
    sprintf(send_buffer, "Subject: Example Email\r\nThis is an example email sent using SMTP protocol.\r\n.\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);

    //Receive response for email message from SMTP server
    n = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);
    if (n < 0) {
        perror("ERROR receiving message from SMTP server");
        exit(1);
    }
    recv_buffer[n] = '\0';
    printf("%s", recv_buffer);

    // Send QUIT command to SMTP server
    sprintf(send_buffer, "QUIT\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        perror("ERROR sending message to SMTP server");
        exit(1);
    }

    //Receive response for QUIT command from SMTP server
    n = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);
    if (n < 0) {
        perror("ERROR receiving message from SMTP server");
        exit(1);
    }
    recv_buffer[n] = '\0';
    printf("%s", recv_buffer);

    // Close socket
    close(sockfd);

    return 0;
}