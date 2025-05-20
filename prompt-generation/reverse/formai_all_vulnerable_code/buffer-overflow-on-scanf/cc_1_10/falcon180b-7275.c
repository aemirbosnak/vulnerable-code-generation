//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_AMOUNT 10

typedef struct {
    char name[MAX_NAME];
    float amount;
} item;

typedef struct {
    char name[MAX_NAME];
    int num_items;
    item items[MAX_ITEMS];
} category;

category categories[MAX_CATEGORIES];
int num_categories = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].num_items = 0;
    num_categories++;
}

void add_item(int category_index) {
    printf("Enter item name: ");
    scanf("%s", categories[category_index].items[categories[category_index].num_items].name);
    printf("Enter item amount: ");
    scanf("%f", &categories[category_index].items[categories[category_index].num_items].amount);
    categories[category_index].num_items++;
}

void display_categories() {
    for(int i=0; i<num_categories; i++) {
        printf("\nCategory %d: %s\n", i+1, categories[i].name);
        for(int j=0; j<categories[i].num_items; j++) {
            printf("Item %d: %s - $%.2f\n", j+1, categories[i].items[j].name, categories[i].items[j].amount);
        }
    }
}

int main() {
    printf("Welcome to the Cyberpunk Expense Tracker!\n");
    add_category();
    add_item(0);
    add_item(0);
    add_category();
    add_item(1);
    display_categories();
    return 0;
}