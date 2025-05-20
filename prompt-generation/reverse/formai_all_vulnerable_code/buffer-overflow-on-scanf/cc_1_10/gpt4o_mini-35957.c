//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MENU_SIZE 5
#define MAX_NAME_LEN 50
#define MAX_ORDER_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MENU_SIZE];
    int orderCount;
    float total;
} Bill;

void initializeMenu(MenuItem menu[]);
void displayMenu(MenuItem menu[]);
void takeOrder(MenuItem menu[], Bill *bill);
void calculateTotal(Bill *bill);
void displayBill(Bill bill);

int main() {
    MenuItem menu[MENU_SIZE];
    Bill bill = { .orderCount = 0, .total = 0.0 };
    char anotherOrder;

    initializeMenu(menu);

    do {
        displayMenu(menu);
        takeOrder(menu, &bill);
        printf("Do you want to add another item to your order? (y/n): ");
        scanf(" %c", &anotherOrder);
    } while (anotherOrder == 'y' || anotherOrder == 'Y');

    calculateTotal(&bill);
    displayBill(bill);

    return 0;
}

void initializeMenu(MenuItem menu[]) {
    // Initialize menu items
    snprintf(menu[0].name, MAX_NAME_LEN, "Coffee");
    menu[0].price = 2.50;

    snprintf(menu[1].name, MAX_NAME_LEN, "Tea");
    menu[1].price = 1.75;

    snprintf(menu[2].name, MAX_NAME_LEN, "Sandwich");
    menu[2].price = 3.00;

    snprintf(menu[3].name, MAX_NAME_LEN, "Cake");
    menu[3].price = 2.25;

    snprintf(menu[4].name, MAX_NAME_LEN, "Juice");
    menu[4].price = 2.00;
}

void displayMenu(MenuItem menu[]) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < MENU_SIZE; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("------------------\n");
}

void takeOrder(MenuItem menu[], Bill *bill) {
    int choice, quantity;

    printf("Select an item by entering its number: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > MENU_SIZE) {
        printf("Invalid choice. Please select a valid item.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    if (quantity < 1) {
        printf("Invalid quantity. Please enter a positive number.\n");
        return;
    }

    // Adjust order count and total
    bill->items[bill->orderCount] = menu[choice - 1]; // Add item to bill
    bill->items[bill->orderCount].price *= quantity;   // Adjust price by quantity
    bill->orderCount++;
    bill->total += bill->items[bill->orderCount - 1].price;

    printf("Added %d x %s to your order.\n", quantity, menu[choice - 1].name);
}

void calculateTotal(Bill *bill) {
    // Finalize bill and calculate total
    printf("\n--- Finalizing Bill ---\n");
    for (int i = 0; i < bill->orderCount; i++) {
        printf("%s - $%.2f\n", bill->items[i].name, bill->items[i].price);
    }
}

void displayBill(Bill bill) {
    printf("-----------------------\n");
    printf("Total Amount: $%.2f\n", bill.total);
    printf("-----------------------\n");
    printf("Thank you for visiting!\n");
}