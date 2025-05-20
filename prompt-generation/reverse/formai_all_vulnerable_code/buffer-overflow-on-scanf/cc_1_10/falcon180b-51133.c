//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Item;

void addItem(Item* inventory, int numItems) {
    printf("Enter the name of the item: ");
    scanf("%s", inventory[numItems].name);
    printf("Enter the description of the item: ");
    scanf("%s", inventory[numItems].description);
    printf("Enter the quantity of the item: ");
    scanf("%d", &inventory[numItems].quantity);
    printf("Enter the price of the item: ");
    scanf("%lf", &inventory[numItems].price);
}

void displayItem(Item item) {
    printf("Name: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Quantity: %d\n", item.quantity);
    printf("Price: $%.2f\n\n", item.price);
}

void searchItem(Item* inventory, int numItems, char* searchTerm) {
    int i;
    for (i = 0; i < numItems; i++) {
        if (strstr(inventory[i].name, searchTerm)!= NULL || strstr(inventory[i].description, searchTerm)!= NULL) {
            displayItem(inventory[i]);
        }
    }
}

int main() {
    Item inventory[MAX_ITEMS];
    int numItems = 0;

    printf("Welcome to the product inventory system!\n\n");

    while (numItems < MAX_ITEMS) {
        printf("Enter 1 to add an item or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addItem(inventory, numItems);
            numItems++;
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\nProduct Inventory:\n");

    while (1) {
        printf("Enter 1 to search for an item or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            char searchTerm[MAX_NAME_LENGTH];
            printf("Enter the search term: ");
            scanf("%s", searchTerm);
            searchItem(inventory, numItems, searchTerm);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}