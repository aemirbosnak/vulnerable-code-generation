//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
    int category;
} item;

typedef struct {
    char name[50];
    int num_items;
} category;

category categories[MAX_CATEGORIES];
item items[MAX_ITEMS];
int num_categories = 0;
int num_items = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter amount: ");
    scanf("%f", &items[num_items].amount);
    printf("Enter category (1-%d): ", num_categories);
    scanf("%d", &items[num_items].category);
    num_items++;
}

void display_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void display_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Category: %s\n", categories[items[i].category-1].name);
        printf("Name: %s\n", items[i].name);
        printf("Amount: $%.2f\n\n", items[i].amount);
    }
}

void main() {
    int choice;
    char cont;

    printf("Welcome to Personal Finance Planner!\n");
    printf("Please choose an option:\n");
    printf("1. Add category\n");
    printf("2. Add item\n");
    printf("3. Display categories\n");
    printf("4. Display items\n");
    printf("5. Exit\n");

    do {
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_category();
            break;
        case 2:
            add_item();
            break;
        case 3:
            display_categories();
            break;
        case 4:
            display_items();
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');
}