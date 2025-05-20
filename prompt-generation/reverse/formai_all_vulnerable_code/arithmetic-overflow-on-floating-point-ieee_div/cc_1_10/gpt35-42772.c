//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n, bytes_received;
    struct sockaddr_in serv_addr;
    socklen_t serv_len;
    char buffer[1024];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error: Unable to create socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(8080);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error: Unable to connect to server");
    }

    long start_time = clock();
    char *request = "GET /testfile HTTP/1.1\r\nHost: localhost\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("Error: Unable to send request");
    }

    n = 0;
    while ((bytes_received = recv(sockfd, buffer, 1024, 0)) > 0) {
        n += bytes_received;
    }
    long end_time = clock();

    if (bytes_received < 0) {
        error("Error: Unable to receive data");
    }

    close(sockfd);

    printf("Download speed: %.2lf KB/s\n", (double) n / (end_time - start_time) * CLOCKS_PER_SEC / 1024);

    return 0;
}