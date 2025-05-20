//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure for the menu items
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the structure for the order
typedef struct {
    int numItems;
    MenuItem items[MAX_ITEMS];
} Order;

// Function to display the menu
void displayMenu(MenuItem menuItems[], int numItems) {
    printf("Menu:\n");
    for(int i=0; i<numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to place an order
void placeOrder(Order order) {
    printf("Order:\n");
    for(int i=0; i<order.numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, order.items[i].name, order.items[i].price);
    }
    printf("Total cost: $%.2f\n", order.items[0].price*order.numItems);
}

// Function to calculate the total cost of the order
float calculateTotal(Order order) {
    return order.items[0].price*order.numItems;
}

// Main function
int main() {
    // Define the menu items
    MenuItem menuItems[] = {{"Coffee", 2.50}, {"Tea", 1.75}, {"Cake", 3.25}, {"Sandwich", 4.50}};
    int numMenuItems = sizeof(menuItems)/sizeof(MenuItem);

    // Initialize the order
    Order order;
    order.numItems = 0;

    // Get the order from the user
    while(order.numItems < MAX_ITEMS) {
        printf("Enter the number of the item you want to order or 0 to finish: ");
        int itemNum = 0;
        scanf("%d", &itemNum);
        if(itemNum >= 1 && itemNum <= numMenuItems) {
            order.items[order.numItems++] = menuItems[itemNum-1];
        } else if(itemNum == 0) {
            break;
        } else {
            printf("Invalid item number.\n");
        }
    }

    // Display the order
    placeOrder(order);

    // Calculate the total cost of the order
    float totalCost = calculateTotal(order);

    // Print the total cost
    printf("Total cost of the order: $%.2f\n", totalCost);

    return 0;
}