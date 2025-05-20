//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[30];
    float price;
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Bill;

void displayMenu();
void addItem(Bill *bill);
void displayBill(Bill bill);
float calculateTotal(Bill bill);

int main() {
    Bill bill;
    bill.itemCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&bill);
                break;
            case 2:
                displayBill(bill);
                break;
            case 3:
                printf("Total Amount: %.2f\n", calculateTotal(bill));
                break;
            case 4:
                printf("Exiting the Café Billing System. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n====== Café Billing System ======\n");
    printf("1. Add Item\n");
    printf("2. View Bill\n");
    printf("3. Calculate Total\n");
    printf("4. Exit\n");
    printf("=================================\n");
}

void addItem(Bill *bill) {
    if (bill->itemCount >= MAX_ITEMS) {
        printf("Cannot add more items. Bill is full!\n");
        return;
    }

    char itemName[30];
    float itemPrice;
    int itemQuantity;

    printf("Enter item name: ");
    scanf("%s", itemName);
    printf("Enter item price: ");
    scanf("%f", &itemPrice);
    printf("Enter item quantity: ");
    scanf("%d", &itemQuantity);

    strcpy(bill->items[bill->itemCount].name, itemName);
    bill->items[bill->itemCount].price = itemPrice;
    bill->items[bill->itemCount].quantity = itemQuantity;

    bill->itemCount++;
    printf("Item added to bill successfully!\n");
}

void displayBill(Bill bill) {
    if (bill.itemCount == 0) {
        printf("No items in the bill.\n");
        return;
    }

    printf("\n====== Bill ======\n");
    for (int i = 0; i < bill.itemCount; i++) {
        printf("%d. %s | Price: %.2f | Quantity: %d | Total: %.2f\n",
               i + 1, bill.items[i].name, bill.items[i].price,
               bill.items[i].quantity, bill.items[i].price * bill.items[i].quantity);
    }
    printf("===================\n");
}

float calculateTotal(Bill bill) {
    float total = 0.0;
    for (int i = 0; i < bill.itemCount; i++) {
        total += bill.items[i].price * bill.items[i].quantity;
    }
    return total;
}