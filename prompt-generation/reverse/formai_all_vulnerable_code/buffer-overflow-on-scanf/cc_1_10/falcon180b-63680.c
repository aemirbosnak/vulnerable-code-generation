//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 20
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} expense;

int main() {
    int num_categories = 0;
    char categories[MAX_CATEGORIES][50];
    int num_expenses = 0;
    expense expenses[MAX_EXPENSES];

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\n");
        printf("1. Add an expense\n");
        printf("2. Add a category\n");
        printf("3. View expenses by category\n");
        printf("4. View all expenses\n");
        printf("5. Quit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_expenses >= MAX_EXPENSES) {
                printf("Sorry, you have reached the maximum number of expenses.\n");
            } else {
                printf("Enter the expense name: ");
                scanf("%s", &expenses[num_expenses].name);
                printf("Enter the expense amount: ");
                scanf("%f", &expenses[num_expenses].amount);
                printf("Enter the expense category: ");
                scanf("%s", &expenses[num_expenses].category);
                num_expenses++;
            }
            break;

        case 2:
            if (num_categories >= MAX_CATEGORIES) {
                printf("Sorry, you have reached the maximum number of categories.\n");
            } else {
                printf("Enter the category name: ");
                scanf("%s", &categories[num_categories]);
                num_categories++;
            }
            break;

        case 3:
            printf("\n");
            printf("Enter the category name: ");
            scanf("%s", &categories[num_categories]);
            num_categories++;
            break;

        case 4:
            printf("\n");
            for (int i = 0; i < num_expenses; i++) {
                printf("%s - %.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
            }
            break;

        case 5:
            printf("Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}