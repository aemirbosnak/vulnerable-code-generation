//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 10
#define MAX_MENU_ITEM_NAME_LENGTH 50
#define MAX_MENU_ITEM_PRICE 9999

typedef struct {
    char name[MAX_MENU_ITEM_NAME_LENGTH];
    int price;
} MenuItem;

int main() {
    int numMenuItems = 0;
    MenuItem menuItems[MAX_MENU_ITEMS];

    // Initialize menu items
    strcpy(menuItems[numMenuItems].name, "Coffee");
    menuItems[numMenuItems].price = 100;
    numMenuItems++;

    strcpy(menuItems[numMenuItems].name, "Tea");
    menuItems[numMenuItems].price = 50;
    numMenuItems++;

    strcpy(menuItems[numMenuItems].name, "Cake");
    menuItems[numMenuItems].price = 200;
    numMenuItems++;

    // Display menu
    printf("Welcome to the Cafe!\n");
    printf("=====================\n");
    printf("| Menu Items         |\n");
    printf("=====================\n");

    for (int i = 0; i < numMenuItems; i++) {
        printf("%d. %s - $%d\n", i + 1, menuItems[i].name, menuItems[i].price);
    }

    printf("\nEnter your choice:\n");
    int choice = 0;
    scanf("%d", &choice);

    // Check if choice is valid
    if (choice < 1 || choice > numMenuItems) {
        printf("Invalid choice!\n");
        return 1;
    }

    // Display selected item and total price
    printf("\nYou chose %s - $%d\n", menuItems[choice - 1].name, menuItems[choice - 1].price);
    return 0;
}