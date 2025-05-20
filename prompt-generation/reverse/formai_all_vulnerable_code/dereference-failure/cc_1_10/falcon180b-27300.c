//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a menu item
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the structure of a customer order
typedef struct {
    int numItems;
    MenuItem items[10];
} CustomerOrder;

// Function to add a menu item to the order
void addItem(CustomerOrder* order) {
    int numItems = order->numItems;
    MenuItem item;

    printf("Enter the name of the item: ");
    scanf("%s", item.name);
    printf("Enter the price of the item: ");
    scanf("%f", &item.price);

    if (numItems < 10) {
        order->items[numItems] = item;
        order->numItems++;
    } else {
        printf("Sorry, you can only order up to 10 items.\n");
    }
}

// Function to calculate the total cost of the order
float calculateTotal(CustomerOrder order) {
    float total = 0.0;

    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }

    return total;
}

// Function to print the customer's order
void printOrder(CustomerOrder order) {
    printf("Customer Order:\n");

    for (int i = 0; i < order.numItems; i++) {
        printf("Item %d: %s - $%.2f\n", i+1, order.items[i].name, order.items[i].price);
    }

    printf("Total Cost: $%.2f\n", calculateTotal(order));
}

// Function to simulate a cafe billing system
int main() {
    CustomerOrder order;
    int choice;

    do {
        printf("Welcome to the Cafe Billing System!\n");
        printf("1. Add an item to your order\n");
        printf("2. Print your current order\n");
        printf("3. Calculate the total cost of your order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem(&order);
                break;
            case 2:
                printOrder(order);
                break;
            case 3:
                printf("Total Cost: $%.2f\n", calculateTotal(order));
                break;
            case 4:
                printf("Thank you for using the Cafe Billing System!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}