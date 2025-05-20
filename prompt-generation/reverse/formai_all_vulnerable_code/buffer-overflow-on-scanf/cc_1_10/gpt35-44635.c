//FormAI DATASET v1.0 Category: Expense Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char name[256];
    float amount;
    char description[256];
};

void displayMenu() {
    printf("\n\nExpense Tracker\n");
    printf("1. Add Expense\n");
    printf("2. Show Expense List\n");
    printf("3. Search Expense\n");
    printf("4. Exit\n\n");
}

void addExpense(struct Expense expenses[], int *index) {
    printf("\n\nAdd Expense\n");
    
    // get expense details from user
    struct Expense expense;
    printf("Enter expense name: ");
    scanf("%s", &expense.name);
    
    printf("Enter amount: ");
    scanf("%f", &expense.amount);
    
    printf("Enter description: ");
    scanf("%s", &expense.description);
    
    // add expense to list
    expenses[*index] = expense;
    (*index)++;
    
    printf("\nExpense has been added successfully!\n");
}

void showExpenseList(struct Expense expenses[], int index) {
    if (index == 0) {
        printf("There are no expenses to display.\n");
    } else {
        printf("\n\nExpense List\n");
        
        // display all expenses
        for (int i = 0; i < index; i++) {
            printf("Expense %d\n", i + 1);
            printf(" Name: %s\n", expenses[i].name);
            printf(" Amount: $%.2f\n", expenses[i].amount);
            printf(" Description: %s\n\n", expenses[i].description);
        }
    }
}

void searchExpense(struct Expense expenses[], int index) {
    printf("\n\nSearch Expense\n");
    
    // get search string from user
    char search[256];
    printf("Enter search string: ");
    scanf("%s", &search);
    
    int found = 0;
    
    // search for matching expenses
    for (int i = 0; i < index; i++) {
        if (strstr(expenses[i].name, search) || strstr(expenses[i].description, search)) {
            printf("Expense %d\n", i + 1);
            printf(" Name: %s\n", expenses[i].name);
            printf(" Amount: $%.2f\n", expenses[i].amount);
            printf(" Description: %s\n\n", expenses[i].description);
            found++;
        }
    }
    
    if (!found) {
        printf("No expenses matched your search.\n");
    }
}

int main() {
    struct Expense expenses[100];
    int index = 0;
    
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(expenses, &index);
                break;
            case 2:
                showExpenseList(expenses, index);
                break;
            case 3:
                searchExpense(expenses, index);
                break;
            case 4:
                printf("Goodbye!\n\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    
    return 0;
}