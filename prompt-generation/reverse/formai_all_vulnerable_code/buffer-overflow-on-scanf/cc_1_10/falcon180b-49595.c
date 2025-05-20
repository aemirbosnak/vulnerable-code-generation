//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

// Struct for storing thread data
struct thread_data {
    int thread_id;
    int port;
};

// Function for scanning a single port
void *scan_port(void *arg) {
    struct thread_data *data = arg;
    int port = data->port;
    int sock;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket on port %d\n", port);
        return NULL;
    }

    // Connect to port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Port %d is open\n", port);
        close(sock);
    }

    return NULL;
}

// Main function
int main() {
    int num_threads;
    int i;
    pthread_t threads[MAX_THREADS];

    // Get number of threads from user
    printf("Enter the number of threads (1-%d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    // Set port range
    int port_range = PORT_RANGE_MAX - PORT_RANGE_MIN + 1;
    int port_step = port_range / num_threads;

    // Create thread data
    struct thread_data data[MAX_THREADS];
    for (i = 0; i < num_threads; i++) {
        data[i].thread_id = i + 1;
        data[i].port = PORT_RANGE_MIN + i * port_step;
    }

    // Create threads
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, &data[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}