//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <time.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n, i;
    struct sockaddr_in servaddr;
    char buf[BUF_SIZE];
    struct pollfd fds[2];
    int timeout = 1000; // 1 second timeout
    int bytes_sent = 0;
    int bytes_received = 0;
    int start_time, end_time;
    double elapsed_time;
    double speed;

    if (argc != 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Set up the poll fds
    fds[0].fd = sockfd;
    fds[0].events = POLLIN;
    fds[1].fd = 0; // stdin
    fds[1].events = POLLIN;

    // Start the timer
    start_time = time(NULL);

    // Main loop
    while (1) {
        // Poll the fds
        if (poll(fds, 2, timeout) == -1) {
            perror("poll");
            exit(EXIT_FAILURE);
        }

        // Check if there is data to read from the socket
        if (fds[0].revents & POLLIN) {
            // Read the data from the socket
            n = read(sockfd, buf, BUF_SIZE);
            if (n == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // Update the bytes received counter
            bytes_received += n;
        }

        // Check if there is data to write to the socket
        if (fds[1].revents & POLLIN) {
            // Read the data from stdin
            n = read(0, buf, BUF_SIZE);
            if (n == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // Update the bytes sent counter
            bytes_sent += n;

            // Write the data to the socket
            if (write(sockfd, buf, n) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        // Check if the timeout has been reached
        end_time = time(NULL);
        elapsed_time = difftime(end_time, start_time);
        if (elapsed_time >= timeout) {
            break;
        }
    }

    // Stop the timer
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    // Calculate the speed
    speed = (double)bytes_received / elapsed_time;

    // Print the results
    printf("Bytes sent: %d\n", bytes_sent);
    printf("Bytes received: %d\n", bytes_received);
    printf("Elapsed time: %f seconds\n", elapsed_time);
    printf("Speed: %f bytes/second\n", speed);

    // Close the socket
    close(sockfd);

    return 0;
}