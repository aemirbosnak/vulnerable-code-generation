//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/* This is a simple IMAP client that connects to an IMAP server and 
 * performs login and displays the number of messages in the inbox.
 */

int main(int argc, char *argv[]) {
    char *hostname = "mail.example.com"; // Change this to the hostname of your IMAP server
    char *username = "your_username"; // Change this to your IMAP username
    char *password = "your_password"; // Change this to your IMAP password
    char buffer[1024];
    struct hostent *host = gethostbyname(hostname);
    struct sockaddr_in server_address;
    int sockfd, n;

    if (host == NULL) {
        printf("Could not resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(143); // IMAP server port
    server_address.sin_addr = *(struct in_addr*)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    n = read(sockfd, buffer, 1024); // Read server greeting
    if (n < 0) {
        printf("Failed to read server greeting\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    sprintf(buffer, "a001 LOGIN %s %s", username, password); // Construct login command
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Failed to send login command\n");
        exit(EXIT_FAILURE);
    }

    n = read(sockfd, buffer, 1024); // Read server response
    if (n < 0) {
        printf("Failed to read server response\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    sprintf(buffer, "a002 SELECT INBOX"); // Construct select command
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Failed to send select command\n");
        exit(EXIT_FAILURE);
    }

    n = read(sockfd, buffer, 1024); // Read server response
    if (n < 0) {
        printf("Failed to read server response\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    sprintf(buffer, "a003 STATUS INBOX (MESSAGES)"); // Construct status command
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Failed to send status command\n");
        exit(EXIT_FAILURE);
    }

    n = read(sockfd, buffer, 1024); // Read server response
    if (n < 0) {
        printf("Failed to read server response\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}