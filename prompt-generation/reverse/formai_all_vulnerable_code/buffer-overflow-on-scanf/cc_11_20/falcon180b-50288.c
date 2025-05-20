//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main() {
    int i, j, k, n, m, sum = 0;
    int arr1[SIZE], arr2[SIZE], result[SIZE];
    char operation;

    printf("Welcome to the year 2050! You are about to witness advanced arithmetic operations.\n");
    printf("This program will generate two arrays of integers, perform an operation on them,\n");
    printf("and store the result in a third array.\n");
    printf("The size of each array is %d.\n", SIZE);

    srand(time(0));

    // Fill the first array with random integers
    for (i = 0; i < SIZE; i++) {
        arr1[i] = rand() % 100;
    }

    // Fill the second array with random integers
    for (i = 0; i < SIZE; i++) {
        arr2[i] = rand() % 100;
    }

    // Perform the operation and store the result in the third array
    printf("Enter the operation you want to perform (+, -, *, /): ");
    scanf("%c", &operation);

    switch (operation) {
        case '+':
            for (i = 0; i < SIZE; i++) {
                result[i] = arr1[i] + arr2[i];
            }
            break;
        case '-':
            for (i = 0; i < SIZE; i++) {
                result[i] = arr1[i] - arr2[i];
            }
            break;
        case '*':
            for (i = 0; i < SIZE; i++) {
                result[i] = arr1[i] * arr2[i];
            }
            break;
        case '/':
            for (i = 0; i < SIZE; i++) {
                if (arr2[i] == 0) {
                    printf("Division by zero is not allowed.\n");
                    exit(1);
                }
                result[i] = arr1[i] / arr2[i];
            }
            break;
        default:
            printf("Invalid operation.\n");
            exit(1);
    }

    // Print the result
    printf("The result of the operation is:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}