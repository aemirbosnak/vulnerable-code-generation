//FormAI DATASET v1.0 Category: Educational ; Style: irregular
#include <stdio.h>

// function to check if a given number is odd or even
int isEven(int num) {
    if (num % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// function to add two numbers
int add(int a, int b) {
    int sum = a + b;
    return sum;
}

// function to check if a given number is prime
int isPrime(int num) {
    int i;
    for (i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// function to calculate the factorial of a number
int factorial(int num) {
    int fact = 1;
    int i;
    for (i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int choice, num1, num2, result;
    printf("Welcome to the C Educational Example Program!\n\n");
    printf("Please select an option:\n");
    printf("1. Check if a number is even or odd\n");
    printf("2. Add two numbers\n");
    printf("3. Check if a number is prime\n");
    printf("4. Calculate the factorial of a number\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &num1);
            if (isEven(num1)) {
                printf("%d is even.\n", num1);
            } else {
                printf("%d is odd.\n", num1);
            }
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = add(num1, num2);
            printf("The sum of %d and %d is %d.\n", num1, num2, result);
            break;
        case 3:
            printf("Enter a number: ");
            scanf("%d", &num1);
            if (isPrime(num1)) {
                printf("%d is prime.\n", num1);
            } else {
                printf("%d is not prime.\n", num1);
            }
            break;
        case 4:
            printf("Enter a number: ");
            scanf("%d", &num1);
            result = factorial(num1);
            printf("The factorial of %d is %d.\n", num1, result);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}