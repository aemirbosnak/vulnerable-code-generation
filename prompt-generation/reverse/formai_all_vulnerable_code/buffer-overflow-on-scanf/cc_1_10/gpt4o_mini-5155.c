//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void displayMenu();
int getChoice();
void calculateFibonacci();
void checkPrime();
void calculateFactorial();

int main() {
    int choice;

    do {
        displayMenu();
        choice = getChoice();
        
        switch (choice) {
            case 1:
                calculateFibonacci();
                break;
            case 2:
                checkPrime();
                break;
            case 3:
                calculateFactorial();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n==================== Mathematical Operations Menu ====================\n");
    printf("1. Calculate Fibonacci Sequence\n");
    printf("2. Check if a Number is Prime\n");
    printf("3. Calculate Factorial of a Number\n");
    printf("4. Exit\n");
    printf("======================================================================\n");
}

// Function to get the user's choice
int getChoice() {
    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    return choice;
}

// Function to calculate and display Fibonacci sequence up to n terms
void calculateFibonacci() {
    int n;
    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("Please enter a positive integer.\n");
        return;
    }

    printf("Fibonacci sequence up to %d terms:\n", n);
    int t1 = 0, t2 = 1, nextTerm;

    for (int i = 1; i <= n; ++i) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

// Function to check if a number is prime
void checkPrime() {
    int num;
    printf("Enter a positive integer to check if it is prime: ");
    scanf("%d", &num);
    
    if (num <= 1) {
        printf("Please enter a number greater than 1.\n");
        return;
    }

    bool isPrime = true;

    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime)
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);
}

// Function to calculate the factorial of a number
void calculateFactorial() {
    int num;
    unsigned long long factorial = 1;
    
    printf("Enter a non-negative integer to calculate its factorial: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return;
    }

    for (int i = 1; i <= num; ++i) {
        factorial *= i;
    }

    printf("Factorial of %d = %llu\n", num, factorial);
}