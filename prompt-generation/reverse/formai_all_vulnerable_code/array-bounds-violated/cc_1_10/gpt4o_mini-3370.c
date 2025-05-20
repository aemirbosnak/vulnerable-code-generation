//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define EMAIL_SERVER_PORT "587"

// Function to create a socket and connect to the server
int connect_to_email_server(const char *hostname) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, EMAIL_SERVER_PORT, &hints, &servinfo) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd < 0) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == 0) {
            break; // Success
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to the server\n");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send data to the server
void send_data(int sockfd, const char *data) {
    if (send(sockfd, data, strlen(data), 0) == -1) {
        perror("send");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

// Function to receive data from the server
void receive_data(int sockfd) {
    char buffer[BUFFER_SIZE];
    int numbytes;

    while ((numbytes = recv(sockfd, buffer, sizeof buffer - 1, 0)) > 0) {
        buffer[numbytes] = '\0'; // Null-terminate the buffer
        printf("%s", buffer); // Print the received data
    }

    if (numbytes == -1) {
        perror("recv");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

// Function to send an email
void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char buffer[BUFFER_SIZE];

    // HELO command
    snprintf(buffer, sizeof buffer, "HELO localhost\r\n");
    send_data(sockfd, buffer);
    receive_data(sockfd);

    // MAIL FROM
    snprintf(buffer, sizeof buffer, "MAIL FROM:<%s>\r\n", from);
    send_data(sockfd, buffer);
    receive_data(sockfd);

    // RCPT TO
    snprintf(buffer, sizeof buffer, "RCPT TO:<%s>\r\n", to);
    send_data(sockfd, buffer);
    receive_data(sockfd);

    // DATA command
    send_data(sockfd, "DATA\r\n");
    receive_data(sockfd);

    // Email content
    snprintf(buffer, sizeof buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_data(sockfd, buffer);
    receive_data(sockfd);
    
    // QUIT command
    send_data(sockfd, "QUIT\r\n");
    receive_data(sockfd);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Change to your SMTP server
    const char *from_email = "your_email@example.com"; // Change to your email
    const char *to_email = "recipient@example.com"; // Change to recipient's email
    const char *subject = "Test Email from C Client";
    const char *body = "Hello, this is a test email sent from a C email client.";

    int sockfd = connect_to_email_server(smtp_server);
    send_email(sockfd, from_email, to_email, subject, body);

    close(sockfd);
    return 0;
}