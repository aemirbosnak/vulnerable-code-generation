//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MIN_NUMBER -100
#define MAX_NUMBER 100

int main() {
    int num_operations;
    int num_numbers;
    int *numbers;
    char operation;
    double result;
    int i;
    srand(time(NULL));

    // Ask user for number of operations
    printf("Enter number of operations: ");
    scanf("%d", &num_operations);

    // Allocate memory for numbers
    numbers = (int *) malloc(sizeof(int) * num_operations);
    if (numbers == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Ask user for numbers
    for (i = 0; i < num_operations; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        if (numbers[i] < MIN_NUMBER || numbers[i] > MAX_NUMBER) {
            printf("Error: Number out of range.\n");
            free(numbers);
            return 1;
        }
    }

    // Ask user for operation
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform operation and print result
    switch (operation) {
        case '+':
            result = 0;
            for (i = 0; i < num_operations; i++) {
                result += numbers[i];
            }
            printf("Result: %lf\n", result);
            break;
        case '-':
            result = numbers[0];
            for (i = 1; i < num_operations; i++) {
                result -= numbers[i];
            }
            printf("Result: %lf\n", result);
            break;
        case '*':
            result = 1;
            for (i = 0; i < num_operations; i++) {
                result *= numbers[i];
            }
            printf("Result: %lf\n", result);
            break;
        case '/':
            result = numbers[0];
            for (i = 1; i < num_operations; i++) {
                result /= numbers[i];
            }
            printf("Result: %lf\n", result);
            break;
        default:
            printf("Error: Invalid operation.\n");
    }

    free(numbers);
    return 0;
}