//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the menu items
typedef struct MenuItem {
    char name[50];
    float price;
} MenuItem;

// Structure to store the order items
typedef struct OrderItem {
    char name[50];
    int quantity;
    float price;
} OrderItem;

// Function to print the menu
void printMenu(MenuItem *menu, int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to get the order from the user
void getOrder(OrderItem *order, int *numItems) {
    int choice;
    char name[50];
    int quantity;
    float price;

    printf("Enter your order:\n");
    *numItems = 0;
    while (1) {
        printf("Enter the item number (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        printf("Enter the item name: ");
        scanf("%s", name);

        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        printf("Enter the price: ");
        scanf("%f", &price);

        strcpy(order[*numItems].name, name);
        order[*numItems].quantity = quantity;
        order[*numItems].price = price;

        (*numItems)++;
    }
}

// Function to calculate the total bill
float calculateBill(OrderItem *order, int numItems) {
    float total = 0;

    for (int i = 0; i < numItems; i++) {
        total += order[i].quantity * order[i].price;
    }

    return total;
}

// Function to print the bill
void printBill(OrderItem *order, int numItems, float total) {
    printf("\nBill:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f - %d\n", order[i].name, order[i].price, order[i].quantity);
    }

    printf("Total: $%.2f\n", total);
}

// Main function
int main() {
    // Define the menu items
    MenuItem menu[] = {
        {"Coffee", 2.50},
        {"Tea", 2.00},
        {"Cake", 3.00},
        {"Muffin", 2.50},
        {"Sandwich", 5.00}
    };
    int numMenuItems = sizeof(menu) / sizeof(MenuItem);

    // Get the order from the user
    OrderItem order[100];
    int numOrderItems;
    getOrder(order, &numOrderItems);

    // Calculate the total bill
    float total = calculateBill(order, numOrderItems);

    // Print the bill
    printBill(order, numOrderItems, total);

    return 0;
}