//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure to hold item details
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Item;

// Function prototypes
void initializeItems(Item items[], int *itemCount);
void displayMenu(Item items[], int itemCount);
void takeOrder(Item items[], int itemCount);
void calculateBill(Item items[], int itemCount, int *orderedIds, int *orderedQuantities, int orderCount);
void printReceipt(Item items[], int *orderedIds, int *orderedQuantities, int orderCount, float total);

int main() {
    Item items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    initializeItems(items, &itemCount);

    do {
        printf("\n=== Cafe Billing System ===\n");
        printf("1. Display Menu\n");
        printf("2. Take Order\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(items, itemCount);
                break;
            case 2:
                takeOrder(items, itemCount);
                break;
            case 3:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void initializeItems(Item items[], int *itemCount) {
    // Sample items
    items[0] = (Item){1, "Coffee", 2.50, 0};
    items[1] = (Item){2, "Tea", 1.75, 0};
    items[2] = (Item){3, "Sandwich", 3.50, 0};
    items[3] = (Item){4, "Cake", 4.00, 0};
    items[4] = (Item){5, "Juice", 2.00, 0};
    *itemCount = 5; // Total number of items
}

void displayMenu(Item items[], int itemCount) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", items[i].id, items[i].name, items[i].price);
    }
}

void takeOrder(Item items[], int itemCount) {
    int orderedIds[MAX_ITEMS] = {0};
    int orderedQuantities[MAX_ITEMS] = {0};
    int orderCount = 0;
    int id, quantity;

    printf("\n--- Place Your Order ---\n");
    while (1) {
        printf("Enter item ID to order (0 to finish): ");
        scanf("%d", &id);
        if (id == 0) {
            break;
        }

        // Validate item ID
        if (id < 1 || id > itemCount) {
            printf("Invalid item ID. Please try again.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);
        if (quantity < 1) {
            printf("Invalid quantity. Please try again.\n");
            continue;
        }

        orderedIds[orderCount] = id;
        orderedQuantities[orderCount] = quantity;
        orderCount++;
        printf("Added %d of %s to your order.\n", quantity, items[id - 1].name);
    }

    // Calculate the bill and print receipt
    calculateBill(items, itemCount, orderedIds, orderedQuantities, orderCount);
}

void calculateBill(Item items[], int itemCount, int *orderedIds, int *orderedQuantities, int orderCount) {
    float total = 0.0;

    for (int i = 0; i < orderCount; i++) {
        int id = orderedIds[i];
        int quantity = orderedQuantities[i];

        if (id > 0 && id <= itemCount) {
            total += items[id - 1].price * quantity;
        }
    }

    printf("\nTotal Amount: $%.2f\n", total);
    printReceipt(items, orderedIds, orderedQuantities, orderCount, total);
}

void printReceipt(Item items[], int *orderedIds, int *orderedQuantities, int orderCount, float total) {
    printf("\n--- Receipt ---\n");
    for (int i = 0; i < orderCount; i++) {
        int id = orderedIds[i];
        int quantity = orderedQuantities[i];
        printf("%d x %s - $%.2f\n", quantity, items[id - 1].name, items[id - 1].price * quantity);
    }
    printf("Total Amount: $%.2f\n", total);
    printf("-------------------\n");
}