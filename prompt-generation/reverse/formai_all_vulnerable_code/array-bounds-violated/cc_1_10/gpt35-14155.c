//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>

#define PORT 80

int main(int argc, char *argv[])
{
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <IP ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    char *ip_address = argv[1];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    char buffer[1024] = {0};

    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    char *http_request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    int request_length = strlen(http_request);
    int bytes_sent = send(sockfd, http_request, request_length, 0);
    if (bytes_sent < 0) {
        perror("Error in sending request");
        exit(EXIT_FAILURE);
    }

    int total_bytes_received = 0;
    int bytes_received = 0;
    while((bytes_received = recv(sockfd, buffer, 1024, 0)) > 0) {
        total_bytes_received += bytes_received;
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        memset(&buffer, 0, 1024);
    }

    if (bytes_received < 0) {
        perror("Error in receiving response");
        exit(EXIT_FAILURE);
    }

    printf("\nTotal bytes received = %d\n", total_bytes_received);

    close(sockfd);
    return 0;
}