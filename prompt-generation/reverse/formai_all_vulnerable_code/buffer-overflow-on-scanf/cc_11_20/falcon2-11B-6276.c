//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char** argv) {
    // create a window and display a message
    printf("Welcome to the C Email Client!\n");
    printf("Please enter a string to send as an email:\n");

    // read user input
    char input[MAXLINE];
    scanf("%s", input);

    // display user input back to the user
    printf("You entered: %s\n", input);

    // create a new buffer and copy the user's input into it
    char* buffer = (char*)malloc(strlen(input)+1);
    strcpy(buffer, input);

    // allocate memory for a new string using the malloc function
    char* new_string = (char*)malloc(strlen(buffer)+1);

    // copy the buffer into the new string
    strcpy(new_string, buffer);

    // set up a socket connection to the SMTP server
    int sockfd;
    struct sockaddr_in serv_addr;
    int opt = 1;
    int addrlen = sizeof(serv_addr);
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error opening socket\n");
        exit(1);
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int))) {
        perror("setsockopt");
        exit(1);
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(25);
    serv_addr.sin_addr.s_addr = inet_addr("smtp.example.com");
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // send HELO command to server
    if (send(sockfd, "HELO myclient\r\n", strlen("HELO myclient\r\n"), 0) == -1) {
        printf("Error sending HELO command\n");
        exit(1);
    }

    // send EHLO command to check if server supports ESMTP extension
    if (send(sockfd, "EHLO myclient\r\n", strlen("EHLO myclient\r\n"), 0) == -1) {
        printf("Error sending EHLO command\n");
        exit(1);
    }

    // send MAIL FROM command
    if (send(sockfd, "MAIL FROM:<user@example.com>\r\n", strlen("MAIL FROM:<user@example.com>\r\n"), 0) == -1) {
        printf("Error sending MAIL FROM command\n");
        exit(1);
    }

    // send RCPT TO command
    if (send(sockfd, "RCPT TO:<recipient@example.com>\r\n", strlen("RCPT TO:<recipient@example.com>\r\n"), 0) == -1) {
        printf("Error sending RCPT TO command\n");
        exit(1);
    }

    // send DATA command
    if (send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0) == -1) {
        printf("Error sending DATA command\n");
        exit(1);
    }

    // send the email body
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending email body\n");
        exit(1);
    }

    // send QUIT command to close the connection
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
        printf("Error sending QUIT command\n");
        exit(1);
    }

    // free the memory allocated for the new string
    free(new_string);

    // close the socket connection
    if (close(sockfd)) {
        printf("Error closing socket\n");
        exit(1);
    }

    printf("Email sent successfully!\n");

    return 0;
}