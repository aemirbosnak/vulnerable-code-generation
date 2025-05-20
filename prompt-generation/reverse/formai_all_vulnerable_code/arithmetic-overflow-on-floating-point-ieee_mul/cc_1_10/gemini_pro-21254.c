//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Structure to store item details
typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

// Structure to store bill details
typedef struct Bill {
    Item items[100];
    int numItems;
    float totalAmount;
} Bill;

// Function to create a new item
Item createItem(char *name, float price, int quantity) {
    Item item;
    strcpy(item.name, name);
    item.price = price;
    item.quantity = quantity;
    return item;
}

// Function to add an item to the bill
void addItemToBill(Bill *bill, Item item) {
    bill->items[bill->numItems] = item;
    bill->numItems++;
    bill->totalAmount += item.price * item.quantity;
}

// Function to print the bill
void printBill(Bill bill) {
    printf("Cafe Billing System\n");
    printf("===================\n");
    printf("Item\t\tPrice\tQuantity\tTotal\n");
    for (int i = 0; i < bill.numItems; i++) {
        printf("%s\t\t%.2f\t%d\t\t%.2f\n", bill.items[i].name, bill.items[i].price, bill.items[i].quantity, bill.items[i].price * bill.items[i].quantity);
    }
    printf("===================\n");
    printf("Total Amount: %.2f\n", bill.totalAmount);
}

// Main function
int main() {
    // Create a new bill
    Bill bill;
    bill.numItems = 0;
    bill.totalAmount = 0.0;

    // Add items to the bill
    addItemToBill(&bill, createItem("Coffee", 2.50, 2));
    addItemToBill(&bill, createItem("Tea", 1.50, 1));
    addItemToBill(&bill, createItem("Cake", 3.00, 1));

    // Print the bill
    printBill(bill);

    return 0;
}