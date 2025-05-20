//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 10
#define MAX_MENU_ITEM_NAME_LENGTH 50
#define MAX_MENU_ITEM_PRICE 1000

typedef struct {
    char name[MAX_MENU_ITEM_NAME_LENGTH];
    int price;
} MenuItem;

void addMenuItem(MenuItem* menuItems, int count, char* name, int price) {
    if (count >= MAX_MENU_ITEMS) {
        printf("Error: maximum number of menu items reached.\n");
        return;
    }

    strcpy(menuItems[count].name, name);
    menuItems[count].price = price;
    count++;
}

int main() {
    char choice;
    int customerCount = 0;
    float totalSales = 0;
    MenuItem menuItems[MAX_MENU_ITEMS];
    int menuItemCount = 0;

    do {
        printf("\nWelcome to the Cafe Billing System!\n");

        if (menuItemCount == 0) {
            printf("No menu items available.\n");
        } else {
            printf("Available menu items:\n");
            for (int i = 0; i < menuItemCount; i++) {
                printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
            }
        }

        printf("\nEnter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter the name of the menu item: ");
                scanf("%s", menuItems[menuItemCount].name);
                printf("Enter the price of the menu item: $");
                scanf("%d", &menuItems[menuItemCount].price);
                menuItemCount++;
                printf("\nMenu item added successfully.\n");
                break;
            case '2':
                printf("Enter the number of customers: ");
                scanf("%d", &customerCount);
                printf("\nTotal sales: $%.2f\n", customerCount * menuItems[0].price);
                totalSales += customerCount * menuItems[0].price;
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nTotal sales: $%.2f\n", totalSales);

    return 0;
}