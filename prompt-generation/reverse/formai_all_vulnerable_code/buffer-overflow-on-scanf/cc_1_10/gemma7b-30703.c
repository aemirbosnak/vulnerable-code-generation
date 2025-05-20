//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY 10

typedef struct HistoryEntry {
    char operator;
    double operand;
    struct HistoryEntry* next;
} HistoryEntry;

HistoryEntry* history = NULL;

void addToHistory(char operator, double operand) {
    HistoryEntry* newEntry = malloc(sizeof(HistoryEntry));
    newEntry->operator = operator;
    newEntry->operand = operand;
    newEntry->next = history;
    history = newEntry;

    if (history->next != NULL) {
        printf("History: ");
        for (HistoryEntry* entry = history; entry; entry = entry->next) {
            printf("%c %f ", entry->operator, entry->operand);
        }
        printf("\n");
    }
}

double calculate(char operator, double operand) {
    switch (operator) {
        case '+':
            return operand + 1;
        case '-':
            return operand - 1;
        case '*':
            return operand * 1;
        case '/':
            return operand / 1;
        default:
            return 0;
    }
}

int main() {
    char operator;
    double operand;

    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter operand: ");
    scanf("%lf", &operand);

    addToHistory(operator, operand);

    double result = calculate(operator, operand);

    printf("Result: %f\n", result);

    return 0;
}