//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a menu item
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the structure of an order
typedef struct {
    int itemCount;
    MenuItem items[10];
} Order;

// Function to add an item to the order
void addItem(Order* order) {
    int count = order->itemCount;
    printf("Enter the name of the item: ");
    scanf("%s", &order->items[count].name);
    printf("Enter the price of the item: $");
    scanf("%f", &order->items[count].price);
    order->itemCount++;
}

// Function to calculate the total cost of the order
float calculateTotal(Order order) {
    float total = 0;
    for(int i=0; i<order.itemCount; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to print the order details
void printOrder(Order order) {
    printf("\nOrder Details:\n");
    printf("--------------------\n");
    printf("Item Name\t\tPrice\n");
    for(int i=0; i<order.itemCount; i++) {
        printf("%s\t\t$%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("\nTotal Cost: $%.2f\n", calculateTotal(order));
}

// Main function to simulate the cafe billing system
int main() {
    Order order;
    order.itemCount = 0;

    // Initialize the menu items
    MenuItem menuItems[5] = {{"Coffee", 2.50}, {"Tea", 1.80}, {"Coca Cola", 1.50}, {"Pepsi", 1.70}, {"Sprite", 1.60}};

    // Display the menu items
    printf("\nMenu Items:\n");
    for(int i=0; i<5; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }

    // Allow the customer to place an order
    int choice;
    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if(choice >= 1 && choice <= 5) {
            addItem(&order);
        }
        else if(choice == 0) {
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    // Print the order details
    printf("\nYour order details:\n");
    printOrder(order);

    return 0;
}