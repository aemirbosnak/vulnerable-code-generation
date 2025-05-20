//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Define the menu items
struct MenuItem {
    char *name;
    float price;
};

// Define the customer order
struct CustomerOrder {
    char *name;
    struct MenuItem *items[10];
    int numItems;
    float total;
};

// Create the menu
struct MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Pastry", 3.00},
    {"Sandwich", 5.00},
    {"Salad", 4.00}
};

// Get the customer's name
char *getCustomerName() {
    char *name = malloc(100);
    printf("What is your name, my dear? ");
    scanf("%s", name);
    return name;
}

// Get the customer's order
struct CustomerOrder *getCustomerOrder(char *name) {
    struct CustomerOrder *order = malloc(sizeof(struct CustomerOrder));
    order->name = name;
    order->numItems = 0;
    order->total = 0.0;

    int choice;
    do {
        printf("What would you like to order, %s? (Enter 0 to finish) ", name);
        scanf("%d", &choice);

        if (choice > 0 && choice <= 5) {
            order->items[order->numItems] = &menuItems[choice - 1];
            order->numItems++;
            order->total += menuItems[choice - 1].price;
        }
    } while (choice != 0);

    return order;
}

// Print the customer's bill
void printBill(struct CustomerOrder *order) {
    printf("\nThank you for your order, %s!\n", order->name);
    printf("-------------------------------------\n");
    printf("Item\t\t\tPrice\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%s\t\t\t$%.2f\n", order->items[i]->name, order->items[i]->price);
    }
    printf("-------------------------------------\n");
    printf("Total:\t\t\t$%.2f\n", order->total);
}

// Main function
int main() {
    // Get the customer's name
    char *name = getCustomerName();

    // Get the customer's order
    struct CustomerOrder *order = getCustomerOrder(name);

    // Print the customer's bill
    printBill(order);

    // Free the memory allocated for the customer's name and order
    free(name);
    free(order);

    return 0;
}