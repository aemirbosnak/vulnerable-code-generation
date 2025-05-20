//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price_str[MAX_PRICE_LEN];
    float price;
} item_t;

typedef struct {
    int num_items;
    item_t items[MAX_ITEMS];
} menu_t;

void add_item(menu_t *menu) {
    printf("Enter item name: ");
    scanf("%s", menu->items[menu->num_items].name);
    printf("Enter item price: ");
    scanf("%s", menu->items[menu->num_items].price_str);
    menu->items[menu->num_items].price = atof(menu->items[menu->num_items].price_str);
    menu->num_items++;
}

void display_menu(menu_t *menu) {
    printf("Menu:\n");
    for (int i = 0; i < menu->num_items; i++) {
        printf("%s - $%.2f\n", menu->items[i].name, menu->items[i].price);
    }
}

void take_order(menu_t *menu) {
    char order[MAX_NAME_LEN];
    float total = 0;

    printf("Enter your order: ");
    scanf("%s", order);

    for (int i = 0; i < menu->num_items; i++) {
        if (strcmp(menu->items[i].name, order) == 0) {
            total += menu->items[i].price;
            printf("You ordered %s for $%.2f.\n", menu->items[i].name, menu->items[i].price);
        }
    }

    if (total == 0) {
        printf("Sorry, we don't have that item.\n");
    } else {
        printf("Your total is $%.2f.\n", total);
    }
}

int main() {
    menu_t menu;
    menu.num_items = 0;

    add_item(&menu);
    add_item(&menu);
    add_item(&menu);

    display_menu(&menu);

    take_order(&menu);

    return 0;
}