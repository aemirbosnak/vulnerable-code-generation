//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to SMTP server at %s:%s\n", argv[1], argv[2]);

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Sending HELO message to server
    char helo_msg[BUFFER_SIZE];
    memset(helo_msg, 0, BUFFER_SIZE);
    sprintf(helo_msg, "HELO %s\r\n", argv[1]);
    n = write(sockfd, helo_msg, strlen(helo_msg));
    if (n < 0) {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Sending MAIL FROM message to server
    char mail_from_msg[BUFFER_SIZE];
    memset(mail_from_msg, 0, BUFFER_SIZE);
    sprintf(mail_from_msg, "MAIL FROM: <sender@%s>\r\n", argv[1]);
    n = write(sockfd, mail_from_msg, strlen(mail_from_msg));
    if (n < 0) {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Sending RCPT TO message to server
    char rcpt_to_msg[BUFFER_SIZE];
    memset(rcpt_to_msg, 0, BUFFER_SIZE);
    sprintf(rcpt_to_msg, "RCPT TO: <recipient@%s>\r\n", argv[1]);
    n = write(sockfd, rcpt_to_msg, strlen(rcpt_to_msg));
    if (n < 0) {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Sending DATA message to server
    char data_msg[BUFFER_SIZE];
    memset(data_msg, 0, BUFFER_SIZE);
    strcpy(data_msg, "DATA\r\n");
    n = write(sockfd, data_msg, strlen(data_msg));
    if (n < 0) {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Sending message body to server
    char message_body[BUFFER_SIZE];
    memset(message_body, 0, BUFFER_SIZE);
    printf("Enter email body:\n");
    fgets(message_body, BUFFER_SIZE - 1, stdin);
    n = write(sockfd, message_body, strlen(message_body));
    if (n < 0) {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }

    // Sending QUIT message to server
    char quit_msg[BUFFER_SIZE];
    memset(quit_msg, 0, BUFFER_SIZE);
    strcpy(quit_msg, "QUIT\r\n");
    n = write(sockfd, quit_msg, strlen(quit_msg));
    if (n < 0) {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}