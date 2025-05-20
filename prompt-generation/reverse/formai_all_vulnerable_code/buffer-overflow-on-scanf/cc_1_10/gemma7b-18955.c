//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a coffee item
typedef struct CoffeeItem {
    char name[20];
    float price;
    int quantity;
} CoffeeItem;

// Create an array of coffee items
CoffeeItem coffeeItems[] = {
    {"Latte", 3.50, 0},
    {"Cappuccino", 4.00, 0},
    {"Americano", 2.50, 0},
    {"Macchiato", 3.00, 0},
    {"Brew", 2.00, 0}
};

// Function to calculate the total cost of a order
float calculateTotalCost(CoffeeItem* item, int quantity) {
    float totalCost = item->price * quantity;
    return totalCost;
}

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Coffee Cafe!\n");
    printf("--------------------\n");
    printf("Items:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - $%.2f, Quantity: %d\n", coffeeItems[i].name, coffeeItems[i].price, coffeeItems[i].quantity);
    }
    printf("--------------------\n");
}

// Function to take an order
void takeOrder() {
    char itemName[20];
    int quantity;

    printf("Enter the name of your coffee item: ");
    scanf("%s", itemName);

    for (int i = 0; i < 5; i++) {
        if (strcmp(itemName, coffeeItems[i].name) == 0) {
            printf("Enter the quantity of your order: ");
            scanf("%d", &quantity);

            coffeeItems[i].quantity += quantity;
            break;
        }
    }

    if (quantity == 0) {
        printf("Error: Item not found.\n");
    }
}

// Function to checkout
void checkout() {
    float totalCost = 0.0f;

    for (int i = 0; i < 5; i++) {
        totalCost += calculateTotalCost(&coffeeItems[i], coffeeItems[i].quantity);
    }

    printf("Total cost: $%.2f\n", totalCost);
    printf("Thank you for your order!\n");
}

int main() {
    displayMenu();
    takeOrder();
    checkout();

    return 0;
}