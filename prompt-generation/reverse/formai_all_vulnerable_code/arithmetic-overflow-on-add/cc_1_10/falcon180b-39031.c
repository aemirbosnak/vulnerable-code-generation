//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int num_threads = 0;
pthread_t threads[MAX_THREADS];
int thread_results[MAX_THREADS];

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        thread_results[num_threads] = 1;
    } else {
        thread_results[num_threads] = 0;
    }
    close(sock);
    return NULL;
}

int main() {
    int start_port, end_port;
    printf("Enter start port: ");
    scanf("%d", &start_port);
    printf("Enter end port: ");
    scanf("%d", &end_port);

    for (int i = start_port; i <= end_port; i++) {
        pthread_create(&threads[num_threads], NULL, scan_port, (void *) &i);
        num_threads++;
        if (num_threads == MAX_THREADS) {
            for (int j = 0; j < num_threads; j++) {
                pthread_join(threads[j], NULL);
            }
            num_threads = 0;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scan complete.\n");
    return 0;
}