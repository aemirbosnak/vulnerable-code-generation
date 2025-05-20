//FormAI DATASET v1.0 Category: Recursive ; Style: synchronous
#include <stdio.h>

// Recursive function to calculate factorial of a number
int factorial(int num) {
    if (num == 1 || num == 0) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

// Recursive function to calculate fibonacci of a number
int fibonacci(int num) {
    if (num <= 1) {
        return num;
    } else {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

// Recursive function to print all the numbers from n to 1 in reverse order
void printReverse(int num) {
    if (num == 0) {
        return;
    } else {
        printf("%d ", num);
        printReverse(num - 1);
    }
}

// Recursive function to compute the sum of natural numbers up to n
int sumOfNaturalNumbers(int num) {
    if (num == 1) {
        return 1;
    } else {
        return num + sumOfNaturalNumbers(num - 1);
    }
}

int main() {
    int choice, num, factorialResult, fibonacciResult, sumOfNaturalNumbersResult;
    
    printf("Enter your choice:\n");
    printf("1. Factorial\n2. Fibonacci\n3. Print numbers in reverse order\n4. Sum of natural numbers\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter a number to calculate factorial: ");
            scanf("%d", &num);
            factorialResult = factorial(num);
            printf("Factorial of %d is %d", num, factorialResult);
            break;
        case 2:
            printf("Enter a number to calculate fibonacci: ");
            scanf("%d", &num);
            fibonacciResult = fibonacci(num);
            printf("Fibonacci of %d is %d", num, fibonacciResult);
            break;
        case 3:
            printf("Enter a number to print in reverse order: ");
            scanf("%d", &num);
            printf("Numbers from %d to 1 in reverse order are:\n", num);
            printReverse(num);
            break;
        case 4:
            printf("Enter a number to compute sum of natural numbers: ");
            scanf("%d", &num);
            sumOfNaturalNumbersResult = sumOfNaturalNumbers(num);
            printf("Sum of natural numbers up to %d is %d", num, sumOfNaturalNumbersResult);
            break;
        default:
            printf("Invalid choice!");
            break;
    }
    
    return 0;
}