//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 10
#define PRICE_PER_ITEM 5.0

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} MenuItem;

MenuItem menu[] = {{"Cappuccino", 1}, {"Latte", 1}, {"Espresso", 1}, {"Mocha", 1}, {"Americano", 1}, {"Tea", 1}, {"Cookies", 1}, {"Cake", 1}, {"Sandwich", 1}, {"Burger", 1}};

void displayMenu() {
    int i;
    printf("\n-------- MENU --------\n");
    for (i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        printf("%d. %s\n", i + 1, menu[i].name);
    }
    printf("\n-------- ORDER --------\n");
}

void takeOrder(MenuItem items[]) {
    int choice, i, qty;
    char name[MAX_NAME_LENGTH];

    for (i = 0; i < MAX_ITEMS; i++) {
        printf("Enter the item number you want to order: ");
        scanf("%d", &choice);
        if (choice > 0 && choice <= sizeof(menu) / sizeof(menu[0])) {
            strcpy(name, menu[choice - 1].name);
            printf("Enter the quantity: ");
            scanf("%d", &qty);
            if (qty > 0 && qty <= MAX_QUANTITY) {
                items[i].quantity += qty;
                printf("%s added to your order.\n", name);
            } else {
                printf("Invalid quantity.\n");
            }
        } else {
            printf("Invalid choice.\n");
        }
    }
}

void calculateBill(MenuItem items[], float *total) {
    int i;
    *total = 0.0;
    for (i = 0; i < MAX_ITEMS; i++) {
        *total += items[i].quantity * PRICE_PER_ITEM;
    }
}

void printReceipt(float total) {
    printf("\n-------- RECEIPT --------\n");
    printf("Total: $%.2f\n", total);
}

int main() {
    MenuItem order[MAX_ITEMS];
    float total;

    displayMenu();
    takeOrder(order);
    calculateBill(order, &total);
    printReceipt(total);

    return 0;
}