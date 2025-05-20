//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

struct item {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
};

int main() {
    int num_items;
    struct item items[MAX_ITEMS];

    printf("Welcome to the Cafe Billing System\n");
    printf("Enter the number of items on the menu: ");
    scanf("%d", &num_items);

    printf("Enter the name, price, and quantity of each item:\n");
    for (int i = 0; i < num_items; i++) {
        scanf(" %s %s %d", items[i].name, items[i].price, &items[i].quantity);
    }

    printf("Select an item to order:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%s (%d in stock)\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }

    int item_choice;
    scanf("%d", &item_choice);

    if (item_choice < 1 || item_choice > num_items) {
        printf("Invalid item choice\n");
        return 1;
    }

    struct item selected_item = items[item_choice-1];

    printf("You have ordered %s - $%s\n", selected_item.name, selected_item.price);

    if (selected_item.quantity <= 0) {
        printf("Sorry, we are out of stock\n");
        return 0;
    } else {
        selected_item.quantity--;
        printf("Your order has been placed\n");
    }

    return 0;
}