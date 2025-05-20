//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int sockfd, bytes;
    struct timeval start, end;
    struct sockaddr_in server;
    socklen_t addrlen = sizeof(server);

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Connect to a server
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&server, addrlen) < 0) {
        perror("connect");
        return 1;
    }

    // Send a request
    printf("GET / HTTP/1.1\r\nHost: example.com\r\n\r\n");
    bytes = send(sockfd, "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n", 58, 0);
    if (bytes < 0) {
        perror("send");
        return 1;
    }

    // Receive a response
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        return 1;
    }
    if (listen(sockfd, 1) < 0) {
        perror("listen");
        return 1;
    }
    addrlen = sizeof(server);
    sockfd = accept(sockfd, (struct sockaddr *)&server, &addrlen);
    if (sockfd < 0) {
        perror("accept");
        return 1;
    }
    if (recv(sockfd, &start, sizeof(start), 0) < 0) {
        perror("recv");
        return 1;
    }
    if (recv(sockfd, &end, sizeof(end), 0) < 0) {
        perror("recv");
        return 1;
    }
    if (end.tv_sec - start.tv_sec > 0 || end.tv_usec - start.tv_usec > 0) {
        printf("Request took %d.%06d seconds\n", (int)end.tv_sec, (int)end.tv_usec);
    } else {
        printf("Request took %d seconds\n", (int)end.tv_sec);
    }

    close(sockfd);
    return 0;
}