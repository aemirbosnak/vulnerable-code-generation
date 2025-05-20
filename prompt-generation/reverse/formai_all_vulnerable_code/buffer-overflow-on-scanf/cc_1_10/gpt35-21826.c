//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void send_message(int, char *);
void receive_message(int, int);

int main() {
    int sockfd, portno, n, i = 1;
    char server_ip[20], buffer[BUFFER_SIZE], message[BUFFER_SIZE];
    struct sockaddr_in serv_addr;

    printf("Enter the IP address of SMTP server: ");
    scanf("%s", server_ip);

    printf("Enter the port number of SMTP server: ");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // initializing server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(server_ip);
    serv_addr.sin_port = htons(portno);

    // connecting to SMTP server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting to SMTP server");
        exit(1);
    }

    // receiving message from SMTP server
    receive_message(sockfd, 220);

    // sending HELO command to SMTP server
    sprintf(buffer, "HELO test.com\r\n");
    send_message(sockfd, buffer);
    sprintf(buffer, "");

    // receiving message from SMTP server
    receive_message(sockfd, 250);

    // sending MAIL FROM command to SMTP server
    sprintf(buffer, "MAIL FROM:<sender@test.com>\r\n");
    send_message(sockfd, buffer);
    sprintf(buffer, "");

    // receiving message from SMTP server
    receive_message(sockfd, 250);

    // sending RCPT TO command to SMTP server
    sprintf(buffer, "RCPT TO:<receiver@test.com>\r\n");
    send_message(sockfd, buffer);
    sprintf(buffer, "");

    // receiving message from SMTP server
    receive_message(sockfd, 250);

    // sending DATA command to SMTP server
    sprintf(buffer, "DATA\r\n");
    send_message(sockfd, buffer);
    sprintf(buffer, "");

    // receiving message from SMTP server
    receive_message(sockfd, 354);

    // constructing message body
    sprintf(message, "Subject: SMTP Client Example\r\n");
    sprintf(message + strlen(message), "\r\n");
    sprintf(message + strlen(message), "This is a test message sent from SMTP client example program.\r\n");

    // sending message body to SMTP server
    send_message(sockfd, message);
    sprintf(buffer, "");

    // sending QUIT command to SMTP server
    sprintf(buffer, "QUIT\r\n");
    send_message(sockfd, buffer);
    sprintf(buffer, "");

    // receiving message from SMTP server
    receive_message(sockfd, 221);

    printf("\nMail sent successfully!\n");

    close(sockfd);
    return 0;
}

// function to send message to SMTP server
void send_message(int sockfd, char *message) {
    int n;

    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}

// function to receive message from SMTP server
void receive_message(int sockfd, int expected_code) {
    int n;
    char buffer[BUFFER_SIZE];

    bzero(buffer, BUFFER_SIZE);

    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        printf("%s", buffer);
        if (buffer[3] == ' ') {
            break;
        }
        bzero(buffer, BUFFER_SIZE);
    }

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    if (atoi(buffer) != expected_code) {
        fprintf(stderr, "Error: Unexpected response code %d\n", atoi(buffer));
        exit(1);
    }
}