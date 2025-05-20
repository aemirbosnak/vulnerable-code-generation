//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

int main(int argc, char *argv[]) {

    // Check for correct usage
    if(argc!= 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        fprintf(stderr, "ERROR: Could not open socket\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        fprintf(stderr, "ERROR: Connection failed\n");
        exit(EXIT_FAILURE);
    }

    // Send HTTP GET request
    char buffer[1024] = {0};
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    if(send(sockfd, buffer, strlen(buffer), 0) == -1) {
        fprintf(stderr, "ERROR: Send failed\n");
        exit(EXIT_FAILURE);
    }

    // Receive HTTP response
    char response[1024] = {0};
    int bytesRead = recv(sockfd, response, sizeof(response), 0);
    if(bytesRead == -1) {
        fprintf(stderr, "ERROR: Receive failed\n");
        exit(EXIT_FAILURE);
    }

    // Close socket
    close(sockfd);

    // Calculate download speed
    struct timeval start, end;
    gettimeofday(&start, NULL);
    if(waitpid(getpid(), 0, 0)!= 0) {
        fprintf(stderr, "ERROR: Failed to wait for child process\n");
        exit(EXIT_FAILURE);
    }
    gettimeofday(&end, NULL);
    double duration = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Convert response to bytes
    int responseSize = atoi(strtok(response, "\r\n"));

    // Calculate download speed in Mbps
    double downloadSpeed = (responseSize * 8) / (duration * 1000);
    printf("Download Speed: %f Mbps\n", downloadSpeed);

    // Calculate upload speed
    struct timeval start2, end2;
    gettimeofday(&start2, NULL);
    if(waitpid(getpid(), 0, 0)!= 0) {
        fprintf(stderr, "ERROR: Failed to wait for child process\n");
        exit(EXIT_FAILURE);
    }
    gettimeofday(&end2, NULL);
    double duration2 = (end2.tv_sec - start2.tv_sec) + (end2.tv_usec - start2.tv_usec) / 1000000.0;

    // Convert response to bytes
    int responseSize2 = atoi(strtok(response, "\r\n"));

    // Calculate upload speed in Mbps
    double uploadSpeed = (responseSize2 * 8) / (duration2 * 1000);
    printf("Upload Speed: %f Mbps\n", uploadSpeed);

    return 0;
}