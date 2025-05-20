//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 20

struct Item {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    double price;
};

void addItem(struct Item items[], int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item category: ");
    scanf("%s", items[numItems].category);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
    printf("Enter item price: ");
    scanf("%lf", &items[numItems].price);
    numItems++;
}

void searchItem(struct Item items[], int numItems, char searchName[]) {
    int i;
    for (i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, searchName) == 0) {
            printf("Item found:\n");
            printf("Name: %s\n", items[i].name);
            printf("Category: %s\n", items[i].category);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Price: $%.2lf\n", items[i].price);
            return;
        }
    }
    printf("Item not found.\n");
}

void displayItems(struct Item items[], int numItems) {
    int i;
    for (i = 0; i < numItems; i++) {
        printf("Name: %s\n", items[i].name);
        printf("Category: %s\n", items[i].category);
        printf("Quantity: %d\n", items[i].quantity);
        printf("Price: $%.2lf\n", items[i].price);
        printf("\n");
    }
}

int main() {
    struct Item items[MAX_ITEMS];
    int numItems = 0;

    addItem(items, numItems);
    addItem(items, numItems);
    addItem(items, numItems);

    printf("Enter item name to search for: ");
    char searchName[MAX_NAME_LENGTH];
    scanf("%s", searchName);

    searchItem(items, numItems, searchName);

    displayItems(items, numItems);

    return 0;
}