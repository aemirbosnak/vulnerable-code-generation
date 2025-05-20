//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_OPERANDS 5
#define MIN_VALUE -100
#define MAX_VALUE 100

typedef struct {
    int value;
    char operation;
} Operand;

void print_operands(Operand operands[], int num_operands) {
    for (int i = 0; i < num_operands; i++) {
        printf("Operand %d: Value = %d, Operation = %c\n", i + 1, operands[i].value, operands[i].operation);
    }
}

int perform_arithmetic(Operand operands[], int num_operands) {
    int result = operands[0].value;

    for (int i = 1; i < num_operands; i++) {
        switch (operands[i].operation) {
            case '+':
                result += operands[i].value;
                break;
            case '-':
                result -= operands[i].value;
                break;
            case '*':
                result *= operands[i].value;
                break;
            case '/':
                if (operands[i].value == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                    exit(EXIT_FAILURE);
                }
                result /= operands[i].value;
                break;
            default:
                printf("Error: Invalid operation symbol.\n");
                exit(EXIT_FAILURE);
        }
    }

    return result;
}

int main() {
    Operand operands[MAX_OPERANDS];
    int num_operands = 0;
    int input;

    printf("Enter the number of operands (max %d): ", MAX_OPERANDS);
    scanf("%d", &input);

    if (input > MAX_OPERANDS) {
        printf("Error: Maximum number of operands exceeded.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter operands and their corresponding operations (+, -, *, /):\n");

    for (int i = 0; i < input; i++) {
        scanf("%d%c", &operands[i].value, &operands[i].operation);
        num_operands++;
    }

    int result = perform_arithmetic(operands, num_operands);

    print_operands(operands, num_operands);

    printf("\nResult: %d\n", result);

    return EXIT_SUCCESS;
}