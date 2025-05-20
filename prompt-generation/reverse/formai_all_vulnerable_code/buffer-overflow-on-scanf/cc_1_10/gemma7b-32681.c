//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 10

typedef struct Expense {
    char name[20];
    float amount;
    struct Expense* next;
} Expense;

void addExpense(Expense* head, char* name, float amount) {
    Expense* newExpense = malloc(sizeof(Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if (head == NULL) {
        head = newExpense;
    } else {
        head->next = newExpense;
    }
}

void printExpenses(Expense* head) {
    Expense* currentExpense = head;
    while (currentExpense) {
        printf("%s: %.2f\n", currentExpense->name, currentExpense->amount);
        currentExpense = currentExpense->next;
    }
}

int main() {

    Expense* head = NULL;

    // Multiplayer interaction
    char name[20];
    float amount;

    printf("Enter expense name:");
    scanf("%s", name);

    printf("Enter expense amount:");
    scanf("%f", &amount);

    addExpense(head, name, amount);

    printExpenses(head);

    return 0;
}