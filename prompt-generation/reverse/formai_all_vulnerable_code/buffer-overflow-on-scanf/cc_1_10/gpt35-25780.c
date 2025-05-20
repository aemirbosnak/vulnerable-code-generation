//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    int id;
    char category[20];
    char description[50];
    float amount;
};

// Function to display main menu
void displayMainMenu() {
    printf("\n======= Expense Tracker =======\n");
    printf("1. Add New Expense\n");
    printf("2. Display All Expenses\n");
    printf("3. Search Expenses by Category\n");
    printf("4. Delete Expense\n");
    printf("5. Exit\n");
    printf("===============================\n");
    printf("Enter your choice: ");
}

// Function to add new expense
void addExpense(struct Expense *e, int *count) {
    printf("\nEnter the following details:\n");
    printf("Category: ");
    scanf("%s", e[*count].category);
    printf("Description: ");
    scanf("%s", e[*count].description);
    printf("Amount: ");
    scanf("%f", &e[*count].amount);
    e[*count].id = *count + 1; // assign unique ID to each expense
    (*count)++;
}

// Function to display all expenses
void displayExpenses(struct Expense *e, int count) {
    if (count == 0) {
        printf("\nNo expenses have been added yet.\n");
        return;
    }
    printf("\n===== All Expenses =====\n");
    printf("ID\tCategory\tDescription\tAmount\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\t\t%.2f\n", e[i].id, e[i].category, e[i].description, e[i].amount);
    }
    printf("=========================\n");
}

// Function to search expenses by category
void searchExpenses(struct Expense *e, int count) {
    char searchCategory[20];
    printf("\nEnter the category you want to search: ");
    scanf("%s", searchCategory);
    printf("\n===== Expenses in %s Category =====\n", searchCategory);
    printf("ID\tCategory\tDescription\tAmount\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(e[i].category, searchCategory) == 0) {
            printf("%d\t%s\t\t%s\t\t%.2f\n", e[i].id, e[i].category, e[i].description, e[i].amount);
        }
    }
    printf("====================================\n");
}

// Function to delete expense
void deleteExpense(struct Expense *e, int *count) {
    int expenseID, found = 0;
    if (*count == 0) {
        printf("\nNo expenses have been added yet.\n");
        return;
    }
    printf("\nEnter the expense ID you want to delete: ");
    scanf("%d", &expenseID);
    for (int i = 0; i < *count; i++) {
        if (e[i].id == expenseID) {
            found = 1;
            for (int j = i; j < *count-1; j++) {
                e[j] = e[j+1]; // shifting all expenses after the deleted one by one position to the left
            }
            (*count)--;
            break;
        }
    }
    if (found) {
        printf("\nExpense with ID %d has been deleted successfully.\n", expenseID);
    } else {
        printf("\nExpense with ID %d not found.\n", expenseID);
    }
}

int main() {
    struct Expense expenses[100]; // array to store up to 100 expenses
    int choice, count = 0; // count variable to keep track of number of expenses added
    do {
        displayMainMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                searchExpenses(expenses, count);
                break;
            case 4:
                deleteExpense(expenses, &count);
                break;
            case 5:
                printf("\nThank you for using Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}