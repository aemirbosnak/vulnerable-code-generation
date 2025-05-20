//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_SIZE 50
#define PRICE_SIZE 10

typedef struct {
    char name[NAME_SIZE];
    float price;
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Inventory;

void print_header() {
    printf("---------------------------------------------------\n");
    printf("| %-40s | %-10s | %-10s |\n", "Item Name", "Price", "Quantity");
    printf("---------------------------------------------------\n");
}

void print_inventory(Inventory inv) {
    print_header();

    for (int i = 0; i < inv.count; i++) {
        printf("| %-40s | %10.2f | %10d |\n", inv.items[i].name, inv.items[i].price, inv.items[i].quantity);
    }

    print_header();
}

void add_item(Inventory *inv, char *name, float price, int quantity) {
    if (inv->count >= MAX_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }

    strcpy(inv->items[inv->count].name, name);
    inv->items[inv->count].price = price;
    inv->items[inv->count].quantity = quantity;

    inv->count++;
}

void remove_item(Inventory *inv, int index) {
    if (index < 0 || index >= inv->count) {
        printf("Invalid index.\n");
        return;
    }

    memmove(&inv->items[index], &inv->items[index + 1], sizeof(Item) * (inv->count - index - 1));
    inv->count--;
}

int main() {
    Inventory inv = {0};
    char name[NAME_SIZE];
    float price;
    int quantity, choice, index;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter price: ");
                scanf("%f", &price);
                printf("Enter quantity: ");
                scanf("%d", &quantity);

                add_item(&inv, name, price, quantity);
                break;

            case 2:
                printf("Enter index of item to remove: ");
                scanf("%d", &index);

                remove_item(&inv, index);
                break;

            case 3:
                print_inventory(inv);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}