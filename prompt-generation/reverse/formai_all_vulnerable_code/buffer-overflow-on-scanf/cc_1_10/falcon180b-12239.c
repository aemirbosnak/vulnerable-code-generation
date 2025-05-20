//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

typedef struct {
    int num;
    int *fibonacci;
} fibonacci_data;

// Function to calculate the Fibonacci sequence
void *fibonacci(void *param) {
    fibonacci_data *data = (fibonacci_data *) param;
    int i, j, n = data->num;
    if (n <= 1) {
        data->fibonacci[0] = n;
        return NULL;
    }
    data->fibonacci[0] = 0;
    data->fibonacci[1] = 1;
    for (i = 2; i < n; i++) {
        data->fibonacci[i] = data->fibonacci[i - 1] + data->fibonacci[i - 2];
    }
    return NULL;
}

int main() {
    int num, i, j, start = 0, end = 0, count = 0;
    pthread_t threads[100];
    fibonacci_data data[100];
    sem_t mutex;

    // Initialize semaphore
    sem_init(&mutex, 0, 1);

    // Get user input
    printf("Enter the number of Fibonacci numbers you want to generate: ");
    scanf("%d", &num);

    // Check if input is valid
    if (num <= 0) {
        printf("Invalid input.\n");
        exit(0);
    }

    // Create threads and pass data to them
    for (i = 0; i < num; i++) {
        data[i].num = i + 1;
        data[i].fibonacci = (int *) malloc(sizeof(int) * (i + 1));
        pthread_create(&threads[i], NULL, fibonacci, (void *) &data[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < num; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the Fibonacci sequence
    printf("Fibonacci sequence:\n");
    for (i = 0; i < num; i++) {
        for (j = 0; j <= data[i].num; j++) {
            printf("%d ", data[i].fibonacci[j]);
        }
        printf("\n");
    }

    return 0;
}