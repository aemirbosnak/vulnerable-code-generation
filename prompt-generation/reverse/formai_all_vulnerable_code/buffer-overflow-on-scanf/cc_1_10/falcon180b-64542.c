//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

int main() {
    int n;
    double a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
    char op;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of array A: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    printf("Enter the elements of array B: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    for (int i = 0; i < n; i++) {
        switch (op) {
            case '+':
                c[i] = a[i] + b[i];
                break;
            case '-':
                c[i] = a[i] - b[i];
                break;
            case '*':
                c[i] = a[i] * b[i];
                break;
            case '/':
                if (b[i] == 0) {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                c[i] = a[i] / b[i];
                break;
            default:
                printf("Error: Invalid operation\n");
                exit(1);
        }
    }

    printf("Result: ");
    for (int i = 0; i < n; i++) {
        printf("%lf ", c[i]);
    }

    return 0;
}