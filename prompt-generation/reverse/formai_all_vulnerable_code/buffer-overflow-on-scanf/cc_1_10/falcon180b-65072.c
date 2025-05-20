//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    double a, b, c;
    char operation;

    printf("Enter the number of terms (n): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the value of term %d: ", i+1);
        scanf("%lf", &a);

        printf("Enter the operator (+, -, *, /): ");
        scanf(" %c", &operation);

        if (i == 0) {
            b = a;
        } else {
            printf("Enter the value of term %d: ", i+1);
            scanf("%lf", &b);

            switch (operation) {
                case '+':
                    c = a + b;
                    break;
                case '-':
                    c = a - b;
                    break;
                case '*':
                    c = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        printf("Division by zero is not allowed.\n");
                    } else {
                        c = a / b;
                    }
                    break;
                default:
                    printf("Invalid operator.\n");
                    return 0;
            }

            a = c;
        }
    }

    printf("The result is: %.2lf\n", a);

    return 0;
}