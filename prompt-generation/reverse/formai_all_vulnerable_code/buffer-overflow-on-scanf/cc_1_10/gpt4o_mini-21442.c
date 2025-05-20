//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define NAME_LEN 30

typedef struct {
    char name[NAME_LEN];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Whoa there! You're spending too much! Can't add more expenses!\n");
        return;
    }

    Expense new_expense;
    
    printf("Enter the name of the expense (you've gotta remember this!): ");
    scanf("%s", new_expense.name);
    
    printf("How much did it cost? (Your money!) ");
    scanf("%f", &new_expense.amount);
    
    expenses[expense_count] = new_expense;
    expense_count++;
    
    printf("Expense added: %s - $%.2f\n", new_expense.name, new_expense.amount);
}

void view_expenses() {
    if (expense_count == 0) {
        printf("You have not spent any money yet! (Probably smart...) \n");
        return;
    }

    printf("\nYour Expenses are like a bad breakup:\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, expenses[i].name, expenses[i].amount);
    }
    printf("\n");
}

void view_total() {
    float total = 0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    printf("You have spent a total of: $%.2f\n", total);
}

void clear_expenses() {
    expense_count = 0;
    printf("All expenses have been erased! Like that embarrassing text from last night...\n");
}

void funny_intro() {
    printf("Welcome to the Expense Tracker - because your bank account deserves some love and attention!\n\n");
}

void show_menu() {
    printf("Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. View Total Expenses\n");
    printf("4. Clear All Expenses\n");
    printf("5. Quit\n");
}

int main() {
    funny_intro();
    
    while (1) {
        show_menu();
        printf("Pick an option (1-5): ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                view_total();
                break;
            case 4:
                clear_expenses();
                break;
            case 5:
                printf("Goodbye! Remember, every dollar counts! (Especially when you're about to run out)\n");
                return 0;
            default:
                printf("Invalid choice! Come on, it's not rocket science.\n");
        }
        printf("\n");
    }

    return 0;
}