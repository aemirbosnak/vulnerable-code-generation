//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage:./client <server_ip> <server_port> <message>\n");
        return 0;
    }

    // Convert server IP and port to network byte order
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 0;
    }

    printf("Connecting to server...\n");
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        return 0;
    }

    printf("Connected to server. Sending message...\n");
    // Send message
    strcpy(send_buffer, argv[3]);
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n == -1) {
        printf("Error sending message\n");
        return 0;
    }

    printf("Message sent successfully\n");
    // Receive response
    memset(recv_buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    if (n == -1) {
        printf("Error receiving response\n");
        return 0;
    }

    printf("Response received: %s\n", recv_buffer);
    // Close socket
    close(sockfd);

    return 0;
}