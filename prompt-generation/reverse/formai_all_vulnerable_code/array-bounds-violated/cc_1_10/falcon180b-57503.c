//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_NUMBERS 100

int numbers[MAX_NUMBERS];
int num_threads = 0;
int num_numbers = 0;

void *generate_numbers(void *arg) {
    int start = *(int *) arg;
    int end = start + 10;

    for (int i = start; i < end; i++) {
        if (num_numbers >= MAX_NUMBERS) {
            break;
        }

        if (i == 1 || i == 2) {
            numbers[num_numbers++] = i;
        } else {
            int prev1 = numbers[num_numbers - 1];
            int prev2 = numbers[num_numbers - 2];

            numbers[num_numbers++] = prev1 + prev2;
        }
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        int start = rand() % 100;
        pthread_create(&threads[i], NULL, generate_numbers, &start);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Fibonacci numbers:\n");
    for (int i = 0; i < num_numbers; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}