//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

int main() {
    int n;
    double x[MAX_SIZE], y[MAX_SIZE], z[MAX_SIZE];
    char op;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the value of x%d: ", i + 1);
        scanf("%lf", &x[i]);
        printf("Enter the value of y%d: ", i + 1);
        scanf("%lf", &y[i]);
        printf("Enter the operation (+, -, *, /): ");
        scanf(" %c", &op);
        z[i] = 0;
        switch (op) {
            case '+':
                z[i] = x[i] + y[i];
                break;
            case '-':
                z[i] = x[i] - y[i];
                break;
            case '*':
                z[i] = x[i] * y[i];
                break;
            case '/':
                if (y[i] == 0) {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                z[i] = x[i] / y[i];
                break;
            default:
                printf("Error: Invalid operation\n");
                exit(1);
        }
    }

    printf("The results are:\n");
    for (int i = 0; i < n; i++) {
        printf("z%d = %.2lf\n", i + 1, z[i]);
    }

    return 0;
}