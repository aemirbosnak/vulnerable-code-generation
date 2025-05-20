//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printFibonacci(int n);
void visualizeFibonacci(int n);
void detailedFibonacci(int n);
void displayMenu();
int getUserInput();

int main() {
    int choice, n;
    bool running = true;

    while (running) {
        displayMenu();
        choice = getUserInput();

        if (choice == 1) {
            printf("Enter the number of terms for Fibonacci sequence: ");
            scanf("%d", &n);
            printFibonacci(n);
        } else if (choice == 2) {
            printf("Enter the number of terms to visualize: ");
            scanf("%d", &n);
            visualizeFibonacci(n);
        } else if (choice == 3) {
            printf("Enter the number of terms for detailed Fibonacci: ");
            scanf("%d", &n);
            detailedFibonacci(n);
        } else if (choice == 4) {
            printf("Exiting the program...\n");
            running = false;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void printFibonacci(int n) {
    if (n < 1) {
        printf("Please enter a positive integer.\n");
        return;
    }
    
    int a = 0, b = 1, nextTerm;
    printf("Fibonacci Series: ");
    
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a);
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    printf("\n");
}

void visualizeFibonacci(int n) {
    if (n < 1) {
        printf("Please enter a positive integer.\n");
        return;
    }

    int a = 0, b = 1, nextTerm;

    printf("Visualizing Fibonacci Series:\n");

    for (int i = 1; i <= n; ++i) {
        nextTerm = a + b;
        printf("%*d ", 4 * i, a);
        a = b;
        b = nextTerm;
    }
    printf("\n");
}

void detailedFibonacci(int n) {
    if (n < 1) {
        printf("Please enter a positive integer.\n");
        return;
    }

    int a = 0, b = 1, nextTerm;

    printf("Detailed Fibonacci Series:\n");
    printf("Term\tValue\n");
    printf("----\t-----\n");

    for (int i = 1; i <= n; ++i) {
        printf("%d\t%d\n", i, a);
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
}

void displayMenu() {
    printf("\n--- Fibonacci Sequence Visualizer Menu ---\n");
    printf("1. Print Fibonacci Sequence\n");
    printf("2. Visualize Fibonacci Sequence\n");
    printf("3. Detailed Fibonacci Sequence\n");
    printf("4. Exit\n");
    printf("Please select an option: ");
}

int getUserInput() {
    int input;
    scanf("%d", &input);
    return input;
}