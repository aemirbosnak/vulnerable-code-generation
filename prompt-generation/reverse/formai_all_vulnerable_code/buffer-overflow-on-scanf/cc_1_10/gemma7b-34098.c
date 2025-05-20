//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10

struct Expense {
    char name[50];
    int amount;
    char category[50];
};

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    // Loop to get expenses
    while (1) {
        printf("Enter expense name: ");
        scanf("%s", expenses[numExpenses].name);

        printf("Enter expense amount: ");
        scanf("%d", &expenses[numExpenses].amount);

        printf("Enter expense category: ");
        scanf("%s", expenses[numExpenses].category);

        numExpenses++;

        // Check if user wants to continue
        char continue_or_not;
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &continue_or_not);

        if (continue_or_not == 'N') {
            break;
        }
    }

    // Print expenses
    printf("Here is a list of your expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: %d\n", expenses[i].amount);
        printf("Category: %s\n", expenses[i].category);
        printf("\n");
    }

    return 0;
}