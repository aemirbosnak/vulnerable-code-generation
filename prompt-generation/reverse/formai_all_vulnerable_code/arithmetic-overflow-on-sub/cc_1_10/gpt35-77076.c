//FormAI DATASET v1.0 Category: Recursive ; Style: immersive
#include<stdio.h>

// Welcome user to the Fibonacci series calculator
void welcome() {
    printf("Welcome to Fibonacci series calculator!\n");
    printf("This program will calculate the n-th term of the Fibonacci sequence using recursion.\n");
}

// Get input from user
int getInput() {
    int n;
    printf("Please enter the n-th term you want to calculate: ");
    scanf("%d", &n);
    return n;
}

// Calculate the Fibonacci series using recursion
int fibonacci(int n) {
    if(n == 0) { // Base case 1
        return 0;
    } else if(n == 1) { // Base case 2
        return 1;
    } else { // Recursive case
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Display the result to the user
void displayResult(int n, int result) {
    printf("The %d-th term of the Fibonacci sequence is %d.\n", n, result);
}

// Say goodbye to the user
void goodbye() {
    printf("Thank you for using Fibonacci series calculator! Goodbye.\n");
}

// Main function
int main() {
    welcome(); // Welcome the user
    
    int n = getInput(); // Get the input from the user
    
    int result = fibonacci(n); // Calculate the Fibonacci series using recursion
    
    displayResult(n, result); // Display the result to the user
    
    goodbye(); // Say goodbye to the user
    
    return 0; // Exit the program
}