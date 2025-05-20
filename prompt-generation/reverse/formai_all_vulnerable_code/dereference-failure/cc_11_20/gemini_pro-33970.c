//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <sender> <recipient> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the sender and recipient addresses
    char *sender = argv[1];
    char *recipient = argv[2];

    // Get the message
    char *message = argv[3];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the SMTP server address
    struct hostent *host = gethostbyname("localhost");
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HELO command
    char helo_command[256];
    sprintf(helo_command, "HELO %s\r\n", host->h_name);
    if (send(sockfd, helo_command, strlen(helo_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the HELO response
    char helo_response[256];
    if (recv(sockfd, helo_response, sizeof(helo_response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    char mail_from_command[256];
    sprintf(mail_from_command, "MAIL FROM: <%s>\r\n", sender);
    if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the MAIL FROM response
    char mail_from_response[256];
    if (recv(sockfd, mail_from_response, sizeof(mail_from_response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command
    char rcpt_to_command[256];
    sprintf(rcpt_to_command, "RCPT TO: <%s>\r\n", recipient);
    if (send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the RCPT TO response
    char rcpt_to_response[256];
    if (recv(sockfd, rcpt_to_response, sizeof(rcpt_to_response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the DATA command
    char data_command[256];
    sprintf(data_command, "DATA\r\n");
    if (send(sockfd, data_command, strlen(data_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the DATA response
    char data_response[256];
    if (recv(sockfd, data_response, sizeof(data_response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the message
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the dot character to signify the end of the message
    char dot_command[256];
    sprintf(dot_command, ".\r\n");
    if (send(sockfd, dot_command, strlen(dot_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the QUIT response
    char quit_response[256];
    if (recv(sockfd, quit_response, sizeof(quit_response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}