//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a coffee item
typedef struct CoffeeItem {
    char name[20];
    float price;
    int quantity;
} CoffeeItem;

// Define a function to calculate the total cost of a coffee order
float calculateTotalCost(CoffeeItem *items, int numItems) {
    float totalCost = 0.0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].price * items[i].quantity;
    }
    return totalCost;
}

// Define a function to print the menu
void printMenu() {
    CoffeeItem items[] = {
        {"Black Coffee", 2.0, 0},
        {"Americano", 3.0, 0},
        {"Cappuccino", 4.0, 0},
        {"Latte", 5.0, 0}
    };

    printf("--------------------------------------------------------\n");
    printf("Welcome to the Coffee Cafe!\n");
    printf("--------------------------------------------------------\n");
    printf("Menu:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s - $%.2f (Quantity: %d)\n", items[i].name, items[i].price, items[i].quantity);
    }
    printf("\n");
}

// Define a function to process an order
void processOrder() {
    CoffeeItem items[] = {
        {"Black Coffee", 2.0, 0},
        {"Americano", 3.0, 0},
        {"Cappuccino", 4.0, 0},
        {"Latte", 5.0, 0}
    };

    int numItems = 0;
    char itemName[20];
    float itemPrice;
    int itemQuantity;

    printf("Please enter the name of the coffee item: ");
    scanf("%s", itemName);

    for (int i = 0; i < 4; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            itemPrice = items[i].price;
            itemQuantity = items[i].quantity;
            items[i].quantity++;
            numItems++;
            break;
        }
    }

    if (numItems == 0) {
        printf("Error: Item not found.\n");
    } else {
        float totalCost = calculateTotalCost(items, numItems);
        printf("Total cost: $%.2f\n", totalCost);
    }
}

int main() {
    printMenu();
    processOrder();

    return 0;
}