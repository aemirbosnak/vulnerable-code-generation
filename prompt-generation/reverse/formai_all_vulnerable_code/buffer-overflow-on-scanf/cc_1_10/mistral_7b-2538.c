//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Expense {
    char name[50];
    float amount;
    time_t timestamp;
} Expense;

#define MAX_EXPENSES 100

Expense expenses[MAX_EXPENSES];
int currentExpense = 0;

void printMenu() {
    printf("\nCreative Expense Tracker\n");
    printf("-------------------------\n");
    printf("1. Add Expense\n");
    printf("2. List Expenses\n");
    printf("3. Search Expenses\n");
    printf("4. Total Expenses\n");
    printf("5. Quit\n");
}

void addExpense(char* name, float amount) {
    if (currentExpense >= MAX_EXPENSES) {
        printf("Expenses limit reached! Delete some expenses to add new ones.\n");
        return;
    }

    strcpy(expenses[currentExpense].name, name);
    expenses[currentExpense].amount = amount;
    expenses[currentExpense].timestamp = time(NULL);

    currentExpense++;
}

void listExpenses() {
    printf("Expenses List:\n");
    for (int i = 0; i < currentExpense; i++) {
        printf("%d. %s: $%.2f (%s)\n", i+1, expenses[i].name, expenses[i].amount, ctime(&expenses[i].timestamp));
    }
}

void searchExpenses(char* keyword) {
    int found = 0;

    printf("Expenses containing '%s':\n", keyword);

    for (int i = 0; i < currentExpense; i++) {
        if (strstr(expenses[i].name, keyword) != NULL) {
            printf("%s: $%.2f (%s)\n", expenses[i].name, expenses[i].amount, ctime(&expenses[i].timestamp));
            found = 1;
        }
    }

    if (!found) {
        printf("No expenses found with the keyword '%s'\n", keyword);
    }
}

void totalExpenses() {
    float total = 0.0;

    printf("Total Expenses: $%.2f\n", total);

    for (int i = 0; i < currentExpense; i++) {
        total += expenses[i].amount;
    }
}

int main() {
    char input[10];
    char name[50];
    float amount;
    int choice;

    while (1) {
        printMenu();
        scanf("%s", input);

        switch(input[0]) {
            case '1':
                printf("Enter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addExpense(name, amount);
                break;
            case '2':
                listExpenses();
                break;
            case '3':
                printf("Enter keyword to search: ");
                scanf("%s", input);
                searchExpenses(input);
                break;
            case '4':
                totalExpenses();
                break;
            case '5':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}