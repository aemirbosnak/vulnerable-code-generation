//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

struct Item {
    char name[50];
    float price;
};

struct Warehouse {
    struct Item items[MAX_ITEMS];
    int count;
    float revenue;
};

void add_item(struct Warehouse *warehouse, char *name, float price) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full, cannot add more items\n");
        return;
    }

    struct Item item;
    strcpy(item.name, name);
    item.price = price;

    warehouse->items[warehouse->count] = item;
    warehouse->count++;
}

void remove_item(struct Warehouse *warehouse, char *name) {
    int found = 0;
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            found = 1;

            warehouse->revenue += warehouse->items[i].price;
            printf("Sold %s for $%.2f\n", name, warehouse->items[i].price);

            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }

            warehouse->count--;
            break;
        }
    }

    if (!found) {
        printf("Item not found\n");
    }
}

void display_inventory(struct Warehouse *warehouse) {
    printf("Warehouse inventory:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%s - $%.2f\n", warehouse->items[i].name, warehouse->items[i].price);
    }
}

void display_revenue(struct Warehouse *warehouse) {
    printf("Warehouse revenue: $%.2f\n", warehouse->revenue);
}


int main() {
    struct Warehouse warehouse;
    warehouse.count = 0;
    warehouse.revenue = 0;

    while (1) {
        printf("1. Add item\n2. Remove item\n3. Display inventory\n4. Display revenue\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                char name[50];
                scanf("%s", name);

                printf("Enter item price: ");
                float price;
                scanf("%f", &price);

                add_item(&warehouse, name, price);
                break;
            case 2:
                printf("Enter item name: ");
                char remove_name[50];
                scanf("%s", remove_name);

                remove_item(&warehouse, remove_name);
                break;
            case 3:
                display_inventory(&warehouse);
                break;
            case 4:
                display_revenue(&warehouse);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("\n");
    }
}