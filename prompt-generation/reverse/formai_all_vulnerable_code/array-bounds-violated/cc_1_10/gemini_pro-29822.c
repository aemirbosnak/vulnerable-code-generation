//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXDATASIZE 1024

void send_command(int sockfd, char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent: %s", command);
}

void receive_response(int sockfd) {
    char buffer[MAXDATASIZE];
    int nbytes;

    while ((nbytes = recv(sockfd, buffer, MAXDATASIZE - 1, 0)) > 0) {
        buffer[nbytes] = '\0';
        printf("Received: %s", buffer);
    }
}

void send_data(int sockfd, char *data) {
    send(sockfd, data, strlen(data), 0);
    printf("Sent: %s", data);
}

void close_connection(int sockfd) {
    close(sockfd);
    printf("Closed connection");
}

void send_ehlo(int sockfd) {
    send_command(sockfd, "EHLO localhost\r\n");
}

void send_mail_from(int sockfd, char *email) {
    char command[MAXDATASIZE];
    snprintf(command, MAXDATASIZE, "MAIL FROM:<%s>\r\n", email);
    send_command(sockfd, command);
}

void send_rcpt_to(int sockfd, char *email) {
    char command[MAXDATASIZE];
    snprintf(command, MAXDATASIZE, "RCPT TO:<%s>\r\n", email);
    send_command(sockfd, command);
}

void send_data_command(int sockfd) {
    send_command(sockfd, "DATA\r\n");
}

void send_email_content(int sockfd, char *content) {
    send_data(sockfd, content);
    send_command(sockfd, "\r\n.\r\n");
}

void send_quit(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
}

void main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <email> <message>\n", argv[0]);
        return;
    }

    char *email = argv[1];
    char *message = argv[2];

    struct hostent *host;
    host = gethostbyname("localhost");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return;
    }

    receive_response(sockfd);

    send_ehlo(sockfd);
    receive_response(sockfd);

    send_mail_from(sockfd, email);
    receive_response(sockfd);

    send_rcpt_to(sockfd, email);
    receive_response(sockfd);

    send_data_command(sockfd);
    receive_response(sockfd);

    send_email_content(sockfd, message);
    receive_response(sockfd);

    send_quit(sockfd);
    close_connection(sockfd);
}