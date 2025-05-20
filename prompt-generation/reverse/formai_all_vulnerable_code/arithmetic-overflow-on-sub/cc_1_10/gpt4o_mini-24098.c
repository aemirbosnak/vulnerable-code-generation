//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define SERVER_ADDR "download.speedtest.net" // An example speed test server
#define PORT 80
#define FILE_PATH "/speedtest/random4000x4000.jpg" // A sample file for speed test
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void test_download_speed(const char *hostname) {
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    FILE *fp;

    clock_t start, end;
    double cpu_time_used;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    // Sending HTTP GET request
    snprintf(buffer, sizeof(buffer), 
             "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", 
             FILE_PATH, hostname);
    
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) 
        error("ERROR sending request");

    fp = fopen("speedtest_output.jpg", "wb");
    if (!fp) {
        perror("Could not open file to write.");
        close(sockfd);
        return;
    }

    // Start timing download
    start = clock();

    // Read response and write to file
    while ((bytes_read = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, fp);
    }

    // Check for errors during receive
    if (bytes_read < 0) 
        error("ERROR reading from socket");

    // End timing
    end = clock();

    // Calculate download time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Download completed! File saved as `speedtest_output.jpg`\n");
    printf("Download time = %f seconds\n", cpu_time_used);

    // Clean up
    fclose(fp);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    printf("=== C Internet Speed Test Application ===\n");
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        printf("Example: %s " SERVER_ADDR "\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    test_download_speed(hostname);

    return 0;
}