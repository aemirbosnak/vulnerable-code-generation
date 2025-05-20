//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>

// Function prototypes
void printMenu();
void processChoice(int choice);
int factorial(int n);
int fibonacci(int n);
void hanoi(int n, char source, char target, char auxiliary);
void printStars(int n);
void reverseString(char str[], int start, int end);
void swap(char *x, char *y);
void processString(char str[]);

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice (1-6, 0 to exit): ");
        scanf("%d", &choice);
        processChoice(choice);

        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
    }

    return 0;
}

// Displaying the menu
void printMenu() {
    printf("\n--- Recursive Functions Menu ---\n");
    printf("1. Calculate Factorial\n");
    printf("2. Calculate Fibonacci\n");
    printf("3. Solve Tower of Hanoi\n");
    printf("4. Print Stars Pattern\n");
    printf("5. Reverse a String\n");
    printf("6. Process String\n");
    printf("0. Exit\n");
}

// Processing the user's choice
void processChoice(int choice) {
    int number;
    char str[100];

    switch (choice) {
        case 1:
            printf("Enter a positive integer: ");
            scanf("%d", &number);
            if (number < 0) {
                printf("Factorial is not defined for negative numbers.\n");
            } else {
                printf("Factorial of %d is %d\n", number, factorial(number));
            }
            break;

        case 2:
            printf("Enter a positive integer: ");
            scanf("%d", &number);
            if (number < 0) {
                printf("Fibonacci is not defined for negative numbers.\n");
            } else {
                printf("Fibonacci of %d is %d\n", number, fibonacci(number));
            }
            break;

        case 3:
            printf("Enter the number of disks: ");
            scanf("%d", &number);
            printf("Solving Tower of Hanoi for %d disks:\n", number);
            hanoi(number, 'A', 'C', 'B'); // A = source, C = target, B = auxiliary
            break;

        case 4:
            printf("Enter the number of rows for star pattern: ");
            scanf("%d", &number);
            printStars(number);
            break;

        case 5:
            printf("Enter a string: ");
            scanf("%s", str);
            reverseString(str, 0, strlen(str) - 1);
            printf("Reversed string: %s\n", str);
            break;

        case 6:
            printf("Enter a string to process: ");
            scanf("%s", str);
            processString(str);
            break;

        default:
            printf("Invalid choice, please try again.\n");
            break;
    }
}

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Recursive function to calculate Fibonacci
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive function to solve Tower of Hanoi
void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    hanoi(n - 1, auxiliary, target, source);
}

// Recursive function to print stars pattern
void printStars(int n) {
    if (n == 0) {
        return;
    }
    printStars(n - 1);
    for (int i = 0; i < n; i++) {
        printf("* ");
    }
    printf("\n");
}

// Recursive function to reverse a string
void reverseString(char str[], int start, int end) {
    if (start >= end)
        return;
    swap(&str[start], &str[end]);
    reverseString(str, start + 1, end - 1);
}

// Function to swap two characters
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to process a string
void processString(char str[]) {
    // Example processing: reversing the string
    int length = strlen(str);
    reverseString(str, 0, length - 1);
    printf("Processed string (reversed): %s\n", str);
}