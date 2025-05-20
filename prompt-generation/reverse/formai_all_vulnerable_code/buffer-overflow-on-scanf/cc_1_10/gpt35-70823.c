//FormAI DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <pthread.h>

#define MAX_INPUT_LENGTH 50
#define BINARY_BASE 2

typedef struct {
    int decimalNumber;
    char binaryString[MAX_INPUT_LENGTH];
} BinaryConversion;

void *convertToBinary(void *arg) {
    BinaryConversion *conversion = (BinaryConversion *)arg;

    int quotient = conversion->decimalNumber;
    int remainder, i = 0;

    while (quotient != 0) {
        remainder = quotient % BINARY_BASE;
        conversion->binaryString[i++] = remainder + '0';
        quotient = quotient / BINARY_BASE;
    }

    conversion->binaryString[i] = '\0';

    int length = strlen(conversion->binaryString);

    for (int j = 0; j < length/2; j++) {
        char temp = conversion->binaryString[j];
        conversion->binaryString[j] = conversion->binaryString[length-1-j];
        conversion->binaryString[length-1-j] = temp;
    }

    pthread_exit(NULL);
}

int main() {
    BinaryConversion conversions[MAX_INPUT_LENGTH];
    char input[MAX_INPUT_LENGTH];
    uint64_t numConversions;

    printf("Enter the number of conversions: ");
    scanf("%lu", &numConversions);

    if (numConversions > MAX_INPUT_LENGTH) {
        printf("Maximum number of conversions is %d\n", MAX_INPUT_LENGTH);
        exit(1);
    }

    printf("Enter %lu decimal numbers to convert to binary:\n", numConversions);

    for (int i = 0; i < numConversions; i++) {
        printf("[%d]: ", i+1);
        scanf("%d", &conversions[i].decimalNumber);
    }

    printf("Converting...\n");

    pthread_t threads[MAX_INPUT_LENGTH];
    int errorCheck;

    for (int i = 0; i < numConversions; i++) {
        errorCheck = pthread_create(&threads[i], NULL, convertToBinary, &conversions[i]);

        if (errorCheck != 0) {
            printf("Error creating thread: %d\n", errorCheck);
            exit(1);
        }
    }

    for (int i = 0; i < numConversions; i++) {
        errorCheck = pthread_join(threads[i], NULL);

        if (errorCheck != 0) {
            printf("Error joining thread: %d\n", errorCheck);
            exit(1);
        }
    }

    printf("Binary conversions:\n");

    for (int i = 0; i < numConversions; i++) {
        printf("%d: %s\n", conversions[i].decimalNumber, conversions[i].binaryString);
    }

    return 0;
}