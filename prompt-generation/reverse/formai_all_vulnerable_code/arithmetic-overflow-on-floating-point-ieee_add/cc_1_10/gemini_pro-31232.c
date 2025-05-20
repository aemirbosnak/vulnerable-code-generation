//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in a bill
#define MAX_ITEMS 100

// Define the maximum length of a menu item name
#define MAX_ITEM_NAME_LENGTH 50

// Define the maximum length of a menu item description
#define MAX_ITEM_DESCRIPTION_LENGTH 255

// Define the maximum length of a menu item price
#define MAX_ITEM_PRICE_LENGTH 10

// Define the structure of a menu item
typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    char description[MAX_ITEM_DESCRIPTION_LENGTH];
    char price[MAX_ITEM_PRICE_LENGTH];
} MenuItem;

// Define the structure of a bill item
typedef struct {
    MenuItem item;
    int quantity;
} BillItem;

// Define the structure of a bill
typedef struct {
    BillItem items[MAX_ITEMS];
    int numItems;
    float totalCost;
} Bill;

// Create a new bill
Bill* createBill() {
    Bill* bill = malloc(sizeof(Bill));
    bill->numItems = 0;
    bill->totalCost = 0.0;
    return bill;
}

// Add an item to a bill
void addItemToBill(Bill* bill, MenuItem item, int quantity) {
    if (bill->numItems >= MAX_ITEMS) {
        printf("Error: Bill is full.\n");
        return;
    }

    bill->items[bill->numItems].item = item;
    bill->items[bill->numItems].quantity = quantity;
    bill->numItems++;

    bill->totalCost += atof(item.price) * quantity;
}

// Print a bill
void printBill(Bill* bill) {
    printf("Bill:\n");
    for (int i = 0; i < bill->numItems; i++) {
        printf("%s x%d = $%.2f\n", bill->items[i].item.name, bill->items[i].quantity, atof(bill->items[i].item.price) * bill->items[i].quantity);
    }
    printf("Total cost: $%.2f\n", bill->totalCost);
}

// Main function
int main() {
    // Create a new bill
    Bill* bill = createBill();

    // Add some items to the bill
    MenuItem item1 = {"Hamburger", "A delicious hamburger with all the fixings.", "5.99"};
    addItemToBill(bill, item1, 2);

    MenuItem item2 = {"French fries", "Crispy golden brown french fries.", "2.99"};
    addItemToBill(bill, item2, 1);

    MenuItem item3 = {"Soda", "A refreshing soda drink.", "1.99"};
    addItemToBill(bill, item3, 3);

    // Print the bill
    printBill(bill);

    // Free the bill
    free(bill);

    return 0;
}