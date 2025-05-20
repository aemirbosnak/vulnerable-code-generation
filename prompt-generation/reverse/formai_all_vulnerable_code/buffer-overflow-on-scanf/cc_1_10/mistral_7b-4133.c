//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Expense {
    char description[50];
    float amount;
    struct Expense* next;
} Expense;

Expense* head = NULL;

void addExpense(char* description, float amount) {
    Expense* newExpense = (Expense*) malloc(sizeof(Expense));
    strcpy(newExpense->description, description);
    newExpense->amount = amount;
    newExpense->next = head;
    head = newExpense;
}

void displayExpenses() {
    Expense* current = head;
    printf("\n****** Welcome to Sunshine Expense Tracker ******\n");
    printf("-----------------------------------------------\n");
    printf("| %-45s | %10s |\n", "Description", "Amount");
    printf("-----------------------------------------------\n");
    while (current != NULL) {
        printf("| %-45s | %10.2f |\n", current->description, current->amount);
        current = current->next;
    }
}

int main() {
    char description[50];
    float amount;
    bool quit = false;

    printf("\n*********** Sunshine Expense Tracker ***********\n");
    printf("************************************************\n");

    while (!quit) {
        printf("\nEnter expense description: ");
        scanf("%s", description);
        printf("Enter expense amount: $");
        scanf("%f", &amount);

        addExpense(description, amount);

        printf("\nWould you like to add another expense? (Y/N) ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'N') {
            quit = true;
        }
    }

    printf("\nExpenses added successfully!\n");
    displayExpenses();

    Expense* temp = head;
    while (temp != NULL) {
        Expense* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}