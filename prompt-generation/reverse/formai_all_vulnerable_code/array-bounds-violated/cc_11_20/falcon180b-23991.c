//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_BUDGET 10000

typedef struct {
    char name[50];
    int id;
    double budget;
    int num_items;
    char *items[MAX_ITEMS];
    char *categories[MAX_CATEGORIES];
    int num_categories;
} Budget;

int main() {
    int choice;
    Budget budget;

    budget.id = 1;
    budget.num_items = 0;
    budget.num_categories = 0;

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Item\n");
        printf("2. Delete Item\n");
        printf("3. Edit Item\n");
        printf("4. Add Category\n");
        printf("5. Delete Category\n");
        printf("6. Edit Category\n");
        printf("7. View Budget\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter item name: ");
            scanf("%s", budget.items[budget.num_items]);
            budget.num_items++;
            break;
        case 2:
            printf("Enter item ID to delete: ");
            scanf("%d", &budget.id);
            break;
        case 3:
            printf("Enter new item name: ");
            scanf("%s", budget.items[budget.num_items - 1]);
            break;
        case 4:
            printf("Enter category name: ");
            scanf("%s", budget.categories[budget.num_categories]);
            budget.num_categories++;
            break;
        case 5:
            printf("Enter category ID to delete: ");
            scanf("%d", &budget.id);
            break;
        case 6:
            printf("Enter new category name: ");
            scanf("%s", budget.categories[budget.num_categories - 1]);
            break;
        case 7:
            printf("Budget:\n");
            for (int i = 0; i < budget.num_categories; i++) {
                printf("%s: $%.2f\n", budget.categories[i], budget.budget / budget.num_categories);
            }
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 8);

    return 0;
}