//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Define structure for menu items
typedef struct {
    char name[50];
    int price;
} MenuItem;

// Define structure for customer orders
typedef struct {
    int numItems;
    MenuItem *items;
} Order;

// Function to display menu
void displayMenu(MenuItem menuItems[], int numItems) {
    printf("Welcome to our cafe!\n\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%d\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to take customer order
Order takeOrder(MenuItem menuItems[], int numItems) {
    Order order = {0, NULL};
    int choice;
    printf("Enter the number of items you would like to order: ");
    scanf("%d", &choice);
    order.numItems = choice;
    order.items = malloc(choice * sizeof(MenuItem));
    for (int i = 0; i < choice; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", order.items[i].name);
        printf("Enter the price of item %d: ", i+1);
        scanf("%d", &order.items[i].price);
    }
    return order;
}

// Function to calculate total price of order
int calculateTotal(Order order) {
    int total = 0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to print order details
void printOrder(Order order) {
    printf("\nYour order:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%s - $%d\n", order.items[i].name, order.items[i].price);
    }
    printf("\nTotal price: $%d\n", calculateTotal(order));
}

// Function to free memory allocated for order
void freeOrder(Order order) {
    for (int i = 0; i < order.numItems; i++) {
        free(order.items[i].name);
    }
    free(order.items);
}

int main() {
    // Define menu items
    MenuItem menuItems[] = {
        {"Coffee", 3},
        {"Tea", 2},
        {"Sandwich", 5},
        {"Cake", 4}
    };

    // Initialize random seed
    srand(time(NULL));

    // Simulate customers coming in and placing orders
    int numCustomers = rand() % 10 + 1; // Between 1 and 10 customers
    for (int i = 0; i < numCustomers; i++) {
        Order order = takeOrder(menuItems, sizeof(menuItems)/sizeof(MenuItem));
        printOrder(order);
        freeOrder(order);
    }

    return 0;
}