//FormAI DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>

#define MAX_INPUT_SIZE 16

void* binary_conversion(void* args) {

    char* str = (char*)args;
    int decimal = atoi(str);

    printf("\n[Thread # %ld] Decimal representation of %s: %d\n", pthread_self(), str, decimal);

    int binary[MAX_INPUT_SIZE];
    int i = 0;

    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    printf("\n[Thread # %ld] Binary representation of %s: ", pthread_self(), str);

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }

    printf("\n");
    pthread_exit(NULL);
}

int main() {

    char* input[MAX_INPUT_SIZE];
    int num_threads;
    pthread_t threads[MAX_INPUT_SIZE];

    printf("Enter number of values you want to convert to binary: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_INPUT_SIZE) {
        printf("\nError: Maximum input size exceeded!");
        return EXIT_FAILURE;
    }

    printf("\nEnter %d values to convert to binary: ", num_threads);

    for (int i = 0; i < num_threads; i++) {
        input[i] = (char*)malloc(MAX_INPUT_SIZE * sizeof(char));
        scanf("%s", input[i]);
    }

    printf("\nCreating %d threads to convert %d values to binary...\n", num_threads, num_threads);

    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, binary_conversion, (void*)input[i])) {
            printf("\n[ERROR] Thread creation failed for value %s. Exiting...", input[i]);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nBinary conversion complete.\n");

    return EXIT_SUCCESS;
}