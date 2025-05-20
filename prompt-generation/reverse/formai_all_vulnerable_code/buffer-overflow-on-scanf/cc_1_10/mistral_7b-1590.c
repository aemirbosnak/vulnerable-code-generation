//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to calculate the sum of digits of a number
int sum_digits(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

// Function to calculate the product of two numbers using recursion
int product(int num1, int num2) {
    if (num2 == 0) {
        return 0;
    } else {
        return num1 + product(num1, num2 - 1);
    }
}

// Function to calculate the factorial of a number using recursion
int factorial(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int main() {
    int num1, num2, sum, prod, fact1, fact2, result;

    printf("Greetings, noble arithmetic-loving alien!\n");
    printf("Please input the first number: ");
    scanf("%d", &num1);

    printf("And the second number: ");
    scanf("%d", &num2);

    // Calculate sum of digits of both numbers
    fact1 = factorial(sum_digits(num1));
    fact2 = factorial(sum_digits(num2));

    // Check if both numbers are prime
    if (is_prime(num1) && is_prime(num2)) {
        // Calculate product and factorial of both numbers
        prod = product(num1, num2);
        fact1 = factorial(num1);
        fact2 = factorial(num2);

        // Calculate the result using a funny formula
        result = (prod * pow(fact1, 2)) / fact2;

        printf("The result of this funny calculation is: %d\n", result);
    } else {
        printf("Error: Both numbers must be prime!\n");
    }

    return 0;
}