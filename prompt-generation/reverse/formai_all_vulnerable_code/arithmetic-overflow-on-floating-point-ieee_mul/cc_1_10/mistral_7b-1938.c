//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 10

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

typedef struct {
    char customerName[MAX_NAME_LEN];
    Item items[MAX_ITEMS];
    int numItems;
    float total;
} Bill;

void initBill(Bill *bill);
void addItem(Bill *bill, const char *itemName, int quantity, float price);
void printBill(const Bill *bill);

int main() {
    Bill bill;
    initBill(&bill);

    while (1) {
        printf("Enter item name (or 'q' to quit): ");
        char itemName[MAX_NAME_LEN];
        scanf("%s", itemName);
        if (itemName[0] == 'q') {
            break;
        }

        printf("Enter quantity: ");
        int quantity;
        scanf("%d", &quantity);

        printf("Enter price: ");
        float price;
        scanf("%f", &price);

        addItem(&bill, itemName, quantity, price);
    }

    printBill(&bill);

    return 0;
}

void initBill(Bill *bill) {
    strcpy(bill->customerName, "");
    bill->numItems = 0;
    bill->total = 0.0;
}

void addItem(Bill *bill, const char *itemName, int quantity, float price) {
    if (bill->numItems == MAX_ITEMS) {
        printf("Cannot add more items to the bill.\n");
        return;
    }

    strcpy(bill->items[bill->numItems].name, itemName);
    bill->items[bill->numItems].quantity = quantity;
    bill->items[bill->numItems].price = price;

    bill->total += quantity * price;
    bill->numItems++;
}

void printBill(const Bill *bill) {
    printf("\n************************************\n");
    printf("Bill for %s\n", bill->customerName);
    printf("------------------------------------\n");

    for (int i = 0; i < bill->numItems; i++) {
        printf("%-20s %4d %8.2f\n", bill->items[i].name, bill->items[i].quantity, bill->items[i].price);
    }

    printf("------------------------------------\n");
    printf("Total: %8.2f\n", bill->total);
    printf("************************************\n");
}