//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j, k;
    double a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];
    char operation;

    printf("Enter the size of the matrices (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &b[i][j]);
        }
    }

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    switch (operation) {
        case '+':
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }
            break;
        case '-':
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    c[i][j] = a[i][j] - b[i][j];
                }
            }
            break;
        case '*':
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    c[i][j] = a[i][j] * b[i][j];
                }
            }
            break;
        case '/':
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (b[i][j] == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    c[i][j] = a[i][j] / b[i][j];
                }
            }
            break;
        default:
            printf("Invalid operation\n");
            exit(1);
    }

    printf("Result:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}