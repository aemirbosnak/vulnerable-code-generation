//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;

Item* insertItem(Item* head) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    printf("Enter item name: ");
    scanf("%s", newNode->name);
    printf("Enter item quantity: ");
    scanf("%d", &newNode->quantity);
    printf("Enter item price: ");
    scanf("%f", &newNode->price);
    newNode->next = head;
    head = newNode;
    return head;
}

void displayItems(Item* head) {
    Item* currentItem = head;
    printf("Items:\n");
    while (currentItem) {
        printf("%s - %d - %.2f\n", currentItem->name, currentItem->quantity, currentItem->price);
        currentItem = currentItem->next;
    }
}

void updateItemQuantity(Item* head, char* name, int newQuantity) {
    Item* currentItem = head;
    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            currentItem->quantity = newQuantity;
            return;
        }
        currentItem = currentItem->next;
    }
    printf("Item not found.\n");
}

void removeItem(Item* head, char* name) {
    Item* currentItem = head;
    Item* previousItem = NULL;
    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            if (previousItem) {
                previousItem->next = currentItem->next;
            } else {
                head = currentItem->next;
            }
            free(currentItem);
            return;
        }
        previousItem = currentItem;
        currentItem = currentItem->next;
    }
    printf("Item not found.\n");
}

int main() {
    Item* head = NULL;
    head = insertItem(head);
    head = insertItem(head);
    displayItems(head);
    updateItemQuantity(head, "Item 1", 10);
    removeItem(head, "Item 2");
    displayItems(head);
    return 0;
}