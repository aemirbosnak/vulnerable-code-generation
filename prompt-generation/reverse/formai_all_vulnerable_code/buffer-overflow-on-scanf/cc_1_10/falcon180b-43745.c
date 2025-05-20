//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 50

typedef struct {
    char name[50];
    float amount;
} item;

typedef struct {
    char name[50];
    int count;
    item items[MAX_ITEMS];
} category;

void initialize_category(category *c) {
    c->count = 0;
}

void add_item(category *c, item i) {
    if (c->count >= MAX_ITEMS) {
        printf("Error: Category is full.\n");
        return;
    }
    strcpy(c->items[c->count].name, i.name);
    c->items[c->count].amount = i.amount;
    c->count++;
}

void print_category(category c) {
    printf("Category: %s\n", c.name);
    printf("Items:\n");
    for (int i = 0; i < c.count; i++) {
        printf("%s - $%.2f\n", c.items[i].name, c.items[i].amount);
    }
}

void initialize_expense_tracker() {
    category categories[MAX_CATEGORIES];
    int count = 0;
    char choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add Category\n2. View Categories\n3. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                if (count >= MAX_CATEGORIES) {
                    printf("Error: Maximum number of categories reached.\n");
                } else {
                    printf("Enter category name: ");
                    scanf("%s", categories[count].name);
                    initialize_category(&categories[count]);
                    count++;
                }
                break;
            case '2':
                printf("Categories:\n");
                for (int i = 0; i < count; i++) {
                    print_category(categories[i]);
                }
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');
}

int main() {
    initialize_expense_tracker();
    return 0;
}