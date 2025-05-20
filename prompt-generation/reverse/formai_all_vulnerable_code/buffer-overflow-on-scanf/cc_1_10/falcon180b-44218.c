//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 10
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_ITEM_PRICE 1000

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int price;
} MenuItem;

int main() {
    int numMenuItems = 0;
    MenuItem menuItems[MAX_MENU_ITEMS];
    char choice;
    int totalPrice = 0;

    do {
        printf("\nWelcome to the Cyberpunk Cafe!\n");
        printf("Please choose an option:\n");
        printf("1. View menu\n");
        printf("2. Order\n");
        printf("3. Pay\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Menu:\n");
                for (int i = 0; i < numMenuItems; i++) {
                    printf("%d. %s - $%d\n", i + 1, menuItems[i].name, menuItems[i].price);
                }
                break;
            case '2':
                printf("Enter the item number you want to order:\n");
                scanf("%d", &choice);
                if (choice >= 1 && choice <= numMenuItems) {
                    totalPrice += menuItems[choice - 1].price;
                    printf("You ordered %s for $%d.\n", menuItems[choice - 1].name, menuItems[choice - 1].price);
                } else {
                    printf("Invalid item number.\n");
                }
                break;
            case '3':
                printf("Your total is $%d.\n", totalPrice);
                break;
            case '4':
                printf("Thank you for visiting the Cyberpunk Cafe!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= '4');

    return 0;
}