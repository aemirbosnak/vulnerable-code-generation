//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000

int main() {
    int num1 = 0, num2 = 1, nextTerm = 0, termCount = 0;
    int maxTerm = 0;
    int *fibonacci = NULL;
    int input;

    srand(time(NULL));

    // Prompt user for number of terms to generate
    printf("Enter the number of terms to generate: ");
    scanf("%d", &input);

    // Validate user input
    if (input <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Allocate memory for Fibonacci sequence
    fibonacci = (int*) malloc(input * sizeof(int));
    if (fibonacci == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Generate Fibonacci sequence
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    termCount = 2;

    while (termCount < input) {
        nextTerm = fibonacci[termCount - 1] + fibonacci[termCount - 2];

        if (nextTerm > MAX_NUM) {
            printf("Maximum number of terms reached.\n");
            break;
        }

        fibonacci[termCount] = nextTerm;
        termCount++;
    }

    // Print Fibonacci sequence
    printf("\nFibonacci sequence:\n");
    for (int i = 0; i < termCount; i++) {
        printf("%d ", fibonacci[i]);
    }

    free(fibonacci);
    return 0;
}