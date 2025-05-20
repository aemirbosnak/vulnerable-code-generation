//FormAI DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100

//define structure for item
struct Item {
    char name[50];
    int quantity;
    float price;
};

//initialize global inventory array
struct Item inventory[MAX_ITEMS];
int numItems = 0;

//function to add item to inventory
void addItem() {
    if(numItems == MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

   struct Item newItem;

   printf("Enter item name: ");
   scanf("%s", newItem.name);

   printf("Enter item quantity: ");
   scanf("%d", &newItem.quantity);

   printf("Enter item price: ");
   scanf("%f", &newItem.price);

   inventory[numItems++] = newItem;

   printf("%s added to inventory.\n", newItem.name);
}

//function to remove item from inventory
void removeItem() {
    char itemName[50];
    printf("Enter item name: ");
    scanf("%s", itemName);

    for(int i=0; i<numItems; i++) {
        if(strcmp(inventory[i].name, itemName) == 0) {
            printf("%s removed from inventory.\n", inventory[i].name);

            //shift subsequent items up
            for(int j=i; j<numItems-1; j++) {
                inventory[j] = inventory[j+1];
            }
            numItems--;
            return;
        }
    }

    printf("%s not found in inventory.\n", itemName);
}

//function to display inventory
void displayInventory() {
    if(numItems == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Inventory:\n");

    for(int i=0; i<numItems; i++) {
        printf("%s - Quantity: %d, Price: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

//main function to run program
int main() {
    int choice;

    printf("\n---- Welcome to Product Inventory System ----\n\n");

    while(1) {
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("\n---- Goodbye! ----\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}