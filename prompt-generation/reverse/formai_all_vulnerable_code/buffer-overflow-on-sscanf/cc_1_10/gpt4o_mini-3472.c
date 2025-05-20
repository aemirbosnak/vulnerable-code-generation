//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_INPUT_SIZE 100

typedef struct {
    char operation[10];
    double operand1;
    double operand2;
    double result;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
} Ledger;

void initLedger(Ledger* ledger) {
    ledger->transactionCount = 0;
}

void addTransaction(Ledger* ledger, const char* operation, double operand1, double operand2, double result) {
    if (ledger->transactionCount >= MAX_TRANSACTIONS) {
        printf("Ledger is full, cannot add more transactions.\n");
        return;
    }
    strcpy(ledger->transactions[ledger->transactionCount].operation, operation);
    ledger->transactions[ledger->transactionCount].operand1 = operand1;
    ledger->transactions[ledger->transactionCount].operand2 = operand2;
    ledger->transactions[ledger->transactionCount].result = result;
    ledger->transactionCount++;
}

void displayLedger(const Ledger* ledger) {
    printf("\n--- Ledger of Transactions ---\n");
    for (int i = 0; i < ledger->transactionCount; i++) {
        printf("%d: %s(%.2f, %.2f) = %.2f\n", i + 1,
               ledger->transactions[i].operation,
               ledger->transactions[i].operand1,
               ledger->transactions[i].operand2,
               ledger->transactions[i].result);
    }
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero!\n");
        return 0;
    }
}

void processInput(Ledger* ledger) {
    char input[MAX_INPUT_SIZE];
    double operand1, operand2;
    char operation[10];

    printf("Enter transactions (format: operation operand1 operand2), type 'exit' to finish:\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        sscanf(input, "%s %lf %lf", operation, &operand1, &operand2);
        
        if (strcmp(operation, "exit") == 0) {
            break;
        }

        double result = 0;
        if (strcmp(operation, "add") == 0) {
            result = add(operand1, operand2);
        } else if (strcmp(operation, "subtract") == 0) {
            result = subtract(operand1, operand2);
        } else if (strcmp(operation, "multiply") == 0) {
            result = multiply(operand1, operand2);
        } else if (strcmp(operation, "divide") == 0) {
            result = divide(operand1, operand2);
        } else {
            printf("Invalid operation. Use add, subtract, multiply, divide.\n");
            continue;
        }

        addTransaction(ledger, operation, operand1, operand2, result);
        printf("Transaction added: %s(%.2f, %.2f) = %.2f\n", operation, operand1, operand2, result);
    }
}

int main() {
    Ledger ledger;
    initLedger(&ledger);
    processInput(&ledger);
    displayLedger(&ledger);

    return 0;
}