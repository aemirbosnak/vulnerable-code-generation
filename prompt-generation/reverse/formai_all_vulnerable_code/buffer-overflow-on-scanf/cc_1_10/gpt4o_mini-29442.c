//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_SIZE 30

typedef struct {
    char name[NAME_SIZE];
    float price;
    int quantity;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int count;
} Bill;

void addItemToBill(Bill *bill) {
    if (bill->count >= MAX_ITEMS) {
        printf("Bill is full! Cannot add more items.\n");
        return;
    }

    MenuItem item;
    printf("Enter the item name: ");
    scanf("%s", item.name);
    printf("Enter the item price: ");
    scanf("%f", &item.price);
    printf("Enter the item quantity: ");
    scanf("%d", &item.quantity);
    
    bill->items[bill->count] = item;
    bill->count++;
    printf("Item added!\n");
}

void printBill(const Bill *bill) {
    if (bill->count == 0) {
        printf("Bill is empty.\n");
        return;
    }

    printf("\n----- Bill -----\n");
    float total = 0.0;
    for (int i = 0; i < bill->count; i++) {
        printf("%d. %s (Price: %.2f, Quantity: %d)\n", i+1, bill->items[i].name, bill->items[i].price, bill->items[i].quantity);
        total += bill->items[i].price * bill->items[i].quantity;
    }
    printf("Total: %.2f\n", total);
    printf("----------------\n");
}

void clearBill(Bill *bill) {
    bill->count = 0;
    printf("Bill cleared!\n");
}

int main() {
    Bill bill = { .count = 0 };
    int choice;

    while (1) {
        printf("\nCafe Billing System:\n");
        printf("1. Add Item to Bill\n");
        printf("2. Print Bill\n");
        printf("3. Clear Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItemToBill(&bill);
                break;
            case 2:
                printBill(&bill);
                break;
            case 3:
                clearBill(&bill);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}