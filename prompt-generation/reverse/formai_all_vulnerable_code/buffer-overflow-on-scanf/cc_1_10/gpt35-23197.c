//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENU_FILE "menu.txt"

struct MenuItem {
    char name[25];
    int price;
};

int main() {
    int numItems;
    struct MenuItem menu[10];
    char itemName[25], response;
    int itemQty, itemPrice, total = 0, i, j;

    FILE *menuFile = fopen(MENU_FILE, "r");

    if (menuFile == NULL) {
        printf("Error opening menu file. Exiting program.\n");
        exit(1);
    }

    fscanf(menuFile, "%d", &numItems);

    for (i = 0; i < numItems; i++) {
        fscanf(menuFile, "%s %d", menu[i].name, &menu[i].price);
        printf("%s - %d\n", menu[i].name, menu[i].price);
    }

    fclose(menuFile);

    while (1) {
        printf("Enter item name: ");
        scanf("%s", itemName);

        for (i = 0; i < numItems; i++) {
            if (strcmp(itemName, menu[i].name) == 0) {
                itemPrice = menu[i].price;
                break;
            }
        }

        if (i == numItems) {
            printf("Item not found. Try again? (y/n) ");
            scanf(" %c", &response);

            if (response == 'n')
                break;

            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &itemQty);

        total += itemQty * itemPrice;

        printf("Item added. Total: %d\n", total);

        printf("Add another item? (y/n) ");
        scanf(" %c", &response);

        if (response == 'n')
            break;
    }

    printf("Total bill: %d\n", total);

    return 0;
}