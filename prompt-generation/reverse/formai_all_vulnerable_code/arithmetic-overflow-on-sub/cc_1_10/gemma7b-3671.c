//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

void createItem(Item** head) {
    *head = malloc(sizeof(Item));
    (*head)->name[0] = '\0';
    (*head)->quantity = 0;
    (*head)->next = NULL;
}

void addItem(Item** head, char name, int quantity) {
    Item* newNode = malloc(sizeof(Item));
    newNode->name[0] = '\0';
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Item* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int getItemQuantity(Item* item) {
    return item->quantity;
}

void useItem(Item* item, int quantity) {
    item->quantity -= quantity;
    if (item->quantity < 0) {
        item->quantity = 0;
    }
}

int main() {
    Item* inventory = NULL;
    createItem(&inventory);

    addItem(inventory, "Sword", 3);
    addItem(inventory, "Shield", 2);
    addItem(inventory, "Potion", 5);

    printf("Your inventory:");
    for (Item* item = inventory; item; item = item->next) {
        printf(" - %s (%d)", item->name, getItemQuantity(item));
    }

    useItem(inventory->next, 1);
    useItem(inventory->next->next, 2);

    printf("Your inventory after use:");
    for (Item* item = inventory; item; item = item->next) {
        printf(" - %s (%d)", item->name, getItemQuantity(item));
    }

    return 0;
}