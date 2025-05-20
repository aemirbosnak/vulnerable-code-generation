//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MENU_ITEMS 50
#define MAX_MENU_ITEM_LEN 50
#define MAX_MENU_ITEM_PRICE 1000

typedef struct {
    char name[MAX_MENU_ITEM_LEN];
    int price;
} menu_item_t;

menu_item_t menu_items[MAX_MENU_ITEMS];
int num_menu_items = 0;

void add_menu_item(char *name, int price) {
    if (num_menu_items >= MAX_MENU_ITEMS) {
        printf("Error: Maximum number of menu items reached.\n");
        return;
    }

    strcpy(menu_items[num_menu_items].name, name);
    menu_items[num_menu_items].price = price;

    num_menu_items++;
}

void display_menu() {
    printf("Cafe Menu:\n");

    for (int i = 0; i < num_menu_items; i++) {
        printf("%d. %s - $%d\n", i+1, menu_items[i].name, menu_items[i].price);
    }
}

void take_order() {
    int choice;
    char name[MAX_MENU_ITEM_LEN];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Select a menu item:\n");
    display_menu();

    scanf("%d", &choice);

    if (choice < 1 || choice > num_menu_items) {
        printf("Invalid choice.\n");
        return;
    }

    printf("You ordered %s for $%d\n", menu_items[choice-1].name, menu_items[choice-1].price);
}

int main() {
    add_menu_item("Coffee", 5);
    add_menu_item("Tea", 4);
    add_menu_item("Milk", 3);

    take_order();

    return 0;
}