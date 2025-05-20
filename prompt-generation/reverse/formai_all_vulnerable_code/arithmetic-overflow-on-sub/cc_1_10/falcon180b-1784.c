//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 25

void print_buffer(char *buffer, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%c", buffer[i]);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char server_name[20];
    char buffer[BUFFER_SIZE];
    char *message = "To: test@example.com\r\n"
                    "From: sender@example.com\r\n"
                    "Subject: Test Message\r\n"
                    "\r\n"
                    "This is a test message.";
    int message_length = strlen(message);
    int bytes_sent = 0;
    int bytes_received = 0;

    printf("Enter SMTP server name: ");
    scanf("%s", server_name);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_name, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    printf("Connected to %s.\n", server_name);

    while (bytes_sent < message_length) {
        int sent_bytes = send(sockfd, message + bytes_sent, message_length - bytes_sent, 0);
        if (sent_bytes == -1) {
            printf("Error sending message.\n");
            exit(1);
        }
        bytes_sent += sent_bytes;
    }

    while (bytes_received < BUFFER_SIZE) {
        int received_bytes = recv(sockfd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (received_bytes == 0) {
            printf("Connection closed.\n");
            exit(0);
        } else if (received_bytes == -1) {
            printf("Error receiving response.\n");
            exit(1);
        }
        bytes_received += received_bytes;
    }

    close(sockfd);

    printf("Response:\n");
    print_buffer(buffer, bytes_received);

    return 0;
}