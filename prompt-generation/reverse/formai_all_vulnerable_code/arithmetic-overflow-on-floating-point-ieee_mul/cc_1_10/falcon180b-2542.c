//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 100

// Struct to hold item details
typedef struct {
    char name[MAX_NAME_LEN];
    double price;
    int quantity;
} Item;

// Function to add an item to the list
void add_item(Item *list, int *num_items) {
    char name[MAX_NAME_LEN];
    double price;
    int quantity;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item price: ");
    scanf("%lf", &price);

    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    list[*num_items] = (Item) {
       .name = strdup(name),
       .price = price,
       .quantity = quantity
    };

    (*num_items)++;
}

// Function to calculate total cost of items
double calculate_total_cost(Item *list, int num_items) {
    double total_cost = 0.0;

    for (int i = 0; i < num_items; i++) {
        total_cost += list[i].price * list[i].quantity;
    }

    return total_cost;
}

// Function to print item details
void print_item(const Item *item) {
    printf("%s: $%.2f x %d = $%.2f\n", item->name, item->price, item->quantity, item->price * item->quantity);
}

// Function to print total cost
void print_total_cost(double total_cost) {
    printf("Total cost: $%.2f\n", total_cost);
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        add_item(items, &num_items);

        printf("Enter Y to add another item, any other key to continue: ");
        char choice;
        scanf(" %c", &choice);

        if (choice!= 'Y' && choice!= 'y') {
            break;
        }
    }

    double total_cost = calculate_total_cost(items, num_items);

    printf("Item list:\n");
    for (int i = 0; i < num_items; i++) {
        print_item(&items[i]);
    }

    print_total_cost(total_cost);

    return 0;
}