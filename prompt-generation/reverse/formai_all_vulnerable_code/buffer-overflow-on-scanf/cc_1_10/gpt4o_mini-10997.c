//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure of an enchanted item
struct Item {
    char name[50];
    int quantity;
    float price;
};

// Function to display the enchanted inventory
void displayInventory(struct Item items[], int count) {
    printf("\n✨ Enchanted Inventory ✨\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Item %d: %s\n", i + 1, items[i].name);
        printf("Quantity: %d\n", items[i].quantity);
        printf("Price: $%.2f\n", items[i].price);
        printf("---------------------------------------------------\n");
    }
}

// Function to add a new enchanted item
void addItem(struct Item items[], int *count) {
    printf("🌹 Adding a new item to the enchanted realm 🌹\n");
    printf("Enter the name of the enchanted item: ");
    scanf("%s", items[*count].name);
    printf("Enter the quantity: ");
    scanf("%d", &items[*count].quantity);
    printf("Enter the price: ");
    scanf("%f", &items[*count].price);
    (*count)++;
    printf("🎉 The item has been added to your collection! 🎉\n");
}

// Function to update the quantity of an enchanted item
void updateItem(struct Item items[], int count) {
    char itemName[50];
    printf("❣️ Which enchanted item do you wish to update? ");
    scanf("%s", itemName);
    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &items[i].quantity);
            printf("💖 The quantity of %s has been updated! 💖\n", items[i].name);
            return;
        }
    }
    printf("😢 The enchanted item was not found in your inventory! 😢\n");
}

// Function to remove an enchanted item from the inventory
void removeItem(struct Item items[], int *count) {
    char itemName[50];
    printf("💔 Which enchanted item do you wish to remove? ");
    scanf("%s", itemName);
    for (int i = 0; i < *count; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            for (int j = i; j < *count - 1; j++) {
                items[j] = items[j + 1];
            }
            (*count)--;
            printf("🕊️ The item %s has been gently released from your heart! 🕊️\n", itemName);
            return;
        }
    }
    printf("😢 The enchanted item was not found in your collection! 😢\n");
}

// Main function where the magic begins
int main() {
    struct Item items[100];
    int count = 0;
    int choice;

    do {
        printf("\n🍷 Welcome to the Enchanted Inventory System 🍷\n");
        printf("1. Display enchanted items\n");
        printf("2. Add a new item\n");
        printf("3. Update an existing item\n");
        printf("4. Remove an item\n");
        printf("5. Exit\n");
        printf("Choose your destiny (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayInventory(items, count);
                break;
            case 2:
                addItem(items, &count);
                break;
            case 3:
                updateItem(items, count);
                break;
            case 4:
                removeItem(items, &count);
                break;
            case 5:
                printf("💞 Thank you for visiting the enchanted realm! Until we meet again! 💞\n");
                break;
            default:
                printf("😳 An unknown enchantment! Please choose a valid option. 😳\n");
        }
    } while (choice != 5);

    return 0;
}