//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10

int main() {
    int i, j, n;
    double a[SIZE], b[SIZE], c[SIZE];
    char op;

    // Fill arrays with random numbers
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }

    // Get operation from user
    printf("Enter operation (+, -, *, /): ");
    scanf("%c", &op);

    // Perform operation on arrays
    switch (op) {
        case '+':
            for (i = 0; i < SIZE; i++) {
                c[i] = a[i] + b[i];
            }
            break;
        case '-':
            for (i = 0; i < SIZE; i++) {
                c[i] = a[i] - b[i];
            }
            break;
        case '*':
            for (i = 0; i < SIZE; i++) {
                c[i] = a[i] * b[i];
            }
            break;
        case '/':
            for (i = 0; i < SIZE; i++) {
                if (b[i] == 0) {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                c[i] = a[i] / b[i];
            }
            break;
        default:
            printf("Invalid operation\n");
            exit(1);
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d %c %d = %.2f\n", a[i], op, b[i], c[i]);
    }

    return 0;
}