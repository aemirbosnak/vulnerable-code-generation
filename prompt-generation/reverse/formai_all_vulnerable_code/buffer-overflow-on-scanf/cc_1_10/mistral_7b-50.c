//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_COUNT 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEM_COUNT];
int num_items = 0;

void add_item(const char* name, int quantity, float price) {
    if (num_items >= MAX_ITEM_COUNT) {
        printf("Inventory is full!\n");
        return;
    }
    strcpy(inventory[num_items].name, name);
    inventory[num_items].quantity = quantity;
    inventory[num_items].price = price;
    num_items++;
}

void remove_item(const char* name) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_items - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_items--;
            return;
        }
    }
    printf("Item not found in inventory!\n");
}

void print_inventory() {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d (%0.2f)\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    char command[20];
    char name[50];
    int quantity;
    float price;

    while (1) {
        printf("\nEnter command (add/remove/print/quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        switch (*command) {
            case 'a':
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                printf("Enter item price: ");
                scanf("%f", &price);
                add_item(name, quantity, price);
                break;

            case 'r':
                printf("Enter item name to remove: ");
                scanf("%s", name);
                remove_item(name);
                break;

            case 'p':
                print_inventory();
                break;

            default:
                printf("Invalid command!\n");
        }
    }

    return 0;
}