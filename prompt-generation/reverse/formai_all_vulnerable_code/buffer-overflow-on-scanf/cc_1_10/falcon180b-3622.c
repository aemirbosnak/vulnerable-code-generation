//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_BUDGET 1000

typedef struct {
    char name[50];
    int budget;
} Category;

int main() {
    int num_categories;
    Category categories[MAX_CATEGORIES];
    char choice;
    int budget_left;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter the number of categories you want to create (up to %d): ", MAX_CATEGORIES);
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Please enter the name of category %d: ", i+1);
        scanf("%s", categories[i].name);
        printf("Please enter the budget for category %s: ", categories[i].name);
        scanf("%d", &categories[i].budget);
    }

    printf("Please enter the total budget you have for the month: ");
    scanf("%d", &budget_left);

    while (budget_left > 0) {
        printf("\nPlease choose an option:\n");
        printf("1. Add expense to a category\n");
        printf("2. View expenses for a category\n");
        printf("3. View total expenses\n");
        printf("4. View remaining budget\n");
        printf("5. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Please enter the name of the category: ");
                scanf("%s", categories[0].name);
                printf("Please enter the amount of the expense: ");
                scanf("%d", &categories[0].budget);
                budget_left -= categories[0].budget;
                printf("\nExpense added to %s\n", categories[0].name);
                break;
            case '2':
                printf("Please enter the name of the category: ");
                scanf("%s", categories[0].name);
                printf("\nExpenses for %s:\n", categories[0].name);
                for (int i = 0; i < num_categories; i++) {
                    if (strcmp(categories[i].name, categories[0].name) == 0) {
                        printf("%d\n", categories[i].budget);
                    }
                }
                break;
            case '3':
                printf("\nTotal expenses: %d\n", budget_left);
                break;
            case '4':
                printf("\nRemaining budget: %d\n", budget_left);
                break;
            case '5':
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}