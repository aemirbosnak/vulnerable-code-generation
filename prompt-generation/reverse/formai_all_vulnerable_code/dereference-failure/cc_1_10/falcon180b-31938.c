//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100

// Function to check if a port is open or not
int check_port(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        printf("socket failed\n");
        exit(0);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
        close(sockfd);
        return 1;
    }
    close(sockfd);
    return 0;
}

// Function to create a new thread
void* thread_func(void* arg) {
    int port = *(int*)arg;
    if (check_port(port)) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }
    return NULL;
}

// Main function to start the port scanner
int main(int argc, char* argv[]) {
    if (argc <= 2) {
        printf("Usage:./port_scanner <start_port> <end_port>\n");
        exit(0);
    }
    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);
    int num_threads = 0;

    // Create a new thread for each port
    for (int i = start_port; i <= end_port; i++) {
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, thread_func, (void*)&i)!= 0) {
            printf("Thread creation failed\n");
            exit(0);
        }
        num_threads++;
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(NULL, NULL);
    }
    return 0;
}