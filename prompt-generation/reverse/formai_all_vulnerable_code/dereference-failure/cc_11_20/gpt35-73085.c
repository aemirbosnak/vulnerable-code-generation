//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server_address> <port_number> <email_address>\n", argv[0]);
        exit(1);
    }

    char *server_address = argv[1];
    int port_number = atoi(argv[2]);
    char *email_address = argv[3];

    // Resolve server address
    struct hostent *he = gethostbyname(server_address);
    if (he == NULL) {
        printf("Error: Unable to resolve server address.\n");
        exit(1);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Unable to create socket.\n");
        exit(1);
    }

    // Set server address info
    struct sockaddr_in server_address_info;
    memset(&server_address_info, 0, sizeof(server_address_info));
    server_address_info.sin_family = AF_INET;
    server_address_info.sin_port = htons(port_number);
    memcpy(&server_address_info.sin_addr, he->h_addr_list[0], he->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_address_info, sizeof(server_address_info)) < 0) {
        printf("Error: Unable to connect to server.\n");
        exit(1);
    }

    char buffer[MAX_BUFFER_SIZE];
    int bytes_read;

    // Receive server header
    bytes_read = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        printf("Error: Unable to receive data from server.\n");
        close(sockfd);
        exit(1);
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    // Send HELO command
    sprintf(buffer, "HELO %s\r\n", server_address);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Unable to send data to server.\n");
        close(sockfd);
        exit(1);
    }

    // Receive server response
    bytes_read = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        printf("Error: Unable to receive data from server.\n");
        close(sockfd);
        exit(1);
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", email_address);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Unable to send data to server.\n");
        close(sockfd);
        exit(1);
    }

    // Receive server response
    bytes_read = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        printf("Error: Unable to receive data from server.\n");
        close(sockfd);
        exit(1);
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    // Send RCPT TO command
    printf("Please enter the recipient email address: ");
    fflush(stdout);
    fgets(buffer, MAX_BUFFER_SIZE - 1, stdin);
    strtok(buffer, "\n");

    sprintf(buffer, "RCPT TO:<%s>\r\n", buffer);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Unable to send data to server.\n");
        close(sockfd);
        exit(1);
    }

    // Receive server response
    bytes_read = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        printf("Error: Unable to receive data from server.\n");
        close(sockfd);
        exit(1);
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Unable to send data to server.\n");
        close(sockfd);
        exit(1);
    }

    // Receive server response
    bytes_read = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        printf("Error: Unable to receive data from server.\n");
        close(sockfd);
        exit(1);
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    // Send email body
    printf("Please enter the email body, end with a single period (\'.\') on a line by itself: ");
    fflush(stdout);

    do {
        fgets(buffer, MAX_BUFFER_SIZE - 1, stdin);
        strtok(buffer, "\n");
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            printf("Error: Unable to send data to server.\n");
            close(sockfd);
            exit(1);
        }
    } while (strcmp(buffer, ".") != 0);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Unable to send data to server.\n");
        close(sockfd);
        exit(1);
    }

    // Receive server response
    bytes_read = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        printf("Error: Unable to receive data from server.\n");
        close(sockfd);
        exit(1);
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}