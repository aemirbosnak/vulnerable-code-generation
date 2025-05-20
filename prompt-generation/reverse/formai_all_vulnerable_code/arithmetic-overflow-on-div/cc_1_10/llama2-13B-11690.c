//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 1000
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;

    printf("Welcome to the Arithmetic Adventure!\n");

    // Initialize the magic number
    srand(time(NULL) + MAGIC_NUMBER);

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        diff = num1 - num2;
    } else if (op == '*') {
        mult = num1 * num2;
    } else if (op == '/') {
        div = num1 / num2;
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Print some fun facts about the result
    if (sum % 2 == 0) {
        printf("Hey, that's a even number!\n");
    } else {
        printf("Oops, that's an odd number!\n");
    }

    if (sum > MAX_NUM) {
        printf("Whoa, that's a big number!\n");
    } else if (sum < 0) {
        printf("Uh oh, that's a negative number!\n");
    }

    return 0;
}