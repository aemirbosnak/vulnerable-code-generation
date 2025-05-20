//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int itemCount;
} Menu;

typedef struct {
    MenuItem orderedItems[MAX_ITEMS];
    int orderedCount;
} Order;

// Function declarations
void displayMenu(Menu *menu);
void addItemToMenu(Menu *menu);
void placeOrder(Menu *menu, Order *order);
void generateBill(Order *order);

int main() {
    Menu menu = { .itemCount = 0 };
    Order order = { .orderedCount = 0 };
    int choice;

    while (1) {
        printf("\nCafe Billing System\n");
        printf("1. Display Menu\n");
        printf("2. Add Item to Menu\n");
        printf("3. Place Order\n");
        printf("4. Generate Bill\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(&menu);
                break;
            case 2:
                addItemToMenu(&menu);
                break;
            case 3:
                placeOrder(&menu, &order);
                break;
            case 4:
                generateBill(&order);
                break;
            case 5:
                printf("Exiting the Cafe Billing System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void displayMenu(Menu *menu) {
    if (menu->itemCount == 0) {
        printf("Menu is currently empty.\n");
        return;
    }
    
    printf("\nMenu:\n");
    for (int i = 0; i < menu->itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu->items[i].name, menu->items[i].price);
    }
}

void addItemToMenu(Menu *menu) {
    if (menu->itemCount >= MAX_ITEMS) {
        printf("Menu is full, cannot add more items.\n");
        return;
    }
    
    MenuItem newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    menu->items[menu->itemCount] = newItem;
    menu->itemCount++;
    printf("Item %s added to the menu.\n", newItem.name);
}

void placeOrder(Menu *menu, Order *order) {
    int itemNumber;
    printf("Enter the item number to order (0 to finish): ");
    
    while (1) {
        scanf("%d", &itemNumber);
        if (itemNumber == 0) {
            break;  // Finish the order
        }
        if (itemNumber < 1 || itemNumber > menu->itemCount) {
            printf("Invalid item number. Please try again: ");
            continue;
        }
        order->orderedItems[order->orderedCount] = menu->items[itemNumber - 1];
        order->orderedCount++;
        printf("%s added to your order.\n", menu->items[itemNumber - 1].name);
    }
}

void generateBill(Order *order) {
    if (order->orderedCount == 0) {
        printf("No items ordered to generate bill.\n");
        return;
    }
    
    float total = 0;
    printf("\nBill:\n");
    for (int i = 0; i < order->orderedCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, order->orderedItems[i].name, order->orderedItems[i].price);
        total += order->orderedItems[i].price;
    }
    printf("Total: $%.2f\n", total);
}