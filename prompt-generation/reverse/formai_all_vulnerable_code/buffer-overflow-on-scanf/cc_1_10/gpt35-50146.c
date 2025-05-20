//FormAI DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

typedef struct {
    char binary[BUFFER_SIZE];
    int decimal;
} Conversion;

// Thread function to convert decimal to binary
void *convertToBinary(void *arg) {
    Conversion *conversion = (Conversion *) arg;
    int decimal = conversion->decimal;
    int index = BUFFER_SIZE - 1;
    while (decimal > 0 && index >= 0) {
        conversion->binary[index--] = (decimal % 2) + '0';
        decimal /= 2;
    }
    conversion->binary[BUFFER_SIZE - 1] = '\0';
    pthread_exit(NULL);
}

// Thread function to convert binary to decimal
void *convertToDecimal(void *arg) {
    Conversion *conversion = (Conversion *) arg;
    char *binary = conversion->binary;
    int decimal = 0, index = 0;
    while (binary[index] != '\0' && index < BUFFER_SIZE) {
        decimal = decimal * 2 + (binary[index++] - '0');
    }
    conversion->decimal = decimal;
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    Conversion conversion;

    printf("Enter a decimal number: ");
    scanf("%d", &conversion.decimal);

    // Create thread to convert decimal to binary
    if (pthread_create(&thread1, NULL, convertToBinary, &conversion)) {
        printf("Error creating thread1\n");
        return 1;
    }

    // Create thread to convert binary to decimal
    if (pthread_create(&thread2, NULL, convertToDecimal, &conversion)) {
        printf("Error creating thread2\n");
        return 1;
    }

    // Wait for both threads to finish
    if (pthread_join(thread1, NULL)) {
        printf("Error joining thread1\n");
        return 1;
    }
    if (pthread_join(thread2, NULL)) {
        printf("Error joining thread2\n");
        return 1;
    }

    printf("Binary: %s\nDecimal: %d\n", conversion.binary, conversion.decimal);
    return 0;
}