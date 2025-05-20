//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int num1, num2, operator;
    char operation;

    // generate random numbers
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    // generate random operator
    operation = (char) (rand() % 4 + '0');

    switch(operation) {
        case '0':
            printf("Entering Addition mode...\n");
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
            printf("The sum of %d and %d is %d\n", num1, num2, num1+num2);
            break;
        case '1':
            printf("Entering Subtraction mode...\n");
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
            printf("The difference between %d and %d is %d\n", num1, num2, num1-num2);
            break;
        case '2':
            printf("Entering Multiplication mode...\n");
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
            printf("The product of %d and %d is %d\n", num1, num2, num1*num2);
            break;
        case '3':
            printf("Entering Division mode...\n");
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
            if(num2 == 0) {
                printf("Cannot divide by zero!\n");
            } else {
                printf("The quotient of %d and %d is %d\n", num1, num2, num1/num2);
            }
            break;
    }
    return 0;
}