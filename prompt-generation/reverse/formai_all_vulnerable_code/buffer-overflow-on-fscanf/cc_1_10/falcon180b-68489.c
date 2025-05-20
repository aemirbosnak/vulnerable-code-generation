//Falcon-180B DATASET v1.0 Category: Data mining ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_NUMBERS 1000
#define MAX_VALUE 100

int numbers[MAX_NUMBERS];
int max_value = 0;
int min_value = MAX_VALUE;
int sum = 0;
int count = 0;

void *thread_func(void *param) {
    int start = *(int *) param;
    int end = start + MAX_NUMBERS / NUM_THREADS;

    for (int i = start; i < end; i++) {
        if (numbers[i] > max_value) {
            max_value = numbers[i];
        }
        if (numbers[i] < min_value) {
            min_value = numbers[i];
        }
        sum += numbers[i];
        count++;
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

    for (i = 0; i < MAX_NUMBERS && fscanf(fp, "%d", &numbers[i])!= EOF; i++) {
        if (numbers[i] > max_value) {
            max_value = numbers[i];
        }
        if (numbers[i] < min_value) {
            min_value = numbers[i];
        }
        sum += numbers[i];
        count++;
    }

    fclose(fp);

    pthread_t threads[NUM_THREADS];
    int thread_params[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        thread_params[i] = i * MAX_NUMBERS / NUM_THREADS;
        pthread_create(&threads[i], NULL, thread_func, &thread_params[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Max value: %d\n", max_value);
    printf("Min value: %d\n", min_value);
    printf("Sum: %d\n", sum);
    printf("Count: %d\n", count);

    return 0;
}