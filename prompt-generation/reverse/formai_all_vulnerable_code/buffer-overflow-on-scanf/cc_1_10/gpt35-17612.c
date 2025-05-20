//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
} Item;

void printMenu() {
    printf("\n-------------------------");
    printf("\n|   WAREHOUSE SYSTEM     |");
    printf("\n-------------------------");
    printf("\n| Options:              |");
    printf("\n|    1. Add Item        |");
    printf("\n|    2. Remove Item     |");
    printf("\n|    3. View Inventory  |");
    printf("\n|    4. Exit            |");
    printf("\n-------------------------");
}

void addItem(Item* items, int* itemCount) {
    printf("\n-------------------------");
    printf("\n| Add Item               |");
    printf("\n-------------------------");

    printf("\nEnter Item Name: ");
    char name[50];
    scanf("%s", name);

    printf("\nEnter Quantity: ");
    int quantity;
    scanf("%d", &quantity);

    Item newItem;
    newItem.id = *itemCount + 1;
    strcpy(newItem.name, name);
    newItem.quantity = quantity;

    items[*itemCount] = newItem;
    *itemCount += 1;

    printf("\nItem Added Successfully!\n");
}

void removeItem(Item* items, int* itemCount) {
    printf("\n-------------------------");
    printf("\n| Remove Item            |");
    printf("\n-------------------------");

    printf("\nEnter Item ID: ");
    int id;
    scanf("%d", &id);

    int indexToRemove = -1;
    for(int i=0; i<*itemCount; i++) {
        if(items[i].id == id) {
            indexToRemove = i;
            break;
        }
    }

    if(indexToRemove == -1) {
        printf("\nItem not found!\n");
        return;
    }

    for(int i=indexToRemove; i<*itemCount-1; i++) {
        items[i] = items[i+1];
    }

    *itemCount -= 1;

    printf("\nItem Removed Successfully!\n");
}

void viewInventory(Item* items, int* itemCount) {
    if(*itemCount == 0) {
        printf("\n-------------------------");
        printf("\n| Inventory is Empty     |");
        printf("\n-------------------------\n");
        return;
    }

    printf("\n-------------------------");
    printf("\n| Inventory              |");
    printf("\n-------------------------");

    printf("\n%-4s %-20s %-10s", "ID", "Name", "Quantity");
    for(int i=0; i<*itemCount; i++) {
        printf("\n%-4d %-20s %-10d", items[i].id, items[i].name, items[i].quantity);
    }
}

int main() {
    Item items[50];
    int itemCount = 0;
    int choice = 0;

    do {
        printMenu();
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem(items, &itemCount);
                break;
            case 2:
                removeItem(items, &itemCount);
                break;
            case 3:
                viewInventory(items, &itemCount);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
        }
    } while(choice != 4);

    return 0;
}