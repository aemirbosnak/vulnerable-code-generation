//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 50
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    double amount;
} item;

void add_category(char *categories[], int num_categories, char *category) {
    int i;
    for (i = 0; i < num_categories; i++) {
        if (strcmp(categories[i], category) == 0) {
            return;
        }
    }
    categories[num_categories] = strdup(category);
    num_categories++;
}

void add_item(item *items, int num_items, char *name, char *category, double amount) {
    items[num_items].name[0] = '\0';
    items[num_items].category[0] = '\0';
    strcpy(items[num_items].name, name);
    strcpy(items[num_items].category, category);
    items[num_items].amount = amount;
    num_items++;
}

void print_items(item *items, int num_items) {
    int i;
    for (i = 0; i < num_items; i++) {
        printf("Category: %s\n", items[i].category);
        printf("Item: %s\n", items[i].name);
        printf("Amount: $%.2f\n", items[i].amount);
        printf("\n");
    }
}

int main() {
    char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];
    int num_categories = 0;
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    double amount;
    int choice;
    item items[MAX_ITEMS];
    int num_items = 0;

    printf("Expense Tracker\n");
    printf("-----------------\n");

    do {
        printf("1. Add expense\n");
        printf("2. Print expenses\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the name of the item: ");
            scanf("%s", name);
            printf("Enter the category of the item: ");
            scanf("%s", category);
            printf("Enter the amount of the item: ");
            scanf("%lf", &amount);

            add_category(categories, num_categories, category);
            add_item(items, num_items, name, category, amount);
            num_categories++;
            num_items++;
            break;

        case 2:
            printf("Expenses:\n");
            print_items(items, num_items);
            break;

        case 3:
            printf("Thanks for using Expense Tracker!\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}