//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void printMenu();
void handleChoice(int choice);
void addTwoNumbers();
int factorial(int n);
void fibonacciSeries(int n);
void reversedString(char str[], int index);
void reverseStringWrapper(char str[]);
void printFactorialSeries(int n);

// Main Function
int main() {
    int choice;

    do {
        printMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);
        handleChoice(choice);
    } while (choice != 0);

    return 0;
}

// Function Definitions

// Display the menu for user interaction
void printMenu() {
    printf("\n*** Recursive Function Menu ***\n");
    printf("1. Add Two Numbers\n");
    printf("2. Calculate Factorial\n");
    printf("3. Display Fibonacci Series\n");
    printf("4. Reverse a String\n");
    printf("5. Print Factorial Series\n");
    printf("0. Exit\n");
}

// Handle user's choice selection
void handleChoice(int choice) {
    switch (choice) {
        case 1:
            addTwoNumbers();
            break;
        case 2: {
            int num;
            printf("Enter a number to calculate factorial: ");
            scanf("%d", &num);
            if (num < 0) {
                printf("Factorial is not defined for negative numbers.\n");
            } else {
                printf("Factorial of %d is %d\n", num, factorial(num));
            }
            break;
        }
        case 3: {
            int n;
            printf("Enter the number of Fibonacci terms: ");
            scanf("%d", &n);
            fibonacciSeries(n);
            break;
        }
        case 4: {
            char str[100];
            printf("Enter a string to reverse: ");
            scanf("%s", str);
            reverseStringWrapper(str);
            printf("\n");
            break;
        }
        case 5: {
            int n;
            printf("Enter a number to print factorial series: ");
            scanf("%d", &n);
            printFactorialSeries(n);
            break;
        }
        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

// Function to add two numbers 
void addTwoNumbers() {
    int a, b;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Sum of %d and %d is: %d\n", a, b, a + b);
}

// Recursive function to calculate factorial
int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

// Recursive function to display Fibonacci series
void fibonacciSeries(int n) {
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Recursive function to calculate nth Fibonacci number
int fibonacci(int n) {
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive function to reverse a string
void reversedString(char str[], int index) {
    if (str[index] == '\0') {
        return;
    }
    reversedString(str, index + 1);
    printf("%c", str[index]);
}

// Wrapper function to call the reverse string recursive function
void reverseStringWrapper(char str[]) {
    printf("Reversed string: ");
    reversedString(str, 0);
}

// Function to print the factorial series
void printFactorialSeries(int n) {
    printf("Factorial Series up to %d: ", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", factorial(i));
    }
    printf("\n");
}