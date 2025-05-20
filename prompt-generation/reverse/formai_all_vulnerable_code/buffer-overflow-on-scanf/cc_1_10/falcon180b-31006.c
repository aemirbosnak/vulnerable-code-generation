//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY_LENGTH 10
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char quantity[MAX_QUANTITY_LENGTH];
    char price[MAX_PRICE_LENGTH];
} item_t;

void add_item(item_t* items, int num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);
    printf("Enter the quantity of the item: ");
    scanf("%s", items[num_items].quantity);
    printf("Enter the price of the item: ");
    scanf("%s", items[num_items].price);
    num_items++;
}

void display_items(item_t* items, int num_items) {
    printf("Item\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\t%s\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void calculate_total(item_t* items, int num_items) {
    float total_cost = 0;
    for (int i = 0; i < num_items; i++) {
        float quantity = atof(items[i].quantity);
        float price = atof(items[i].price);
        total_cost += quantity * price;
    }
    printf("Total cost: $%f\n", total_cost);
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        printf("Do you want to add an item? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            add_item(items, num_items);
        } else {
            break;
        }
    }

    display_items(items, num_items);
    calculate_total(items, num_items);

    return 0;
}