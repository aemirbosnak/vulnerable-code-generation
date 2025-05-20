//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_SIZE 50

typedef struct {
    char description[DESCRIPTION_SIZE];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    if (expense_count < MAX_EXPENSES) {
        printf("Enter expense description: ");
        scanf("%s", expenses[expense_count].description);
        printf("Enter expense amount: ");
        scanf("%f", &expenses[expense_count].amount);
        expense_count++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense limit reached!\n");
    }
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\nList of Expenses:\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

void save_expenses(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < expense_count; i++) {
        fprintf(file, "%s %.2f\n", expenses[i].description, expenses[i].amount);
    }
    
    fclose(file);
    printf("Expenses saved to %s\n", filename);
}

void load_expenses(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    while (fscanf(file, "%s %f", expenses[expense_count].description, &expenses[expense_count].amount) == 2) {
        expense_count++;
        if (expense_count >= MAX_EXPENSES) {
            printf("Expense limit reached!\n");
            break;
        }
    }

    fclose(file);
    printf("Expenses loaded from %s\n", filename);
}

void menu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Save Expenses\n");
    printf("4. Load Expenses\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    const char *filename = "expenses.txt";
    
    load_expenses(filename);
    
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            add_expense();
            break;
        case 2:
            view_expenses();
            break;
        case 3:
            save_expenses(filename);
            break;
        case 4:
            load_expenses(filename);
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}