//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// structure to hold expense details
typedef struct {
    char name[50];
    char category[50];
    float amount;
    char date[20];
} Expense;

// function to add an expense
void addExpense(Expense expenses[], int count) {
    printf("Enter expense name: ");
    scanf("%s", expenses[count].name);

    printf("Enter expense category: ");
    scanf("%s", expenses[count].category);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[count].amount);

    printf("Enter expense date (dd/mm/yyyy): ");
    scanf("%s", expenses[count].date);

    count++;
}

// function to display all expenses
void displayExpenses(Expense expenses[], int count) {
    printf("\nExpenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-20s %-10.2f %s\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

// function to search for an expense by name
int searchExpense(Expense expenses[], int count, char name[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// function to delete an expense
void deleteExpense(Expense expenses[], int count, int index) {
    for (int i = index; i < count - 1; i++) {
        strcpy(expenses[i].name, expenses[i+1].name);
        strcpy(expenses[i].category, expenses[i+1].category);
        expenses[i].amount = expenses[i+1].amount;
        strcpy(expenses[i].date, expenses[i+1].date);
    }
    count--;
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;

    while (count < MAX_EXPENSES) {
        printf("\nEnter 1 to add an expense or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addExpense(expenses, count);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\nExpenses:\n");
    displayExpenses(expenses, count);

    char name[50];
    printf("\nEnter expense name to search: ");
    scanf("%s", name);

    int index = searchExpense(expenses, count, name);

    if (index!= -1) {
        printf("\nExpense found:\n");
        displayExpenses(expenses, count);

        printf("\nEnter 1 to delete this expense or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            deleteExpense(expenses, count, index);
            count--;
        } else if (choice == 0) {
            printf("\nExiting program...\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } else {
        printf("\nExpense not found.\n");
    }

    return 0;
}