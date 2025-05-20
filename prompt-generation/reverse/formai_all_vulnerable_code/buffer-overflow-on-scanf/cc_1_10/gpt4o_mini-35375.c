//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_NUMBERS 100
#define MAX_THREADS 10

typedef struct {
    int *numbers;
    int start;
    int end;
} ThreadData;

void *convert_to_hex(void *data) {
    ThreadData *td = (ThreadData *)data;
    
    for (int i = td->start; i < td->end; ++i) {
        printf("Decimal: %d -> Hexadecimal: %X\n", td->numbers[i], td->numbers[i]);
    }
    
    return NULL;
}

void create_threads(int *numbers, int num_count) {
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    int numbers_per_thread = num_count / MAX_THREADS;
    
    for (int i = 0; i < MAX_THREADS; ++i) {
        thread_data[i].numbers = numbers;
        thread_data[i].start = i * numbers_per_thread;
        
        // Ensure the last thread processes all remaining numbers
        if (i == MAX_THREADS - 1) {
            thread_data[i].end = num_count;
        } else {
            thread_data[i].end = (i + 1) * numbers_per_thread;
        }

        if (pthread_create(&threads[i], NULL, convert_to_hex, (void *)&thread_data[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < MAX_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    int *numbers = malloc(MAX_NUMBERS * sizeof(int));
    if (!numbers) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    int num_count;
    printf("Enter the number of decimal numbers to convert (max %d): ", MAX_NUMBERS);
    scanf("%d", &num_count);

    if (num_count > MAX_NUMBERS || num_count <= 0) {
        fprintf(stderr, "Invalid number count. Must be between 1 and %d.\n", MAX_NUMBERS);
        free(numbers);
        return EXIT_FAILURE;
    }

    printf("Enter %d decimal numbers:\n", num_count);
    for (int i = 0; i < num_count; i++) {
        scanf("%d", &numbers[i]);
    }

    create_threads(numbers, num_count);

    free(numbers);
    return EXIT_SUCCESS;
}