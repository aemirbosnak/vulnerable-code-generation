//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>

// This program performs a series of arithmetic operations
// on a list of user-provided integers and introspects on the results.

#define MAX_NUMBERS 10

// Function prototypes
void inputNumbers(int arr[], int *n);
void calculateArithmetic(int arr[], int n);
void displayResults(int sum, double average, int max, int min);
void introspectArithmetic(int sum, double average, int max, int min);

int main() {
    int numbers[MAX_NUMBERS];
    int count = 0;

    // Step 1: Input the numbers
    inputNumbers(numbers, &count);

    // Step 2: Perform arithmetic calculations
    calculateArithmetic(numbers, count);

    return 0;
}

// Function to take user input for the numbers
void inputNumbers(int arr[], int *n) {
    printf("Enter up to %d integers (type -1 to finish early):\n", MAX_NUMBERS);
    for (int i = 0; i < MAX_NUMBERS; i++) {
        int input;
        printf("Number %d: ", i + 1);
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        arr[i] = input;
        (*n)++;
    }
}

// Function to calculate the arithmetic results
void calculateArithmetic(int arr[], int n) {
    if (n == 0) {
        printf("No numbers entered. Please provide at least one number for arithmetic operations.\n");
        return;
    }

    int sum = 0, max = arr[0], min = arr[0];
    
    // Calculate sum, max, and min
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    double average = (double)sum / n;

    // Display the results
    displayResults(sum, average, max, min);
}

// Function to display arithmetic results
void displayResults(int sum, double average, int max, int min) {
    printf("\nResults of Arithmetic Operations:\n");
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    
    // Introspection on the results
    introspectArithmetic(sum, average, max, min);
}

// Function for introspection based on results
void introspectArithmetic(int sum, double average, int max, int min) {
    printf("\nIntrospection Results:\n");
    
    if (sum < 0) {
        printf("The sum of the numbers is negative.\n");
    } else if (sum == 0) {
        printf("The sum of the numbers is zero. An interesting balance!\n");
    } else {
        printf("The sum of the numbers is positive. Good job!\n");
    }

    if (average > 50.0) {
        printf("The average is quite high, indicating large input values.\n");
    } else if (average > 0.0) {
        printf("The average is moderate, suggesting a balanced dataset.\n");
    } else {
        printf("The average is non-positive, hinting at small or negative inputs.\n");
    }

    printf("The maximum value of the inputs is %d.\n", max);
    printf("The minimum value of the inputs is %d.\n", min);

    // Reflecting on the max and min values
    if (max - min > 20) {
        printf("There's a significant range in your inputs!\n");
    } else {
        printf("The values are closely grouped together, quite consistent!\n");
    }
}