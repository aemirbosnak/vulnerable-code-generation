//FormAI DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char category[30];
    float amount;
    char date[30];
};

int main() {
    struct expense expenses[100];
    int num_expenses = 0;
    char option;

    do {
        printf("Expense Tracker\n");
        printf("--------------\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. Exit\n");

        printf("Select an option: ");
        scanf(" %c", &option);

        switch(option) {
            case '1': {
                // Add expense
                printf("Add Expense\n");
                printf("-----------\n");

                // Get category
                printf("Enter category: ");
                scanf("%s", expenses[num_expenses].category);

                // Get amount
                printf("Enter amount: ");
                scanf("%f", &expenses[num_expenses].amount);

                // Get date
                printf("Enter date: ");
                scanf("%s", expenses[num_expenses].date);

                num_expenses++;
                break;
            }
            case '2': {
                // View expenses
                printf("Expenses\n");
                printf("--------\n");
                printf("Category\tAmount\tDate\n");
                printf("---------------------------------------------\n");
                for(int i = 0; i < num_expenses; i++) {
                    printf("%s\t\t%.2f\t%s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
                }
                printf("---------------------------------------------\n");
                break;
            }
            case '3': {
                // Exit
                printf("Exiting program...\n");
                exit(0);
                break;
            }
            default: {
                printf("Invalid option!\n");
                break;
            }
        }

        // Pause program to allow user to read output
        printf("Press ENTER to continue...");
        while(getchar() != '\n');
        getchar();
        printf("\033[2J\033[1;1H"); // Clear screen
    } while(option != '3');

    return 0;
}