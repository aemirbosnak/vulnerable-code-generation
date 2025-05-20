//FormAI DATASET v1.0 Category: Email Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SMTP_PORT 25
#define MAX_BUFFER_SIZE 4096

int send_email(char *hostname, char *to, char *from, char *subject, char *message)
{
    int sockfd, bytes_sent, bytes_received;
    char buffer[MAX_BUFFER_SIZE];
    struct hostent *server;
    struct sockaddr_in serv_addr;

    // create a new socket for the SMTP server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: could not create socket");
        return -1;
    }

    // get hostname by DNS resolution
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host '%s'\n", hostname);
        return -1;
    }

    // make sure server address is cleared out
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // set server address parameters
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMTP_PORT);
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);

    // connect to the SMTP server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR: could not connect to server");
        return -1;
    }

    // receive the server's welcome message
    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("ERROR: could not receive data from server");
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    // send the HELO command
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", hostname);
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("ERROR: could not send data to server");
        return -1;
    }

    // receive the server's response
    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("ERROR: could not receive data from server");
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    // send the MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", from);
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("ERROR: could not send data to server");
        return -1;
    }

    // receive the server's response
    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("ERROR: could not receive data from server");
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    // send the RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", to);
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("ERROR: could not send data to server");
        return -1;
    }

    // receive the server's response
    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("ERROR: could not receive data from server");
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    // send the DATA command
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("ERROR: could not send data to server");
        return -1;
    }

    // receive the server's response
    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("ERROR: could not receive data from server");
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    // send the email header and message body
    snprintf(buffer, sizeof(buffer),
             "From: %s\r\n"
             "To: %s\r\n"
             "Subject: %s\r\n"
             "%s\r\n" // blank line 
             "%s\r\n" // message body
             ".\r\n", // end message
             from, to, subject, message);
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("ERROR: could not send data to server");
        return -1;
    }

    // receive the server's response
    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("ERROR: could not receive data from server");
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    // send the QUIT command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("ERROR: could not send data to server");
        return -1;
    }

    // receive the server's response
    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("ERROR: could not receive data from server");
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    // close the socket
    close(sockfd);

    return 0;
}

int main()
{
    char *hostname = "mail.example.com";
    char *to = "johndoe@example.com";
    char *from = "janedoe@example.com";
    char *subject = "Hello, World!";
    char *message = "This is a test message.";

    if (send_email(hostname, to, from, subject, message) == 0) {
        printf("Email sent successfully.\n");
        return 0;
    } else {
        printf("Email failed to send.\n");
        return -1;
    }
}