//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_NUMBERS 100
#define BUFFER_SIZE 10

// Struct for passing data to threads
typedef struct {
    int number;
    char hexString[BUFFER_SIZE];
} ThreadData;

// Function to convert decimal to hexadecimal
void *decimalToHex(void *arg) {
    ThreadData *data = (ThreadData *)arg;  
    sprintf(data->hexString, "%X", data->number);  
    pthread_exit(NULL);
}

// Function to display numbers and their hexadecimal equivalents
void displayResults(ThreadData *data, int count) {
    printf("\nDecimal to Hexadecimal Conversion:\n");
    printf("----------------------------------\n");
    for(int i = 0; i < count; i++) {
        printf("Decimal: %d | Hexadecimal: %s\n", data[i].number, data[i].hexString);
    }
    printf("----------------------------------\n");
}

int main() {
    int count;
    ThreadData data[MAX_NUMBERS];
    pthread_t threads[MAX_NUMBERS];

    // Input the number of elements
    printf("Enter the number of decimal numbers to convert (max %d): ", MAX_NUMBERS);
    scanf("%d", &count);

    if (count > MAX_NUMBERS || count <= 0) {
        printf("Invalid number of entries. Please enter a number between 1 and %d.\n", MAX_NUMBERS);
        return 1;
    }

    // Read the decimal numbers from the user
    for(int i = 0; i < count; i++) {
        printf("Enter decimal number %d: ", i + 1);
        scanf("%d", &data[i].number);
        data[i].hexString[0] = '\0';  // Initialize hexString
    }

    // Create threads to perform conversion
    for(int i = 0; i < count; i++) {
        if(pthread_create(&threads[i], NULL, decimalToHex, (void *)&data[i]) != 0) {
            perror("Error creating thread");
            return 1;
        }
    }

    // Wait for all threads to finish
    for(int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display results
    displayResults(data, count);

    return 0;
}