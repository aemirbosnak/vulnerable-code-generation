//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    double itemPrice;
    int itemQuantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Bill;

void displayMenu() {
    printf("Cafe Menu:\n");
    printf("1. Espresso - $2.50\n");
    printf("2. Cappuccino - $3.00\n");
    printf("3. Latte - $3.50\n");
    printf("4. Mocha - $4.00\n");
    printf("5. Tea - $1.50\n");
    printf("Please enter the item number to add to your bill or 0 to finish:\n");
}

void addItemToBill(Bill* bill, int itemNumber) {
    char* names[] = {"Espresso", "Cappuccino", "Latte", "Mocha", "Tea"};
    double prices[] = {2.50, 3.00, 3.50, 4.00, 1.50};

    if (itemNumber < 1 || itemNumber > 5) {
        return;
    }

    strcpy(bill->items[bill->itemCount].itemName, names[itemNumber - 1]);
    bill->items[bill->itemCount].itemPrice = prices[itemNumber - 1];
    bill->items[bill->itemCount].itemQuantity = 1; // Default to 1 for simplicity
    bill->itemCount++;
}

void printBill(const Bill* bill) {
    double total = 0.0;
    printf("\nYour Bill:\n");
    printf("-------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Item", "Price", "Quantity");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < bill->itemCount; i++) {
        printf("%-20s $%-9.2f %-10d\n", bill->items[i].itemName, bill->items[i].itemPrice, bill->items[i].itemQuantity);
        total += bill->items[i].itemPrice * bill->items[i].itemQuantity;
    }

    printf("-------------------------------------------------\n");
    printf("Total Amount: $%.2f\n", total);
}

int main() {
    Bill bill;
    bill.itemCount = 0;

    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }

        addItemToBill(&bill, choice);
    }

    printBill(&bill);

    // Final message
    printf("Thank you for visiting our cafe! Have a great day!\n");

    return 0;
}