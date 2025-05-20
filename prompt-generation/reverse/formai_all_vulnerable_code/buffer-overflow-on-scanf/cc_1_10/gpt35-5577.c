//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char type[20];
    float amount;
} Expense;

int main() {

    int numExpenses = 0; // counter for number of expenses
    Expense expenses[50]; // array to store expenses
    char input[20];
    float value;

    while (1) {
        printf("Enter a command (add, view, exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) { // add an expense
            printf("Enter expense type: ");
            scanf("%s", expenses[numExpenses].type);
            printf("Enter expense amount: ");
            scanf("%f", &expenses[numExpenses].amount);
            numExpenses++;
            printf("Expense added!\n");

        } else if (strcmp(input, "view") == 0) { // view expenses

            if (numExpenses == 0) {
                printf("No expenses to show!\n");
                continue;
            }

            // separate expenses into categories
            float totalFood = 0, totalRent = 0, totalEntertainment = 0;
            printf("Expenses: \n");
            for (int i = 0; i < numExpenses; i++) {
                if (strcmp(expenses[i].type, "food") == 0) {
                    totalFood += expenses[i].amount;
                } else if (strcmp(expenses[i].type, "rent") == 0) {
                    totalRent += expenses[i].amount;
                } else if (strcmp(expenses[i].type, "entertainment") == 0) {
                    totalEntertainment += expenses[i].amount;
                }

                printf("%s: $%.2f\n", expenses[i].type, expenses[i].amount);

            }

            // show totals for each category
            printf("Total for food: $%.2f\n", totalFood);
            printf("Total for rent: $%.2f\n", totalRent);
            printf("Total for entertainment: $%.2f\n", totalEntertainment);

        } else if (strcmp(input, "exit") == 0) { // exit the program
            printf("Goodbye!\n");
            break;

        } else { // invalid command
            printf("Invalid command!\n");

        }
    }

    return 0;
}