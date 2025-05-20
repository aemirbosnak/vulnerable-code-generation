//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

void strip_newline(char *string) {
    int len = strlen(string);
    if (string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }
}

int main() {
    // Get the recipient's email address.
    char recipient_email[MAX_BUFFER_SIZE];
    printf("Enter the recipient's email address: ");
    scanf("%s", recipient_email);

    // Get the subject of the email.
    char subject[MAX_BUFFER_SIZE];
    printf("Enter the subject of the email: ");
    scanf("%[^\n]s", subject);
    strip_newline(subject);

    // Get the body of the email.
    char body[MAX_BUFFER_SIZE];
    printf("Enter the body of the email: ");
    scanf("%[^\n]s", body);
    strip_newline(body);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Lookup the mail server.
    struct hostent *server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Connect to the mail server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HELO command.
    char buffer[MAX_BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", "example.com");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command.
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", "sender@example.com");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command.
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", recipient_email);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the DATA command.
    if (send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the email subject and body.
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.", subject, body);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the QUIT command.
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}