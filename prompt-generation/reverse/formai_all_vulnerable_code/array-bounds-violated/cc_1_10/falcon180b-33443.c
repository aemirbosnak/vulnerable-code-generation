//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int arr[SIZE];
    srand(time(NULL));

    // Fill array with random numbers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Get user input for operation
    char op;
    printf("Enter operation (+, -, *, /): ");
    scanf("%c", &op);

    // Get user input for two indices
    int index1, index2;
    printf("Enter first index: ");
    scanf("%d", &index1);
    printf("Enter second index: ");
    scanf("%d", &index2);

    // Perform operation on selected elements
    switch (op) {
        case '+':
            arr[index1] += arr[index2];
            break;
        case '-':
            arr[index1] -= arr[index2];
            break;
        case '*':
            arr[index1] *= arr[index2];
            break;
        case '/':
            if (arr[index2] == 0) {
                printf("Error: Division by zero\n");
            } else {
                arr[index1] /= arr[index2];
            }
            break;
        default:
            printf("Invalid operation\n");
            return 1;
    }

    // Print updated array
    printf("Updated array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}