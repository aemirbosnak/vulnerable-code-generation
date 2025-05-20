//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
} item_t;

typedef struct {
    char name[MAX_NAME_LEN];
    int num_items;
    item_t items[MAX_ITEMS];
} category_t;

category_t categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
    num_categories++;
    printf("Enter category name: ");
    scanf("%s", categories[num_categories - 1].name);
    categories[num_categories - 1].num_items = 0;
}

void add_item() {
    printf("Enter item name: ");
    scanf("%s", categories[num_categories - 1].items[categories[num_categories - 1].num_items].name);
    printf("Enter item amount: ");
    scanf("%f", &categories[num_categories - 1].items[categories[num_categories - 1].num_items].amount);
    categories[num_categories - 1].num_items++;
}

void print_categories() {
    for (int i = 0; i < num_categories; i++) {
        printf("%s:\n", categories[i].name);
        for (int j = 0; j < categories[i].num_items; j++) {
            printf("%s - $%.2f\n", categories[i].items[j].name, categories[i].items[j].amount);
        }
    }
}

void main() {
    num_categories = 0;
    add_category();
    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add category\n");
        printf("2. Add item\n");
        printf("3. Print categories\n");
        printf("4. Quit\n");
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
                print_categories();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}