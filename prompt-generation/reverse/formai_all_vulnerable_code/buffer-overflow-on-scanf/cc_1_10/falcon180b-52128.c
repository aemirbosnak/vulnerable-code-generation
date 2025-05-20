//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

int main() {
    int num_expenses = 0;
    Expense expenses[MAX_EXPENSES];
    char choice;

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. View Expenses by Category\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_expenses >= MAX_EXPENSES) {
                    printf("Maximum number of expenses reached.\n");
                } else {
                    printf("Enter expense name: ");
                    scanf("%s", expenses[num_expenses].name);
                    printf("Enter expense amount: ");
                    scanf("%f", &expenses[num_expenses].amount);
                    printf("Enter expense category: ");
                    scanf("%s", expenses[num_expenses].category);
                    num_expenses++;
                }
                break;
            case '2':
                printf("\nExpenses:\n");
                for(int i = 0; i < num_expenses; i++) {
                    printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                }
                break;
            case '3':
                printf("\nEnter category to view expenses: ");
                char category[50];
                scanf("%s", category);
                printf("\nExpenses in %s:\n", category);
                for(int i = 0; i < num_expenses; i++) {
                    if(strcmp(expenses[i].category, category) == 0) {
                        printf("%s - $%.2f\n", expenses[i].name, expenses[i].amount);
                    }
                }
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= '4');

    return 0;
}