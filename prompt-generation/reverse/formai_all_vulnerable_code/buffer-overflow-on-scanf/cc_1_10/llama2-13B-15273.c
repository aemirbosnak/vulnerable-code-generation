//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MIN_VALUE -100
#define MAX_VALUE 100

int main() {
    // Declare variables to store the binary representation
    int binary[MAX_LENGTH];
    int i;

    // Declare a random number to convert
    int number = (rand() % 100) + MIN_VALUE;

    // Convert the number to binary
    for (i = 0; i < MAX_LENGTH; i++) {
        binary[i] = number % 2;
        number /= 2;
    }

    // Print the binary representation
    for (i = 0; i < MAX_LENGTH; i++) {
        printf("%d", binary[i]);
        if (i != MAX_LENGTH - 1) {
            printf(" ");
        }
    }

    // Print a happy message
    printf("\nHappy Binary Conversion! 😊\n");

    // Get the user's input and convert it to binary
    printf("Enter a number to convert: ");
    scanf("%d", &number);
    for (i = 0; i < MAX_LENGTH; i++) {
        binary[i] = number % 2;
        number /= 2;
    }

    // Print the binary representation
    for (i = 0; i < MAX_LENGTH; i++) {
        printf("%d", binary[i]);
        if (i != MAX_LENGTH - 1) {
            printf(" ");
        }
    }

    return 0;
}