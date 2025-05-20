//FormAI DATASET v1.0 Category: Educational ; Style: random
#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
int factorial(int num);
int fibonacci(int n);
int palindrome(int num);

int main() {
    int choice, num, result;
    printf("Welcome to the C Educational Example Program!\n");
    printf("Please choose an option from the menu:\n");
    printf("1. Factorial of a number\n");
    printf("2. Fibonacci sequence\n");
    printf("3. Palindrome check\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Please enter a number to find the factorial: ");
            scanf("%d", &num);
            result = factorial(num);
            printf("The factorial of %d is %d\n", num, result);
            break;
        case 2:
            printf("Please enter a number of terms for the fibonacci sequence: ");
            scanf("%d", &num);
            printf("The fibonacci sequence is: ");
            for(int i = 0; i < num; i++) {
                printf("%d ", fibonacci(i));
            }
            printf("\n");
            break;
        case 3:
            printf("Please enter a number to check if it is a palindrome: ");
            scanf("%d", &num);
            if(palindrome(num)) {
                printf("%d is a palindrome!\n", num);
            } else {
                printf("%d is NOT a palindrome!\n", num);
            }
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }
    return 0;
}

int factorial(int num) {
    if(num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num-1);
    }
}

int fibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int palindrome(int num) {
    int original, reverse = 0, remainder;
    original = num;
    while(num != 0) {
        remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num /= 10;
    }
    if(original == reverse) {
        return 1;
    } else {
        return 0;
    }
}