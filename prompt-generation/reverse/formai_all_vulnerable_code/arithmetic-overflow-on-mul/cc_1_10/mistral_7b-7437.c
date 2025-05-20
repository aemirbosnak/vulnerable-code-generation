//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: expert-level
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define SERVER_ADDRESS "192.168.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define DATA_SIZE 1024

int main(void) {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE], data[DATA_SIZE], *result = NULL;
    struct timeval start, end;
    double elapsed_time, throughput;
    size_t len;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&start, NULL);

    len = write(sockfd, "GET /speedtest.bin\r\nHost: Localhost\r\nConnection: close\r\n\r\n", 58);
    if (len < 0) {
        perror("writing to socket failed");
        exit(EXIT_FAILURE);
    }

    len = read(sockfd, data, DATA_SIZE);
    if (len < 0) {
        perror("reading from socket failed");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&end, NULL);
    elapsed_time = (end.tv_sec * 1000) + (end.tv_usec / 1000.0);
    throughput = (double)len / (elapsed_time / 1000.0);

    printf("Downloaded %ld bytes in %.3f ms, throughput: %.2f MB/s\n", len, elapsed_time / 1000.0, throughput / (1024.0 * 1024.0));

    close(sockfd);

    return EXIT_SUCCESS;
}

// speedtest.bin file content:
// Content-Length: 1024
//

// This is a simple C Internet Speed Test Application example program. It connects to a server,
// sends a GET request for a binary file and reads the response data. The time taken to download
// the data and the throughput are calculated and printed to the console.