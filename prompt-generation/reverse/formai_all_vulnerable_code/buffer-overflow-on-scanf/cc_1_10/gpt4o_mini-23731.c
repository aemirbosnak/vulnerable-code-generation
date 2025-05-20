//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
} Item;

// Declaring the warehouse as an array of items
Item warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Hold your horses, we can't fit more items! Warehouse is full!\n");
        return;
    }
    
    printf("Enter the item name: ");
    scanf("%s", warehouse[itemCount].name);
    
    printf("How many of these do we have? ");
    scanf("%d", &warehouse[itemCount].quantity);
    
    printf("Added %d of %s to the warehouse! 🎉\n", warehouse[itemCount].quantity, warehouse[itemCount].name);
    itemCount++;
}

void listItems() {
    if (itemCount == 0) {
        printf("The warehouse is empty! Did a raccoon break in and steal everything? 🦝\n");
        return;
    }
    
    printf("🏭 Items currently in the warehouse:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - Quantity: %d\n", i + 1, warehouse[i].name, warehouse[i].quantity);
    }
}

void removeItem() {
    if (itemCount == 0) {
        printf("There's nothing to throw out. Let's not waste our time! 🤷\n");
        return;
    }

    listItems();
    
    int index;
    printf("Which item number do you want to remove? (1 to %d): ", itemCount);
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Invalid choice! You can't just throw out anything, my friend! 🚫\n");
        return;
    }

    itemCount--;
    for (int i = index - 1; i < itemCount; i++) {
        warehouse[i] = warehouse[i + 1];
    }
    printf("Farewell, %s! You shall not be missed! 👋\n", warehouse[index - 1].name);
}

void warehouseMenu() {
    int choice;
    while (1) {
        printf("\n** Warehouse Management System **\n");
        printf("1. Add New Item\n");
        printf("2. List Items\n");
        printf("3. Remove Item\n");
        printf("4. Exit (or is it?)\n");
        printf("Choose your doom (1-4): ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                listItems();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                printf("So long, and thanks for all the fish! 🐟\n");
                exit(0);
            default:
                printf("Did you really think that was an option? 🤔\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to the Wacky Warehouse Management System! 🎊\n");
    warehouseMenu();
    return 0;
}