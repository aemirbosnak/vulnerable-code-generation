//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

// Function to perform basic arithmetic operations
void performArithmetic(int *arr, int size) {
    int sum = 0;
    float average;
    int highest = arr[0];
    int lowest = arr[0];
    int product = 1;

    printf("\nArithmetic Operations:\n");

    for(int i = 0; i < size; i++) {
        sum += arr[i];
        product *= arr[i];

        if(arr[i] > highest) {
            highest = arr[i];
        }
        if(arr[i] < lowest) {
            lowest = arr[i];
        }
    }

    average = (float)sum / size;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Product: %d\n", product);
    printf("Highest: %d\n", highest);
    printf("Lowest: %d\n", lowest);
}

// Function to display array contents
void displayArray(int *arr, int size) {
    printf("Array elements:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the factorial of a number
int factorial(int num) {
    if(num == 0) return 1;
    return num * factorial(num - 1);
}

// Function to calculate permuation nPr
int permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Function to calculate combination nCr
int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Main function - entry point of the program
int main() {
    int size;
    int arr[MAX_SIZE];

    // Getting the size of the array
    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if(size <= 0 || size > MAX_SIZE) {
        printf("Invalid size. Exiting program.\n");
        return 1;
    }

    // Input array elements
    for(int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display array and perform arithmetic operations
    displayArray(arr, size);
    performArithmetic(arr, size);

    // Perform permutation and combination operations
    int n, r;
    printf("\nEnter values for n and r for permutation and combination:\n");
    printf("n: ");
    scanf("%d", &n);
    printf("r: ");
    scanf("%d", &r);

    // Basic input validation
    if(r > n || n < 0 || r < 0) {
        printf("Invalid input for n and r. Exiting program.\n");
        return 1;
    }
    
    printf("Permutation (nPr) of %d and %d = %d\n", n, r, permutation(n, r));
    printf("Combination (nCr) of %d and %d = %d\n", n, r, combination(n, r));

    // Additional demonstration of power
    int base, exponent;
    printf("\nEnter base and exponent for power calculation:\n");
    printf("Base: ");
    scanf("%d", &base);
    printf("Exponent: ");
    scanf("%d", &exponent);

    printf("%d to the power of %d is %f\n", base, exponent, pow(base, exponent));

    // Closing statement
    printf("\nThank you for using the Arithmetic Operations Program!\n");
    return 0;
}