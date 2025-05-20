//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <ctype.h>

#define MAX_LINE 2048

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    struct hostent *he;
    he = gethostbyname(host);
    if (he == NULL) {
        fprintf(stderr, "gethostbyname() failed: %s\n", hstrerror(h_errno));
        exit(EXIT_FAILURE);
    }
    memcpy(&serv_addr.sin_addr, he->h_addr, he->h_length);
    serv_addr.sin_port = htons(port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    int status = connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (status < 0) {
        perror("connect() failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    char *username = "user";
    char *password = "password";

    char buffer[MAX_LINE];

    // Send the username
    sprintf(buffer, "USER %s\r\n", username);
    status = send(sock, buffer, strlen(buffer), 0);
    if (status < 0) {
        perror("send() failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Receive the response
    status = recv(sock, buffer, MAX_LINE, 0);
    if (status < 0) {
        perror("recv() failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Check the response code
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error sending username: %s\n", buffer);
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Send the password
    sprintf(buffer, "PASS %s\r\n", password);
    status = send(sock, buffer, strlen(buffer), 0);
    if (status < 0) {
        perror("send() failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Receive the response
    status = recv(sock, buffer, MAX_LINE, 0);
    if (status < 0) {
        perror("recv() failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Check the response code
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error sending password: %s\n", buffer);
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Send the LIST command
    sprintf(buffer, "LIST \"\"\r\n");
    status = send(sock, buffer, strlen(buffer), 0);
    if (status < 0) {
        perror("send() failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Receive the response
    status = recv(sock, buffer, MAX_LINE, 0);
    if (status < 0) {
        perror("recv() failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Parse the response
    printf("Mailbox:\n");
    while (!strncmp(buffer, "+OK", 3)) {
        char *mailbox = malloc(strlen(buffer));
        strcpy(mailbox, buffer + 4);
        printf("%s\n", mailbox);

        status = recv(sock, buffer, MAX_LINE, 0);
        if (status < 0) {
            perror("recv() failed");
            close(sock);
            exit(EXIT_FAILURE);
        }
    }

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    status = send(sock, buffer, strlen(buffer), 0);
    if (status < 0) {
        perror("send() failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    close(sock);

    return EXIT_SUCCESS;
}