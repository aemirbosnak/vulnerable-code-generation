//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Item;

void addItem(Item items[], int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);

    printf("Enter item description: ");
    scanf("%s", items[numItems].description);

    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);

    printf("Enter item price: ");
    scanf("%lf", &items[numItems].price);

    numItems++;
}

void displayItems(Item items[], int numItems) {
    printf("\nItem List:\n");
    printf("---------------------------------------------------\n");
    printf("| Name     | Description | Quantity | Price   |\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < numItems; i++) {
        printf("| %s      | %s          | %d       | $%.2lf |\n", items[i].name, items[i].description, items[i].quantity, items[i].price);
    }

    printf("---------------------------------------------------\n");
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (numItems < MAX_ITEMS) {
        printf("\nDo you want to add an item? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y') {
            addItem(items, numItems);
        } else {
            displayItems(items, numItems);
            break;
        }
    }

    return 0;
}