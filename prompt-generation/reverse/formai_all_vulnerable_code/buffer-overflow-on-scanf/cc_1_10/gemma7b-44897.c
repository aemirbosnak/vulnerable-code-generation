//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

int item_count = 0;

void add_item() {
    items[item_count].name[0] = '\0';
    printf("Enter item name: ");
    scanf("%s", items[item_count].name);

    items[item_count].quantity = 0;
    printf("Enter item quantity: ");
    scanf("%d", &items[item_count].quantity);

    items[item_count].price = 0.0f;
    printf("Enter item price: ");
    scanf("%f", &items[item_count].price);

    item_count++;
}

void list_items() {
    for (int i = 0; i < item_count; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void update_item(char *name) {
    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);

            printf("Enter new item price: ");
            scanf("%f", &items[i].price);

            return;
        }
    }

    printf("Item not found.\n");
}

void remove_item(char *name) {
    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].name[0] = '\0';
            item_count--;

            return;
        }
    }

    printf("Item not found.\n");
}

int main() {
    int choice;

    printf("Welcome to the Medical Store Management System.\n");

    while (1) {
        printf("1. Add Item\n");
        printf("2. List Items\n");
        printf("3. Update Item\n");
        printf("4. Remove Item\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                list_items();
                break;
            case 3:
                update_item("Item Name");
                break;
            case 4:
                remove_item("Item Name");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}