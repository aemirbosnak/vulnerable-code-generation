//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int n;
    double a[MAX_SIZE];
    char op;
    int i = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int j = 0; j < n; j++) {
        scanf("%lf", &a[j]);
        if (isnan(a[j])) {
            printf("Invalid input! Please enter a valid number.\n");
            exit(1);
        }
    }
    printf("Enter the operation to be performed (+, -, *, /): ");
    scanf(" %c", &op);
    switch (op) {
        case '+':
            for (int j = 0; j < n; j++) {
                a[j] += a[j + 1];
            }
            break;
        case '-':
            for (int j = 0; j < n; j++) {
                a[j] -= a[j + 1];
            }
            break;
        case '*':
            for (int j = 0; j < n; j++) {
                a[j] *= a[j + 1];
            }
            break;
        case '/':
            for (int j = 0; j < n; j++) {
                if (a[j + 1] == 0) {
                    printf("Division by zero! Please enter a valid number.\n");
                    exit(1);
                }
                a[j] /= a[j + 1];
            }
            break;
        default:
            printf("Invalid operation! Please enter a valid operation.\n");
            exit(1);
    }
    printf("The result of the operation is:\n");
    for (int j = 0; j < n; j++) {
        printf("%.2lf ", a[j]);
    }
    printf("\n");
    return 0;
}