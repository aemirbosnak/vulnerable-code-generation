//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size;

    // prompt user for array size
    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    // prompt user for array elements
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // prompt user for operation
    char operation;
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // perform operation on array elements
    switch (operation) {
        case '+':
            for (int i = 0; i < size; i++) {
                arr[i] += i;
            }
            break;
        case '-':
            for (int i = 0; i < size; i++) {
                arr[i] -= i;
            }
            break;
        case '*':
            for (int i = 0; i < size; i++) {
                arr[i] *= i;
            }
            break;
        case '/':
            for (int i = 0; i < size; i++) {
                arr[i] /= i;
            }
            break;
        default:
            printf("Invalid operation\n");
            return 1;
    }

    // display result
    printf("Result:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}