//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void displayMenu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
bool isPrime(int num);
void generateFibonacci(int n);

int main() {
    int choice, a, b, n;
    bool running = true;

    while (running) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two integers for addition: ");
                scanf("%d %d", &a, &b);
                printf("Result: %d + %d = %d\n", a, b, add(a, b));
                break;

            case 2:
                printf("Enter two integers for subtraction: ");
                scanf("%d %d", &a, &b);
                printf("Result: %d - %d = %d\n", a, b, subtract(a, b));
                break;

            case 3:
                printf("Enter two integers for multiplication: ");
                scanf("%d %d", &a, &b);
                printf("Result: %d * %d = %d\n", a, b, multiply(a, b));
                break;

            case 4:
                printf("Enter two integers for division: ");
                scanf("%d %d", &a, &b);
                if (b != 0) {
                    printf("Result: %d / %d = %.2f\n", a, b, divide(a, b));
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;

            case 5:
                printf("Enter an integer to check if it's prime: ");
                scanf("%d", &a);
                if (isPrime(a)) {
                    printf("%d is a prime number.\n", a);
                } else {
                    printf("%d is not a prime number.\n", a);
                }
                break;

            case 6:
                printf("Enter how many Fibonacci numbers to generate: ");
                scanf("%d", &n);
                printf("Fibonacci sequence:\n");
                generateFibonacci(n);
                break;

            case 7:
                running = false;
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Math Operations Menu ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Prime Check\n");
    printf("6. Fibonacci Sequence Generator\n");
    printf("7. Exit\n");
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / (float)b;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void generateFibonacci(int n) {
    int a = 0, b = 1, next;
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = a + b;
            a = b;
            b = next;
        }
        printf("%d ", next);
    }
    printf("\n");
}