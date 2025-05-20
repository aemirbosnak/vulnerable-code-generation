//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float amount;
    char category[30];
} Expense;

void createExpense(Expense *expenses, int capacity, char *name, float amount, char *category) {
    if (capacity <= capacity) {
        printf("Error: Expenses array is full.\n");
        return;
    }

    strcpy(expenses[capacity - 1].name, name);
    expenses[capacity - 1].amount = amount;
    strcpy(expenses[capacity - 1].category, category);
}

void printExpenses(Expense *expenses, int count) {
    for (int i = 0; i < count; i++) {
        printf("\n%s\n%s: $%.2f", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

int main() {
    int capacity = 10;
    Expense *expenses = (Expense *)malloc(capacity * sizeof(Expense));
    int numExpenses = 0;

    while (1) {
        char name[50], category[30];
        float amount;
        printf("\nEnter expense name: ");
        scanf("%s", name);
        printf("Enter expense amount: ");
        scanf("%f", &amount);
        printf("Enter expense category: ");
        scanf("%s", category);

        createExpense(expenses, capacity, name, amount, category);
        numExpenses++;

        char choice;
        printf("\nDo you want to add another expense? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'N') {
            break;
        }

        if (numExpenses >= capacity) {
            printf("Error: Expenses array is full. Increase array size.\n");
            capacity *= 2;
            Expense *newExpenses = (Expense *)realloc(expenses, capacity * sizeof(Expense));
            if (newExpenses == NULL) {
                printf("Error: Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
            expenses = newExpenses;
        }
    }

    printf("\nTotal expenses:\n");
    printExpenses(expenses, numExpenses);

    free(expenses);

    return 0;
}