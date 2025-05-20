//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 50
#define MAX_QUANTITY_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char quantity[MAX_QUANTITY_LEN];
} Item;

void print_item(Item *item) {
    printf("Name: %s\n", item->name);
    printf("Quantity: %s\n", item->quantity);
}

int main() {
    Item inventory[MAX_ITEMS];
    int num_items = 0;
    char choice;

    do {
        printf("=== Post-Apocalyptic Inventory System ===\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. View inventory\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (num_items >= MAX_ITEMS) {
                printf("Inventory is full.\n");
            } else {
                printf("Enter item name: ");
                scanf("%s", inventory[num_items].name);
                printf("Enter item quantity: ");
                scanf("%s", inventory[num_items].quantity);
                num_items++;
                printf("Item added successfully.\n");
            }
            break;
        case '2':
            if (num_items == 0) {
                printf("Inventory is empty.\n");
            } else {
                printf("Enter item name to remove: ");
                scanf("%s", inventory[0].name);
                for (int i = 0; i < num_items; i++) {
                    if (strcmp(inventory[i].name, inventory[0].name) == 0) {
                        printf("Item removed successfully.\n");
                        for (int j = i; j < num_items - 1; j++) {
                            strcpy(inventory[j].name, inventory[j + 1].name);
                            strcpy(inventory[j].quantity, inventory[j + 1].quantity);
                        }
                        num_items--;
                        break;
                    }
                }
            }
            break;
        case '3':
            printf("Inventory:\n");
            for (int i = 0; i < num_items; i++) {
                print_item(&inventory[i]);
            }
            break;
        case '4':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice!= '4');

    return 0;
}