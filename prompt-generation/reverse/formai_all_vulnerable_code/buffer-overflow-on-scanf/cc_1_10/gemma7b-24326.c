//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a coffee item
typedef struct CoffeeItem {
    char name[20];
    float price;
    int quantity;
} CoffeeItem;

// Create an array of coffee items
CoffeeItem items[] = {
    {"Latte", 5.0, 0},
    {"Cappuccino", 4.5, 0},
    {"Americano", 3.0, 0},
    {"Macchiato", 4.0, 0},
    {"Expresso", 2.5, 0}
};

// Function to calculate the total cost of an order
float calculateTotalCost(CoffeeItem* item, int quantity) {
    return item->price * quantity;
}

// Function to display the menu
void displayMenu() {
    printf("Here is our menu:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }
}

// Function to take an order
CoffeeItem* takeOrder() {
    // Get the item name
    char itemName[20];
    printf("What would you like to order? ");
    scanf("%s", itemName);

    // Find the item in the menu
    for (int i = 0; i < 5; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            return &items[i];
        }
    }

    // Return NULL if the item is not found
    return NULL;
}

// Function to process an order
void processOrder(CoffeeItem* item, int quantity) {
    item->quantity++;
    printf("Your order has been placed. Your total cost is $%.2f.\n", calculateTotalCost(item, quantity));
}

int main() {
    // Display the menu
    displayMenu();

    // Take an order
    CoffeeItem* item = takeOrder();

    // Process the order
    if (item) {
        processOrder(item, 1);
    } else {
        printf("Error: item not found.\n");
    }

    return 0;
}