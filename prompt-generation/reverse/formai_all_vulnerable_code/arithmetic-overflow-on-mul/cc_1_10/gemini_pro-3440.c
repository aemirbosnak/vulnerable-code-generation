//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }
    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZE];
    int bytes_sent = 0;
    int bytes_received = 0;
    int total_bytes = 0;
    time_t start_time = time(NULL);
    while (1) {
        int bytes_read = recv(sockfd, buf, BUFSIZE, 0);
        if (bytes_read == 0) {
            break;
        }
        bytes_received += bytes_read;
        total_bytes += bytes_read;
        int bytes_written = send(sockfd, buf, bytes_read, 0);
        if (bytes_written == 0) {
            break;
        }
        bytes_sent += bytes_written;
        total_bytes += bytes_written;
    }
    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);
    double speed = (total_bytes * 8) / (elapsed_time * 1000);
    printf("Speed: %f kbps\n", speed);

    close(sockfd);
    return 0;
}