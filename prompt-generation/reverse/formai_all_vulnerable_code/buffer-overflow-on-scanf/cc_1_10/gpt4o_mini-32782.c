//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_NUMBERS 50

typedef struct {
    int decimalNumber;
    char binaryRepresentation[32]; // support up to 32-bit integer
} ThreadData;

// Function to convert decimal to binary
void* convertToBinary(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int num = data->decimalNumber;
    int index = 31;  // Start filling binary representation from the end
    data->binaryRepresentation[index + 1] = '\0'; // Null-terminate the string

    // Special case for zero
    if (num == 0) {
        data->binaryRepresentation[index] = '0';
        return NULL;
    }

    while (num > 0) {
        data->binaryRepresentation[index--] = (num % 2) ? '1' : '0';
        num /= 2;
    }
    
    // Fill left side with '0's
    while (index >= 0) {
        data->binaryRepresentation[index--] = '0';
    }

    return NULL;
}

void printBinary(int decimal) {
    ThreadData data;
    data.decimalNumber = decimal;

    pthread_t thread;
    pthread_create(&thread, NULL, convertToBinary, &data);
    pthread_join(thread, NULL);

    printf("Decimal: %d, Binary: %s\n", data.decimalNumber, data.binaryRepresentation);
}

int main() {
    int decimalNumbers[MAX_NUMBERS];
    int count = 0;

    printf("Enter up to %d decimal numbers (enter -1 to stop):\n", MAX_NUMBERS);
    
    // Input decimal numbers
    while (count < MAX_NUMBERS) {
        int num;
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        decimalNumbers[count++] = num;
    }

    // Create threads for conversion
    for (int i = 0; i < count; i++) {
        printBinary(decimalNumbers[i]);
    }

    return 0;
}