//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j, *a, *b, *c, sum;
    char operation;

    // Allocate memory for arrays
    a = (int*) malloc(MAX_SIZE * sizeof(int));
    b = (int*) malloc(MAX_SIZE * sizeof(int));
    c = (int*) malloc(MAX_SIZE * sizeof(int));

    // Get number of elements from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Get elements of first array
    printf("Enter the elements of first array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    // Get elements of second array
    printf("Enter the elements of second array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", b + i);
    }

    // Get operation from user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform arithmetic operation
    switch(operation) {
        case '+':
            for (i = 0; i < n; i++) {
                sum = a[i] + b[i];
                c[i] = sum;
            }
            break;
        case '-':
            for (i = 0; i < n; i++) {
                sum = a[i] - b[i];
                c[i] = sum;
            }
            break;
        case '*':
            for (i = 0; i < n; i++) {
                sum = a[i] * b[i];
                c[i] = sum;
            }
            break;
        case '/':
            for (i = 0; i < n; i++) {
                if (b[i] == 0) {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                sum = a[i] / b[i];
                c[i] = sum;
            }
            break;
        default:
            printf("Error: Invalid operation\n");
            exit(1);
    }

    // Print result
    printf("Result:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    // Free memory
    free(a);
    free(b);
    free(c);

    return 0;
}