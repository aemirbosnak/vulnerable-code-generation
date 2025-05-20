//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_LENGTH 256

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    printf("Welcome to the Expense Tracker!\n");
    printf("What would you like to do?\n");
    printf("1. Add an expense\n");
    printf("2. Print all expenses\n");
    printf("3. Exit\n");

    while (1) {
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the description of the expense: ");
                scanf("%s", expenses[num_expenses].description);
                printf("Enter the amount of the expense: ");
                scanf("%f", &expenses[num_expenses].amount);
                num_expenses++;
                break;
            case 2:
                printf("Here is a list of all expenses:\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%s: %f\n", expenses[i].description, expenses[i].amount);
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}