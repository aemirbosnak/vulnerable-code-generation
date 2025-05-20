//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 30

// structure to store item details
struct item {
    char name[MAX_NAME_LENGTH];
    float price;
};

// structure to store customer order
struct order {
    int num_items;
    struct item items[MAX_ITEMS];
};

// function to add an item to the order
void add_item(struct order *order) {
    int i;
    char name[MAX_NAME_LENGTH];
    float price;

    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item price: ");
    scanf("%f", &price);

    for (i = 0; i < order->num_items; i++) {
        if (strcmp(name, order->items[i].name) == 0) {
            printf("Item already exists in order.\n");
            return;
        }
    }

    strcpy(order->items[order->num_items].name, name);
    order->items[order->num_items].price = price;
    order->num_items++;
}

// function to display the order
void display_order(struct order *order) {
    int i;

    printf("Order:\n");
    for (i = 0; i < order->num_items; i++) {
        printf("%s - $%.2f\n", order->items[i].name, order->items[i].price);
    }
}

// function to calculate total cost of order
float calculate_total(struct order *order) {
    int i;
    float total = 0.0;

    for (i = 0; i < order->num_items; i++) {
        total += order->items[i].price;
    }

    return total;
}

// main function
int main() {
    struct order order;
    int choice;
    float total;

    order.num_items = 0;

    do {
        printf("\nCafe Billing System\n");
        printf("1. Add item to order\n");
        printf("2. Display order\n");
        printf("3. Calculate total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&order);
                break;
            case 2:
                display_order(&order);
                break;
            case 3:
                total = calculate_total(&order);
                printf("Total cost of order: $%.2f\n", total);
                break;
            case 4:
                printf("Thank you for using our cafe billing system!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}