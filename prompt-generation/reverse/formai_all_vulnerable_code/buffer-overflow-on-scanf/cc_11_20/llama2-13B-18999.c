//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    char op;

    // Exercise 1: Evaluate the expression
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        diff = num1 - num2;
    } else if (op == '*') {
        mult = num1 * num2;
    } else if (op == '/') {
        div = num1 / num2;
    } else {
        mod = num1 % num2;
    }

    // Exercise 2: Check if the result is a magic number
    if (sum == MAGIC_NUMBER || diff == MAGIC_NUMBER || mult == MAGIC_NUMBER || div == MAGIC_NUMBER || mod == MAGIC_NUMBER) {
        printf("Congratulations! You got a magic result! The result is %d\n", sum);
    } else {
        printf("Too bad, the result is not a magic number. The result is %d\n", sum);
    }

    // Exercise 3: Add a random twist
    if (num1 > num2) {
        num2 = num2 + (rand() % 5) - (rand() % 3);
    } else if (num1 < num2) {
        num1 = num1 + (rand() % 5) - (rand() % 3);
    }

    // Exercise 4: Check if the result is still a magic number
    if (sum == MAGIC_NUMBER || diff == MAGIC_NUMBER || mult == MAGIC_NUMBER || div == MAGIC_NUMBER || mod == MAGIC_NUMBER) {
        printf("Congratulations! You got a magic result again! The result is %d\n", sum);
    } else {
        printf("Too bad, the result is not a magic number. The result is %d\n", sum);
    }

    return 0;
}