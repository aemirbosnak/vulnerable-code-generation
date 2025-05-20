//FormAI DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char category[20];
    float amount;
};

int main() {

    struct Expense expenses[100];
    int num_expenses = 0;

    while(1) {

        printf("\nChoose an option:\n1. Add Expense\n2. View Expenses by Category\n3. View Total Expenses\n4. Quit\n");
        int choice;
        scanf("%d", &choice);

        if(choice == 1) {

            printf("\nEnter the expense category:");
            scanf("%s", expenses[num_expenses].category);

            printf("Enter the expense amount:");
            scanf("%f", &expenses[num_expenses].amount);

            printf("\nExpense added successfully!\n");
            num_expenses++;

        } else if(choice == 2) {

            printf("\nEnter the category to view expenses:");
            char category[20];
            scanf("%s", category);

            float total_spent = 0;
            int found = 0;

            for(int i = 0; i < num_expenses; i++) {
                if(strcmp(expenses[i].category, category) == 0) {
                    printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
                    found = 1;
                    total_spent += expenses[i].amount;
                }
            }

            if(found == 0) {
                printf("\nNo expenses found in the category '%s'\n", category);
            } else {
                printf("\nTotal spent in the category '%s': $%.2f\n", category, total_spent);
            }

        } else if(choice == 3) {

            float total_spent = 0;

            for(int i = 0; i < num_expenses; i++) {
                total_spent += expenses[i].amount;
            }

            printf("\nTotal expenses: $%.2f\n", total_spent);

        } else if(choice == 4) {

            printf("\nThank you for using the Expense Tracker!\n");
            break;

        } else {

            printf("\nInvalid choice. Try again!\n");

        }
    }

    return 0;
}