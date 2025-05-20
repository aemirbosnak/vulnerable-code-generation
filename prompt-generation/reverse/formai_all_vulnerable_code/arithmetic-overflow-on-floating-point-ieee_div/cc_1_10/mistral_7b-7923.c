//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define SERVER_ADDRESS "192.168.0.1"
#define SERVER_PORT 12345
#define BUFFER_SIZE 1024
#define TIMEOUT 5000

typedef struct {
    float download_speed;
    float upload_speed;
} Bandwidth;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int sockfd, read_size;
    struct sockaddr_in server_addr;
    struct timeval start, end;
    char buffer[BUFFER_SIZE];
    Bandwidth bandwidth;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        die("socket creation error");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        die("connection failed");

    gettimeofday(&start, NULL);
    if (send(sockfd, "TEST", 4, 0) < 0)
        die("send error");

    read_size = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (read_size <= 0)
        die("recv error");

    gettimeofday(&end, NULL);
    long long elapsed = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;

    bandwidth.download_speed = (float)read_size / elapsed * 8;

    close(sockfd);

    printf("\n[ Post-Apocalyptic Internet Speed Test ]\n");
    printf("-------------------------------------------\n");
    printf("Download Speed: %.2f bps\n", bandwidth.download_speed);

    return 0;
}