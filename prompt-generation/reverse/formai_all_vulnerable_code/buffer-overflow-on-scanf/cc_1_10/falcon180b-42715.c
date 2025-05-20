//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int main() {
    int i, j, n;
    double x, y, sum = 0.0, prod = 1.0, diff, quot;
    char op;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter term %d: ", i + 1);
        scanf("%lf", &x);

        if (i == 0) {
            sum = x;
            prod = x;
            continue;
        }

        printf("Enter operator (+, -, *, /): ");
        scanf(" %c", &op);

        switch (op) {
            case '+':
                sum += x;
                break;
            case '-':
                sum -= x;
                break;
            case '*':
                prod *= x;
                break;
            case '/':
                if (x == 0.0) {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                quot = prod / x;
                prod = x;
                sum += quot;
                break;
            default:
                printf("Error: Invalid operator\n");
                exit(1);
        }
    }

    printf("Sum: %lf\n", sum);
    printf("Product: %lf\n", prod);

    return 0;
}