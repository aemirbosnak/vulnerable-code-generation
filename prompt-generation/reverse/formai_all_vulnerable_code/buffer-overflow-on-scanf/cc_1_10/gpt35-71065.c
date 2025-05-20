//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
};

void add_item(struct Item item, struct Item inventory[], int *inventory_count) {
    inventory[*inventory_count] = item;
    *inventory_count += 1;
    printf("%s added to inventory.\n", item.name);
}

void remove_item(int item_id, struct Item inventory[], int *inventory_count) {
    int index = -1;
    for (int i = 0; i < *inventory_count; i++) {
        if (inventory[i].id == item_id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Item not found in inventory.\n");
    } else {
        for (int i = index; i < *inventory_count - 1; i++) {
            inventory[i] = inventory[i+1];
        }
        *inventory_count -= 1;
        printf("Item removed from inventory.\n");
    }
}

void list_items(struct Item inventory[], int inventory_count) {
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < inventory_count; i++) {
        printf("%d\t%s\t$%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void check_stock(int item_id, struct Item inventory[], int inventory_count) {
    int index = -1;
    for (int i = 0; i < inventory_count; i++) {
        if (inventory[i].id == item_id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Item not found in inventory.\n");
    } else {
        printf("%s has %d in stock.\n", inventory[index].name, inventory[index].quantity);
    }
}

int main() {
    struct Item inventory[50];
    int inventory_count = 0;
    int choice, item_id, quantity;
    char item_name[50];
    float item_price;

    printf("Welcome to the Warehouse Management System.\n");

    while(1) {
        printf("\nMENU:\n");
        printf("1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. List all items in inventory\n");
        printf("4. Check stock of item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the details of the item to add:\n");
                printf("Name: ");
                scanf("%s", item_name);
                printf("Price: ");
                scanf("%f", &item_price);
                printf("Quantity: ");
                scanf("%d", &quantity);
                struct Item item = {
                    .id = inventory_count+1,
                    .price = item_price,
                    .quantity = quantity
                };
                strcpy(item.name, item_name);
                add_item(item, inventory, &inventory_count);
                break;
            case 2:
                printf("Enter the ID of the item to remove: ");
                scanf("%d", &item_id);
                remove_item(item_id, inventory, &inventory_count);
                break;
            case 3:
                list_items(inventory, inventory_count);
                break;
            case 4:
                printf("Enter the ID of the item to check stock: ");
                scanf("%d", &item_id);
                check_stock(item_id, inventory, inventory_count);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}