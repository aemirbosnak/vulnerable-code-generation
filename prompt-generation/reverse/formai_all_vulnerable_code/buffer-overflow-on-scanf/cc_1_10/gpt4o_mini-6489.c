//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>

void getInput(int *numbers, int n);
void performCalculations(int *numbers, int n, int *sum, float *average, int *min, int *max);
void displayResults(int sum, float average, int min, int max);

int main() {
    int n;

    // Prompt user for number of elements
    printf("Welcome to the Arithmetic Operations Program!\n");
    printf("Please enter the number of elements you want to operate on: ");
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return -1;
    }

    int *numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed. Exiting the program.\n");
        return -1;
    }

    // Get input from the user
    getInput(numbers, n);

    // Prepare to store results
    int sum = 0;
    float average = 0.0;
    int min = numbers[0];
    int max = numbers[0];

    // Perform arithmetic operations
    performCalculations(numbers, n, &sum, &average, &min, &max);
    
    // Display results
    displayResults(sum, average, min, max);

    // Clean up
    free(numbers);
    return 0;
}

void getInput(int *numbers, int n) {
    printf("Please enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter integer %d: ", i + 1);
        while (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input. Please enter an integer: ");
            while(getchar() != '\n'); // clear invalid input
        }
    }
}

void performCalculations(int *numbers, int n, int *sum, float *average, int *min, int *max) {
    *sum = 0;
    *min = numbers[0];
    *max = numbers[0];

    // Calculate sum, average, min, and max
    for (int i = 0; i < n; i++) {
        *sum += numbers[i];

        if (numbers[i] < *min) {
            *min = numbers[i];
        }
        if (numbers[i] > *max) {
            *max = numbers[i];
        }
    }

    *average = (float)(*sum) / n;
}

void displayResults(int sum, float average, int min, int max) {
    printf("\nResults of the Arithmetic Operations:\n");
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
}