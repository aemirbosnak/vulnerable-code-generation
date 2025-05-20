//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ORDER 50  // Maximum orders a user can place at once
#define MAX_ITEMS 10  // Maximum items a user can order at once
#define TAX 1.06      // Tax rate for orders

struct MenuItem {
    char name[50];
    float price;
    int quantity;
};

struct Order {
    struct MenuItem items[MAX_ITEMS];
    int numItems;
};

struct Table {
    struct Order orders[MAX_ORDER];
    int numOrders;
    float total;
};

int main() {
    int numTables;
    printf("How many tables do you have? ");
    scanf("%d", &numTables);
    struct Table tables[numTables];

    for(int i = 0; i < numTables; i++) {
        char orderMore = 'y';
        while(orderMore == 'y') {
            printf("\nOrder for table %d:\n", i+1);
            struct Order newOrder;
            newOrder.numItems = 0;
            char itemName[50];
            float itemPrice;

            do {
                printf("Enter item name: ");
                scanf("%s", itemName);

                struct MenuItem newItem;
                newItem.quantity = 1;
                strcpy(newItem.name, itemName);

                printf("Enter item price: ");
                scanf("%f", &itemPrice);
                newItem.price = itemPrice;

                newOrder.items[newOrder.numItems] = newItem;
                newOrder.numItems++;

                printf("Add another item? (y/n)");
                scanf(" %c", &orderMore);

            } while(orderMore == 'y' && newOrder.numItems < MAX_ITEMS);

            tables[i].orders[tables[i].numOrders] = newOrder;
            tables[i].numOrders++;
        }

        float tableTotal = 0;
        for(int j = 0; j < tables[i].numOrders; j++) {
            printf("\nTable %d, Order %d\n", i+1, j+1);
            float orderTotal = 0;
            for(int k = 0; k < tables[i].orders[j].numItems; k++) {
                struct MenuItem item = tables[i].orders[j].items[k];
                printf("%dx %s - $%.2f\n", item.quantity, item.name, item.price);
                orderTotal += item.price;
            }
            printf("Order total: $%.2f\n", orderTotal);
            tableTotal += orderTotal;
        }

        float taxedTotal = tableTotal * TAX;
        printf("\nTable %d total before tax: $%.2f\n", i+1, tableTotal);
        printf("Table %d total after tax: $%.2f\n", i+1, taxedTotal);
        tables[i].total = taxedTotal;
    }

    printf("\n\nBilling Summary:\n");
    for(int i = 0; i < numTables; i++) {
        printf("Table %d total: $%.2f\n", i+1, tables[i].total);
    }

    return 0;
}