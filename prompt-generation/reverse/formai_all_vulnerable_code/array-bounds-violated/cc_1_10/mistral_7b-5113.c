//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(void) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    ssize_t read_size;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    const char *request = "GET / HTTP/1.1\r\n"
                           "Host: 127.0.0.1\r\n"
                           "User-Agent: MyHTTPClient/1.0\r\n"
                           "Accept: */*\r\n"
                           "Connection: close\r\n\r\n";

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    read_size = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (read_size < 0) {
        perror("recv failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    buffer[read_size] = '\0';
    printf("Response:\n%s\n", buffer);

    close(sockfd);
    return EXIT_SUCCESS;
}