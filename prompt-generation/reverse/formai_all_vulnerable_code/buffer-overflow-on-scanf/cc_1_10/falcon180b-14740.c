//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <math.h>

// Define a function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Define a function to calculate the Fibonacci sequence up to a given number of terms
void fibonacci(int n) {
    int term1 = 0, term2 = 1, nextTerm;

    printf("Fibonacci sequence up to %d terms:\n", n);
    printf("0 1 ");

    for (int i = 2; i < n; i++) {
        nextTerm = term1 + term2;
        term1 = term2;
        term2 = nextTerm;
        printf("%d ", nextTerm);
    }
}

// Define a function to calculate the sum of squares of even numbers up to a given number
int sumOfSquares(int n) {
    int sum = 0;

    for (int i = 2; i <= n; i += 2) {
        sum += i * i;
    }

    return sum;
}

int main() {
    int num1, num2, choice;

    // Prompt the user to choose an option
    printf("Enter your choice:\n");
    printf("1. Factorial\n2. Fibonacci sequence\n3. Sum of squares of even numbers\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Calculate the factorial of a number entered by the user
            printf("Enter a number: ");
            scanf("%d", &num1);
            printf("The factorial of %d is %d\n", num1, factorial(num1));
            break;
        case 2:
            // Calculate the Fibonacci sequence up to a given number of terms entered by the user
            printf("Enter the number of terms: ");
            scanf("%d", &num1);
            fibonacci(num1);
            break;
        case 3:
            // Calculate the sum of squares of even numbers up to a given number entered by the user
            printf("Enter a number: ");
            scanf("%d", &num1);
            printf("The sum of squares of even numbers up to %d is %d\n", num1, sumOfSquares(num1));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}