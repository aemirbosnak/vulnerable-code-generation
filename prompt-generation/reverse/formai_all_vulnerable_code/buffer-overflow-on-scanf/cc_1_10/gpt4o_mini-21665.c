//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_THREADS 50
#define PORT_RANGE 65535

int open_ports[PORT_RANGE];
int scan_port = 1;
pthread_mutex_t mutex;

void *port_scanner(void *arg) {
    int port;
    struct sockaddr_in server;
    int sockfd;

    while (1) {
        // Lock mutex to safely access shared variable
        pthread_mutex_lock(&mutex);
        port = scan_port;
        scan_port++;
        pthread_mutex_unlock(&mutex);

        if (port > PORT_RANGE) {
            break; // Exit when port range exceeds
        }

        // Create socket
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Socket creation failed");
            continue;
        }

        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to target IP
        server.sin_port = htons(port);

        // Set a timeout for the socket
        struct timeval tv;
        tv.tv_sec = 1; // 1 second
        tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);
        
        // Attempt to connect
        int connection_status = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
        if (connection_status == 0) {
            // If connection was successful
            printf("Port %d is open\n", port);
            open_ports[port] = 1; // Mark port as open
        }
        close(sockfd); // Close the socket
    }
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    pthread_mutex_init(&mutex, NULL);

    // Ask user for the number of threads to use
    int num_threads;
    printf("Enter the number of threads to use (Max: %d): ", MAX_THREADS);
    scanf("%d", &num_threads);
    
    // Ensure it does not exceed our limit
    if (num_threads > MAX_THREADS) {
        printf("Limiting to maximum number of threads: %d\n", MAX_THREADS);
        num_threads = MAX_THREADS;
    }

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, port_scanner, NULL);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the summary of open ports
    printf("\n--- Open Ports Summary ---\n");
    for (int i = 1; i < PORT_RANGE; i++) {
        if (open_ports[i]) {
            printf("Port %d is open!\n", i);
        }
    }

    // Cleanup
    pthread_mutex_destroy(&mutex);
    return 0;
}