//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_ITEMS 20

typedef struct {
    char name[50];
    int price;
} Item;

void addItem(Item menu[], int *numItems) {
    char name[50];
    int price;

    printf("Enter the name of the item: ");
    scanf("%s", name);

    printf("Enter the price of the item: ");
    scanf("%d", &price);

    strcpy(menu[*numItems].name, name);
    menu[*numItems].price = price;

    (*numItems)++;
}

void displayMenu(Item menu[], int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%d\n", i+1, menu[i].name, menu[i].price);
    }
}

void placeOrder(Item menu[], int numItems, int budget, int *totalSpent) {
    int choice;
    char name[50];
    int price;

    printf("Enter the name of the item you want to order: ");
    scanf("%s", name);

    for (int i = 0; i < numItems; i++) {
        if (strcmp(menu[i].name, name) == 0) {
            printf("You have chosen %s - $%d\n", menu[i].name, menu[i].price);
            printf("Do you want to order this item? (y/n): ");
            scanf(" %c", &choice);

            if (choice == 'y' || choice == 'Y') {
                if (*totalSpent + menu[i].price > budget) {
                    printf("You do not have enough budget to order this item.\n");
                } else {
                    printf("Order placed successfully!\n");
                    (*totalSpent) += menu[i].price;
                }
            }

            return;
        }
    }

    printf("Item not found in the menu.\n");
}

int main() {
    Item menu[MAX_ITEMS];
    int numItems = 0;

    addItem(menu, &numItems);
    addItem(menu, &numItems);
    addItem(menu, &numItems);

    int budget, totalSpent = 0;

    printf("Enter your budget: ");
    scanf("%d", &budget);

    displayMenu(menu, numItems);

    while (1) {
        placeOrder(menu, numItems, budget, &totalSpent);

        if (totalSpent >= budget) {
            printf("You have spent $%d out of $%d.\n", totalSpent, budget);
            break;
        }
    }

    return 0;
}