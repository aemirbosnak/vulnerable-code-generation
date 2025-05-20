//Falcon-180B DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_REQUESTS 100
#define MAX_REQUEST_SIZE 1024

typedef struct {
    char ip[16];
    int port;
    char request[MAX_REQUEST_SIZE];
} request_t;

void *handle_request(void *arg) {
    request_t *request = (request_t *) arg;
    printf("Received request from %s:%d - %s\n", request->ip, request->port, request->request);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, num_threads = 0;

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, handle_request, NULL);
        num_threads++;
    }

    while (1) {
        request_t request;
        memset(&request, 0, sizeof(request_t));

        printf("Enter IP address: ");
        scanf("%s", request.ip);

        printf("Enter port number: ");
        scanf("%d", &request.port);

        printf("Enter request: ");
        scanf("%s", request.request);

        if (num_threads >= MAX_THREADS) {
            printf("Maximum number of threads reached. Please try again later.\n");
        } else {
            pthread_join(threads[num_threads], NULL);
            num_threads++;
            printf("Request sent to thread %d\n", num_threads - 1);
        }
    }

    return 0;
}