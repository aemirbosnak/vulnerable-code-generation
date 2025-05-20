//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }
    
    Expense new_expense;
    printf("Enter expense description: ");
    getchar(); // Clear newline before getting input
    fgets(new_expense.description, MAX_DESC_LEN, stdin);
    new_expense.description[strcspn(new_expense.description, "\n")] = 0; // Remove newline

    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);

    expenses[expense_count] = new_expense;
    expense_count++;
    printf("Expense added successfully!\n");
}

void display_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }
    
    float total = 0.0;
    printf("Expense Report:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
        total += expenses[i].amount;
    }
    printf("---------------------------------------------------\n");
    printf("Total Expenses: $%.2f\n", total);
}

void search_expense() {
    char search_term[MAX_DESC_LEN];
    printf("Enter the description to search for: ");
    getchar(); // Clear newline before getting input
    fgets(search_term, MAX_DESC_LEN, stdin);
    search_term[strcspn(search_term, "\n")] = 0; // Remove newline

    printf("Search Results:\n");
    printf("---------------------------------------------------\n");
    int found = 0;
    for (int i = 0; i < expense_count; i++) {
        if (strstr(expenses[i].description, search_term) != NULL) {
            printf("%d. %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
            found = 1;
        }
    }
    if (!found) {
        printf("No expenses found with the description: %s\n", search_term);
    }
    printf("---------------------------------------------------\n");
}

void delete_expense() {
    int index;
    printf("Enter the expense index to delete (1 to %d): ", expense_count);
    scanf("%d", &index);
    if (index < 1 || index > expense_count) {
        printf("Invalid index! Please try again.\n");
        return;
    }
    index--; // Adjust for 0-based index
    for (int i = index; i < expense_count - 1; i++) {
        expenses[i] = expenses[i + 1]; // Shift expenses down
    }
    expense_count--;
    printf("Expense deleted successfully!\n");
}

void display_menu() {
    printf("\n--- Expense Tracker ---\n");
    printf("1. Add an Expense\n");
    printf("2. Display All Expenses\n");
    printf("3. Search an Expense\n");
    printf("4. Delete an Expense\n");
    printf("5. Exit\n");
    printf("-----------------------\n");
}

int main() {
    int choice;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                search_expense();
                break;
            case 4:
                delete_expense();
                break;
            case 5:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}