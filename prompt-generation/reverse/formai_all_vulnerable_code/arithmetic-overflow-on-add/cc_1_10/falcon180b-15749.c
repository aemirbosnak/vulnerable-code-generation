//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000
#define MAX_DIGITS 1000

int main() {
    int numbers[MAX_NUMBERS];
    int count = 0;
    int i, j;
    int num1 = 0, num2 = 1, nextTerm;
    srand(time(NULL));

    // Initialize the first two terms of the sequence
    numbers[count++] = num1;
    numbers[count++] = num2;

    // Generate the rest of the sequence
    for (i = 2; i < MAX_NUMBERS; i++) {
        nextTerm = num1 + num2;
        numbers[count++] = nextTerm;
        num1 = num2;
        num2 = nextTerm;
    }

    // Print the sequence
    printf("Fibonacci Sequence:\n");
    for (j = 0; j < count; j++) {
        printf("%d ", numbers[j]);
    }
    printf("\n");

    // Visualize the sequence
    for (j = 0; j < count; j++) {
        int k = 0;
        while (numbers[j] % 10 == 0) {
            numbers[j] /= 10;
            k++;
        }
        while (k < MAX_DIGITS) {
            printf(" ");
            k++;
        }
        printf("%d ", numbers[j]);
    }
    printf("\n");

    return 0;
}