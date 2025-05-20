//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int qty;
    float price;
} Item;

typedef struct {
    int id;
    char description[100];
    Item items[10];
    float total;
} Bill;

void read_item(Item *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter quantity: ");
    scanf("%d", &item->qty);
    printf("Enter price: ");
    scanf("%f", &item->price);
}

void add_item(Bill *bill, Item item) {
    int i;
    for (i = 0; i < 10 && bill->items[i].qty != 0; i++);

    if (i == 10) {
        printf("Bill full, can't add item.\n");
        return;
    }

    bill->items[i] = item;
    bill->total += item.qty * item.price;
}

void print_bill(Bill bill) {
    int i;
    printf("\n---Bill---\n");
    printf("Bill ID: %d\n", bill.id);
    printf("Description: %s\n", bill.description);
    printf("\n---Items---\n");
    for (i = 0; i < 10; i++) {
        if (bill.items[i].qty != 0) {
            printf("%s: %d x %0.2f\n", bill.items[i].name, bill.items[i].qty, bill.items[i].price);
        }
    }
    printf("\n---Total---\n");
    printf("Total: %0.2f\n", bill.total);
}

int main() {
    Bill bill;
    int i, choice;
    char desc[50];

    printf("Enter bill ID: ");
    scanf("%d", &bill.id);
    printf("Enter description: ");
    scanf("%s", desc);
    strcpy(bill.description, desc);

    for (i = 0; i < 10; i++) {
        Item item;
        printf("\nAdd item %d? (1 - Yes, 0 - No)\n", i + 1);
        scanf("%d", &choice);

        if (choice) {
            read_item(&item);
            add_item(&bill, item);
        }
    }

    print_bill(bill);

    return 0;
}