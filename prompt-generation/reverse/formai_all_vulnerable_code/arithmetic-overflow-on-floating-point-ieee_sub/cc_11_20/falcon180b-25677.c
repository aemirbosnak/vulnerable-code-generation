//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    double x, y, z;
    char op;

    printf("Enter the number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the operation (+, -, *, /): ");
        scanf(" %c", &op);

        printf("Enter the first operand: ");
        scanf("%lf", &x);

        if (op == '+' || op == '-' || op == '*' || op == '/') {
            printf("Enter the second operand: ");
            scanf("%lf", &y);
        }

        switch (op) {
            case '+':
                z = x + y;
                break;
            case '-':
                z = x - y;
                break;
            case '*':
                z = x * y;
                break;
            case '/':
                if (y == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                    exit(1);
                }
                z = x / y;
                break;
            default:
                printf("Error: Invalid operation.\n");
                exit(1);
        }

        printf("Result: %lf\n", z);
    }

    return 0;
}