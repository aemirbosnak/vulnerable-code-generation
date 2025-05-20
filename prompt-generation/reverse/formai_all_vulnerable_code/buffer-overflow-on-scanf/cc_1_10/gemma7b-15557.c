//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a coffee item
typedef struct CoffeeItem {
    char name[20];
    int price;
    int quantity;
} CoffeeItem;

// Create an array of coffee items
CoffeeItem coffeeItems[] = {
    {"Cappuccino", 50, 0},
    {"Latte", 40, 0},
    {"Americano", 30, 0},
    {"Mocha", 45, 0},
    {"Macchiato", 42, 0}
};

// Function to calculate the total cost of a coffee order
int calculateTotalCost(CoffeeItem item, int quantity) {
    return item.price * quantity;
}

// Function to display the menu
void displayMenu() {
    int i = 0;
    for (i = 0; i < 5; i++) {
        printf("%s - $%d,  Quantity: %d\n", coffeeItems[i].name, coffeeItems[i].price, coffeeItems[i].quantity);
    }
}

// Function to take an order
void takeOrder() {
    char itemName[20];
    int itemQuantity;

    printf("Enter the name of your coffee: ");
    scanf("%s", itemName);

    int i = 0;
    for (i = 0; i < 5; i++) {
        if (strcmp(itemName, coffeeItems[i].name) == 0) {
            printf("Enter the quantity of your coffee: ");
            scanf("%d", &itemQuantity);

            coffeeItems[i].quantity += itemQuantity;
            break;
        }
    }

    if (i == 5) {
        printf("Error: Invalid coffee name.\n");
    }
}

int main() {
    displayMenu();
    takeOrder();
    displayMenu();

    return 0;
}