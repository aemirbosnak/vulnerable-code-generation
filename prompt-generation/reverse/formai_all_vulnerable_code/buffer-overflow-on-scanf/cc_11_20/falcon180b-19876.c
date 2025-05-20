//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000

int main() {
    int num_operations;
    int numbers[MAX_NUMBERS];
    int i;
    int operation;
    int result;
    int valid_input;

    srand(time(NULL));

    // Prompt user for number of operations
    do {
        printf("Enter the number of operations: ");
        scanf("%d", &num_operations);
        valid_input = 1;
    } while (num_operations <= 0 || num_operations > MAX_NUMBERS);

    // Prompt user for input numbers
    for (i = 0; i < num_operations; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Prompt user for operations
    for (i = 0; i < num_operations; i++) {
        do {
            printf("Enter operation for number %d (1 for addition, 2 for subtraction, 3 for multiplication, 4 for division): ", i + 1);
            scanf("%d", &operation);
            valid_input = 1;
        } while (operation < 1 || operation > 4);

        switch (operation) {
            case 1:
                result = numbers[i] + numbers[i];
                break;
            case 2:
                result = numbers[i] - numbers[i];
                break;
            case 3:
                result = numbers[i] * numbers[i];
                break;
            case 4:
                if (numbers[i] == 0) {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                result = numbers[i] / numbers[i];
                break;
            default:
                printf("Error: Invalid operation\n");
                exit(1);
        }

        printf("Result for number %d: %d\n", i + 1, result);
    }

    return 0;
}