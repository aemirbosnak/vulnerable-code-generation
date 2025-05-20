//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    // Checking for the command line arguments
    if(argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    // Retrieving the host details
    server = gethostbyname(argv[1]);
    if(server == NULL) {
        fprintf(stderr, "Error: No such host.\n");
        exit(0);
    }
    port = atoi(argv[2]);

    // Creating a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        fprintf(stderr, "Error: cannot create socket.\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Connecting to the server
    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: Cannot connect to the server.\n");
        exit(0);
    }

    // Reading the welcome message from the server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if(n < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // Sending the HELO command to the server
    char helo_command[BUFFER_SIZE];
    sprintf(helo_command, "HELO %s\r\n", argv[1]);
    n = write(sockfd, helo_command, strlen(helo_command));
    if(n < 0) {
        fprintf(stderr, "Error: Cannot write to socket.\n");
        exit(0);
    }

    // Reading the response from the server for the HELO command
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if(n < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // Sending the MAIL FROM command to the server
    char mail_from_command[BUFFER_SIZE];
    sprintf(mail_from_command, "MAIL FROM: <%s>\r\n", "sender@example.com");
    n = write(sockfd, mail_from_command, strlen(mail_from_command));
    if(n < 0) {
        fprintf(stderr, "Error: Cannot write to socket.\n");
        exit(0);
    }

    // Reading the response from the server for the MAIL FROM command
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if(n < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // Sending the RCPT TO command to the server
    char rcpt_to_command[BUFFER_SIZE];
    sprintf(rcpt_to_command, "RCPT TO: <%s>\r\n", "receiver@example.com");
    n = write(sockfd, rcpt_to_command, strlen(rcpt_to_command));
    if(n < 0) {
        fprintf(stderr, "Error: Cannot write to socket.\n");
        exit(0);
    }

    // Reading the response from the server for the RCPT TO command
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if(n < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // Sending the DATA command to the server
    char data_command[] = "DATA\r\n";
    n = write(sockfd, data_command, strlen(data_command));
    if(n < 0) {
        fprintf(stderr, "Error: Cannot write to socket.\n");
        exit(0);
    }

    // Reading the response from the server for the DATA command
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if(n < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // Sending the message body to the server
    char message_body[] = "From: sender@example.com\nTo:receiver@example.com\nSubject: Test\n\nHello World!";
    n = write(sockfd, message_body, strlen(message_body));
    if(n < 0) {
        fprintf(stderr, "Error: Cannot write to socket.\n");
        exit(0);
    }

    // Sending the QUIT command to the server
    char quit_command[] = "QUIT\r\n";
    n = write(sockfd, quit_command, strlen(quit_command));
    if(n < 0) {
        fprintf(stderr, "Error: Cannot write to socket.\n");
        exit(0);
    }

    // Reading the response from the server for the QUIT command
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if(n < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }

    // Closing the socket and exiting the program
    close(sockfd);
    return 0;
}