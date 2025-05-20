//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int quantity;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int count;
} Bill;

void addItem(Bill *bill, const char *name, float price, int quantity) {
    if (bill->count < MAX_ITEMS) {
        strcpy(bill->items[bill->count].name, name);
        bill->items[bill->count].price = price;
        bill->items[bill->count].quantity = quantity;
        bill->count++;
    } else {
        printf("Bill is full, cannot add more items.\n");
    }
}

void printBill(const Bill *bill) {
    printf("\n--- Cafe Billing Summary ---\n");
    for (int i = 0; i < bill->count; i++) {
        printf("%s (x%d): %.2f\n", bill->items[i].name, bill->items[i].quantity, 
               bill->items[i].price * bill->items[i].quantity);
    }
}

float calculateTotal(const Bill *bill) {
    float total = 0.0;
    for (int i = 0; i < bill->count; i++) {
        total += bill->items[i].price * bill->items[i].quantity;
    }
    return total;
}

void clearBill(Bill *bill) {
    bill->count = 0;
}

void displayMenu() {
    printf("Available items:\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $1.75\n");
    printf("3. Sandwich - $5.00\n");
    printf("4. Cake - $3.25\n");
    printf("5. Exit\n");
}

int main() {
    Bill bill = {{}, 0};
    int choice;
    char name[NAME_LENGTH];
    float price;
    int quantity;

    while (1) {
        displayMenu();
        printf("Select an item to add to the bill (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(name, "Coffee");
                price = 2.50;
                break;
            case 2:
                strcpy(name, "Tea");
                price = 1.75;
                break;
            case 3:
                strcpy(name, "Sandwich");
                price = 5.00;
                break;
            case 4:
                strcpy(name, "Cake");
                price = 3.25;
                break;
            case 5:
                printf("Exiting...\n");
                printBill(&bill);
                printf("Total Amount Due: %.2f\n", calculateTotal(&bill));
                clearBill(&bill);
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);
        addItem(&bill, name, price, quantity);
    }

    return 0;
}