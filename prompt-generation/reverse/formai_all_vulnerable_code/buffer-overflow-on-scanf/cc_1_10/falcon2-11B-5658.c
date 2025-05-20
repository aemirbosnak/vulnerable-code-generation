//Falcon2-11B DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num, i, j;

    // Read a number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if the number is negative or zero
    if (num <= 0) {
        printf("Factorial of %d is undefined.\n", num);
        return 0;
    }

    // Calculate the factorial of the number
    int fact = factorial(num);

    // Print the result
    printf("Factorial of %d is %d\n", num, fact);

    // Check if the factorial is odd or even
    if (fact % 2 == 0) {
        printf("The factorial is even.\n");
    } else {
        printf("The factorial is odd.\n");
    }

    // Print a pattern based on the factorial
    for (i = 1; i <= num; i++) {
        for (j = 1; j <= num - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}