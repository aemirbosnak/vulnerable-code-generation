//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LEN 50

typedef struct {
    char name[ITEM_NAME_LEN];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void displayWelcomeMessage() {
    printf("Welcome to the Cheerful Warehouse Management System!\n");
    printf("Here, managing your warehouse is a joyful experience!\n");
    printf("Let's get started! 😊\n\n");
}

void addItem(Warehouse *warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Oops! The warehouse is full! Can't add more items! 🎉\n");
        return;
    }
    
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    warehouse->items[warehouse->itemCount] = newItem;
    warehouse->itemCount++;
    
    printf("Yay! Added item '%s' with quantity %d to the warehouse! 🎊\n", newItem.name, newItem.quantity);
}

void listItems(const Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("The warehouse is empty! 😢 Let's add some items!\n");
        return;
    }

    printf("Here are the items in the warehouse: 📦\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%d. %s - Quantity: %d\n", i + 1, warehouse->items[i].name, warehouse->items[i].quantity);
    }
    printf("Keep up the great work managing your warehouse! 🌟\n");
}

void removeItem(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items to remove! The warehouse is still empty! 🌈\n");
        return;
    }

    listItems(warehouse);
    int index;
    printf("Enter the item number you want to remove: ");
    scanf("%d", &index);
    
    if (index < 1 || index > warehouse->itemCount) {
        printf("That item number doesn't exist! Please check and try again! ✨\n");
        return;
    }

    for (int i = index - 1; i < warehouse->itemCount - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->itemCount--;
    
    printf("Hooray! Removed the selected item! Now, let's keep managing the warehouse! 💪\n");
}

void displayMenu() {
    printf("What would you like to do? Choose an option:\n");
    printf("1. Add Item\n");
    printf("2. List Items\n");
    printf("3. Remove Item\n");
    printf("4. Exit\n");
}

int main() {
    Warehouse warehouse = { .itemCount = 0 };
    int choice;

    displayWelcomeMessage();

    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                listItems(&warehouse);
                break;
            case 3:
                removeItem(&warehouse);
                break;
            case 4:
                printf("Thank you for using the Cheerful Warehouse Management System! Goodbye! 🎉\n");
                break;
            default:
                printf("Oops! That's an invalid choice. Please try again! 😬\n");
                break;
        }

        printf("\n"); // Just for spacing
    } while (choice != 4);
    
    return 0;
}