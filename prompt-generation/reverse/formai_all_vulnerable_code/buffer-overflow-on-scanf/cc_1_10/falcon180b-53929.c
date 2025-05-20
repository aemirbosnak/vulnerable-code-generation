//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ROUTES 100
#define MAX_ROUTE_SIZE 100

typedef struct {
    int id;
    char *route;
} gps_thread_data_t;

void *gps_thread(void *arg) {
    gps_thread_data_t *data = arg;
    int i;

    for(i = 0; i < strlen(data->route); i++) {
        printf("Thread %d processing route: %c\n", data->id, data->route[i]);
        sleep(1);
    }

    return NULL;
}

int main() {
    int i, j, num_threads;
    pthread_t threads[MAX_THREADS];
    gps_thread_data_t data[MAX_THREADS];

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    for(i = 0; i < num_threads; i++) {
        printf("Enter route for thread %d: ", i+1);
        scanf("%s", data[i].route);
        data[i].id = i+1;
    }

    for(i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, gps_thread, &data[i]);
    }

    for(i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}