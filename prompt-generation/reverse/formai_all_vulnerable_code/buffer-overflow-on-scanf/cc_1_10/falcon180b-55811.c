//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_SIZE 50
#define MAX_QUANTITY_SIZE 10

typedef struct {
    char name[MAX_NAME_SIZE];
    int quantity;
    float price;
} Item;

void addItem(Item* inventory, int count) {
    char name[MAX_NAME_SIZE];
    float price;
    int quantity;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item price: ");
    scanf("%f", &price);

    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < count; i++) {
        strcpy(inventory[i].name, name);
        inventory[i].quantity = quantity;
        inventory[i].price = price;
    }

    printf("\nItem added successfully!\n");
}

void displayItems(Item* inventory, int count) {
    printf("\nItem List:\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateItemQuantity(Item* inventory, int count) {
    char name[MAX_NAME_SIZE];

    printf("\nEnter item name to update quantity: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\nEnter new item quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("\nItem quantity updated successfully!\n");
            return;
        }
    }

    printf("\nItem not found.\n");
}

void deleteItem(Item* inventory, int* count) {
    char name[MAX_NAME_SIZE];

    printf("\nEnter item name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                strcpy(inventory[j].name, inventory[j + 1].name);
                inventory[j].quantity = inventory[j + 1].quantity;
                inventory[j].price = inventory[j + 1].price;
            }

            (*count)--;

            printf("\nItem deleted successfully!\n");
            return;
        }
    }

    printf("\nItem not found.\n");
}

int main() {
    Item inventory[MAX_ITEMS];
    int count = 0;

    while (count < MAX_ITEMS) {
        printf("\nSelect an option:\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Update item quantity\n");
        printf("4. Delete item\n");
        printf("0. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, count);
                break;
            case 2:
                displayItems(inventory, count);
                break;
            case 3:
                updateItemQuantity(inventory, count);
                break;
            case 4:
                deleteItem(inventory, &count);
                break;
            case 0:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}