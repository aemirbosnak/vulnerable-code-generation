//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Item;

void addItem(Item items[], int numItems) {
    printf("Enter the name of the item (up to %d characters): ", MAX_NAME_LENGTH);
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter the description of the item (up to %d characters): ", MAX_DESCRIPTION_LENGTH);
    char description[MAX_DESCRIPTION_LENGTH];
    fgets(description, MAX_DESCRIPTION_LENGTH, stdin);
    description[strcspn(description, "\n")] = '\0';

    printf("Enter the quantity of the item: ");
    scanf("%d", &items[numItems].quantity);

    printf("Enter the price of the item: ");
    scanf("%lf", &items[numItems].price);
}

void displayItems(Item items[], int numItems) {
    printf("Item\tDescription\tQuantity\tPrice\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%s\t%d\t$%.2f\n", items[i].name, items[i].description, items[i].quantity, items[i].price);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (numItems < MAX_ITEMS) {
        printf("Enter 1 to add an item, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addItem(items, numItems);
            numItems++;
        } else if (choice!= 0) {
            printf("Invalid input, please try again.\n");
        }
    }

    printf("Product Inventory:\n");
    displayItems(items, numItems);

    return 0;
}