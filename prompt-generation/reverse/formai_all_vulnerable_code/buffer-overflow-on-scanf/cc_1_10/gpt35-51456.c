//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 50

struct MenuItem {
    char name[MAX_NAME_LENGTH];
    double price;
};

struct Order {
    char menuItem[MAX_NAME_LENGTH];
    int quantity;
    double totalPrice;
};

typedef struct MenuItem MenuItem;
typedef struct Order Order;

int getMenuSelection() {
    int selection;
    printf("\nMenu:\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. View Menu\n");
    printf("4. Place Order\n");
    printf("5. Exit\n");
    printf("Enter selection: ");
    scanf("%d", &selection);

    return selection;
}

void addItem(MenuItem menu[], int* numItems) {
    if (*numItems == MAX_ITEMS) {
        printf("Menu is full. Cannot add new items.\n");
        return;
    }

    printf("Enter name of menu item: ");
    scanf("%s", menu[*numItems].name);

    printf("Enter price of menu item: ");
    scanf("%lf", &menu[*numItems].price);

    printf("%s added to the menu.\n", menu[*numItems].name);

    *numItems += 1;
}

void removeItem(MenuItem menu[], int* numItems) {
    char name[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter name of item to remove: ");
    scanf("%s", name);

    for (int i = 0; i < *numItems; i++) {
        if (strcmp(name, menu[i].name) == 0) {
            found = 1;
            printf("%s removed from the menu.\n", menu[i].name);
            for (int j = i; j < *numItems - 1; j++) {
                menu[j] = menu[j + 1];
            }
            *numItems -= 1;
            break;
        }
    }

    if (!found) {
        printf("%s not found in the menu.\n", name);
    }
}

void viewMenu(MenuItem menu[], int numItems) {
    if (numItems == 0) {
        printf("Menu is empty.\n");
        return;
    }

    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s: %0.2lf\n", i + 1, menu[i].name, menu[i].price);
    }
}

double getPriceFromMenu(MenuItem menu[], int numItems, char name[MAX_NAME_LENGTH]) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(name, menu[i].name) == 0) {
            return menu[i].price;
        }
    }

    return 0;
}

void placeOrder(MenuItem menu[], int numItems, Order orders[], int* numOrders) {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double totalPrice = 0;

    printf("Enter name of menu item to order: ");
    scanf("%s", name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    double price = getPriceFromMenu(menu, numItems, name);
    if (price == 0) {
        printf("%s not found in the menu.\n", name);
        return;
    }

    totalPrice = price * quantity;
    printf("%d %s ordered for a total price of %0.2lf\n", quantity, name, totalPrice);

    strcpy(orders[*numOrders].menuItem, name);
    orders[*numOrders].quantity = quantity;
    orders[*numOrders].totalPrice = totalPrice;

    *numOrders += 1;
}

void viewOrders(Order orders[], int numOrders) {
    if (numOrders == 0) {
        printf("No orders placed yet.\n");
        return;
    }

    printf("Orders:\n");
    for (int i = 0; i < numOrders; i++) {
        printf("%d. %d %s: %0.2lf\n", i + 1, orders[i].quantity, orders[i].menuItem, orders[i].totalPrice);
    }
}

int main() {
    MenuItem menu[MAX_ITEMS];
    int numItems = 0;
    Order orders[MAX_ITEMS];
    int numOrders = 0;

    while (1) {
        int selection = getMenuSelection();

        switch (selection) {
            case 1:
                addItem(menu, &numItems);
                break;
            case 2:
                removeItem(menu, &numItems);
                break;
            case 3:
                viewMenu(menu, numItems);
                break;
            case 4:
                placeOrder(menu, numItems, orders, &numOrders);
                break;
            case 5:
                viewOrders(orders, numOrders);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid selection. Try again.\n");
                break;
        }
    }

    return 0;
}