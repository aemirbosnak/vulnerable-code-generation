//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: irregular
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 10000

int main() {
    int i, j, n, m;
    double a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
    char choice;
    srand(time(NULL));

    printf("Enter the size of the arrays (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    printf("Enter the size of the second array (max %d): ", MAX_SIZE);
    scanf("%d", &m);

    printf("Enter the elements of the first array:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Enter the elements of the second array:\n");
    for (i = 0; i < m; i++) {
        b[i] = rand() % 100;
        printf("%d ", b[i]);
    }
    printf("\n");

    printf("Enter the operation to be performed:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%c", &choice);

    switch (choice) {
        case '1':
            printf("Addition:\n");
            for (i = 0; i < n && i < m; i++) {
                c[i] = a[i] + b[i];
                printf("%d ", c[i]);
            }
            break;
        case '2':
            printf("Subtraction:\n");
            for (i = 0; i < n && i < m; i++) {
                c[i] = a[i] - b[i];
                printf("%d ", c[i]);
            }
            break;
        case '3':
            printf("Multiplication:\n");
            for (i = 0; i < n && i < m; i++) {
                c[i] = a[i] * b[i];
                printf("%d ", c[i]);
            }
            break;
        case '4':
            printf("Division:\n");
            for (i = 0; i < n && i < m; i++) {
                if (b[i] == 0) {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                c[i] = a[i] / b[i];
                printf("%d ", c[i]);
            }
            break;
        default:
            printf("Invalid operation\n");
            exit(1);
    }

    return 0;
}