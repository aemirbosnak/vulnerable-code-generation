//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 5

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

Item* createItem(char* name, int quantity) {
    Item* item = (Item*)malloc(sizeof(Item));
    strcpy(item->name, name);
    item->quantity = quantity;
    item->next = NULL;
    return item;
}

void addItem(Item* head, char* name, int quantity) {
    Item* item = createItem(name, quantity);
    if (head == NULL) {
        head = item;
    } else {
        item->next = head;
        head = item;
    }
}

void showItems(Item* head) {
    Item* item = head;
    printf("Items:\n");
    while (item) {
        printf("%s: %d\n", item->name, item->quantity);
        item = item->next;
    }
}

int main() {
    Item* inventory = NULL;

    // Start the adventure
    printf("You wake up in a mysterious forest clearing. The sun shines upon your face, and the wind whispers secrets in your ear. You have no memory of how you ended up here.\n");

    // Inventory management
    printf("You find a worn leather pouch in your pocket and open it. Inside, you discover a few items:");
    showItems(inventory);

    // Interactive choices
    printf("What do you want to do? (a) Search the clearing, (b) Travel north, (c) Examine the pouch:\n");
    char choice;
    scanf("%c", &choice);

    // Based on your choice, the story unfolds...

    // For example, if you choose (a):
    if (choice == 'a') {
        printf("You search the clearing and find a hidden treasure. You have added a silver coin to your inventory.\n");
        addItem(inventory, "Silver Coin", 1);
        showItems(inventory);
    }

    // Repeat the above steps until the player chooses to leave the forest or something else happens...

    return 0;
}