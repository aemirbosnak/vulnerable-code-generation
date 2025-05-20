//FormAI DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char category[20];
    float amount;
};

void displayMenu() {
    printf("Welcome to the Expense Tracker!\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses by Category\n");
    printf("3. View Total Expenses\n");
    printf("4. Quit\n");
    printf("\n");
}

int main() {
    int choice, numExpenses = 0;
    float totalExpenses = 0.0;
    struct Expense expenses[100];

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                printf("Enter the category of the expense: ");
                scanf("%s", &expenses[numExpenses].category);
                printf("Enter the amount of the expense: ");
                scanf("%f", &expenses[numExpenses].amount);
                totalExpenses += expenses[numExpenses].amount;
                numExpenses++;
                printf("Expense added successfully!\n");
                printf("\n");
                break;

            case 2:
                printf("Enter the category to search: ");
                char searchCategory[20];
                scanf("%s", &searchCategory);
                printf("\n");

                float categoryTotal = 0.0;
                int categoryExpenses = 0;

                for(int i = 0; i < numExpenses; i++) {
                    if(strcmp(searchCategory, expenses[i].category) == 0) {
                        printf("%s - $%.2f\n", expenses[i].category, expenses[i].amount);
                        categoryTotal += expenses[i].amount;
                        categoryExpenses++;
                    }
                }

                if(categoryExpenses == 0) {
                    printf("No expenses found for this category.\n");
                } else {
                    printf("\n");
                    printf("Total expenses for %s: $%.2f\n", searchCategory, categoryTotal);
                }
                printf("\n");
                break;

            case 3:
                printf("Total expenses: $%.2f\n", totalExpenses);
                printf("\n");
                break;

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select again.\n");
                printf("\n");
                break;
        }
    } while(choice != 4);

    return 0;
}