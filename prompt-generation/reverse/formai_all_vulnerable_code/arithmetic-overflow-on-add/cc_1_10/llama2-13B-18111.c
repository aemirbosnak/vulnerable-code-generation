//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the Arithmetic Adventure! \n");

    do {
        printf("Please enter a number: ");
        scanf("%d", &num1);

        printf("Please enter an operation (+, -, *, /): ");
        scanf(" %c", &op);

        if (op == '+') {
            num2 = get_random_number();
            sum = num1 + num2;
        } else if (op == '-') {
            num2 = get_random_number();
            sum = num1 - num2;
        } else if (op == '*') {
            num2 = get_random_number();
            sum = num1 * num2;
        } else if (op == '/') {
            num2 = get_random_number();
            if (num2 == 0) {
                printf("Error: division by zero! \n");
            } else {
                sum = num1 / num2;
            }
        } else {
            printf("Invalid operation! \n");
            continue;
        }

        printf("The result of %d %c %d is %d\n", num1, op, num2, sum);

    } while (1);

    return 0;
}

int get_random_number() {
    int num;
    num = rand() % 100 + 1;
    return num;
}