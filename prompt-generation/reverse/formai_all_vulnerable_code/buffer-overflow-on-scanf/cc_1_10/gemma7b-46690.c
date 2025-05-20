//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a coffee item
typedef struct CoffeeItem {
    char name[20];
    int price;
    int quantity;
} CoffeeItem;

// Create an array of coffee items
CoffeeItem items[] = {
    {"Latte", 50, 0},
    {"Cappuccino", 60, 0},
    {"Americano", 40, 0},
    {"Mocha", 55, 0},
    {"Macchiato", 45, 0}
};

// Define a function to calculate the total cost of an order
int calculateTotalCost(CoffeeItem *item, int quantity) {
    return item->price * quantity;
}

// Define a function to print the menu
void printMenu() {
    int i = 0;
    for (i = 0; i < 5; i++) {
        printf("%s - \$%d,  Qty: %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

// Define a function to process an order
void processOrder() {
    char itemName[20];
    int quantity;

    printf("Enter the name of your coffee item: ");
    scanf("%s", itemName);

    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            found = 1;
            printf("Enter the quantity of your order: ");
            scanf("%d", &quantity);

            items[i].quantity += quantity;
            break;
        }
    }

    if (!found) {
        printf("Error: item not found.\n");
    }
}

// Main function
int main() {
    printMenu();
    processOrder();
    printMenu();

    return 0;
}