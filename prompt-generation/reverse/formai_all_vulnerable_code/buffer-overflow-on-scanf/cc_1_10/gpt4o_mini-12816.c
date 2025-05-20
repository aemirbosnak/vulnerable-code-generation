//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_NUMBERS 100
#define MAX_BIN_LENGTH 32

typedef struct {
    int decimalNumber;
    char binaryString[MAX_BIN_LENGTH];
} ThreadData;

void* convertToBinary(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int n = data->decimalNumber;
    char* binStr = data->binaryString;
    int index = 0;

    if (n == 0) {
        strcpy(binStr, "0");
        return NULL;
    }

    while (n > 0) {
        binStr[index++] = (n % 2) + '0'; // get the last binary digit
        n /= 2; // divide the number by 2
    }
    
    binStr[index] = '\0';
    
    // Reverse the string to obtain the correct binary representation
    for (int i = 0; i < index / 2; i++) {
        char temp = binStr[i];
        binStr[i] = binStr[index - 1 - i];
        binStr[index - 1 - i] = temp;
    }
    
    return NULL;
}

void* processInput(void* arg) {
    int* numbers = (int*)arg;
    pthread_t threads[MAX_NUMBERS];
    ThreadData threadData[MAX_NUMBERS];

    for (int i = 0; numbers[i] != -1; i++) {
        threadData[i].decimalNumber = numbers[i];
        pthread_create(&threads[i], NULL, convertToBinary, &threadData[i]);
    }

    for (int i = 0; numbers[i] != -1; i++) {
        pthread_join(threads[i], NULL);
        printf("Decimal: %d, Binary: %s\n", threadData[i].decimalNumber, threadData[i].binaryString);
    }

    return NULL;
}

int main() {
    pthread_t inputThread;
    int numbers[MAX_NUMBERS];

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Enter decimal numbers (type -1 to end input):\n");

    for (int i = 0; i < MAX_NUMBERS; i++) {
        scanf("%d", &numbers[i]);
        if (numbers[i] == -1) {
            break;
        }
    }
    
    // Create a thread to process the input
    pthread_create(&inputThread, NULL, processInput, numbers);

    // Wait for the input thread to finish
    pthread_join(inputThread, NULL);

    printf("All conversions completed!\n");
    return 0;
}