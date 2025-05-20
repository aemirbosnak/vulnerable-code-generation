//FormAI DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, prod;
    float quo;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;

    if (num2 == 0) {
        printf("Undefined division\n");
    }
    else {
        quo = (float) num1 / num2;
        printf("Quotient: %.2f\n", quo);
    }

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Product: %d\n", prod);

    int option;

    printf("\nChoose an operation (1: Multiply, 2: Add, 3: Subtract): ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            prod = num1 * num2;
            printf("Product: %d\n", prod);
            break;

        case 2:
            sum = num1 + num2;
            printf("Sum: %d\n", sum);
            break;

        case 3:
            diff = num1 - num2;
            printf("Difference: %d\n", diff);
            break;

        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}