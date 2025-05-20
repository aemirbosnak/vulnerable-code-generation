//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <time.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[BUF_SIZE];
    char recv_buffer[BUF_SIZE];
    int bytes_sent, bytes_recv;
    int opt = 1;
    time_t start_time, end_time;
    double elapsed_time;

    if (argc!= 3) {
        printf("Usage: %s <SMTP server address> <port number>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    start_time = time(NULL);

    printf("Connected to SMTP server\n");

    strcpy(send_buffer, "HELO ");
    strcat(send_buffer, argv[1]);
    strcat(send_buffer, "\r\n");
    bytes_sent = send(sockfd, send_buffer, strlen(send_buffer), 0);

    strcpy(send_buffer, "MAIL FROM:<");
    strcat(send_buffer, argv[1]);
    strcat(send_buffer, ">\r\n");
    bytes_sent = send(sockfd, send_buffer, strlen(send_buffer), 0);

    strcpy(send_buffer, "RCPT TO:<");
    strcat(send_buffer, argv[1]);
    strcat(send_buffer, ">\r\n");
    bytes_sent = send(sockfd, send_buffer, strlen(send_buffer), 0);

    strcpy(send_buffer, "DATA\r\n");
    bytes_sent = send(sockfd, send_buffer, strlen(send_buffer), 0);

    strcpy(send_buffer, "Subject: Test Message\r\n");
    bytes_sent = send(sockfd, send_buffer, strlen(send_buffer), 0);

    strcpy(send_buffer, "Hello, world!\r\n.\r\n");
    bytes_sent = send(sockfd, send_buffer, strlen(send_buffer), 0);

    close(sockfd);

    end_time = time(NULL);

    elapsed_time = difftime(end_time, start_time);

    printf("Message sent successfully\n");
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    return 0;
}