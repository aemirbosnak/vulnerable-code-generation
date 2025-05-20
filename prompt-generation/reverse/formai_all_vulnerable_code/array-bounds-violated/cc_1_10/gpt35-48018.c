//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd = 0, n = 0;
    char send_buffer[BUFF_SIZE], receive_buffer[BUFF_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    
    // Check command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    // Get server info
    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    // Initialize server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting\n");
        exit(1);
    }

    // Send greeting message to server
    sprintf(send_buffer, "EHLO client.example.com\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    n = recv(sockfd, receive_buffer, BUFF_SIZE-1, 0);
    receive_buffer[n] = '\0';
    printf("%s", receive_buffer);
    if (strncmp(receive_buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: %s", receive_buffer);
        exit(1);
    }

    // Send mail from and to messages
    sprintf(send_buffer, "MAIL FROM:<user1@example.com>\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    n = recv(sockfd, receive_buffer, BUFF_SIZE-1, 0);
    receive_buffer[n] = '\0';
    printf("%s", receive_buffer);
    if (strncmp(receive_buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: %s", receive_buffer);
        exit(1);
    }
    sprintf(send_buffer, "RCPT TO:<user2@example.com>\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    n = recv(sockfd, receive_buffer, BUFF_SIZE-1, 0);
    receive_buffer[n] = '\0';
    printf("%s", receive_buffer);
    if (strncmp(receive_buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: %s", receive_buffer);
        exit(1);
    }

    // Send message body
    sprintf(send_buffer, "DATA\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    n = recv(sockfd, receive_buffer, BUFF_SIZE-1, 0);
    receive_buffer[n] = '\0';
    printf("%s", receive_buffer);
    if (strncmp(receive_buffer, "354", 3) != 0) {
        fprintf(stderr, "Error: %s", receive_buffer);
        exit(1);
    }
    sprintf(send_buffer, "Subject: This is a test message\r\n\r\nHello world!\r\n.\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    n = recv(sockfd, receive_buffer, BUFF_SIZE-1, 0);
    receive_buffer[n] = '\0';
    printf("%s", receive_buffer);
    if (strncmp(receive_buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: %s", receive_buffer);
        exit(1);
    }

    // Close connection
    sprintf(send_buffer, "QUIT\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    close(sockfd);

    return 0;
}