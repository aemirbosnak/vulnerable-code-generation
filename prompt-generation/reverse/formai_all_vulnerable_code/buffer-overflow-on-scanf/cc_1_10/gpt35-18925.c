//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int amount;
    char* category;
    char* date;
} Expense; // A struct to hold expense information

typedef struct {
    Expense* expenses;
    int size;
    int capacity;
} ExpenseList; // A dynamic array to hold a list of expenses

void addExpense(ExpenseList* list, Expense* expense) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->expenses = realloc(list->expenses, list->capacity * sizeof(Expense));
    }
    list->expenses[list->size++] = *expense;
}

int getTotalExpense(ExpenseList* list, char* category) {
    int totalExpense = 0;
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->expenses[i].category, category) == 0) {
            totalExpense += list->expenses[i].amount;
        }
    }
    return totalExpense;
}

int main() {
    ExpenseList list;
    list.size = 0;
    list.capacity = 1;
    list.expenses = malloc(sizeof(Expense));

    char option[10];
    do {
        printf("\n1. Add expense\n");
        printf("2. Get total expense for a category\n");
        printf("3. Exit\n");
        printf("Enter option (1-3): ");
        scanf("%s", option);

        if (strcmp(option, "1") == 0) {
            int amount;
            char* category = malloc(20 * sizeof(char));
            char* date = malloc(20 * sizeof(char));

            printf("Enter expense amount: ");
            scanf("%d", &amount);

            printf("Enter category: ");
            scanf("%s", category);

            printf("Enter date (dd-mm-yyyy): ");
            scanf("%s", date);

            Expense expense = { amount, category, date };
            addExpense(&list, &expense);
        }
        else if (strcmp(option, "2") == 0) {
            char* category = malloc(20 * sizeof(char));
            printf("Enter category: ");
            scanf("%s", category);
            int total = getTotalExpense(&list, category);
            printf("Total expense for category %s: %d\n", category, total);
        }
        else if (strcmp(option, "3") == 0) {
            printf("Exiting...\n");
        }
        else {
            printf("Invalid option!\n");
        }

    } while (strcmp(option, "3") != 0);

    return 0;
}