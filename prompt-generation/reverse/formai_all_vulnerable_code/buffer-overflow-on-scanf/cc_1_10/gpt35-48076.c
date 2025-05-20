//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: synchronous
#include <stdio.h>
#include <string.h>

struct Inventory {
    char itemName[50];
    int quantity;
    float costPrice;
    float sellingPrice;
};

struct Warehouse {
    struct Inventory items[100];
    int numItems;
};

void addNewItem(struct Warehouse *w) {
    struct Inventory newItem;
    printf("\nEnter item name: ");
    scanf("%s", newItem.itemName);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter cost price: ");
    scanf("%f", &newItem.costPrice);
    printf("Enter selling price: ");
    scanf("%f", &newItem.sellingPrice);
    
    w->items[w->numItems] = newItem;
    w->numItems++;
    
    printf("\nItem added!\n");
}

void displayInventory(struct Warehouse *w) {
    printf("\n%-20s %-10s %-15s %-15s\n", "Item Name", "Quantity", "Cost Price", "Selling Price");
    for(int i=0; i<w->numItems; i++) {
        printf("%-20s %-10d %-15.2f %-15.2f\n", w->items[i].itemName, w->items[i].quantity, w->items[i].costPrice, w->items[i].sellingPrice);
    }
}

struct Inventory* searchItem(struct Warehouse *w, char itemName[]) {
    for(int i=0; i<w->numItems; i++) {
        if(strcmp(w->items[i].itemName, itemName) == 0) {
            return &w->items[i];
        }
    }
    return NULL;
}

void sellItem(struct Warehouse *w) {
    char itemName[50];
    printf("\nEnter item name to sell: ");
    scanf("%s", itemName);
    struct Inventory *item = searchItem(w, itemName);
    if(item != NULL) {
        int quantity;
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        if(quantity > item->quantity) {
            printf("\nInsufficient stock. Available quantity: %d\n", item->quantity);
        } else {
            float totalPrice = item->sellingPrice * quantity;
            item->quantity -= quantity;
            printf("\nSold %d %s for %.2f total\n", quantity, item->itemName, totalPrice);
        }
    } else {
        printf("\nItem not found.\n");
    }
}

int main() {
    struct Warehouse warehouse = {0};

    while(1) {
        printf("\n\nWarehouse Management System\n\n");
        printf("1. Add new item\n");
        printf("2. Display inventory\n");
        printf("3. Sell item\n");
        printf("4. Exit\n");
        printf("\nEnter option: ");
        int option;
        scanf("%d", &option);

        switch(option) {
            case 1:
                addNewItem(&warehouse);
                break;
            case 2:
                displayInventory(&warehouse);
                break;
            case 3:
                sellItem(&warehouse);
                break;
            case 4:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}