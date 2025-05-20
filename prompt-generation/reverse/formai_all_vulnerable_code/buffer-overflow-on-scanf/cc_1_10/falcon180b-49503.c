//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Define structure for expenses
typedef struct {
    char category[50];
    char description[100];
    float amount;
    char date[20];
} Expense;

void addExpense(Expense *expenses, int *numExpenses) {
    printf("Enter expense category: ");
    scanf("%s", (*expenses).category);
    printf("Enter expense description: ");
    scanf("%s", (*expenses).description);
    printf("Enter expense amount: ");
    scanf("%f", &(*expenses).amount);
    strcpy((*expenses).date, "Today");
    (*numExpenses)++;
}

void displayExpenses(Expense expenses[], int numExpenses) {
    printf("\nExpense List:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%d. Category: %s, Description: %s, Amount: $%.2f, Date: %s\n", i+1, expenses[i].category, expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

void searchExpense(Expense expenses[], int numExpenses, char *category) {
    int found = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("\nExpense found:\n");
            printf("Category: %s\n", expenses[i].category);
            printf("Description: %s\n", expenses[i].description);
            printf("Amount: $%.2f\n", expenses[i].amount);
            printf("Date: %s\n", expenses[i].date);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Expense not found.\n");
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    printf("Welcome to the Expense Tracker!\n\n");

    while (numExpenses < MAX_EXPENSES) {
        printf("\nEnter 1 to add an expense or 0 to exit:\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            addExpense(expenses, &numExpenses);
        } else if (choice == 0) {
            break;
        }
    }

    printf("\nEnter a category to search for expenses:\n");
    char category[50];
    scanf("%s", category);
    searchExpense(expenses, numExpenses, category);

    printf("\nExpense List:\n");
    displayExpenses(expenses, numExpenses);

    return 0;
}