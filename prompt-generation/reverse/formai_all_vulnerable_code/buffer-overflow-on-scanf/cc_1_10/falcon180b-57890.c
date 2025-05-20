//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

void addItem(Item *items, int count, char *name, int quantity, float price) {
    if (count >= MAX_ITEMS) {
        printf("Sorry, cannot add more items. Maximum limit reached.\n");
        return;
    }

    strcpy(items[count].name, name);
    items[count].quantity = quantity;
    items[count].price = price;

    printf("Item added successfully!\n");
}

void displayItems(Item *items, int count) {
    printf("\nProduct Inventory:\n");
    printf("===================\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s %10d $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void updateItemQuantity(Item *items, int count, char *name, int quantity) {
    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity += quantity;
            printf("Item quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found.\n");
}

void main() {
    Item items[MAX_ITEMS];
    int count = 0;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Update item quantity\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LEN];
                int quantity;
                float price;

                printf("Enter item name: ");
                scanf("%s", name);

                printf("Enter item quantity: ");
                scanf("%d", &quantity);

                printf("Enter item price: $");
                scanf("%f", &price);

                addItem(items, count, name, quantity, price);
                break;
            }

            case 2: {
                displayItems(items, count);
                break;
            }

            case 3: {
                char name[MAX_NAME_LEN];
                int quantity;

                printf("Enter item name: ");
                scanf("%s", name);

                printf("Enter item quantity: ");
                scanf("%d", &quantity);

                updateItemQuantity(items, count, name, quantity);
                break;
            }

            case 4: {
                printf("Exiting program...\n");
                exit(0);
            }

            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
}