//FormAI DATASET v1.0 Category: Recursive ; Style: intelligent
#include <stdio.h>

// This is a recursive function that calculates the factorial of a given number
int factorial(int num) {
    if (num == 0) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}

// This function prompts the user for an integer input and calculates its factorial
void calculateFactorial() {
    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    int fact = factorial(num);
    printf("The factorial of %d is %d\n", num, fact);
}

// This is a recursive function that calculates the Fibonacci sequence up to a given number of terms
int fibonacci(int num) {
    if (num == 0 || num == 1) {
        return num;
    }
    else {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

// This function prompts the user for an integer input and prints the Fibonacci sequence up to that number of terms
void printFibonacci() {
    int num;
    printf("Enter the number of terms to print in the Fibonacci sequence: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        int fib = fibonacci(i);
        printf("%d ", fib);
    }
    printf("\n");
}

// This is the main function that prompts the user for options and calls the corresponding functions
int main() {
    while (1) {
        printf("\nEnter an option:\n");
        printf("1. Calculate factorial\n");
        printf("2. Print Fibonacci sequence\n");
        printf("3. Quit\n");
        int option;
        scanf("%d", &option);

        if (option == 1) {
            calculateFactorial();
        }
        else if (option == 2) {
            printFibonacci();
        }
        else if (option == 3) {
            break;
        }
        else {
            printf("Invalid option\n");
        }
    }
    return 0;
}