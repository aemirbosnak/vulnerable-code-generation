//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDR "speedtest.net"

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *message;
    int numbytes;
    int total_bytes_received = 0;
    double start_time, end_time, elapsed_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    message = "GET /speedtest.php HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n";

    send(sockfd, message, strlen(message), 0);

    while ((numbytes = recv(sockfd, message, BUFFER_SIZE, 0)) > 0) {
        total_bytes_received += numbytes;
    }

    close(sockfd);

    start_time = difftime(time(NULL), start_time);
    elapsed_time = start_time;

    printf("Total bytes received: %d\n", total_bytes_received);
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    return 0;
}