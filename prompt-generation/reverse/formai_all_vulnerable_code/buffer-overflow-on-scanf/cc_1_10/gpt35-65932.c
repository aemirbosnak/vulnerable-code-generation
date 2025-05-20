//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 20
#define MAX_NAME_LENGTH 30
#define MAX_ORDER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
} MenuItem;

void printMenu(MenuItem menu[MAX_MENU_ITEMS], int numItems) {
    printf("----- C Cafe Menu -----\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f\n", menu[i].name, menu[i].price);
    }
}

void addMenuItem(MenuItem menu[MAX_MENU_ITEMS], int *numItems) {
    if (*numItems == MAX_MENU_ITEMS) {
        printf("Menu is full! Please remove an item before adding a new one.\n");
        return;
    }
    printf("Enter new item name: ");
    scanf("%s", menu[*numItems].name);
    printf("Enter new item price: ");
    scanf("%lf", &menu[*numItems].price);
    (*numItems)++;
    printf("New item added to menu!\n");
}

void removeMenuItem(MenuItem menu[MAX_MENU_ITEMS], int *numItems) {
    char itemToRemove[MAX_NAME_LENGTH];
    printf("Enter name of item to remove: ");
    scanf("%s", itemToRemove);
    for (int i = 0; i < *numItems; i++) {
        if (strcmp(menu[i].name, itemToRemove) == 0) {
            for (int j = i; j < *numItems - 1; j++) {
                strcpy(menu[j].name, menu[j + 1].name);
                menu[j].price = menu[j + 1].price;
            }
            (*numItems)--;
            printf("Item removed from menu!\n");
            return;
        }
    }
    printf("Item not found in menu!\n");
}

int main() {
    MenuItem menu[MAX_MENU_ITEMS];
    int numItems = 0;
    int option;
    char order[MAX_ORDER_LENGTH] = "";
    double totalCost = 0;
    
    printf("Welcome to C Cafe!\n");
    printf("-------------------\n");
    while(1) {
        printf("Menu options:\n");
        printf("1. View menu\n");
        printf("2. Add item to menu\n");
        printf("3. Remove item from menu\n");
        printf("4. Place order\n");
        printf("5. Exit\n");
        printf("Enter option number: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printMenu(menu, numItems);
                break;
            case 2:
                addMenuItem(menu, &numItems);
                break;
            case 3:
                removeMenuItem(menu, &numItems);
                break;
            case 4:
                printf("Enter order (comma-separated names of items): ");
                scanf("%s", order);

                char *token = strtok(order, ",");
                while (token != NULL) {
                    int itemFound = 0;
                    for (int i = 0; i < numItems; i++) {
                        if (strcmp(menu[i].name, token) == 0) {
                            totalCost += menu[i].price;
                            itemFound = 1;
                            break;
                        }
                    }
                    if (!itemFound) {
                        printf("Item \"%s\" not found in menu.\n", token);
                    }
                    token = strtok(NULL, ",");
                }

                printf("---- Order Summary ----\n");
                printf("Items: %s\n", order);
                printf("Total cost: $%.2f\n", totalCost);
                break;
            case 5:
                printf("Thank you for choosing C Cafe!\n");
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}