//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    char description[100];
    float price;
    int quantity;
} Item;

void addItem(Item items[], int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item description: ");
    scanf("%s", items[numItems].description);
    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
    numItems++;
}

void displayItems(Item items[], int numItems) {
    printf("\nItem List:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f (%d in stock)\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }
}

void searchItem(Item items[], int numItems) {
    char searchName[50];
    printf("\nEnter item name to search: ");
    scanf("%s", searchName);
    int index = -1;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, searchName) == 0) {
            index = i;
            break;
        }
    }
    if (index!= -1) {
        printf("\nItem found:\n");
        printf("%s - $%.2f (%d in stock)\n", items[index].name, items[index].price, items[index].quantity);
    } else {
        printf("\nItem not found.\n");
    }
}

void updateItemQuantity(Item items[], int numItems) {
    int index;
    printf("\nEnter item index to update quantity: ");
    scanf("%d", &index);
    if (index >= 0 && index < numItems) {
        printf("\nEnter new item quantity: ");
        scanf("%d", &items[index].quantity);
    } else {
        printf("\nInvalid item index.\n");
    }
}

void main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (numItems < MAX_ITEMS) {
        printf("\nEnter 1 to add item, 2 to display items, 3 to search item, 4 to update item quantity, or 0 to exit: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem(items, numItems);
                numItems++;
                break;
            case 2:
                displayItems(items, numItems);
                break;
            case 3:
                searchItem(items, numItems);
                break;
            case 4:
                updateItemQuantity(items, numItems);
                break;
            case 0:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }
}