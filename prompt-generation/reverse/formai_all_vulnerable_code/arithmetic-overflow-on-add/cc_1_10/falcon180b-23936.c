//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[30];
    int quantity;
    double price;
} item;

typedef struct {
    int num_items;
    item items[10];
} order;

void add_item(order* o) {
    printf("Enter item name: ");
    scanf("%s", o->items[o->num_items].name);
    printf("Enter item quantity: ");
    scanf("%d", &o->items[o->num_items].quantity);
    printf("Enter item price: ");
    scanf("%lf", &o->items[o->num_items].price);
    o->num_items++;
}

void remove_item(order* o) {
    printf("Enter item index to remove: ");
    int index;
    scanf("%d", &index);
    if (index >= 0 && index < o->num_items) {
        memmove(&o->items[index], &o->items[index+1], (o->num_items - index - 1) * sizeof(item));
        o->num_items--;
    } else {
        printf("Invalid item index.\n");
    }
}

void print_order(order* o) {
    printf("Order:\n");
    for (int i = 0; i < o->num_items; i++) {
        printf("%s - %d - $%.2lf\n", o->items[i].name, o->items[i].quantity, o->items[i].price);
    }
}

void calc_total(order* o) {
    double total = 0;
    for (int i = 0; i < o->num_items; i++) {
        total += o->items[i].quantity * o->items[i].price;
    }
    printf("Total: $%.2lf\n", total);
}

int main() {
    order o;
    o.num_items = 0;
    int choice;
    do {
        printf("1. Add item\n2. Remove item\n3. Print order\n4. Calculate total\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item(&o);
                break;
            case 2:
                remove_item(&o);
                break;
            case 3:
                print_order(&o);
                break;
            case 4:
                calc_total(&o);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);
    return 0;
}