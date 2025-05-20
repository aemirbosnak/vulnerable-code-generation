//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_MENU_ITEMS 10
#define MAX_MENU_ITEM_LEN 50
#define MAX_MENU_ITEM_PRICE 1000

typedef struct {
    char name[MAX_MENU_ITEM_LEN];
    int price;
} MenuItem;

typedef struct {
    char name[MAX_MENU_ITEM_LEN];
    int price;
    int quantity;
} OrderItem;

void printMenu(MenuItem menuItems[], int numMenuItems) {
    for (int i = 0; i < numMenuItems; i++) {
        printf("%d. %s - $%d\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

int getMenuItemIndex(MenuItem menuItems[], int numMenuItems, char* name) {
    for (int i = 0; i < numMenuItems; i++) {
        if (strcmp(menuItems[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    MenuItem menuItems[] = {{"Coffee", 50}, {"Tea", 25}, {"Cake", 75}, {"Sandwich", 100}};
    int numMenuItems = sizeof(menuItems) / sizeof(MenuItem);

    int choice;
    printf("Welcome to the Cafe in the Wasteland!\n");
    while (true) {
        printf("Please choose an option:\n");
        printf("1. View Menu\n");
        printf("2. Place Order\n");
        printf("3. View Order\n");
        printf("4. Pay Bill\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printMenu(menuItems, numMenuItems);
                break;
            case 2:
                // Place Order
                break;
            case 3:
                // View Order
                break;
            case 4:
                // Pay Bill
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}