//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} item;

typedef struct {
    int num_items;
    item *items;
    float total_price;
} order;

void print_menu() {
    printf("------- Cafe Menu -------\n");
    printf("1. Coffee\t\t$2.00\n");
    printf("2. Tea\t\t$1.50\n");
    printf("3. Cake\t\t$3.00\n");
    printf("4. Muffin\t\t$2.50\n");
    printf("5. Quit\t\t$0.00\n");
}

order* create_order() {
    order *o = malloc(sizeof(order));
    o->num_items = 0;
    o->items = NULL;
    o->total_price = 0.0f;
    return o;
}

void add_item_to_order(order *o, item *i) {
    o->num_items++;
    o->items = realloc(o->items, o->num_items * sizeof(item));
    o->items[o->num_items - 1] = *i;
    o->total_price += i->price * i->quantity;
}

void print_order(order *o) {
    printf("------- Order -------\n");
    for (int i = 0; i < o->num_items; i++) {
        printf("%s\t\t%d\t\t$%.2f\n", o->items[i].name, o->items[i].quantity, o->items[i].price * o->items[i].quantity);
    }
    printf("Total:\t\t\t$%.2f\n", o->total_price);
}

int main() {
    order *o = create_order();
    int choice;
    item i;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(i.name, "Coffee");
                i.quantity = 1;
                i.price = 2.00;
                add_item_to_order(o, &i);
                break;
            case 2:
                strcpy(i.name, "Tea");
                i.quantity = 1;
                i.price = 1.50;
                add_item_to_order(o, &i);
                break;
            case 3:
                strcpy(i.name, "Cake");
                i.quantity = 1;
                i.price = 3.00;
                add_item_to_order(o, &i);
                break;
            case 4:
                strcpy(i.name, "Muffin");
                i.quantity = 1;
                i.price = 2.50;
                add_item_to_order(o, &i);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    print_order(o);

    free(o->items);
    free(o);

    return 0;
}