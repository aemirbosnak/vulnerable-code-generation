//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Structure to store the item details
struct Item {
    char name[50];
    float price;
    int quantity;
};

// Structure to store the bill details
struct Bill {
    struct Item items[100];
    int numItems;
    float totalAmount;
};

// Function to create a new bill
struct Bill* createBill() {
    struct Bill *bill = (struct Bill*)malloc(sizeof(struct Bill));
    bill->numItems = 0;
    bill->totalAmount = 0.0;
    return bill;
}

// Function to add an item to the bill
void addItem(struct Bill *bill, struct Item item) {
    bill->items[bill->numItems] = item;
    bill->numItems++;
    bill->totalAmount += item.price * item.quantity;
}

// Function to print the bill
void printBill(struct Bill *bill) {
    printf("Bill Details:\n");
    for (int i = 0; i < bill->numItems; i++) {
        printf("%s\t%d\t%.2f\n", bill->items[i].name, bill->items[i].quantity, bill->items[i].price * bill->items[i].quantity);
    }
    printf("Total Amount: %.2f\n", bill->totalAmount);
}

// Driver code
int main() {
    // Create a new bill
    struct Bill *bill = createBill();

    // Add items to the bill
    struct Item item1 = {"Coffee", 10.0, 2};
    addItem(bill, item1);
    struct Item item2 = {"Tea", 5.0, 3};
    addItem(bill, item2);
    struct Item item3 = {"Sandwich", 15.0, 1};
    addItem(bill, item3);

    // Print the bill
    printBill(bill);

    return 0;
}