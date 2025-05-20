//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 10
#define MAX_NAME 20
#define MAX_PRICE 10
#define MAX_QUANTITY 10
#define MAX_BILL_ITEMS 100

typedef struct {
    char name[MAX_NAME];
    float price;
    int quantity;
} Item;

typedef struct {
    int count;
    Item items[MAX_BILL_ITEMS];
} Bill;

void addItem(Item *item, int *count) {
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter item price: ");
    scanf("%f", &item->price);
    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);
    (*count)++;
}

void displayBill(Bill *bill) {
    printf("\nBill:\n");
    printf("Item\tPrice\tQuantity\tTotal\n");
    for (int i = 0; i < bill->count; i++) {
        float total = bill->items[i].price * bill->items[i].quantity;
        printf("%-20s $%-10.2f %d $%-10.2f\n", bill->items[i].name, bill->items[i].price, bill->items[i].quantity, total);
    }
    printf("\nTotal: $%.2f\n", bill->items[0].price * bill->items[0].quantity);
}

void main() {
    char choice;
    int count = 0;
    Item items[MAX_ITEMS];
    Bill bill;

    do {
        printf("\nCafe Billing System\n");
        printf("1. Add item\n2. Display bill\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                addItem(&items[count], &count);
                break;
            case '2':
                bill.count = count;
                for (int i = 0; i < count; i++) {
                    bill.items[i] = items[i];
                }
                displayBill(&bill);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '3');
}