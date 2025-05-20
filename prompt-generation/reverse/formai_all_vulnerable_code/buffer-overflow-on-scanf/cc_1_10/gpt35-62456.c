//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5001
#define BUFFER_SIZE 1024
#define MB_TO_BYTES 1000000

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int num_mb, i;
    struct timeval t1, t2;

    if(argc < 2) {
        printf("Usage: %s <server-ip-address>\n", argv[0]);
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Could not create socket");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton error");
        return -1;
    }

    if(connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connect failed");
        return -1;
    }

    printf("Enter number of MB to download: ");
    scanf("%d", &num_mb);
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "%d", num_mb);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);

    gettimeofday(&t1, NULL);

    for(i=0; i<num_mb; i++) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if(bytes_received < 0) {
            perror("Error receiving data");
            return -1;
        }
        fwrite(buffer, sizeof(char), bytes_received, stdout);
    }

    gettimeofday(&t2, NULL);

    long long elapsed_time = (t2.tv_sec - t1.tv_sec) * 1000000LL + t2.tv_usec - t1.tv_usec;
    double speed = (double) (num_mb * MB_TO_BYTES) / elapsed_time;
    printf("\nDownloaded %d MB in %.2f seconds at %.2f MB/s\n", num_mb, (double) elapsed_time / 1000000, speed);

    close(sockfd);

    return 0;
}