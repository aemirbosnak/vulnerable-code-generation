//FormAI DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Category { GROCERY, TRANSPORTATION, ENTERTAINMENT, UTILITIES };

struct Expense {
    int id;
    char item[50];
    double amount;
    enum Category category;
};

void displayCategories() {
    printf("Categories:\n");
    printf("1. Grocery\n");
    printf("2. Transportation\n");
    printf("3. Entertainment\n");
    printf("4. Utilities\n");
}

void displayExpenses(struct Expense *expenses, int count) {
    if(count == 0) {
        printf("No expenses found!\n");
        return;
    }
    printf("\nExpenses:\n");
    printf("%-15s %-15s %-15s %-15s\n", "ID", "Item", "Amount", "Category");
    for(int i = 0; i < count; i++) {
        printf("%-15d %-15s %-15.2lf %-15d\n", expenses[i].id, expenses[i].item, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    struct Expense expenses[50];
    int count = 0;
    int choice = 0;
    char decision = 'n';

    while(1) {

        printf("\nWelcome to Expense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                struct Expense expense;

                printf("\nAdd Expense\n");
                printf("Enter item name: ");
                scanf("%s", expense.item);
                printf("Enter amount: ");
                scanf("%lf", &expense.amount);
                displayCategories();
                printf("Enter category: ");
                scanf("%d", &expense.category);

                expense.id = count + 1;

                expenses[count++] = expense;

                printf("Expense added successfully!\n");
                break;
            }
            case 2: {
                displayExpenses(expenses, count);
                break;
            }
            case 3: {
                printf("Are you sure you want to exit? (y/n): ");
                fflush(stdin);
                scanf("%c", &decision);
                if(decision == 'y') {
                    printf("Thank you for using Expense Tracker!\n");
                    exit(0);
                }
                break;
            }
            default: {
                printf("Invalid choice! Please try again.\n");
                break;
            }
        }

    }

    return 0;
}