//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_CATEGORIES 50
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int category;
} expense;

int main() {
    int num_categories = 0, num_expenses = 0;
    expense categories[MAX_CATEGORIES], expenses[MAX_EXPENSES];
    char category_name[50];
    float category_total = 0.0;
    int category_count = 0;
    int choice;

    do {
        printf("\n");
        printf("1. Add expense\n");
        printf("2. Add category\n");
        printf("3. View expenses\n");
        printf("4. View categories\n");
        printf("5. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_expenses >= MAX_EXPENSES) {
                    printf("Maximum number of expenses reached.\n");
                } else {
                    printf("Enter expense name: ");
                    scanf("%s", expenses[num_expenses].name);
                    printf("Enter expense amount: ");
                    scanf("%f", &expenses[num_expenses].amount);
                    printf("Enter expense category (0-9): ");
                    scanf("%d", &expenses[num_expenses].category);
                    num_expenses++;
                }
                break;

            case 2:
                if (num_categories >= MAX_CATEGORIES) {
                    printf("Maximum number of categories reached.\n");
                } else {
                    printf("Enter category name: ");
                    scanf("%s", categories[num_categories].name);
                    printf("Enter category total: ");
                    scanf("%f", &categories[num_categories].amount);
                    num_categories++;
                }
                break;

            case 3:
                printf("\n");
                printf("Expense Name\tAmount\tCategory\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%s\t%.2f\t%d\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                }
                break;

            case 4:
                printf("\n");
                printf("Category Name\tTotal\n");
                for (int i = 0; i < num_categories; i++) {
                    printf("%s\t%.2f\n", categories[i].name, categories[i].amount);
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}