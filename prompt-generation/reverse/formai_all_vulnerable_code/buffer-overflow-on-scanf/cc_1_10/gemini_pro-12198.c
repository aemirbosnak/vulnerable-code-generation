//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char name[50];
    int price;
    int quantity;
} item;

typedef struct order {
    int num_items;
    item *items;
} order;

void print_menu() {
    printf("Welcome to the Cafe Billing System!\n");
    printf("---------------------------------\n");
    printf("1. Add item to order\n");
    printf("2. Remove item from order\n");
    printf("3. Print order\n");
    printf("4. Checkout\n");
    printf("5. Exit\n");
}

order *create_order() {
    order *o = malloc(sizeof(order));
    o->num_items = 0;
    o->items = NULL;
    return o;
}

void add_item_to_order(order *o, item i) {
    o->num_items++;
    o->items = realloc(o->items, o->num_items * sizeof(item));
    o->items[o->num_items - 1] = i;
}

void remove_item_from_order(order *o, int index) {
    if (index < 0 || index >= o->num_items) {
        printf("Invalid index\n");
        return;
    }
    for (int i = index + 1; i < o->num_items; i++) {
        o->items[i - 1] = o->items[i];
    }
    o->num_items--;
    o->items = realloc(o->items, o->num_items * sizeof(item));
}

void print_order(order *o) {
    printf("Your order:\n");
    printf("---------------------------------\n");
    for (int i = 0; i < o->num_items; i++) {
        printf("%s x %d = %d\n", o->items[i].name, o->items[i].quantity, o->items[i].price * o->items[i].quantity);
    }
    printf("Total: %d\n", get_total(o));
}

int get_total(order *o) {
    int total = 0;
    for (int i = 0; i < o->num_items; i++) {
        total += o->items[i].price * o->items[i].quantity;
    }
    return total;
}

int main() {
    order *o = create_order();
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                item i;
                printf("Enter item name: ");
                scanf("%s", i.name);
                printf("Enter item price: ");
                scanf("%d", &i.price);
                printf("Enter item quantity: ");
                scanf("%d", &i.quantity);
                add_item_to_order(o, i);
                break;
            }
            case 2: {
                int index;
                printf("Enter item index: ");
                scanf("%d", &index);
                remove_item_from_order(o, index);
                break;
            }
            case 3: {
                print_order(o);
                break;
            }
            case 4: {
                int total = get_total(o);
                printf("Your total is: %d\n", total);
                printf("Thank you for your order!\n");
                free(o);
                return 0;
            }
            case 5: {
                printf("Goodbye!\n");
                free(o);
                return 0;
            }
            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    } while (choice != 5);
    return 0;
}