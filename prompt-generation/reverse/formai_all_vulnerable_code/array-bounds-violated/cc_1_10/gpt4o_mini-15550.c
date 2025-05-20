//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define PORT 80

void print_help() {
    printf("Usage: ./http_client <hostname> <path>\n");
    printf("Example: ./http_client example.com /index.html\n");
}

void send_http_request(const char* hostname, const char* path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buf[BUFFER_SIZE];
    char recv_buf[BUFFER_SIZE];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    snprintf(send_buf, sizeof(send_buf),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, hostname);

    send(sockfd, send_buf, strlen(send_buf), 0);
    
    printf("Response:\n");
    while (1) {
        ssize_t bytes_received = recv(sockfd, recv_buf, sizeof(recv_buf)-1, 0);
        if (bytes_received <= 0)
            break;
        recv_buf[bytes_received] = '\0'; // Null terminate
        printf("%s", recv_buf);
    }

    close(sockfd);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_help();
        return EXIT_FAILURE;
    }

    const char* hostname = argv[1];
    const char* path = argv[2];

    send_http_request(hostname, path);

    return EXIT_SUCCESS;
}