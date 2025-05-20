//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <time.h>

#define SERVER_ADDR "192.168.1.1"
#define SERVER_PORT 8080
#define BUF_SIZE 1024

// Global variables
int sockfd;
struct sockaddr_in server_addr;
uint8_t *buf;
size_t buf_len;
pthread_t thread;
int bytes_sent;
int bytes_received;
clock_t start_time;
clock_t end_time;

// Thread function
void *thread_func(void *arg) {
    while (1) {
        // Send data to the server
        bytes_sent += send(sockfd, buf, buf_len, 0);

        // Receive data from the server
        bytes_received += recv(sockfd, buf, buf_len, 0);
    }

    return NULL;
}

int main() {
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Allocate a buffer for the data
    buf = malloc(BUF_SIZE);
    if (buf == NULL) {
        perror("malloc");
        exit(1);
    }

    // Set the buffer length
    buf_len = BUF_SIZE;

    // Create a thread to send and receive data
    if (pthread_create(&thread, NULL, thread_func, NULL) != 0) {
        perror("pthread_create");
        exit(1);
    }

    // Start the timer
    start_time = clock();

    // Run the test for 10 seconds
    sleep(10);

    // Stop the timer
    end_time = clock();

    // Calculate the elapsed time
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the throughput
    double throughput = (double)(bytes_sent + bytes_received) / elapsed_time / 1024 / 1024;

    // Print the results
    printf("Throughput: %.2f Mbps\n", throughput);

    // Close the socket
    close(sockfd);

    // Free the buffer
    free(buf);

    return 0;
}