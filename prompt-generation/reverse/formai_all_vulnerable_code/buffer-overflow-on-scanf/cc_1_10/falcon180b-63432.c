//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 20
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int numItems;
} Menu;

void addItem(Menu* menu, char* name, int price) {
    if (menu->numItems >= MAX_ITEMS) {
        printf("Error: menu is full.\n");
        return;
    }

    strcpy(menu->items[menu->numItems].name, name);
    menu->items[menu->numItems].price = price;
    menu->numItems++;
}

int main() {
    Menu menu = { { { "", 0 }, { "", 0 }, { "", 0 }, { "", 0 }, { "", 0 }, { "", 0 }, { "", 0 }, { "", 0 }, { "", 0 }, { "", 0 } }, 0 };

    addItem(&menu, "Coffee", 50);
    addItem(&menu, "Tea", 30);
    addItem(&menu, "Cake", 100);

    int choice;
    printf("Welcome to our cafe!\n");
    printf("Please choose an item:\n");

    for (int i = 0; i < menu.numItems; i++) {
        printf("%d. %s - $%d\n", i+1, menu.items[i].name, menu.items[i].price);
    }

    scanf("%d", &choice);

    if (choice < 1 || choice > menu.numItems) {
        printf("Invalid choice.\n");
        return 1;
    }

    Item* item = &menu.items[choice-1];
    printf("You chose %s for $%d.\n", item->name, item->price);

    return 0;
}