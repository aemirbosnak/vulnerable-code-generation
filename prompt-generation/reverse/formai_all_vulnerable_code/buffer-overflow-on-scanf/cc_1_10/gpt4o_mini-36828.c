//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define ITEM_NAME_LENGTH 30

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float value; // Value in barter points
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} ResourceTracker;

void addItem(ResourceTracker *tracker) {
    if (tracker->itemCount >= MAX_ITEMS) {
        printf("Error: Item limit reached. Can't add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item value (barter points): ");
    scanf("%f", &newItem.value);

    tracker->items[tracker->itemCount] = newItem;
    tracker->itemCount++;
    printf("Item '%s' added successfully!\n", newItem.name);
}

void displayResources(ResourceTracker *tracker) {
    printf("\nCurrent Resources:\n");
    for (int i = 0; i < tracker->itemCount; i++) {
        printf("%d. %s - Quantity: %d, Value: %.2f points\n", 
                i + 1, tracker->items[i].name, tracker->items[i].quantity, tracker->items[i].value);
    }
}

float calculateTotalValue(ResourceTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->itemCount; i++) {
        total += tracker->items[i].quantity * tracker->items[i].value;
    }
    return total;
}

void makeTrade(ResourceTracker *tracker) {
    char itemName[ITEM_NAME_LENGTH];
    int tradeQuantity;
    
    printf("Enter the name of the item to trade: ");
    scanf("%s", itemName);
    
    for (int i = 0; i < tracker->itemCount; i++) {
        if (strcmp(tracker->items[i].name, itemName) == 0) {
            printf("You have %d of '%s'. Enter quantity to trade: ", 
                    tracker->items[i].quantity, tracker->items[i].name);
            scanf("%d", &tradeQuantity);

            if (tradeQuantity > tracker->items[i].quantity) {
                printf("Error: You don't have enough of '%s' to trade.\n", itemName);
                return;
            }

            tracker->items[i].quantity -= tradeQuantity;
            printf("Traded %d of '%s'.\n", tradeQuantity, itemName);
            return;
        }
    }

    printf("Error: Item '%s' not found in resources.\n", itemName);
}

void displayMenu() {
    printf("\nPost-Apocalyptic Personal Finance Planner\n");
    printf("1. Add Resource\n");
    printf("2. Display Resources\n");
    printf("3. Calculate Total Value\n");
    printf("4. Make a Trade\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    ResourceTracker tracker;
    tracker.itemCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&tracker);
                break;
            case 2:
                displayResources(&tracker);
                break;
            case 3: {
                float totalValue = calculateTotalValue(&tracker);
                printf("Total Resource Value: %.2f points\n", totalValue);
                break;
            }
            case 4:
                makeTrade(&tracker);
                break;
            case 5:
                printf("Leaving Post-Apocalyptic Finance Planner. Stay safe!\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}