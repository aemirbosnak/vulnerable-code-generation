//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int count;
} CafeMenu;

typedef struct {
    char customerName[MAX_NAME_LENGTH];
    MenuItem orderedItems[MAX_ITEMS];
    int orderedCount;
    float totalAmount;
} Invoice;

void displayMenu(CafeMenu *menu) {
    printf("\nCafe Menu:\n");
    for (int i = 0; i < menu->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu->items[i].name, menu->items[i].price);
    }
    printf("0. Finish Order\n");
}

void takeOrder(CafeMenu *menu, Invoice *invoice) {
    int choice;
    printf("Enter Customer Name: ");
    fgets(invoice->customerName, sizeof(invoice->customerName), stdin);
    invoice->customerName[strcspn(invoice->customerName, "\n")] = 0; // Remove newline

    do {
        displayMenu(menu);
        printf("Select an item by number: ");
        scanf("%d", &choice);
        if (choice > 0 && choice <= menu->count) {
            invoice->orderedItems[invoice->orderedCount] = menu->items[choice - 1]; // Add item to order
            invoice->totalAmount += menu->items[choice - 1].price;
            invoice->orderedCount++;
            printf("Added %s to your order.\n", menu->items[choice - 1].name);
        } else if (choice != 0) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0 && invoice->orderedCount < MAX_ITEMS);
}

void printInvoice(const Invoice *invoice) {
    printf("\n--- INVOICE ---\n");
    printf("Customer Name: %s\n", invoice->customerName);
    printf("Ordered Items:\n");
    for (int i = 0; i < invoice->orderedCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, invoice->orderedItems[i].name, invoice->orderedItems[i].price);
    }
    printf("Total Amount: $%.2f\n", invoice->totalAmount);
}

int main() {
    CafeMenu menu = {
        .items = {
            {"Espresso", 2.50},
            {"Latte", 3.00},
            {"Cappuccino", 3.50},
            {"Tea", 1.50},
            {"Sandwich", 5.00}
        },
        .count = 5
    };

    Invoice invoice = { .orderedCount = 0, .totalAmount = 0.0 };

    printf("Welcome to the Cafe Billing System!\n");
    
    takeOrder(&menu, &invoice);
    printInvoice(&invoice);

    printf("Thank you for visiting!\n");
    return 0;
}