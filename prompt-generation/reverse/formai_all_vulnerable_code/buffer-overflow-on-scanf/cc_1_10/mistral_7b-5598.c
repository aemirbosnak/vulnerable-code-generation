//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items == MAX_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", inventory[num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &inventory[num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &inventory[num_items].price);

    num_items++;
}

void display_inventory() {
    int i;

    printf("\nCurrent Inventory:\n");

    for (i = 0; i < num_items; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_item() {
    char name[MAX_NAME_LENGTH];
    int i;

    printf("Enter item name to search: ");
    scanf("%s", name);

    for (i = 0; i < num_items; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            printf("Item found:\nName: %s\nQuantity: %d\nPrice: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }

    printf("Item not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nPost-Apocalyptic Medical Store Management System\n");
        printf("1. Add Item\n2. Display Inventory\n3. Search Item\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                search_item();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}