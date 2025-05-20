//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    float amount;
    char category[20];
} Expense;

#define MAX_EXPENSES 100

Expense expenses[MAX_EXPENSES];
int currentExpense = 0;

void addExpense(const char* name, const char* category, float amount) {
    if (currentExpense >= MAX_EXPENSES) {
        printf("Error: Reached maximum number of expenses.\n");
        return;
    }

    strcpy(expenses[currentExpense].name, name);
    strcpy(expenses[currentExpense].category, category);
    expenses[currentExpense].amount = amount;

    currentExpense++;
}

void displayExpenses() {
    printf("\n**** The Enchanted Wallet ****\n");

    for (int i = 0; i < currentExpense; i++) {
        printf("\n%s\n", expenses[i].name);
        printf("Category: %s\n", expenses[i].category);
        printf("Amount: $%.2f\n", expenses[i].amount);
    }
}

int main() {
    char name[50], category[20];
    float amount;

    while (true) {
        printf("\n**** Welcome to The Enchanted Wallet ****\n");
        printf("Please enter the expense name: ");
        scanf("%s", name);

        printf("Enter the expense category: ");
        scanf("%s", category);

        printf("Enter the expense amount: ");
        scanf("%f", &amount);

        addExpense(name, category, amount);

        printf("Expense added successfully! Do you want to add another expense? (Y/N) ");
        char answer;
        scanf(" %c", &answer);

        if (answer != 'Y') {
            break;
        }
    }

    displayExpenses();

    return 0;
}