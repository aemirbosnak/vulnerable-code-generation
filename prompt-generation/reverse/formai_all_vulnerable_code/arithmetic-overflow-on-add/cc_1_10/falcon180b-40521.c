//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of items that can be stored in memory
#define MAX_ITEMS 100

// Define the structure for each item in the menu
typedef struct {
    char name[50];
    float price;
} Item;

// Define the structure for the customer's order
typedef struct {
    char name[50];
    int numItems;
    Item items[MAX_ITEMS];
} Order;

// Function to add an item to the customer's order
void addItem(Order* order) {
    if (order->numItems >= MAX_ITEMS) {
        printf("Sorry, you can only order up to %d items.\n", MAX_ITEMS);
        return;
    }

    printf("Enter the name of the item: ");
    scanf("%s", order->items[order->numItems].name);

    printf("Enter the price of the item: $");
    scanf("%f", &order->items[order->numItems].price);

    order->numItems++;
}

// Function to calculate the total cost of the order
float calculateTotal(Order* order) {
    float total = 0.0;

    for (int i = 0; i < order->numItems; i++) {
        total += order->items[i].price;
    }

    return total;
}

// Function to print the customer's order
void printOrder(Order* order) {
    printf("\nOrder for %s:\n", order->name);

    for (int i = 0; i < order->numItems; i++) {
        printf("%s - $%.2f\n", order->items[i].name, order->items[i].price);
    }

    printf("\nTotal cost: $%.2f\n", calculateTotal(order));
}

int main() {
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    Order order;
    strcpy(order.name, name);

    int choice;
    do {
        printf("\nCafe Menu:\n");
        printf("1. Add item to order\n");
        printf("2. Print order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&order);
                break;
            case 2:
                printOrder(&order);
                break;
            case 3:
                printf("Thank you for visiting our cafe, %s!\n", name);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}