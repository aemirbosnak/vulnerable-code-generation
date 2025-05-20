//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a menu item
typedef struct {
    char name[50];
    float price;
    int quantity;
} MenuItem;

// Define the structure of a customer order
typedef struct {
    char customerName[50];
    MenuItem items[10];
    int numItems;
    float totalPrice;
} CustomerOrder;

// Function to add a menu item to the order
void addMenuItem(CustomerOrder* order) {
    printf("Enter the name of the item: ");
    scanf("%s", order->items[order->numItems].name);
    printf("Enter the price of the item: ");
    scanf("%f", &order->items[order->numItems].price);
    printf("Enter the quantity of the item: ");
    scanf("%d", &order->items[order->numItems].quantity);
    order->numItems++;
}

// Function to calculate the total price of the order
void calculateTotalPrice(CustomerOrder* order) {
    order->totalPrice = 0;
    for (int i = 0; i < order->numItems; i++) {
        order->totalPrice += order->items[i].price * order->items[i].quantity;
    }
}

// Function to print the order details
void printOrderDetails(CustomerOrder* order) {
    printf("\nCustomer Name: %s\n", order->customerName);
    printf("Order Details:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("Item Name: %s\n", order->items[i].name);
        printf("Price: $%.2f\n", order->items[i].price);
        printf("Quantity: %d\n", order->items[i].quantity);
        printf("Total Price: $%.2f\n", order->items[i].price * order->items[i].quantity);
        printf("\n");
    }
    printf("Total Price: $%.2f\n", order->totalPrice);
}

int main() {
    CustomerOrder order;
    
    // Get customer details
    printf("Enter the name of the customer: ");
    scanf("%s", order.customerName);
    
    // Add menu items to the order
    int choice;
    while (1) {
        printf("\nSelect an option:\n1. Add menu item\n2. Print order details\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMenuItem(&order);
                break;
            case 2:
                printOrderDetails(&order);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}