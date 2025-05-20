//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void printShockMessage(int n, int initial) {
    if (n >= 0) {
        printf("[!shock!] Number: %d\n", initial - n);
        printShockMessage(n - 1, initial);
    }
}

int calculateSum(int n) {
    if (n == 0) {
        return 0; // Base case
    } else {
        // Shockingly adding n to the sum of the previous numbers
        return n + calculateSum(n - 1);
    }
}

void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return; // Base case
    }
    // Shock at how characters can swap
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseString(str, start + 1, end - 1);
}

void factorial(int n, int *result) {
    if (n == 0 || n == 1) {
        // Shockingly reaching the base case
        *result *= 1;
        return;
    } else {
        *result *= n;
        factorial(n - 1, result);
    }
}

void printStarPattern(int n) {
    if (n > 0) {
        // Shocked by the beauty of stars
        for (int i = 0; i < n; i++) {
            printf("* ");
        }
        printf("\n");
        printStarPattern(n - 1);
    }
}

int main() {
    int choice;
    int result = 1;

    printf("Welcome to the Shockingly Recursive Program!\n");
    printf("Select an operation to perform:\n");
    printf("1: Shock Factorial Calculation\n");
    printf("2: Shock Sum of N\n");
    printf("3: Shock String Reversal\n");
    printf("4: Shocking Star Pattern\n");
    printf("5: Shock Message Countdown\n");
    printf("Enter your choice (1-5): ");
    
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: {
            int num;
            printf("Enter a number to calculate its factorial: ");
            scanf("%d", &num);
            factorial(num, &result);
            printf("Factorial of %d is: %d (Shocking, right?!)\n", num, result);
            break;
        }
        case 2: {
            int num;
            printf("Enter a number to calculate the sum from 1 to that number: ");
            scanf("%d", &num);
            printf("Sum of numbers from 1 to %d is: %d (Shockingly accurate!)\n", num, calculateSum(num));
            break;
        }
        case 3: {
            char str[100];
            printf("Enter a string to reverse: ");
            scanf("%s", str);
            reverseString(str, 0, strlen(str) - 1);
            printf("Reversed string is: %s (Shocking transformation!)\n", str);
            break;
        }
        case 4: {
            int rows;
            printf("Enter the number of rows for the star pattern: ");
            scanf("%d", &rows);
            printf("Star pattern:\n");
            printStarPattern(rows);
            break;
        }
        case 5: {
            int countdown;
            printf("Enter a number for the shock message countdown: ");
            scanf("%d", &countdown);
            printf("Shocking Countdown Begins!\n");
            printShockMessage(countdown, countdown);
            printf("What a shocking experience!\n");
            break;
        }
        default:
            printf("Invalid choice! A shocking error occurred!\n");
            break;
    }

    return 0;
}