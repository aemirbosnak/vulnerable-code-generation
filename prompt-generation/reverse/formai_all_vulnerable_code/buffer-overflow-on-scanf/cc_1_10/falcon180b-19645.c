//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float price;
    char category[20];
} item;

typedef struct {
    char name[20];
    int count;
} category;

item items[MAX_ITEMS];
category categories[MAX_CATEGORIES];
int num_items = 0;
int num_categories = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    printf("Enter item category: ");
    scanf("%s", items[num_items].category);
    num_items++;
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void display_items() {
    printf("Item Name | Price | Category\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s | %.2f | %s\n", items[i].name, items[i].price, items[i].category);
    }
}

void display_categories() {
    printf("Category | Count\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s | %d\n", categories[i].name, categories[i].count);
    }
}

void main() {
    system("clear");
    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        system("clear");
        printf("1. Add Item\n");
        printf("2. Add Category\n");
        printf("3. Display Items\n");
        printf("4. Display Categories\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                add_category();
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
                printf("Invalid choice. Please try again.\n");
        }
    }
}