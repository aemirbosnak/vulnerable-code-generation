//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_INPUT 100

typedef struct {
    int decimal;
    char hex[20];
} Conversion;

// Function to convert a decimal number to hexadecimal
void* convertToHex(void* arg) {
    Conversion* conv = (Conversion*) arg;
    sprintf(conv->hex, "%X", conv->decimal);
    return NULL;
}

// Function to read inputs and create threads for conversion
void readAndConvert() {
    int n;
    printf("Enter the number of decimal values you want to convert: ");
    scanf("%d", &n);
    
    if (n > MAX_INPUT) {
        printf("Maximum limit is %d.\n", MAX_INPUT);
        return;
    }
    
    Conversion conversions[MAX_INPUT];
    pthread_t threads[MAX_INPUT];

    for (int i = 0; i < n; i++) {
        printf("Enter decimal number %d: ", i + 1);
        scanf("%d", &conversions[i].decimal);
        // Create a thread to convert the decimal to hexadecimal
        if (pthread_create(&threads[i], NULL, convertToHex, &conversions[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
        printf("Decimal: %d => Hexadecimal: %s\n", conversions[i].decimal, conversions[i].hex);
    }
}

// Entry point of the program
int main() {
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    readAndConvert();
    printf("Conversion complete. Thank you!\n");
    return 0;
}