//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char date[11];
    char description[50];
    float amount;
};

int main() {
    struct Expense expenses[100];
    int num_expenses = 0;
    char option;

    do {
        printf("\nC EXPENSE TRACKER");
        printf("\nSelect an option:");
        printf("\n1. Add an Expense");
        printf("\n2. View All Expenses");
        printf("\n3. Exit");
        printf("\nOption: ");
        scanf(" %c", &option);

        switch(option) {
            case '1':
                printf("\nEnter expense date (MM/DD/YYYY format): ");
                scanf("%s", expenses[num_expenses].date);
                printf("Enter expense description: ");
                scanf(" %[^\n]s", expenses[num_expenses].description);
                printf("Enter expense amount: $");
                scanf("%f", &expenses[num_expenses].amount);
                num_expenses++;
                printf("\nExpense added successfully!\n");
                break;
            case '2':
                if(num_expenses == 0) {
                    printf("\nNo expenses have been added yet.\n");
                    break;
                }
                float total = 0;
                printf("\nExpenses\n");
                printf("%-15s %-50s %-10s\n", "Date", "Description", "Amount");
                for(int i = 0; i < num_expenses; i++) {
                    printf("%-15s %-50s $%-10.2f\n", expenses[i].date, expenses[i].description, expenses[i].amount);
                    total += expenses[i].amount;
                }
                printf("Total: $%.2f\n", total);
                break;
            case '3':
                printf("\nExiting expense tracker...\n");
                exit(0);
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while(1);

    return 0;
}