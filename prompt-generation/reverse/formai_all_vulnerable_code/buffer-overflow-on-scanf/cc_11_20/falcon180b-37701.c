//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j;
    double x[MAX_SIZE], y[MAX_SIZE], z[MAX_SIZE];
    char op;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the coordinates of the points:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf %lf %lf", &x[i], &y[i], &z[i]);
    }

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
            for (i = 0; i < n; i++) {
                x[i] += x[i];
                y[i] += y[i];
                z[i] += z[i];
            }
            break;
        case '-':
            for (i = 0; i < n; i++) {
                x[i] -= x[i];
                y[i] -= y[i];
                z[i] -= z[i];
            }
            break;
        case '*':
            for (i = 0; i < n; i++) {
                x[i] *= x[i];
                y[i] *= y[i];
                z[i] *= z[i];
            }
            break;
        case '/':
            for (i = 0; i < n; i++) {
                x[i] /= x[i];
                y[i] /= y[i];
                z[i] /= z[i];
            }
            break;
        default:
            printf("Invalid operation.\n");
            exit(1);
    }

    printf("Result:\n");
    for (i = 0; i < n; i++) {
        printf("(%lf, %lf, %lf)\n", x[i], y[i], z[i]);
    }

    return 0;
}