//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_PRICE 10

typedef struct {
    char name[MAX_NAME];
    float price;
} Item;

typedef struct {
    int numItems;
    Item items[MAX_ITEMS];
} Menu;

void addItem(Menu* menu) {
    int i;
    for (i = 0; i < menu->numItems; i++) {
        if (strcmp(menu->items[i].name, "") == 0) {
            printf("Enter name of item %d:\n", i+1);
            scanf("%s", menu->items[i].name);
            printf("Enter price of item %d:\n", i+1);
            scanf("%f", &menu->items[i].price);
            break;
        }
    }
    if (i == menu->numItems) {
        printf("Menu is full.\n");
    }
}

void displayMenu(Menu* menu) {
    int i;
    printf("Menu:\n");
    for (i = 0; i < menu->numItems; i++) {
        if (strcmp(menu->items[i].name, "")!= 0) {
            printf("%d. %s - $%.2f\n", i+1, menu->items[i].name, menu->items[i].price);
        }
    }
}

void orderItem(Menu* menu, int choice) {
    int i;
    for (i = 0; i < menu->numItems; i++) {
        if (strcmp(menu->items[i].name, "")!= 0 && i+1 == choice) {
            printf("You ordered %s for $%.2f.\n", menu->items[i].name, menu->items[i].price);
            break;
        }
    }
}

int main() {
    Menu menu;
    menu.numItems = 0;
    int choice;

    while (1) {
        printf("1. Add item\n2. Display menu\n3. Order item\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addItem(&menu);
            break;
        case 2:
            displayMenu(&menu);
            break;
        case 3:
            printf("Enter choice:\n");
            scanf("%d", &choice);
            orderItem(&menu, choice-1);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}