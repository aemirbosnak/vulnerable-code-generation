//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char name[30];
    float price;
    int quantity;
} item;

typedef struct order {
    int id;
    char date[11];
    char time[9];
    item items[10];
    int num_items;
    float total_price;
} order;

void print_menu() {
    printf("\n\nWelcome to our cafe!\n");
    printf("---------------------\n");
    printf("1. Cappuccino - $3.50\n");
    printf("2. Latte - $4.00\n");
    printf("3. Americano - $2.50\n");
    printf("4. Espresso - $2.00\n");
    printf("5. Tea - $2.00\n");
    printf("6. Muffin - $2.50\n");
    printf("7. Croissant - $3.00\n");
}

int get_choice() {
    int choice;
    printf("\nEnter your choice (1-7): ");
    scanf("%d", &choice);
    return choice;
}

order create_order() {
    order new_order;

    printf("\nEnter the order ID: ");
    scanf("%d", &new_order.id);

    printf("\nEnter the date (dd/mm/yyyy): ");
    scanf("%s", new_order.date);

    printf("\nEnter the time (hh:mm): ");
    scanf("%s", new_order.time);

    new_order.num_items = 0;
    new_order.total_price = 0.0;

    return new_order;
}

void add_item(order *o) {
    int choice = get_choice();

    switch (choice) {
        case 1:
            strcpy(o->items[o->num_items].name, "Cappuccino");
            o->items[o->num_items].price = 3.50;
            break;
        case 2:
            strcpy(o->items[o->num_items].name, "Latte");
            o->items[o->num_items].price = 4.00;
            break;
        case 3:
            strcpy(o->items[o->num_items].name, "Americano");
            o->items[o->num_items].price = 2.50;
            break;
        case 4:
            strcpy(o->items[o->num_items].name, "Espresso");
            o->items[o->num_items].price = 2.00;
            break;
        case 5:
            strcpy(o->items[o->num_items].name, "Tea");
            o->items[o->num_items].price = 2.00;
            break;
        case 6:
            strcpy(o->items[o->num_items].name, "Muffin");
            o->items[o->num_items].price = 2.50;
            break;
        case 7:
            strcpy(o->items[o->num_items].name, "Croissant");
            o->items[o->num_items].price = 3.00;
            break;
    }

    printf("\nEnter the quantity: ");
    scanf("%d", &o->items[o->num_items].quantity);

    o->num_items++;
    o->total_price += o->items[o->num_items - 1].price * o->items[o->num_items - 1].quantity;
}

void print_order(order o) {
    printf("\n\nOrder ID: %d\n", o.id);
    printf("Date: %s\n", o.date);
    printf("Time: %s\n", o.time);

    printf("\nItems:\n");
    for (int i = 0; i < o.num_items; i++) {
        printf("%d. %s - $%.2f x %d\n", i + 1, o.items[i].name, o.items[i].price, o.items[i].quantity);
    }

    printf("\nTotal price: $%.2f\n", o.total_price);
}

int main() {
    order o = create_order();

    int choice;
    do {
        print_menu();
        choice = get_choice();

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                add_item(&o);
                break;
            case 8:
                print_order(o);
                break;
            case 9:
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 9);

    printf("\nThank you for your order!\n");

    return 0;
}