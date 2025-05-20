//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Recursive function to print the Fibonacci Sequence
void fibonacci(int num1, int num2, int count, int *sequence, bool start) {
    sequence[0] = num1;
    sequence[1] = num2;

    if (count == 0) {
        return;
    }

    for (int i = 2; i < count; i++) {
        sequence[i] = num1 + num2;
        num1 = num2;
        num2 = sequence[i];
    }

    if (!start) {
        return;
    }

    // Output the sequence based on the user's choice
    int option;
    printf("\nChoose the output style:\n");
    printf("1. Horizontal\n");
    printf("2. Vertical\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Fibonacci Sequence: ");
            for (int i = 0; i < count; i++) {
                printf("%d ", sequence[i]);
            }
            break;
        case 2:
            printf("Fibonacci Sequence:\n");
            for (int i = 0; i < count; i++) {
                printf("%d\n", sequence[i]);
            }
            break;
        default:
            printf("Invalid option selected. Generating sequence in horizontal style.\n");
            printf("Fibonacci Sequence: ");
            for (int i = 0; i < count; i++) {
                printf("%d ", sequence[i]);
            }
            break;
    }
}

// Main function
int main() {
    int count, num1, num2;

    // User Input
    printf("Enter the number of terms to be generated in the Fibonacci Sequence: ");
    scanf("%d", &count);

    printf("\nEnter the starting number for the sequence: ");
    scanf("%d", &num1);

    printf("\nEnter the second number for the sequence: ");
    scanf("%d", &num2);

    if (count < 2) {
        printf("Invalid number of terms. Please enter a number greater than or equal to 2.\n");
        return 0;
    }

    int *sequence = (int*) malloc(count * sizeof(int));

    // Call the recursive function to generate the sequence
    fibonacci(num1, num2, count, sequence, true);

    // Allow the user to choose the nth term of the sequence
    int option, index;
    printf("\nDo you want to select a specific term in the sequence?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("\nEnter the index of the term you want to select (starting from 0): ");
            scanf("%d", &index);

            if (index < 0 || index > count - 1) {
                printf("Invalid index selected.\n");
                return 0;
            }

            printf("The %dth term of the Fibonacci Sequence is: %d", index, sequence[index]);
            break;
        case 2:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }

    free(sequence);
    return 0;
}