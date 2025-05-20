//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: light-weight
#include <stdio.h>

// Function to calculate the sum of digits of a number recursively
int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sum_of_digits(n / 10);
}

// Function to print Fibonacci sequence up to a given number
void print_fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci sequence up to %d:\n", n);
    for (int i = 0; i < n; i++) {
        if (a > n) break;
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

// Function to display a menu and get user choice
int display_menu() {
    int choice;
    printf("Menu:\n");
    printf("1. Sum of digits of a number\n");
    printf("2. Fibonacci sequence up to a number\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice, number;

    while (1) {
        choice = display_menu();
        
        if (choice == 1) {
            printf("Enter a number to calculate the sum of its digits: ");
            scanf("%d", &number);
            int sum = sum_of_digits(number);
            printf("The sum of digits of %d is: %d\n", number, sum);
        } else if (choice == 2) {
            printf("Enter a number to print Fibonacci sequence up to: ");
            scanf("%d", &number);
            print_fibonacci(number);
        } else if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}