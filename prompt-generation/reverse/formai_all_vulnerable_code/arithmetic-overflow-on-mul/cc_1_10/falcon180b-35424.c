//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MAX_OPERATIONS 100

// Function prototypes
void generate_random_number(int *number);
void perform_operation(int *num1, int *num2, char operation, int *result);
void print_result(int result);

int main() {
    srand(time(NULL));

    int numbers[MAX_NUMBERS];
    char operations[MAX_OPERATIONS];
    int results[MAX_NUMBERS];
    int num_operations = 0;

    for (int i = 0; i < MAX_NUMBERS; i++) {
        generate_random_number(&numbers[i]);
        results[i] = numbers[i];
    }

    while (num_operations < MAX_OPERATIONS) {
        printf("Enter an operation (+, -, *, /): ");
        scanf("%c", &operations[num_operations]);

        int num1, num2;
        printf("Enter two numbers separated by a space: ");
        scanf("%d %d", &num1, &num2);

        perform_operation(&num1, &num2, operations[num_operations], &results[num_operations]);
        num_operations++;
    }

    for (int i = 0; i < num_operations; i++) {
        printf("Result of operation %d: ", i + 1);
        print_result(results[i]);
        printf("\n");
    }

    return 0;
}

void generate_random_number(int *number) {
    *number = rand() % 100;
}

void perform_operation(int *num1, int *num2, char operation, int *result) {
    switch (operation) {
        case '+':
            *result = *num1 + *num2;
            break;
        case '-':
            *result = *num1 - *num2;
            break;
        case '*':
            *result = *num1 * *num2;
            break;
        case '/':
            if (*num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                exit(1);
            }
            *result = *num1 / *num2;
            break;
        default:
            printf("Error: Invalid operation.\n");
            exit(1);
    }
}

void print_result(int result) {
    if (result >= 0) {
        printf("%.2f", result);
    } else {
        printf("-%.2f", result);
    }
}