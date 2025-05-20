//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50

typedef struct item {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    double price;
    int quantity;
} item_t;

void init_item(item_t *item) {
    strcpy(item->name, "");
    strcpy(item->category, "");
    item->price = 0.0;
    item->quantity = 0;
}

void print_item(const item_t *item) {
    printf("Name: %s\n", item->name);
    printf("Category: %s\n", item->category);
    printf("Price: $%.2f\n", item->price);
    printf("Quantity: %d\n", item->quantity);
    printf("\n");
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;
    char input[MAX_NAME_LEN + MAX_CATEGORY_LEN + 10];
    char name[MAX_NAME_LEN + 1];
    char category[MAX_CATEGORY_LEN + 1];
    double price;
    int quantity;

    printf("Welcome to the Expense Tracker!\n");
    printf("Enter expenses in the format: name category price quantity\n");
    printf("Example: groceries food $50.00 2\n");

    while (fgets(input, sizeof(input), stdin)) {
        if (sscanf(input, "%s %s %lf %d", name, category, &price, &quantity) == 4) {
            init_item(&items[num_items]);
            strcpy(items[num_items].name, name);
            strcpy(items[num_items].category, category);
            items[num_items].price = price;
            items[num_items].quantity = quantity;
            num_items++;
        } else {
            printf("Invalid input format. Please try again.\n");
        }
    }

    printf("Expenses entered:\n");
    for (int i = 0; i < num_items; i++) {
        print_item(&items[i]);
    }

    return 0;
}