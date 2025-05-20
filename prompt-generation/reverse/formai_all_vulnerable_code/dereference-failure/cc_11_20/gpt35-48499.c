//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <SMTP IP>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *smtp_ip = argv[1];
    struct hostent *he;
    he = gethostbyname(smtp_ip);
    if (he == NULL) {
        fprintf(stderr, "Error: Invalid SMTP IP address.\n");
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to create socket.\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(25);  // SMTP port
    memcpy(&serv_addr.sin_addr, he->h_addr_list[0], he->h_length);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: Failed to connect.\n");
        exit(EXIT_FAILURE);
    } 
    
    char recv_buf[MAX_BUFF_SIZE];
    char command[MAX_BUFF_SIZE];
    int recv_len;
    int send_len;
    
    recv_len = recv(sockfd, recv_buf, MAX_BUFF_SIZE, 0);
    if (recv_len < 0) {
        fprintf(stderr, "Error: Failed to receive data.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", recv_buf);
    
    send_len = snprintf(command, MAX_BUFF_SIZE, "HELO localhost\r\n");
    if (send(sockfd, command, send_len, 0) < 0) {
        fprintf(stderr, "Error: Failed to send data.\n");
        exit(EXIT_FAILURE);
    }

    recv_len = recv(sockfd, recv_buf, MAX_BUFF_SIZE, 0);
    if (recv_len < 0) {
        fprintf(stderr, "Error: Failed to receive data.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", recv_buf);
    
    send_len = snprintf(command, MAX_BUFF_SIZE, "MAIL FROM:<john@example.com>\r\n");
    if (send(sockfd, command, send_len, 0) < 0) {
        fprintf(stderr, "Error: Failed to send data.\n");
        exit(EXIT_FAILURE);
    }

    recv_len = recv(sockfd, recv_buf, MAX_BUFF_SIZE, 0);
    if (recv_len < 0) {
        fprintf(stderr, "Error: Failed to receive data.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", recv_buf);
    
    send_len = snprintf(command, MAX_BUFF_SIZE, "RCPT TO:<jane@example.com>\r\n");
    if (send(sockfd, command, send_len, 0) < 0) {
        fprintf(stderr, "Error: Failed to send data.\n");
        exit(EXIT_FAILURE);
    }

    recv_len = recv(sockfd, recv_buf, MAX_BUFF_SIZE, 0);
    if (recv_len < 0) {
        fprintf(stderr, "Error: Failed to receive data.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", recv_buf);
    
    send_len = snprintf(command, MAX_BUFF_SIZE, "DATA\r\n");
    if (send(sockfd, command, send_len, 0) < 0) {
        fprintf(stderr, "Error: Failed to send data.\n");
        exit(EXIT_FAILURE);
    }

    recv_len = recv(sockfd, recv_buf, MAX_BUFF_SIZE, 0);
    if (recv_len < 0) {
        fprintf(stderr, "Error: Failed to receive data.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", recv_buf);
    
    send_len = snprintf(command, MAX_BUFF_SIZE, "Subject: Example Subject\r\n\r\nHello, this is an example email.\r\n.\r\n");
    if (send(sockfd, command, send_len, 0) < 0) {
        fprintf(stderr, "Error: Failed to send data.\n");
        exit(EXIT_FAILURE);
    }

    recv_len = recv(sockfd, recv_buf, MAX_BUFF_SIZE, 0);
    if (recv_len < 0) {
        fprintf(stderr, "Error: Failed to receive data.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", recv_buf);
    
    send_len = snprintf(command, MAX_BUFF_SIZE, "QUIT\r\n");
    if (send(sockfd, command, send_len, 0) < 0) {
        fprintf(stderr, "Error: Failed to send data.\n");
        exit(EXIT_FAILURE);
    }
    
    recv_len = recv(sockfd, recv_buf, MAX_BUFF_SIZE, 0);
    if (recv_len < 0) {
        fprintf(stderr, "Error: Failed to receive data.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", recv_buf);
    
    close(sockfd);
    return 0;
}