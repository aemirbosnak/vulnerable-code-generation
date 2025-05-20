//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a coffee item
typedef struct CoffeeItem {
    char name[20];
    float price;
    int quantity;
} CoffeeItem;

// Create an array of coffee items
CoffeeItem items[] = {
    {"Black Coffee", 5.0, 0},
    {"Cappuccino", 6.0, 0},
    {"Latte", 7.0, 0},
    {"Mocha", 8.0, 0},
    {"Americano", 4.0, 0}
};

// Define the function to calculate the total cost of an order
float calculateTotalCost(CoffeeItem item, int quantity) {
    return item.price * quantity;
}

// Define the function to display the menu
void displayMenu() {
    printf("*** Coffee Menu ***\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - $%.2f, Quantity: %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

// Define the function to take an order
void takeOrder() {
    char item_name[20];
    int quantity;

    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < 5; i++) {
        if (strcmp(item_name, items[i].name) == 0) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            items[i].quantity += quantity;
            break;
        }
    }

    if (quantity == 0) {
        printf("Item not found.\n");
    }
}

int main() {
    displayMenu();
    takeOrder();
    displayMenu();

    return 0;
}