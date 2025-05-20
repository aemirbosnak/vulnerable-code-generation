//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_NAME_LEN];
    double amount;
} expense_t;

int main() {
    int choice;
    expense_t expenses[MAX_EXPENSES];
    int num_expenses = 0;
    
    printf("Welcome to the Expense Tracker!\n");
    printf("1. Add Expense\n");
    printf("2. Remove Expense\n");
    printf("3. Display Expenses\n");
    printf("4. Total Amount Spent\n");
    printf("5. Exit\n");
    
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the name of the expense: ");
                scanf("%s", expenses[num_expenses].name);
                printf("Enter the description of the expense: ");
                scanf("%s", expenses[num_expenses].description);
                printf("Enter the amount of the expense: ");
                scanf("%lf", &expenses[num_expenses].amount);
                num_expenses++;
                break;
            case 2:
                printf("Enter the name of the expense to remove: ");
                scanf("%s", expenses[num_expenses].name);
                for (int i = 0; i < num_expenses; i++) {
                    if (strcmp(expenses[i].name, expenses[num_expenses].name) == 0) {
                        for (int j = i; j < num_expenses - 1; j++) {
                            expenses[j] = expenses[j + 1];
                        }
                        num_expenses--;
                        break;
                    }
                }
                break;
            case 3:
                if (num_expenses > 0) {
                    printf("Expenses:\n");
                    for (int i = 0; i < num_expenses; i++) {
                        printf("%s: %s - $%.2lf\n", expenses[i].name, expenses[i].description, expenses[i].amount);
                    }
                } else {
                    printf("No expenses to display.\n");
                }
                break;
            case 4:
                if (num_expenses > 0) {
                    double total_amount = 0.0;
                    for (int i = 0; i < num_expenses; i++) {
                        total_amount += expenses[i].amount;
                    }
                    printf("Total amount spent: $%.2lf\n", total_amount);
                } else {
                    printf("No expenses to display.\n");
                }
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}