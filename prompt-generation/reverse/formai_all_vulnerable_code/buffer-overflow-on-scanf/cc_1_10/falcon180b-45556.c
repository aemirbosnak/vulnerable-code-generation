//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char category[50];
    char description[100];
    float amount;
};

int main() {
    int num_expenses = 0;
    struct expense expenses[MAX_EXPENSES];

    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("\nOptions:\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_expenses >= MAX_EXPENSES) {
                printf("Maximum number of expenses reached.\n");
                break;
            }
            printf("\nEnter expense details:\n");
            printf("Category: ");
            scanf("%s", expenses[num_expenses].category);
            printf("Description: ");
            scanf("%s", expenses[num_expenses].description);
            printf("Amount: ");
            scanf("%f", &expenses[num_expenses].amount);
            num_expenses++;
            break;
        case 2:
            printf("\nExpenses:\n");
            for (int i = 0; i < num_expenses; i++) {
                printf("%d. %s - %.2f\n", i+1, expenses[i].category, expenses[i].amount);
            }
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}