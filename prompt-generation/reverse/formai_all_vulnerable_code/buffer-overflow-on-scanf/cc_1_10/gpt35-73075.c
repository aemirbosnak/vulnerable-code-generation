//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: authentic
#include <stdio.h>

// Function to calculate and print the Fibonacci sequence up to n
void fibonacci(int n) { 
    int i, first = 0, second = 1, next; 
  
    printf("The Fibonacci sequence up to %d is:\n", n);

    for (i = 0; i < n; i++) { 
        if (i <= 1) 
            next = i; 
        else { 
            next = first + second; 
            first = second; 
            second = next; 
        } 
        printf("%d, ", next);
    } 
} 

// Function to print a row of asterisks based on the input length
void printAsterisks(int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("*");
    }
    printf("\n");
}

int main () {
    int n, i, width = 10; // width of each column
    
    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &n);

    fibonacci(n);

    // Print the visual representation of the Fibonacci sequence
    printf("\nVisual representation of the Fibonacci sequence:\n");

    int first = 0, second = 1, next;
    
    for (i = 0; i < n; i++) {
        if (i <= 1) 
            next = i; 
        else { 
            next = first + second; 
            first = second; 
            second = next; 
        }
        printAsterisks(next * width);
    }
    return 0;
}