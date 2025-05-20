//FormAI DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char category[20];
    float amount;
};

void addExpense(struct Expense expenses[], int *numExpenses);
void editExpense(struct Expense expenses[], int numExpenses);
void deleteExpense(struct Expense expenses[], int *numExpenses);
void displayExpenses(struct Expense expenses[], int numExpenses);
void displayMenu();

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char input;

    do {
        displayMenu();
        scanf(" %c", &input);

        switch(input) {
            case '1':
                addExpense(expenses, &numExpenses);
                break;
            case '2':
                editExpense(expenses, numExpenses);
                break;
            case '3':
                deleteExpense(expenses, &numExpenses);
                break;
            case '4':
                displayExpenses(expenses, numExpenses);
                break;
            case '5':
                printf("Exiting program...");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while(input != '5');

    return 0;
}

void addExpense(struct Expense expenses[], int *numExpenses) {
    if(*numExpenses >= MAX_EXPENSES) {
        printf("Cannot add additional expenses. Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense category: ");
    scanf("%s", expenses[*numExpenses].category);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);

    (*numExpenses)++;
    printf("Expense added successfully!\n");
}

void editExpense(struct Expense expenses[], int numExpenses) {
    int choice;

    displayExpenses(expenses, numExpenses);

    printf("Which expense would you like to edit? (Choose index number):\n");
    scanf("%d", &choice);

    if(choice >= 0 && choice < numExpenses) {
        printf("Enter new expense category: ");
        scanf("%s", expenses[choice].category);

        printf("Enter new expense amount: ");
        scanf("%f", &expenses[choice].amount);

        printf("Expense edited successfully!\n");
    } else {
        printf("Invalid index number. Please try again.\n");
    }
}

void deleteExpense(struct Expense expenses[], int *numExpenses) {
    int choice;

    displayExpenses(expenses, *numExpenses);

    printf("Which expense would you like to delete? (Choose index number):\n");
    scanf("%d", &choice);

    if(choice >= 0 && choice < *numExpenses) {
        for(int i = choice; i < *numExpenses-1; i++) {
            strcpy(expenses[i].category, expenses[i+1].category);
            expenses[i].amount = expenses[i+1].amount;
        }

        (*numExpenses)--;
        printf("Expense deleted successfully!\n");
    } else {
        printf("Invalid index number. Please try again.\n");
    }
}

void displayExpenses(struct Expense expenses[], int numExpenses) {
    if(numExpenses == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("Expense List:\n");
    for(int i = 0; i < numExpenses; i++) {
        printf("%d. %s\t\t$%.2f\n", i, expenses[i].category, expenses[i].amount);
    }
}

void displayMenu() {
    printf("\nExpense Tracker\n");
    printf("1. Add expense\n");
    printf("2. Edit expense\n");
    printf("3. Delete expense\n");
    printf("4. Display expenses\n");
    printf("5. Exit\n");
    printf("What would you like to do? ");
}