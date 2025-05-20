//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_QUANTITY 10

typedef struct {
    char name[MAX_NAME];
    int quantity;
} Item;

void addItem(Item items[], int count, char name[], int quantity) {
    if (count >= MAX_ITEMS) {
        printf("Cannot add more items. Inventory is full.\n");
        return;
    }
    strcpy(items[count].name, name);
    items[count].quantity = quantity;
    count++;
}

void removeItem(Item items[], int count, char name[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity = 0;
            printf("Item '%s' removed from inventory.\n", name);
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void displayInventory(Item items[], int count) {
    int i;
    printf("Current inventory:\n");
    for (i = 0; i < count; i++) {
        if (items[i].quantity > 0) {
            printf("%s: %d\n", items[i].name, items[i].quantity);
        }
    }
}

int main() {
    Item inventory[MAX_ITEMS];
    int count = 0;
    char name[MAX_NAME];
    int quantity;

    while (1) {
        printf("Enter item name (or type 'exit' to quit): ");
        scanf("%s", name);
        if (strcmp(name, "exit") == 0) {
            break;
        }
        printf("Enter item quantity: ");
        scanf("%d", &quantity);
        addItem(inventory, count, name, quantity);
        count++;
    }

    while (1) {
        printf("Enter item name to remove (or type 'exit' to quit): ");
        scanf("%s", name);
        if (strcmp(name, "exit") == 0) {
            break;
        }
        removeItem(inventory, count, name);
    }

    printf("Current inventory:\n");
    displayInventory(inventory, count);

    return 0;
}