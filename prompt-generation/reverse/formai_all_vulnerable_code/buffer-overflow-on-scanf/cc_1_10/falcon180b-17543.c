//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

typedef struct {
    char name[50];
    double amount;
    char category[20];
} item;

item items[MAX_ITEMS];
int num_items = 0;

char categories[MAX_CATEGORIES][20];
int num_categories = 0;

void add_category() {
    char category[20];
    printf("Enter a new category: ");
    scanf("%s", category);
    strcpy(categories[num_categories], category);
    num_categories++;
}

void add_item() {
    char name[50];
    double amount;
    char category[20];
    printf("Enter the item name: ");
    scanf("%s", name);
    printf("Enter the item amount: ");
    scanf("%lf", &amount);
    printf("Enter the item category: ");
    scanf("%s", category);
    strcpy(items[num_items].name, name);
    items[num_items].amount = amount;
    strcpy(items[num_items].category, category);
    num_items++;
}

void display_items() {
    printf("\nItem Name\tAmount\tCategory\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2lf\t%s\n", items[i].name, items[i].amount, items[i].category);
    }
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

void main() {
    int choice;
    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Category\n2. Add Item\n3. Display Items\n4. Display Categories\n5. Exit\n");
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
                display_categories();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}