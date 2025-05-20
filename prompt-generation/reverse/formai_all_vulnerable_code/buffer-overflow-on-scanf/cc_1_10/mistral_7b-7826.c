//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    float total;
} Invoice;

void add_item(Item *item, char *name, int quantity, float price);
void print_invoice(const Invoice *invoice);

int main() {
    Invoice invoice;
    Item items[MAX_ITEMS];

    invoice.num_items = 0;

    while (1) {
        printf("Enter item name (empty line to stop):\n");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);
        if (strlen(name) == 0)
            break;

        printf("Enter item quantity:\n");
        int quantity;
        scanf("%d", &quantity);

        printf("Enter item price:\n");
        float price;
        scanf("%f", &price);

        add_item(&items[invoice.num_items], name, quantity, price);
        invoice.num_items++;
    }

    for (int i = 0; i < invoice.num_items; i++) {
        invoice.total += items[i].quantity * items[i].price;
    }

    print_invoice(&invoice);

    return 0;
}

void add_item(Item *item, char *name, int quantity, float price) {
    strcpy(item->name, name);
    item->quantity = quantity;
    item->price = price;
}

void print_invoice(const Invoice *invoice) {
    printf("\nINVOICE\n");
    printf("--------\n");

    for (int i = 0; i < invoice->num_items; i++) {
        printf("%s\t%d\t%.2f\t%.2f\n", invoice->items[i].name,
               invoice->items[i].quantity, invoice->items[i].price,
               invoice->items[i].quantity * invoice->items[i].price);
    }

    printf("\nTotal:\t%.2f\n", invoice->total);
}