//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ITEM_NAME_LENGTH 255
#define MAX_ITEM_DESCRIPTION_LENGTH 1024

typedef struct Item {
    char name[MAX_ITEM_NAME_LENGTH];
    char description[MAX_ITEM_DESCRIPTION_LENGTH];
    int quantity;
    double price;
    struct Item* next;
} Item;

Item* addItem(Item* head) {
    Item* newNode = (Item*)malloc(sizeof(Item));

    printf("Enter item name: ");
    scanf("%s", newNode->name);

    printf("Enter item description: ");
    scanf("%s", newNode->description);

    printf("Enter item quantity: ");
    scanf("%d", &newNode->quantity);

    printf("Enter item price: ");
    scanf("%lf", &newNode->price);

    newNode->next = head;
    head = newNode;

    return head;
}

void displayItems(Item* head) {
    Item* currentItem = head;

    printf("Items:\n");
    while (currentItem) {
        printf("Name: %s\n", currentItem->name);
        printf("Description: %s\n", currentItem->description);
        printf("Quantity: %d\n", currentItem->quantity);
        printf("Price: %.2lf\n", currentItem->price);
        printf("\n");
        currentItem = currentItem->next;
    }
}

int main() {
    Item* head = NULL;

    while (1) {
        printf("Enter 'add' to add an item, 'display' to display items, or 'exit' to exit: ");
        char input[20];
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            head = addItem(head);
        } else if (strcmp(input, "display") == 0) {
            displayItems(head);
        } else if (strcmp(input, "exit") == 0) {
            exit(0);
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}