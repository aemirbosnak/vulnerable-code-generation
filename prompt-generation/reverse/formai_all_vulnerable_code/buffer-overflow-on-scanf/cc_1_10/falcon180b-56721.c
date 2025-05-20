//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, c, d;
    int sum, diff, prod, quot;
    int choice;
    int flag = 0;

    printf("Welcome to the Arithmetic Calculator\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers:\n");
            scanf("%d %d", &a, &b);
            sum = a + b;
            printf("The sum of %d and %d is %d\n", a, b, sum);
            break;
        case 2:
            printf("Enter two numbers:\n");
            scanf("%d %d", &a, &b);
            diff = a - b;
            printf("The difference of %d and %d is %d\n", a, b, diff);
            break;
        case 3:
            printf("Enter two numbers:\n");
            scanf("%d %d", &a, &b);
            prod = a * b;
            printf("The product of %d and %d is %d\n", a, b, prod);
            break;
        case 4:
            printf("Enter two numbers:\n");
            scanf("%d %d", &a, &b);
            if(b == 0) {
                printf("Division by zero is not allowed\n");
            }
            else {
                quot = a / b;
                printf("The quotient of %d and %d is %d\n", a, b, quot);
            }
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}