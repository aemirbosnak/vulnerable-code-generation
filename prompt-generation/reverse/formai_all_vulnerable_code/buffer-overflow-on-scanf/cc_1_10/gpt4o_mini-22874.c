//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void addItem(Warehouse* warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Oh no! The warehouse is full! Can't add more items.\n");
        return;
    }
    Item newItem;
    printf("🎉 Let's add a new item to the warehouse!\n");
    printf("Enter the name of the item: ");
    scanf("%s", newItem.name);
    printf("Enter the quantity: ");
    scanf("%d", &newItem.quantity);

    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("✨ Item \"%s\" with quantity %d added to the warehouse! 🎉\n", newItem.name, newItem.quantity);
}

void viewInventory(const Warehouse* warehouse) {
    if (warehouse->count == 0) {
        printf("The warehouse is empty! 📦😟\n");
        return;
    }

    printf("📦 Here's the current inventory of the warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d. %s: %d\n", i + 1, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void manageStock(Warehouse* warehouse) {
    if (warehouse->count == 0) {
        printf("The warehouse is empty! Nothing to manage! 🥺\n");
        return;
    }

    char itemName[NAME_LENGTH];
    int quantityChange;
    printf("🤔 Which item's stock would you like to manage? ");
    scanf("%s", itemName);

    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, itemName) == 0) {
            printf("🎈 Current quantity of \"%s\" is %d\n", itemName, warehouse->items[i].quantity);
            printf("Enter the quantity to add/subtract (use negative to subtract): ");
            scanf("%d", &quantityChange);
            warehouse->items[i].quantity += quantityChange;

            if (warehouse->items[i].quantity < 0) {
                warehouse->items[i].quantity = 0; // Avoid negative stock
                printf("⚠️ Oops! Stock can't go negative. Setting it to 0!\n");
            }

            printf("🎊 New quantity of \"%s\" is %d\n", itemName, warehouse->items[i].quantity);
            return;
        }
    }
    printf("😢 Item \"%s\" not found in the warehouse!\n", itemName);
}

void displayMenu() {
    printf("\n🌟 Welcome to the Warehouse Management System! 🌟\n");
    printf("1. Add Item\n");
    printf("2. View Inventory\n");
    printf("3. Manage Stock\n");
    printf("4. Exit\n");
    printf("Please select an option: ");
}

int main() {
    Warehouse warehouse = { .count = 0 };
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                viewInventory(&warehouse);
                break;
            case 3:
                manageStock(&warehouse);
                break;
            case 4:
                printf("🚪 Thank you for using the Warehouse Management System! Bye! 🎉\n");
                break;
            default:
                printf("😅 Invalid choice, please try again!\n");
        }
    } while (choice != 4);

    return 0;
}