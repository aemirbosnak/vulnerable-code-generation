//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a futuristic inventory system structure
typedef struct InventorySystem {
    char item_name[20];
    int item_quantity;
    float item_price;
    struct InventorySystem* next_item;
} InventorySystem;

// Function to insert an item into the inventory system
void insert_item(InventorySystem** head) {
    // Allocate memory for a new item
    InventorySystem* new_item = (InventorySystem*)malloc(sizeof(InventorySystem));

    // Get item name, quantity, and price
    printf("Enter item name: ");
    scanf("%s", new_item->item_name);

    printf("Enter item quantity: ");
    scanf("%d", &new_item->item_quantity);

    printf("Enter item price: ");
    scanf("%f", &new_item->item_price);

    // Insert the new item into the head of the inventory system
    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next_item = new_item;
    }
}

// Function to display all items in the inventory system
void display_items(InventorySystem* head) {
    // Traverse the inventory system and print each item
    while (head) {
        printf("%s - %d - $%.2f\n", head->item_name, head->item_quantity, head->item_price);
        head = head->next_item;
    }
}

int main() {
    // Create an inventory system
    InventorySystem* head = NULL;

    // Insert items into the inventory system
    insert_item(&head);
    insert_item(&head);
    insert_item(&head);

    // Display all items in the inventory system
    display_items(head);

    return 0;
}