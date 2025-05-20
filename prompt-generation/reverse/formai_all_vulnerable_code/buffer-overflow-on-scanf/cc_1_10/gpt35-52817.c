//FormAI DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 50

// Structure to hold the expense details
struct Expense {
    char date[MAX_LENGTH];
    float amount;
    char category[MAX_LENGTH];
    char description[MAX_LENGTH];
};

int main() {
    int numExpenses = 0; // To keep track of number of expenses
    struct Expense *expenses; // Dynamic array to hold the expenses

    while(1) { // Loop until user chooses to exit
        printf("Select an option:\n");
        printf("1. Add expense\n2. View expenses\n3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Adding expense
                printf("Enter date (dd/mm/yyyy): ");
                char date[MAX_LENGTH];
                scanf("%s", date);

                float amount;
                printf("Enter amount: ");
                scanf("%f", &amount);

                printf("Enter category: ");
                char category[MAX_LENGTH];
                scanf("%s", category);

                printf("Enter description: ");
                char description[MAX_LENGTH];
                scanf("%s", description);

                // Allocate memory for a new expense and add to array
                numExpenses++;
                expenses = (struct Expense*) realloc(expenses, numExpenses * sizeof(struct Expense));

                strcpy(expenses[numExpenses-1].date, date);
                expenses[numExpenses-1].amount = amount;
                strcpy(expenses[numExpenses-1].category, category);
                strcpy(expenses[numExpenses-1].description, description);

                printf("Expense added successfully!\n\n");
                break;

            case 2: // Viewing expenses
                if(numExpenses == 0) {
                    printf("No expenses to show.\n\n");
                } else {
                    printf("Date\t| Amount\t| Category\t| Description\t\n");
                    printf("----------------------------------------------------\n");

                    for(int i = 0; i < numExpenses; i++) {
                        printf("%s\t| %.2f\t| %s\t| %s\n", expenses[i].date, expenses[i].amount, expenses[i].category, expenses[i].description);
                    }

                    printf("\n");
                }
                break;

            case 3: // Exiting
                printf("Thank you for using the expense tracker!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
}