//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./smtpClient <server_ip> <port_number> <email.txt>\n");
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[2]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR creating socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting to server");
        exit(EXIT_FAILURE);
    }

    // Read email content from file
    char *filename = argv[3];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("ERROR opening file");
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    char email_content[file_size];
    fread(email_content, 1, file_size, fp);
    fclose(fp);

    // Send email
    char buffer[BUF_SIZE];
    memset(buffer, 0, BUF_SIZE);
    int bytes_sent = send(sockfd, "HELO client\r\n", 13, 0);
    if (bytes_sent < 0) {
        perror("ERROR sending data to server");
        exit(EXIT_FAILURE);
    }
    printf("HELO client\n");

    bytes_sent = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (bytes_sent < 0) {
        perror("ERROR receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    memset(buffer, 0, BUF_SIZE);
    sprintf(buffer, "MAIL FROM:<%s>\r\n", strtok(email_content, "\r\n"));
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("ERROR sending data to server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    bytes_sent = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (bytes_sent < 0) {
        perror("ERROR receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    memset(buffer, 0, BUF_SIZE);
    sprintf(buffer, "RCPT TO:<%s>\r\n", strtok(NULL, "\r\n"));
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("ERROR sending data to server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    bytes_sent = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (bytes_sent < 0) {
        perror("ERROR receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    memset(buffer, 0, BUF_SIZE);
    sprintf(buffer, "DATA\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("ERROR sending data to server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    bytes_sent = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (bytes_sent < 0) {
        perror("ERROR receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    bytes_sent = send(sockfd, email_content, strlen(email_content), 0);
    if (bytes_sent < 0) {
        perror("ERROR sending data to server");
        exit(EXIT_FAILURE);
    }

    bytes_sent = send(sockfd, "\r\n.\r\n", 5, 0);
    if (bytes_sent < 0) {
        perror("ERROR sending data to server");
        exit(EXIT_FAILURE);
    }

    bytes_sent = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (bytes_sent < 0) {
        perror("ERROR receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    memset(buffer, 0, BUF_SIZE);
    sprintf(buffer, "QUIT\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("ERROR sending data to server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    bytes_sent = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (bytes_sent < 0) {
        perror("ERROR receiving data from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    close(sockfd);

    return 0;
}