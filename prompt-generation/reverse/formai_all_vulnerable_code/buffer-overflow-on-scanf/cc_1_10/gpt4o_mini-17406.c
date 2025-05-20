//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_BITS 32
#define THREAD_COUNT 4

typedef struct {
    int number;
    char binary[MAX_BITS + 1];
} Conversion;

void* convert_to_binary(void* args) {
    Conversion *conversion = (Conversion *)args;
    int num = conversion->number;
    int index = 0;

    if (num == 0) {
        strcpy(conversion->binary, "0");
        return NULL;
    }

    while (num > 0 && index < MAX_BITS) {
        conversion->binary[MAX_BITS - 1 - index] = (num % 2) ? '1' : '0';
        num /= 2;
        index++;
    }
    conversion->binary[MAX_BITS - 1 - index] = '\0';
    return NULL;
}

void convert_single_threaded(int number) {
    Conversion conversion;
    conversion.number = number;
    convert_to_binary(&conversion);  // No need to create a thread for single-threaded
    printf("Decimal: %d, Binary: %s\n", conversion.number, conversion.binary);
}

void convert_multi_threaded(int number) {
    pthread_t threads[THREAD_COUNT];
    Conversion conversions[THREAD_COUNT];
    
    for (int i = 0; i < THREAD_COUNT; i++) {
        // Each thread will work with a different method to represent binary
        conversions[i].number = number >> (i * 8);  // Shift right for distributed computation
        conversions[i].binary[MAX_BITS] = '\0';  // Initialize binary string
        pthread_create(&threads[i], NULL, convert_to_binary, (void*)&conversions[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
        printf("Thread %d - Decimal: %d, Binary: %s\n", i, conversions[i].number, conversions[i].binary);
    }
}

int main() {
    int choice = 0, number = 0;

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Choose an option:\n");
    printf("1. Single-threaded conversion\n");
    printf("2. Multi-threaded conversion\n");
    printf("Enter your choice (1 or 2): ");
    
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice! Please enter 1 or 2.\n");
        return 1;
    }

    printf("Enter a decimal number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input! Please enter a valid number.\n");
        return 1;
    }

    switch (choice) {
        case 1:
            convert_single_threaded(number);
            break;
        case 2:
            convert_multi_threaded(number);
            break;
        default:
            printf("Unexpected error in choice.\n");
            break;
    }

    return 0;
}