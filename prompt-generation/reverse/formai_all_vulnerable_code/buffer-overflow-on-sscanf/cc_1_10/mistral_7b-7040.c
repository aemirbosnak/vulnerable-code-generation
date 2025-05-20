//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    float price;
    int quantity;
} MenuItem;

typedef struct {
    char customerName[50];
    int tableNumber;
    MenuItem items[10];
    int numItems;
    float total;
} Bill;

void printMenu() {
    printf("\n--- MENU ---");
    FILE *menuFile = fopen("menu.txt", "r");
    char line[100];
    MenuItem currentItem;
    int i = 0;

    while (fgets(line, sizeof(line), menuFile)) {
        sscanf(line, "%s %f", currentItem.name, &currentItem.price);
        currentItem.quantity = 0;
        if (i < 10) {
            printf("%d. %s $%.2f\n", i + 1, currentItem.name, currentItem.price);
            i++;
        }
    }

    fclose(menuFile);
}

void orderItem(Bill *bill, int itemNumber) {
    MenuItem *item = &bill->items[itemNumber - 1];
    item->quantity++;
    bill->numItems++;
    bill->total += item->price;
}

void printBill(Bill bill) {
    printf("\n--- BILL ---");
    printf("\nCustomer: %s", bill.customerName);
    printf("\nTable: %d", bill.tableNumber);

    int i;
    for (i = 0; i < bill.numItems; i++) {
        printf("\n%s: $%.2f x%d", bill.items[i].name, bill.items[i].price, bill.items[i].quantity);
        bill.total += bill.items[i].price * bill.items[i].quantity;
    }

    printf("\nTotal: $%.2f", bill.total);
}

int main() {
    Bill myBill;
    strcpy(myBill.customerName, "John Doe");
    myBill.tableNumber = 42;

    printMenu();

    int choice;
    for (;;) {
        printf("\nEnter item number or 0 to finish: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        orderItem(&myBill, choice);
    }

    printBill(myBill);

    return 0;
}