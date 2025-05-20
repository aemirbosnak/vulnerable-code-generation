//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char name[30];
    float price;
    struct Item* next;
} Item;

typedef struct GroceryList {
    Item* head;
    int itemCount;
} GroceryList;

GroceryList* createGroceryList() {
    GroceryList* list = (GroceryList*)malloc(sizeof(GroceryList));
    list->head = NULL;
    list->itemCount = 0;
    return list;
}

void addItem(GroceryList* list, const char* name, float price) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    strncpy(newItem->name, name, sizeof(newItem->name) - 1);
    newItem->name[sizeof(newItem->name) - 1] = '\0'; // Ensure null-termination
    newItem->price = price;
    newItem->next = list->head;
    list->head = newItem;
    list->itemCount++;
}

void displayList(GroceryList* list) {
    printf("Grocery List:\n");
    Item* current = list->head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (current != NULL) {
        printf("Item: %s, Price: $%.2f\n", current->name, current->price);
        current = current->next;
    }
    printf("Total Items: %d\n", list->itemCount);
}

void freeList(GroceryList* list) {
    Item* current = list->head;
    Item* nextItem;
    while (current != NULL) {
        nextItem = current->next;
        free(current);
        current = nextItem;
    }
    free(list);
}

float calculateTotalPrice(GroceryList* list) {
    float total = 0.0;
    Item* current = list->head;
    while (current != NULL) {
        total += current->price;
        current = current->next;
    }
    return total;
}

int main() {
    GroceryList* myGroceryList = createGroceryList();
    int choice;
    char itemName[30];
    float itemPrice;

    do {
        printf("\n1. Add Item\n2. Display List\n3. Calculate Total Price\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", itemName);
                printf("Enter item price: ");
                scanf("%f", &itemPrice);
                addItem(myGroceryList, itemName, itemPrice);
                break;
            case 2:
                displayList(myGroceryList);
                break;
            case 3:
                printf("Total Price: $%.2f\n", calculateTotalPrice(myGroceryList));
                break;
            case 4:
                printf("Exiting...\n");
                // Free memory
                freeList(myGroceryList);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}