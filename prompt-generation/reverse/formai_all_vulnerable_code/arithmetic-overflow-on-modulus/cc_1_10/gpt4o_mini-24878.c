//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: thoughtful
#include <stdio.h>

// Function to print the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to reverse a given string
void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }

    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call
    reverseString(str, start + 1, end - 1);
}

// Function to calculate the factorial of a number
long long factorial(int num) {
    if (num == 0) {
        return 1;
    }
    return num * factorial(num - 1);
}

// Function to print numbers from n to 1
void printDescending(int n) {
    if (n < 1) {
        return;
    }
    
    printf("%d ", n);
    printDescending(n - 1);
}

// Function to calculate the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to print patterns recursively
void printPattern(int n) {
    if (n == 0) {
        return;
    }
    
    // Print stars for the current level
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");

    // Recursive call for the next row
    printPattern(n - 1);
}

// Main function to tie everything together
int main() {
    int choice, num;

    printf("Welcome to the Recursive Programming World!\n");
    printf("Select a task to perform:\n");
    printf("1. Fibonacci Series\n");
    printf("2. Reverse a String\n");
    printf("3. Factorial Calculation\n");
    printf("4. Print Descending Numbers\n");
    printf("5. GCD Calculation\n");
    printf("6. Print Patterns\n");
    printf("7. Exit\n");
    
    while (1) {
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number for Fibonacci: ");
                scanf("%d", &num);
                printf("Fibonacci of %d is %d\n", num, fibonacci(num));
                break;

            case 2: {
                char str[100];
                printf("Enter a string to reverse: ");
                scanf("%s", str);
                int length = 0;
                while (str[length] != '\0') {
                    length++;
                }
                reverseString(str, 0, length - 1);
                printf("Reversed String: %s\n", str);
                break;
            }

            case 3:
                printf("Enter a number to calculate factorial: ");
                scanf("%d", &num);
                printf("Factorial of %d is %lld\n", num, factorial(num));
                break;

            case 4:
                printf("Enter a number to print descending: ");
                scanf("%d", &num);
                printf("Descending from %d: ", num);
                printDescending(num);
                printf("\n");
                break;

            case 5:
                {
                    int a, b;
                    printf("Enter two numbers to calculate GCD: ");
                    scanf("%d %d", &a, &b);
                    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
                    break;
                }

            case 6:
                printf("Enter the height of the pattern: ");
                scanf("%d", &num);
                printf("Printing Pattern:\n");
                printPattern(num);
                break;

            case 7:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}