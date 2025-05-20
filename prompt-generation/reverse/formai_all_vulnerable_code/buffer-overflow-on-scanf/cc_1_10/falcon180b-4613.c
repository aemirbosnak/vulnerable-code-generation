//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
} budget_item_t;

typedef struct {
    char name[20];
    int num_items;
    budget_item_t items[MAX_BUDGET_ITEMS];
} budget_category_t;

budget_category_t categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
    char name[20];
    printf("Enter category name: ");
    scanf("%s", name);

    for (int i = 0; i < num_categories; i++) {
        if (strcmp(name, categories[i].name) == 0) {
            printf("Category already exists.\n");
            return;
        }
    }

    strcpy(categories[num_categories].name, name);
    categories[num_categories].num_items = 0;
    num_categories++;
}

void add_item() {
    char name[50];
    float amount;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item amount: $");
    scanf("%f", &amount);

    for (int i = 0; i < num_categories; i++) {
        if (strcmp(categories[i].name, "Miscellaneous") == 0) {
            strcpy(categories[i].items[categories[i].num_items].name, name);
            categories[i].items[categories[i].num_items].amount = amount;
            categories[i].num_items++;
            return;
        }
    }

    printf("Category not found.\n");
}

void display_category(int category_index) {
    printf("Category: %s\n", categories[category_index].name);

    for (int i = 0; i < categories[category_index].num_items; i++) {
        printf("- %s: $%.2f\n", categories[category_index].items[i].name, categories[category_index].items[i].amount);
    }
}

int main() {
    num_categories = 0;

    while (num_categories < MAX_CATEGORIES) {
        printf("Enter category name (or press enter to finish): ");
        scanf("%s", categories[num_categories].name);

        if (strcmp(categories[num_categories].name, "") == 0) {
            break;
        }

        num_categories++;
    }

    while (1) {
        printf("\nPersonal Finance Planner\n");

        for (int i = 0; i < num_categories; i++) {
            printf("%d. %s\n", i + 1, categories[i].name);
        }

        printf("%d. Add category\n", num_categories + 1);
        printf("%d. Add item\n", num_categories + 2);
        printf("%d. Display budget\n", num_categories + 3);
        printf("%d. Quit\n", num_categories + 4);

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_category();
            break;
        case 2:
            add_item();
            break;
        case 3:
            printf("\nBudget:\n");

            for (int i = 0; i < num_categories; i++) {
                display_category(i);
            }

            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}