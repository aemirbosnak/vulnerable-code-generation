//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <pthread.h>
#include <time.h>

// Constants
#define BUFFER_SIZE 4096
#define NUM_THREADS 4
#define TEST_DURATION 10 // in seconds

// Global variables
int sockfd;
struct sockaddr_in serveraddr;
uint64_t total_bytes_received = 0;
uint64_t total_bytes_sent = 0;
time_t start_time;
time_t end_time;

// Function prototypes
void *thread_function(void *arg);
void signal_handler(int signum);
void print_results();

int main(int argc, char *argv[]) {
    // Check if the user specified a server address
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the server address
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(80);
    if (inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) != 1) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Register signal handler
    signal(SIGINT, signal_handler);

    // Create threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return EXIT_FAILURE;
        }
    }

    // Print the results
    print_results();

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}

void *thread_function(void *arg) {
    // Get the current time
    start_time = time(NULL);

    // Send data to the server
    char buffer[BUFFER_SIZE];
    memset(buffer, 'a', BUFFER_SIZE);
    while (time(NULL) - start_time < TEST_DURATION) {
        ssize_t num_bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (num_bytes_sent == -1) {
            perror("send");
            return NULL;
        }

        total_bytes_sent += num_bytes_sent;
    }

    // Receive data from the server
    memset(buffer, 0, BUFFER_SIZE);
    while (time(NULL) - start_time < TEST_DURATION) {
        ssize_t num_bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (num_bytes_received == -1) {
            perror("recv");
            return NULL;
        }

        total_bytes_received += num_bytes_received;
    }

    return NULL;
}

void signal_handler(int signum) {
    // Get the current time
    end_time = time(NULL);

    // Print the results
    print_results();

    // Exit the program
    exit(EXIT_SUCCESS);
}

void print_results() {
    // Calculate the elapsed time
    double elapsed_time = difftime(end_time, start_time);

    // Calculate the download speed
    double download_speed = (double)total_bytes_received / elapsed_time / 1024.0 / 1024.0;

    // Calculate the upload speed
    double upload_speed = (double)total_bytes_sent / elapsed_time / 1024.0 / 1024.0;

    // Print the results
    printf("Download speed: %.2f Mbps\n", download_speed);
    printf("Upload speed: %.2f Mbps\n", upload_speed);
}