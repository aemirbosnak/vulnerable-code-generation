//Falcon-180B DATASET v1.0 Category: Data mining ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_NUMBERS 100000
#define MAX_VALUE 1000000

int numbers[MAX_NUMBERS];
int min_value = MAX_VALUE;
pthread_mutex_t min_mutex = PTHREAD_MUTEX_INITIALIZER;

void *find_min_value(void *arg) {
    int start_index = *(int *) arg;
    int end_index = start_index + MAX_NUMBERS / NUM_THREADS;

    for (int i = start_index; i < end_index; i++) {
        if (numbers[i] < min_value) {
            pthread_mutex_lock(&min_mutex);
            min_value = numbers[i];
            pthread_mutex_unlock(&min_mutex);
        }
    }

    return NULL;
}

int main() {
    FILE *fp;
    int i;

    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (i = 0; i < MAX_NUMBERS; i++) {
        fscanf(fp, "%d", &numbers[i]);
    }

    fclose(fp);

    pthread_t threads[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        int start_index = i * MAX_NUMBERS / NUM_THREADS;
        int end_index = (i + 1) * MAX_NUMBERS / NUM_THREADS;
        if (i == NUM_THREADS - 1) {
            end_index = MAX_NUMBERS - 1;
        }

        pthread_create(&threads[i], NULL, find_min_value, &start_index);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Minimum value: %d\n", min_value);

    return 0;
}