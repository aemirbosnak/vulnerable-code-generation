//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

struct thread_data {
    char* date_string;
    int thread_id;
};

void* convert_date(void* arg) {
    struct thread_data* data = (struct thread_data*) arg;

    char* date_str = data->date_string;
    int thread_id = data->thread_id;

    char month[4] = {0};
    char day[3] = {0};
    char year[5] = {0};

    sscanf(date_str, "%s %s, %s", month, day, year);

    printf("Thread %d: Converted date: %s %s, %s\n", thread_id, month, day, year);

    return NULL;
}

int main() {
    int num_threads;
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[MAX_THREADS];
    struct thread_data data[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        printf("Enter date string for thread %d: ", i+1);
        scanf("%s", data[i].date_string);
        data[i].thread_id = i+1;

        int ret = pthread_create(&threads[i], NULL, convert_date, (void*) &data[i]);
        if (ret!= 0) {
            printf("Error: Unable to create thread %d\n", i+1);
            exit(1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        int ret = pthread_join(threads[i], NULL);
        if (ret!= 0) {
            printf("Error: Unable to join thread %d\n", i+1);
            exit(1);
        }
    }

    return 0;
}