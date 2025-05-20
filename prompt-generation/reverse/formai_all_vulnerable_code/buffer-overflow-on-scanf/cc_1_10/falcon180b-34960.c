//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: funny
/* C Performance-Critical Component Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_LENGTH 1000

/* Function to compute the factorial of a number */
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

/* Function to reverse a string */
void reverse_string(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

/* Function to calculate the Fibonacci sequence */
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    /* Prompt the user for a string */
    printf("Enter a string: ");
    char input_string[MAX_STRING_LENGTH];
    scanf("%s", input_string);

    /* Reverse the string */
    reverse_string(input_string);

    /* Prompt the user for a number */
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);

    /* Calculate the factorial of the number */
    int fact = factorial(num);

    /* Calculate the Fibonacci sequence up to the number */
    int fib_result = fibonacci(num);

    /* Print the results */
    printf("The reversed string is: %s\n", input_string);
    printf("The factorial of %d is: %d\n", num, fact);
    printf("The %dth number in the Fibonacci sequence is: %d\n", num, fib_result);

    return 0;
}