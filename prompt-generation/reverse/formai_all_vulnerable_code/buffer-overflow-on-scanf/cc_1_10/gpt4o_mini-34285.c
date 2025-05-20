//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} CafeMenu;

// Function Declarations
void initMenu(CafeMenu* menu);
void displayMenu(CafeMenu* menu);
void addItemToMenu(CafeMenu* menu);
void orderItems(CafeMenu* menu);
void generateBill(CafeMenu* menu, int* orderQuantities);
void adminMenu(CafeMenu* menu);

int main() {
    CafeMenu menu;
    initMenu(&menu);
    adminMenu(&menu);
    return 0;
}

// Initialize Menu
void initMenu(CafeMenu* menu) {
    menu->count = 0;
}

// Display Menu
void displayMenu(CafeMenu* menu) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < menu->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu->items[i].name, menu->items[i].price);
    }
}

// Add Item to Menu
void addItemToMenu(CafeMenu* menu) {
    if (menu->count >= MAX_ITEMS) {
        printf("Menu is full! Cannot add more items.\n");
        return;
    }
    Item newItem;
    printf("Enter item name: ");
    getchar(); // Clear newline from buffer
    fgets(newItem.name, MAX_NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove newline character
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    printf("Enter quantity available: ");
    scanf("%d", &newItem.quantity);

    menu->items[menu->count] = newItem;
    menu->count++;
    printf("Item added successfully!\n");
}

// Order Items
void orderItems(CafeMenu* menu) {
    int orderQuantities[MAX_ITEMS] = {0};
    int choice, i;

    printf("How many different items would you like to order? ");
    int numItems;
    scanf("%d", &numItems);

    for (i = 0; i < numItems; i++) {
        displayMenu(menu);
        printf("Select item number (1 to %d): ", menu->count);
        scanf("%d", &choice);
        if (choice < 1 || choice > menu->count) {
            printf("Invalid choice. Please try again.\n");
            i--; // Retry the same item
            continue;
        }
        printf("Enter quantity for %s: ", menu->items[choice - 1].name);
        scanf("%d", &orderQuantities[choice - 1]);
    }

    generateBill(menu, orderQuantities);
}

// Generate Bill
void generateBill(CafeMenu* menu, int* orderQuantities) {
    float totalBill = 0.0;
    printf("\n--- Invoice ---\n");
    for (int i = 0; i < menu->count; i++) {
        if (orderQuantities[i] > 0) {
            float itemTotal = orderQuantities[i] * menu->items[i].price;
            printf("%s (x%d) = $%.2f\n", menu->items[i].name, orderQuantities[i], itemTotal);
            totalBill += itemTotal;
        }
    }
    printf("Total Amount Due: $%.2f\n", totalBill);
}

// Admin Menu
void adminMenu(CafeMenu* menu) {
    int choice;
    do {
        printf("\n--- Admin Menu ---\n");
        printf("1. Display Menu\n");
        printf("2. Add Item to Menu\n");
        printf("3. Order Items\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayMenu(menu);
                break;
            case 2:
                addItemToMenu(menu);
                break;
            case 3:
                orderItems(menu);
                break;
            case 4:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 4);
}