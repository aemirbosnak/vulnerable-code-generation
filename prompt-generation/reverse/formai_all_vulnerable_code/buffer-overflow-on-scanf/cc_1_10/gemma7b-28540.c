//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store warehouse item information
typedef struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;

// Function to insert an item into the warehouse
void insertItem(Item** head) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    printf("Enter item name: ");
    scanf("%s", newNode->name);
    printf("Enter item quantity: ");
    scanf("%d", &newNode->quantity);
    printf("Enter item price: ");
    scanf("%f", &newNode->price);

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
    newNode->next = NULL;
}

// Function to search for an item in the warehouse
void searchItem(Item* head) {
    char itemName[50];
    printf("Enter item name: ");
    scanf("%s", itemName);

    Item* currentItem = head;
    while (currentItem) {
        if (strcmp(currentItem->name, itemName) == 0) {
            printf("Item name: %s\n", currentItem->name);
            printf("Item quantity: %d\n", currentItem->quantity);
            printf("Item price: %.2f\n", currentItem->price);
            break;
        }
        currentItem = currentItem->next;
    }

    if (currentItem == NULL) {
        printf("Item not found.\n");
    }
}

// Function to update item quantity in the warehouse
void updateItemQuantity(Item* head) {
    char itemName[50];
    int newQuantity;

    printf("Enter item name: ");
    scanf("%s", itemName);

    Item* currentItem = head;
    while (currentItem) {
        if (strcmp(currentItem->name, itemName) == 0) {
            printf("Enter new item quantity: ");
            scanf("%d", &newQuantity);
            currentItem->quantity = newQuantity;
            break;
        }
        currentItem = currentItem->next;
    }

    if (currentItem == NULL) {
        printf("Item not found.\n");
    }
}

// Function to delete an item from the warehouse
void deleteItem(Item* head) {
    char itemName[50];

    printf("Enter item name: ");
    scanf("%s", itemName);

    Item* currentItem = head;
    Item* previousItem = NULL;

    while (currentItem) {
        if (strcmp(currentItem->name, itemName) == 0) {
            if (previousItem) {
                previousItem->next = currentItem->next;
            } else {
                head = currentItem->next;
            }
            free(currentItem);
            break;
        }
        previousItem = currentItem;
        currentItem = currentItem->next;
    }

    if (currentItem == NULL) {
        printf("Item not found.\n");
    }
}

// Main function
int main() {
    Item* head = NULL;

    while (1) {
        printf("Enter 1 to insert an item, 2 to search for an item, 3 to update item quantity, or 4 to delete an item: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertItem(&head);
                break;
            case 2:
                searchItem(head);
                break;
            case 3:
                updateItemQuantity(head);
                break;
            case 4:
                deleteItem(head);
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf("%c", &answer);

        if (answer == 'N') {
            break;
        }
    }

    return 0;
}