//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

struct warehouse {
    struct item items[MAX_ITEMS];
    int num_items;
};

void add_item(struct warehouse *w, char *name, int quantity, float price) {
    if (w->num_items < MAX_ITEMS) {
        struct item new_item;
        strncpy(new_item.name, name, MAX_NAME_LENGTH);
        new_item.quantity = quantity;
        new_item.price = price;
        w->items[w->num_items] = new_item;
        w->num_items++;
    } else {
        printf("Warehouse is full! Cannot add item.\n");
    }
}

void remove_item(struct warehouse *w, int index) {
    if (index >= 0 && index < w->num_items) {
        for (int i = index; i < w->num_items - 1; i++) {
            w->items[i] = w->items[i+1];
        }
        w->num_items--;
    } else {
        printf("Invalid index!\n");
    }
}

void list_items(struct warehouse *w) {
    printf("%-30s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < w->num_items; i++) {
        struct item curr_item = w->items[i];
        printf("%-30s %-10d %-10.2f\n", curr_item.name, curr_item.quantity, curr_item.price);
    }
}

int main(void) {
    struct warehouse w;
    w.num_items = 0;

    printf("Warehouse Management System\n\n");
    int choice;
    do {
        printf("Options:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. List items\n");
        printf("4. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                int quantity;
                float price;
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                add_item(&w, name, quantity, price);
                printf("Item added!\n");
                break;
            }
            case 2: {
                int index;
                printf("Enter index of item to remove: ");
                scanf("%d", &index);
                remove_item(&w, index);
                printf("Item removed!\n");
                break;
            }
            case 3: {
                list_items(&w);
                break;
            }
            case 4: {
                printf("Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }

        printf("\n");

    } while (choice != 4);

    return 0;
}