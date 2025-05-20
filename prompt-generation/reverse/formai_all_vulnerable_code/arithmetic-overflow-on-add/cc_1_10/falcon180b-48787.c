//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

#define BUF_SIZE 1024
#define SERVER "smtp.example.com"
#define PORT 587

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    char *message = "Subject: Test Message\r\n\r\nThis is a test message sent from a SMTP client.\r\n";
    int bytes_sent;
    int total_bytes_sent = 0;
    int max_attempts = 5;
    int attempt = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))!= 0) {
        printf("Error connecting to server\n");
        close(sockfd);
        exit(1);
    }

    printf("Connected to server\n");

    while (attempt < max_attempts) {
        bytes_sent = send(sockfd, message, strlen(message), 0);
        if (bytes_sent == -1) {
            printf("Error sending message\n");
            close(sockfd);
            exit(1);
        }
        total_bytes_sent += bytes_sent;
        if (total_bytes_sent == strlen(message)) {
            printf("Message sent successfully\n");
            close(sockfd);
            exit(0);
        }
        usleep(100000);
        attempt++;
    }

    printf("Maximum number of attempts reached\n");
    close(sockfd);
    exit(1);
}