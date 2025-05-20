//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBERS 100
#define MAX_OPERATIONS 1000

typedef struct {
    int num1;
    int num2;
    int result;
} operation;

int main() {
    int num_operations = 0;
    operation *operations = malloc(MAX_OPERATIONS * sizeof(operation));
    int num1, num2;
    int choice;
    srand(time(NULL));

    do {
        printf("Enter the number of operations you want to perform (1-100): ");
        scanf("%d", &num_operations);
    } while (num_operations < 1 || num_operations > MAX_OPERATIONS);

    for (int i = 0; i < num_operations; i++) {
        printf("Enter two numbers: ");
        scanf("%d %d", &num1, &num2);
        operations[i].num1 = num1;
        operations[i].num2 = num2;
    }

    printf("Enter the operation you want to perform (+, -, *, /): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (int i = 0; i < num_operations; i++) {
                operations[i].result = operations[i].num1 + operations[i].num2;
            }
            break;
        case 2:
            for (int i = 0; i < num_operations; i++) {
                operations[i].result = operations[i].num1 - operations[i].num2;
            }
            break;
        case 3:
            for (int i = 0; i < num_operations; i++) {
                operations[i].result = operations[i].num1 * operations[i].num2;
            }
            break;
        case 4:
            for (int i = 0; i < num_operations; i++) {
                if (operations[i].num2 == 0) {
                    printf("Error: Division by zero\n");
                } else {
                    operations[i].result = operations[i].num1 / operations[i].num2;
                }
            }
            break;
        default:
            printf("Invalid operation\n");
            break;
    }

    printf("Results:\n");
    for (int i = 0; i < num_operations; i++) {
        printf("%d %c %d = %d\n", operations[i].num1, choice + 48, operations[i].num2, operations[i].result);
    }

    free(operations);
    return 0;
}