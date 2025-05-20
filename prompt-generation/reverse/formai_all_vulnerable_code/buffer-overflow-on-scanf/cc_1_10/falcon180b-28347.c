//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 50
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    double amount;
} ExpenseItem;

int num_categories = 0;
char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];

int num_items = 0;
ExpenseItem items[MAX_ITEMS];

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories]);
    num_categories++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter category: ");
    char category[MAX_NAME_LENGTH];
    scanf("%s", category);

    int i;
    for (i = 0; i < num_categories; i++) {
        if (strcmp(category, categories[i]) == 0) {
            strcpy(items[num_items].category, category);
            break;
        }
    }

    printf("Enter amount: ");
    scanf("%lf", &items[num_items].amount);

    num_items++;
}

void display_items() {
    printf("Category\tItem\tAmount\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\t%.2lf\n", items[i].category, items[i].name, items[i].amount);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\n1. Add category\n2. Add item\n3. Display items\n4. Exit\n");
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
                display_items();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}