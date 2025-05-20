//FormAI DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 110

int main(int argc, char **argv) {
    char *server_ip = "mail.example.com";
    char *username = "example_user";
    char *password = "example_password";
    char *from = "example_user@example.com";
    char *to = "recipient@example.com";
    char *subject = "Test email";
    char *body = "This is a test email sent from my C email client!";
    char buffer[BUFFER_SIZE];
    int sock_fd;

    struct hostent *he;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Get hostent from server IP
    if ((he = gethostbyname(server_ip)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Zero out server_addr
    memset(&server_addr, 0, sizeof(server_addr));

    // Set server_addr information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Receive greeting from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send username to server
    sprintf(buffer, "USER %s\r\n", username);
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive response from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send password to server
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive response from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send MAIL FROM command to server
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive response from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send RCPT TO command to server
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive response from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send DATA command to server
    sprintf(buffer, "DATA\r\n");
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive response from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send email content to server
    sprintf(buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, body);
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive response from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Close connection to server
    sprintf(buffer, "QUIT\r\n");
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive response from server
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    close(sock_fd);
    return 0;
}