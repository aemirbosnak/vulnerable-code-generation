//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    int numItems;
    MenuItem items[MAX_ITEMS];
} Menu;

void addItem(Menu *menu) {
    int numItems = menu->numItems;
    menu->items[numItems].name[0] = '\0';
    printf("Enter item name: ");
    scanf("%s", menu->items[numItems].name);
    printf("Enter item price: ");
    scanf("%f", &menu->items[numItems].price);
    menu->numItems++;
}

void displayMenu(Menu *menu) {
    int i;
    printf("\nMenu:\n");
    for (i = 0; i < menu->numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu->items[i].name, menu->items[i].price);
    }
}

void placeOrder(Menu *menu, int customerNum) {
    int order[MAX_ITEMS];
    int numItems = 0;
    float totalPrice = 0.0;

    printf("\nCustomer %d's Order:\n", customerNum);

    while (numItems < MAX_ITEMS && menu->numItems > 0) {
        displayMenu(menu);
        printf("\nEnter item number to order or 0 to finish: ");
        scanf("%d", &order[numItems]);

        if (order[numItems] > 0 && order[numItems] <= menu->numItems) {
            totalPrice += menu->items[order[numItems]-1].price;
            numItems++;
        } else if (order[numItems] == 0) {
            break;
        } else {
            printf("Invalid item number.\n");
        }
    }

    printf("\nTotal price: $%.2f\n", totalPrice);
}

int main() {
    Menu menu;
    menu.numItems = 0;

    addItem(&menu);
    addItem(&menu);
    addItem(&menu);

    int numCustomers;
    printf("Enter number of customers: ");
    scanf("%d", &numCustomers);

    int i;
    for (i = 1; i <= numCustomers; i++) {
        placeOrder(&menu, i);
    }

    return 0;
}