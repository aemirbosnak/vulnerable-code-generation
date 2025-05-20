//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ultraprecise
#include <stdio.h>

// Function to calculate the nth number in the Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to visualize the Fibonacci sequence upto n numbers
void visualizeFibonacci(int n) {
    // Initializing the first two numbers
    int n1 = 0, n2 = 1;
    // Printing the initial fibonacci sequence for the first two numbers
    printf("%d, %d, ", n1, n2);

    // Loop to continue Fibonacci sequence upto n numbers
    for (int i = 3; i <= n; i++) {
        // Calculating the next Fibonacci number
        int next = n1 + n2;
        // Printing the next Fibonacci number
        printf("%d, ", next);
        // Updating the values of the first two numbers for the next sequence
        n1 = n2;
        n2 = next;
    }
    // Printing a new line to separate the output visually
    printf("\n");
}

// Main function to test the above functions
int main()
{
    // Taking user input for the number of Fibonacci numbers to visualize
    int n;
    printf("Enter the number of Fibonacci numbers to visualize: ");
    scanf("%d", &n);

    // Validating the input number
    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    // Printing the Fibonacci sequence upto n numbers using visualization
    printf("The Fibonacci sequence upto %d numbers is:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            // Printing the Fibonacci number with spaces and padding for better visualization
            printf("%3d ", fibonacci(j));
        }
        // Printing a new line at the end of each row to separate the output visually
        printf("\n");
    }

    // Printing the Fibonacci sequence upto n numbers without visualization
    printf("The Fibonacci sequence upto %d numbers without visualization is: ", n);
    visualizeFibonacci(n);

    return 0;
}