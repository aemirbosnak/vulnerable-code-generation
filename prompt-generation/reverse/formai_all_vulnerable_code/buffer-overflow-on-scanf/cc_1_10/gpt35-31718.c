//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50

struct item {
    char name[MAX_NAME_LEN];
    int quantity;
};

struct warehouse {
    struct item items[MAX_ITEMS];
    int num_items;
};

void add_item(struct warehouse* w, char* name, int quantity) {
    if (w->num_items == MAX_ITEMS) {
        printf("Warehouse is full\n");
        return;
    }
    strcpy(w->items[w->num_items].name, name);
    w->items[w->num_items].quantity = quantity;
    w->num_items++;
    printf("Item added to warehouse\n");
}

void remove_item(struct warehouse* w, char* name, int quantity) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            if (w->items[i].quantity < quantity) {
                printf("Not enough quantity to remove\n");
                return;
            }
            w->items[i].quantity -= quantity;
            printf("Item removed from warehouse\n");
            return;
        }
    }
    printf("Item not found in warehouse\n");
}

void display_inventory(struct warehouse* w) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < w->num_items; i++) {
        printf("%s: %d\n", w->items[i].name, w->items[i].quantity);
    }
}

int main() {
    struct warehouse my_warehouse = {0};
    int choice, quantity;
    char name[MAX_NAME_LEN];
    while (1) {
        printf("1. Add item to warehouse\n");
        printf("2. Remove item from warehouse\n");
        printf("3. Display inventory\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name of item: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_item(&my_warehouse, name, quantity);
                break;
            case 2:
                printf("Enter name of item: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                remove_item(&my_warehouse, name, quantity);
                break;
            case 3:
                display_inventory(&my_warehouse);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}