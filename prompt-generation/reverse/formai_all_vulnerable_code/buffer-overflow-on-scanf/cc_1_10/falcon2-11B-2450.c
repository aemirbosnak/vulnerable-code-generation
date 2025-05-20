//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: ultraprecise
#include <stdio.h>

struct Item {
    char name[50];
    int quantity;
};

struct Item items[10];
int numItems = 0;

void addItem(struct Item *item) {
    if (numItems >= 10) {
        printf("Warehouse is full. Cannot add more items.\n");
    } else {
        strcpy(item->name, "item");
        item->quantity = 10;
        items[numItems] = *item;
        numItems++;
    }
}

void removeItem(struct Item *item) {
    if (numItems <= 0) {
        printf("Warehouse is empty. Cannot remove any items.\n");
    } else if (numItems == 1) {
        printf("Removing only item from the warehouse.\n");
    } else {
        for (int i = 0; i < numItems; i++) {
            if (strcmp(items[i].name, item->name) == 0) {
                for (int j = i; j < numItems - 1; j++) {
                    items[j] = items[j + 1];
                }
                numItems--;
                break;
            }
        }
    }
}

void displayItems() {
    if (numItems == 0) {
        printf("Warehouse is empty.\n");
    } else {
        printf("Warehouse contains:\n");
        for (int i = 0; i < numItems; i++) {
            printf("- %s: %d\n", items[i].name, items[i].quantity);
        }
    }
}

int main() {
    struct Item item;
    int choice;
    while (1) {
        printf("\n1. Add item\n2. Remove item\n3. Display items\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", item.name);
                printf("Enter item quantity: ");
                scanf("%d", &item.quantity);
                addItem(&item);
                break;
            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", item.name);
                removeItem(&item);
                break;
            case 3:
                displayItems();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}