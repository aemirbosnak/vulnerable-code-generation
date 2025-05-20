//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void printStars(int);

int main() {
    int levels;

    printf("Welcome to the Star Pyramid Program!\n");
    printf("Enter the number of levels for the pyramid (1-20): ");
    scanf("%d", &levels);
    
    // Input validation
    if (levels < 1 || levels > 20) {
        printf("Please enter a number between 1 and 20.\n");
        return 1;
    }

    printf("Constructing a Pyramid of %d levels...\n", levels);
    printStars(levels);
    
    printf("Pyramid Construction Complete!\n");
    return 0;
}

// Recursive function to print stars in a pyramid
void printStars(int n) {
    if (n <= 0) {
        return;
    }

    // Print spaces
    for (int i = 0; i < (20 - n); i++) {
        printf(" ");
    }

    // Print stars
    for (int j = 0; j < (2 * n - 1); j++) {
        printf("*");
    }
    
    printf("\n");
    printStars(n - 1);
}

// Function to calculate factorial recursively
unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate Fibonacci recursively
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to display Fibonacci numbers
void displayFibonacci(int count) {
    printf("Fibonacci Series:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to reverse a string recursively
void reverseString(char str[], int start, int end) {
    if (start >= end) return;
    
    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call
    reverseString(str, start + 1, end - 1);
}

// Function to gather user input for string manipulation
void manipulateString() {
    char str[100];
    printf("Enter a string (max 99 characters): ");
    scanf(" %[^\n]s", str);
    
    int len = 0;
    while (str[len] != '\0') len++;
    
    reverseString(str, 0, len - 1);
    printf("Reversed String: %s\n", str);
}

// Main manipulation function
void manipulateData() {
    int choice;
    printf("Select an operation:\n");
    printf("1. Display Fibonacci\n");
    printf("2. Reverse a String\n");
    printf("Select your option (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("How many Fibonacci numbers do you want? ");
            int count;
            scanf("%d", &count);
            displayFibonacci(count);
            break;
        case 2:
            manipulateString();
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }
}

int mainMenu() {
    printf("******** Welcome to the Recursive Functions Program ********\n");
    int continueMenu = 1;
    
    while (continueMenu) {
        manipulateData();
        printf("Do you want to continue? (1 = Yes, 0 = No): ");
        scanf("%d", &continueMenu);
    }

    return 0;
}