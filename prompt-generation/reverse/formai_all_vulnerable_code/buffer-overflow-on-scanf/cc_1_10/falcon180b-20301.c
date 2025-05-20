//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_CATEGORIES 50
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_AMOUNT_DIGITS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
    int category;
} expense;

int num_categories = 0;
char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];

int num_items = 0;
expense items[MAX_ITEMS];

void add_category() {
    char name[MAX_NAME_LENGTH];
    printf("Enter category name: ");
    scanf("%s", name);
    strcpy(categories[num_categories], name);
    num_categories++;
}

void add_item() {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
    int category;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item description: ");
    scanf("%s", description);

    printf("Enter item amount: ");
    scanf("%lf", &amount);

    printf("Enter item category (1-%d): ", num_categories);
    scanf("%d", &category);

    strcpy(items[num_items].name, name);
    strcpy(items[num_items].description, description);
    items[num_items].amount = amount;
    items[num_items].category = category;

    num_items++;
}

void view_items() {
    int i;

    printf("Name\tDescription\tAmount\tCategory\n");
    for (i = 0; i < num_items; i++) {
        printf("%s\t%s\t%.2lf\t%d\n", items[i].name, items[i].description, items[i].amount, items[i].category);
    }
}

void view_categories() {
    int i;

    printf("Categories:\n");
    for (i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    int choice;

    printf("Expense Tracker\n");

    while (1) {
        printf("\n1. Add category\n2. Add item\n3. View items\n4. View categories\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                add_item();
                break;
            case 3:
                view_items();
                break;
            case 4:
                view_categories();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}