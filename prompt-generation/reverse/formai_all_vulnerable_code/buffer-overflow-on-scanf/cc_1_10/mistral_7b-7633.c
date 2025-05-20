//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
    int quantity;
    struct Item *next;
} Item;

Item *head = NULL;

void addItem(char *name, int id, int quantity) {
    Item *newItem = (Item *)malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->id = id;
    newItem->quantity = quantity;
    newItem->next = head;
    head = newItem;
}

void removeItem(int id) {
    Item *current = head;
    Item *previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void updateQuantity(int id, int newQuantity) {
    Item *current = head;

    while (current != NULL) {
        if (current->id == id) {
            current->quantity = newQuantity;
            break;
        }
        current = current->next;
    }
}

void displayInventory() {
    Item *current = head;

    printf("\nCurrent Inventory:\n");
    while (current != NULL) {
        printf("%s (ID: %d) - Quantity: %d\n", current->name, current->id, current->quantity);
        current = current->next;
    }
}

int main() {
    int choice, id, newQuantity;
    char name[50];

    while (1) {
        printf("\n1. Add Item\n2. Remove Item\n3. Update Quantity\n4. Display Inventory\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Item Name: ");
                scanf("%s", name);
                printf("Enter Item ID: ");
                scanf("%d", &id);
                printf("Enter Quantity: ");
                scanf("%d", &newQuantity);
                addItem(name, id, newQuantity);
                break;
            case 2:
                printf("Enter Item ID to Remove: ");
                scanf("%d", &id);
                removeItem(id);
                break;
            case 3:
                printf("Enter Item ID to Update Quantity: ");
                scanf("%d", &id);
                printf("Enter New Quantity: ");
                scanf("%d", &newQuantity);
                updateQuantity(id, newQuantity);
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}