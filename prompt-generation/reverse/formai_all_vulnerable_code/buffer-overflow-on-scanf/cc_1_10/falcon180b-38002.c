//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100

// Function to scan a single port
void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
    int ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (ret == 0) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }
    close(sock);
    return NULL;
}

int main() {
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);
    if (num_threads > MAX_THREADS) {
        printf("Error: Number of threads exceeds the limit\n");
        return 1;
    }
    pthread_t threads[num_threads];
    int ports[num_threads];
    printf("Enter the ports to scan (separated by space): ");
    scanf("%d", &ports[0]);
    for (int i = 1; i < num_threads; i++) {
        scanf("%d", &ports[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, &ports[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}