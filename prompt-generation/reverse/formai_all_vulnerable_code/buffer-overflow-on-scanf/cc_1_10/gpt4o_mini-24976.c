//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    int itemID;
    char itemName[30];
    float itemPrice;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int itemCount = 0;

void addMenuItem(int id, const char* name, float price) {
    menu[itemCount].itemID = id;
    snprintf(menu[itemCount].itemName, sizeof(menu[itemCount].itemName), "%s", name);
    menu[itemCount].itemPrice = price;
    itemCount++;
}

void displayMenu() {
    printf("\nCafe Menu:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", menu[i].itemID, menu[i].itemName, menu[i].itemPrice);
    }
}

void generateBill(int orderedItems[], int quantities[], int orderCount) {
    float total = 0.0;
    printf("\n--- Bill ---\n");
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < orderCount; i++) {
        int itemIndex = orderedItems[i] - 1; // Get the index
        float cost = quantities[i] * menu[itemIndex].itemPrice;
        total += cost;
        printf("%s\t\t%d\t\t$%.2f\n", menu[itemIndex].itemName, quantities[i], cost);
    }
    printf("-------------------------------------\n");
    printf("Total Amount: $%.2f\n", total);
}

int main() {
    int orderedItems[MAX_ITEMS];
    int quantities[MAX_ITEMS];
    int orderCount = 0;
    char choice;

    // Adding menu items
    addMenuItem(1, "Coffee", 2.50);
    addMenuItem(2, "Tea", 1.80);
    addMenuItem(3, "Sandwich", 3.50);
    addMenuItem(4, "Pasta", 4.00);
    addMenuItem(5, "Cake", 2.20);

    do {
        displayMenu();
        printf("\nSelect item by ID (0 to finish selection): ");
        int itemID;
        scanf("%d", &itemID);

        if (itemID == 0) {
            break; // Exit selection
        } else if (itemID > 0 && itemID <= itemCount) {
            printf("Enter quantity for %s: ", menu[itemID - 1].itemName);
            int qty;
            scanf("%d", &qty);
            orderedItems[orderCount] = itemID;
            quantities[orderCount] = qty;
            orderCount++;
        } else {
            printf("Invalid item ID. Please try again.\n");
        }

        printf("Do you want to order more items? (y/n): ");
        getchar(); // Clear newline character
        choice = getchar();
    } while (choice == 'y' || choice == 'Y');

    if (orderCount > 0) {
        generateBill(orderedItems, quantities, orderCount);
    } else {
        printf("No items ordered.\n");
    }

    return 0;
}