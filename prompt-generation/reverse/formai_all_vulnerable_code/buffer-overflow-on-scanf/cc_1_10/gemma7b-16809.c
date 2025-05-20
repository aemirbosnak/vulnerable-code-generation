//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

struct Item {
    char name[20];
    int quantity;
    float price;
};

struct Item items[MAX_ITEMS];

void update_inventory() {
    FILE *fp = fopen("inventory.txt", "w");
    fprintf(fp, "Item Name, Quantity, Price\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        fprintf(fp, "%s, %d, %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
    fclose(fp);
}

void add_item() {
    items[MAX_ITEMS - 1].name[0] = '\0';
    printf("Enter item name: ");
    scanf("%s", items[MAX_ITEMS - 1].name);

    items[MAX_ITEMS - 1].quantity = 0;
    printf("Enter item quantity: ");
    scanf("%d", &items[MAX_ITEMS - 1].quantity);

    items[MAX_ITEMS - 1].price = 0.0f;
    printf("Enter item price: ");
    scanf("%f", &items[MAX_ITEMS - 1].price);

    update_inventory();
}

void remove_item() {
    char item_name[20];
    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            items[i].quantity = 0;
            update_inventory();
            return;
        }
    }

    printf("Item not found.\n");
}

void list_items() {
    printf("Inventory:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    char command;

    printf("Welcome to the Retro Inventory System!\n");
    printf("Enter command (add/remove/list): ");
    scanf("%c", &command);

    switch (command) {
        case 'a':
            add_item();
            break;
        case 'r':
            remove_item();
            break;
        case 'l':
            list_items();
            break;
        default:
            printf("Invalid command.\n");
    }

    return 0;
}