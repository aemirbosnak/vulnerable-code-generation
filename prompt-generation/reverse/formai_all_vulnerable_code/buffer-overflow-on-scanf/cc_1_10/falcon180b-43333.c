//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} expense;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_expenses;
    expense expenses[MAX_EXPENSES];
} category;

int main() {
    category categories[MAX_CATEGORIES];
    int num_categories = 0;
    int choice;

    while (1) {
        printf("1. Add category\n2. View expenses\n3. Add expense\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_categories >= MAX_CATEGORIES) {
                printf("Maximum number of categories reached.\n");
                break;
            }

            printf("Enter category name: ");
            scanf("%s", categories[num_categories].name);
            categories[num_categories].num_expenses = 0;
            num_categories++;
            break;

        case 2:
            printf("Enter category name: ");
            scanf("%s", categories[num_categories - 1].name);
            for (int i = 0; i < categories[num_categories - 1].num_expenses; i++) {
                printf("Name: %s\nAmount: %.2f\n", categories[num_categories - 1].expenses[i].name, categories[num_categories - 1].expenses[i].amount);
            }
            break;

        case 3:
            printf("Enter category name: ");
            scanf("%s", categories[num_categories - 1].name);

            printf("Enter expense name: ");
            scanf("%s", categories[num_categories - 1].expenses[categories[num_categories - 1].num_expenses].name);
            printf("Enter expense amount: ");
            scanf("%f", &categories[num_categories - 1].expenses[categories[num_categories - 1].num_expenses].amount);
            categories[num_categories - 1].num_expenses++;
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}