//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    double price;
} Item;

void addItem(Item* inventory, int numItems) {
    printf("Enter item name: ");
    scanf("%s", inventory[numItems].name);
    printf("Enter item description: ");
    scanf("%s", inventory[numItems].description);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[numItems].quantity);
    printf("Enter item price: ");
    scanf("%lf", &inventory[numItems].price);
    numItems++;
}

void displayInventory(Item* inventory, int numItems) {
    printf("\nInventory:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - %s\n", i+1, inventory[i].name, inventory[i].description);
        printf("Quantity: %d, Price: $%.2lf\n\n", inventory[i].quantity, inventory[i].price);
    }
}

void searchItem(Item* inventory, int numItems) {
    printf("\nEnter item name to search: ");
    char searchName[MAX_NAME_LEN];
    scanf("%s", searchName);
    for (int i = 0; i < numItems; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("\nItem found:\n");
            printf("%s - %s\n", inventory[i].name, inventory[i].description);
            printf("Quantity: %d, Price: $%.2lf\n\n", inventory[i].quantity, inventory[i].price);
        }
    }
}

int main() {
    Item inventory[MAX_ITEMS];
    int numItems = 0;

    addItem(inventory, numItems);

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add item\n");
        printf("2. Display inventory\n");
        printf("3. Search item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem(inventory, numItems);
                break;
            case 2:
                displayInventory(inventory, numItems);
                break;
            case 3:
                searchItem(inventory, numItems);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}