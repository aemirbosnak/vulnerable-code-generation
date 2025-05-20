//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>

/* Function to calculate factorial */
long long factorial(int n) {
    if (n < 0) {
        return -1; // returns error if negative
    }
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

/* Function to calculate GCD using Euclidean algorithm */
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Function to generate Fibonacci sequence */
void fibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm = 0;
    printf("Fibonacci sequence up to %d terms:\n", n);
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            printf("%d, ", t1);
            continue;
        }
        if (i == 2) {
            printf("%d, ", t2);
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        printf("%d, ", nextTerm);
    }
    printf("\n");
}

/* Main function */
int main() {
    int choice;
    printf("Welcome to the Math Exploration Program!\n");
    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Calculate Factorial\n");
        printf("2. Find GCD\n");
        printf("3. Generate Fibonacci Sequence\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int num;
                printf("Let's calculate the factorial of a number! Please enter a non-negative integer: ");
                scanf("%d", &num);
                long long fact = factorial(num);
                if (fact == -1) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    printf("The factorial of %d is %lld\n", num, fact);
                }
                break;
            }
            case 2: {
                int a, b;
                printf("Let's find the GCD of two numbers! Please enter two integers:\n");
                printf("First number: ");
                scanf("%d", &a);
                printf("Second number: ");
                scanf("%d", &b);
                int greatestCommonDivisor = gcd(a, b);
                printf("The GCD of %d and %d is %d\n", a, b, greatestCommonDivisor);
                break;
            }
            case 3: {
                int n;
                printf("Curious about the Fibonacci sequence? How many terms would you like to generate? ");
                scanf("%d", &n);
                fibonacci(n);
                break;
            }
            case 4:
                printf("Thank you for exploring math with us! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please choose between 1 and 4.\n");
        }
    }
    return 0;
}