//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_NUMBERS 100000

int numbers[MAX_NUMBERS];
int search_number;
int found = 0;

void *search_thread(void *arg) {
    int start = *(int *) arg;
    int end = start + MAX_NUMBERS / MAX_THREADS;

    for (int i = start; i < end; i++) {
        if (numbers[i] == search_number) {
            found = 1;
            pthread_exit(NULL);
        }
    }

    pthread_exit(NULL);
}

int main() {
    int i, num_threads;
    pthread_t threads[MAX_THREADS];

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the search number: ");
    scanf("%d", &search_number);

    srand(time(NULL));

    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand() % 10000;
    }

    int chunk_size = MAX_NUMBERS / num_threads;

    for (i = 0; i < num_threads; i++) {
        int start = i * chunk_size;
        int end = (i == num_threads - 1)? MAX_NUMBERS : (i + 1) * chunk_size;

        pthread_create(&threads[i], NULL, search_thread, &start);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    if (found) {
        printf("Number found!\n");
    } else {
        printf("Number not found.\n");
    }

    return 0;
}