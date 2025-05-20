//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    float total;
} Bill;

void print_menu() {
    printf("\n------------------------\n");
    printf("| Welcome to C Cafe! |\n");
    printf("------------------------\n");
    printf("| Available Items:     |\n");
    printf("------------------------\n");
    printf("| 1. Burger              | $5.99\n");
    printf("| 2. Sandwich           | $4.99\n");
    printf("| 3. Soda               | $1.99\n");
    printf("| 4. Coffee              | $2.99\n");
    printf("------------------------\n");
}

void add_item(Bill *bill) {
    if (bill->num_items >= MAX_ITEMS) {
        printf("\nMaximum number of items reached!\n");
        return;
    }

    printf("\nEnter item name: ");
    scanf("%s", bill->items[bill->num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &bill->items[bill->num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &bill->items[bill->num_items].price);

    bill->num_items++;
}

void calculate_total(Bill *bill) {
    for (int i = 0; i < bill->num_items; i++) {
        bill->total += bill->items[i].quantity * bill->items[i].price;
    }
}

void display_bill(Bill bill) {
    printf("\n------------------------\n");
    printf("| Bill                |\n");
    printf("------------------------\n");
    printf("| Items               |\n");
    printf("------------------------\n");

    for (int i = 0; i < bill.num_items; i++) {
        printf("| %-20s | %5d | $%6.2f |\n", bill.items[i].name, bill.items[i].quantity, bill.items[i].price);
    }

    printf("------------------------\n");
    printf("| Subtotal            | $%9.2f |\n", bill.total - 1.5); // Subtract 1.5 as a discount
    printf("| Tax (10%)            | $%6.2f |\n", bill.total * 0.1);
    printf("| Total               | $%9.2f |\n", bill.total);
    printf("------------------------\n");
}

int main() {
    Bill bill = {0};

    print_menu();

    while (1) {
        printf("\nDo you want to add an item? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y') {
            add_item(&bill);
        } else if (choice == 'n') {
            calculate_total(&bill);
            display_bill(bill);
            break;
        }
    }

    return 0;
}