//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "speedtest.net"
#define SERVER_PORT 80

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    double start_time, end_time;
    double elapsed_time;
    int total_bytes_received = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        fprintf(stderr, "Error connecting to server\n");
        exit(2);
    }

    memset(send_buffer, 'a', BUFFER_SIZE);
    n = send(sockfd, send_buffer, BUFFER_SIZE, 0);

    if (n == -1) {
        fprintf(stderr, "Error sending data\n");
        exit(3);
    }

    start_time = difftime(time(NULL), time(NULL));

    while (1) {
        n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

        if (n <= 0) {
            break;
        }

        total_bytes_received += n;
    }

    end_time = difftime(time(NULL), time(NULL));
    elapsed_time = end_time - start_time;

    printf("Total bytes received: %d\n", total_bytes_received);
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    close(sockfd);

    return 0;
}