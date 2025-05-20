//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 100
#define MAX_QUANTITY_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char quantity[MAX_QUANTITY_LEN];
    char price[MAX_PRICE_LEN];
} item;

typedef struct {
    int num_items;
    item items[MAX_ITEMS];
} order;

void add_item(order *o) {
    if (o->num_items >= MAX_ITEMS) {
        printf("Cannot add more items\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", o->items[o->num_items].name);
    printf("Enter item quantity: ");
    scanf("%s", o->items[o->num_items].quantity);
    printf("Enter item price: ");
    scanf("%s", o->items[o->num_items].price);
    o->num_items++;
}

void print_order(order o) {
    printf("Order:\n");
    for (int i = 0; i < o.num_items; i++) {
        printf("Item %d:\n", i+1);
        printf("Name: %s\n", o.items[i].name);
        printf("Quantity: %s\n", o.items[i].quantity);
        printf("Price: $%s\n\n", o.items[i].price);
    }
}

void calculate_total(order o) {
    float total = 0;
    for (int i = 0; i < o.num_items; i++) {
        float quantity = atof(o.items[i].quantity);
        float price = atof(o.items[i].price);
        total += quantity * price;
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    order o;
    o.num_items = 0;
    int choice;
    do {
        printf("1. Add item\n2. Print order\n3. Calculate total\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item(&o);
                break;
            case 2:
                print_order(o);
                break;
            case 3:
                calculate_total(o);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 4);
    return 0;
}