//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} MenuItem;

void addMenuItem(MenuItem* menuItems, int* numItems) {
    printf("Enter menu item name: ");
    scanf("%s", (*numItems >= MAX_ITEMS? "Error: too many items" : (*numItems) < MAX_ITEMS? menuItems[*numItems].name : ""));
    printf("Enter menu item price: ");
    scanf("%f", &menuItems[*numItems].price);
    (*numItems)++;
}

void displayMenu(MenuItem* menuItems, int numItems) {
    printf("\nMenu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

void placeOrder(MenuItem* menuItems, int numItems) {
    int order[MAX_ITEMS];
    int numOrders = 0;

    printf("\nEnter order (item number followed by quantity):\n");
    char input[100];
    while (fgets(input, sizeof(input), stdin)!= NULL && numOrders < MAX_ITEMS) {
        input[strcspn(input, "\n")] = '\0';
        sscanf(input, "%d %d", &order[numOrders], &order[numOrders+1]);
        numOrders += 2;
    }

    float totalPrice = 0;
    for (int i = 0; i < numOrders; i += 2) {
        totalPrice += menuItems[order[i]].price * order[i+1];
    }

    printf("\nTotal price: $%.2f\n", totalPrice);
}

int main() {
    MenuItem menuItems[MAX_ITEMS];
    int numMenuItems = 0;

    addMenuItem(menuItems, &numMenuItems);
    displayMenu(menuItems, numMenuItems);
    placeOrder(menuItems, numMenuItems);

    return 0;
}