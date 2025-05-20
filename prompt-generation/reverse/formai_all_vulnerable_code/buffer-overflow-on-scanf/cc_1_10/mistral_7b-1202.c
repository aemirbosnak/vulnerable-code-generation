//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY 10

typedef struct {
    float num1;
    float num2;
    float result;
    char op;
} CalcHistory;

void displayMenu();
void performOperation(CalcHistory *history, int *currentIndex, float num1, float num2, char op);
void printHistory(CalcHistory *history, int size);

int main() {
    CalcHistory history[MAX_HISTORY];
    int currentIndex = 0;

    while (1) {
        displayMenu();
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
            case 'a': {
                float num1, num2;
                char op;
                printf("Enter first number: ");
                scanf("%f", &num1);
                printf("Enter second number: ");
                scanf("%f", &num2);
                printf("Enter operator (+, -, *, /): ");
                scanf(" %c", &op);

                performOperation(history, &currentIndex, num1, num2, op);
                break;
            }
            case 'H':
            case 'h': {
                printf("\nCalculation History:\n");
                printHistory(history, currentIndex);
                break;
            }
            case 'E':
            case 'e': {
                printf("\nExiting the calculator...\n");
                exit(0);
            }
            default: {
                printf("Invalid option! Please try again.\n");
            }
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nCalculator Menu:\n");
    printf("---------------------\n");
    printf("A. Addition\n");
    printf("S. Subtraction\n");
    printf("M. Multiplication\n");
    printf("D. Division\n");
    printf("H. History\n");
    printf("E. Exit\n");
}

void performOperation(CalcHistory *history, int *currentIndex, float num1, float num2, char op) {
    (*currentIndex)++;

    if (*currentIndex >= MAX_HISTORY) {
        printf("Calculation history is full! Clear the history first.\n");
        (*currentIndex)--;
        return;
    }

    history[*currentIndex].num1 = num1;
    history[*currentIndex].num2 = num2;

    switch (op) {
        case '+': {
            history[*currentIndex].result = num1 + num2;
            break;
        }
        case '-': {
            history[*currentIndex].result = num1 - num2;
            break;
        }
        case '*': {
            history[*currentIndex].result = num1 * num2;
            break;
        }
        case '/': {
            if (num2 == 0) {
                printf("Cannot divide by zero!\n");
                (*currentIndex)--;
                return;
            }
            history[*currentIndex].result = num1 / num2;
            break;
        }
        default: {
            printf("Invalid operator!\n");
            (*currentIndex)--;
            return;
        }
    }

    history[*currentIndex].op = op;
}

void printHistory(CalcHistory *history, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("\nIndex: %d", i);
        printf("\nNumber 1: %.2f", history[i].num1);
        printf("\nNumber 2: %.2f", history[i].num2);
        printf("\nOperation: %c", history[i].op);
        printf("\nResult: %.2f", history[i].result);
    }
}