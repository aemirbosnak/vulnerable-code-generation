//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SMTP_PORT 25

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <from> <to>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the server address
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: could not create socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: could not connect to server");
        return EXIT_FAILURE;
    }

    // Read the server greeting
    char buffer[1024];
    int n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error: could not read server greeting");
        return EXIT_FAILURE;
    }
    buffer[n] = '\0';

    // Print the server greeting
    printf("Server greeting: %s\n", buffer);

    // Send the HELO command
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", argv[1]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: could not send HELO command");
        return EXIT_FAILURE;
    }

    // Read the server response
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error: could not read server response to HELO command");
        return EXIT_FAILURE;
    }
    buffer[n] = '\0';

    // Print the server response
    printf("Server response to HELO command: %s\n", buffer);

    // Send the MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: could not send MAIL FROM command");
        return EXIT_FAILURE;
    }

    // Read the server response
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error: could not read server response to MAIL FROM command");
        return EXIT_FAILURE;
    }
    buffer[n] = '\0';

    // Print the server response
    printf("Server response to MAIL FROM command: %s\n", buffer);

    // Send the RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", argv[3]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: could not send RCPT TO command");
        return EXIT_FAILURE;
    }

    // Read the server response
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error: could not read server response to RCPT TO command");
        return EXIT_FAILURE;
    }
    buffer[n] = '\0';

    // Print the server response
    printf("Server response to RCPT TO command: %s\n", buffer);

    // Send the DATA command
    n = write(sockfd, "DATA\r\n", 5);
    if (n < 0) {
        perror("Error: could not send DATA command");
        return EXIT_FAILURE;
    }

    // Read the server response
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error: could not read server response to DATA command");
        return EXIT_FAILURE;
    }
    buffer[n] = '\0';

    // Print the server response
    printf("Server response to DATA command: %s\n", buffer);

    // Send the email message
    FILE *fp = fopen("email.txt", "r");
    if (fp == NULL) {
        perror("Error: could not open email file");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Error: could not send email message");
            fclose(fp);
            return EXIT_FAILURE;
        }
    }

    fclose(fp);

    // Send the QUIT command
    n = write(sockfd, "QUIT\r\n", 6);
    if (n < 0) {
        perror("Error: could not send QUIT command");
        return EXIT_FAILURE;
    }

    // Read the server response
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error: could not read server response to QUIT command");
        return EXIT_FAILURE;
    }
    buffer[n] = '\0';

    // Print the server response
    printf("Server response to QUIT command: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}