//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char itemName[50];
    int quantity;
    float price;
} Item;

void addItem(Item itemArray[], int *currentIndex) {
    Item newItem;
    printf("Enter the name of the item: ");
    scanf("%s", newItem.itemName);
    printf("Enter the quantity of the item: ");
    scanf("%d", &newItem.quantity);
    printf("Enter the price of the item: ");
    scanf("%f", &newItem.price);
    itemArray[*currentIndex] = newItem;
    (*currentIndex)++;
    printf("Item added successfully.\n");
}

void removeItem(Item itemArray[], int *currentIndex) {
    char nameToRemove[50];
    printf("Enter the name of the item to remove: ");
    scanf("%s", nameToRemove);
    for(int i = 0; i < *currentIndex; i++) {
        if(strcmp(itemArray[i].itemName, nameToRemove) == 0) {
            for(int j = i; j < *currentIndex - 1; j++) {
                itemArray[j] = itemArray[j+1];
            }
            (*currentIndex)--;
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void displayInventory(Item itemArray[], int *currentIndex) {
    printf("Inventory:\n");
    for(int i = 0; i < *currentIndex; i++) {
        printf("%s\t%d\t%.2f\n", itemArray[i].itemName, itemArray[i].quantity, itemArray[i].price);
    }
}

void exitProgram() {
    printf("Program terminated.");
    exit(0);
}

int main() {
    Item itemArray[100];
    int currentIndex = 0;
    printf("Welcome to the fantastical C Product Inventory System!\n");
    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display inventory\n");
        printf("4. Exit program\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addItem(itemArray, &currentIndex);
                break;
            case 2:
                removeItem(itemArray, &currentIndex);
                break;
            case 3:
                displayInventory(itemArray, &currentIndex);
                break;
            case 4:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}