//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 100

struct item {
    char name[MAX_NAME_LEN];
    int quantity;
    double price;
};

void add_item(struct item *items, int num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);

    printf("Enter the quantity of the item: ");
    scanf("%d", &items[num_items].quantity);

    printf("Enter the price of the item: ");
    scanf("%lf", &items[num_items].price);

    num_items++;
}

void display_items(struct item *items, int num_items) {
    printf("\nProduct Inventory:\n");
    printf("--------------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("Name: %s\n", items[i].name);
        printf("Quantity: %d\n", items[i].quantity);
        printf("Price: $.2f\n\n", items[i].price);
    }
}

void update_item_quantity(struct item *items, int num_items) {
    printf("\nEnter the name of the item to update quantity: ");
    scanf("%s", items[num_items].name);

    printf("Enter the new quantity: ");
    scanf("%d", &items[num_items].quantity);
}

void delete_item(struct item *items, int num_items) {
    printf("\nEnter the name of the item to delete: ");
    scanf("%s", items[num_items].name);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, items[num_items].name) == 0) {
            for (int j = i; j < num_items - 1; j++) {
                items[j] = items[j + 1];
            }
            num_items--;
            break;
        }
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        printf("\nEnter 1 to add an item, 2 to display items, 3 to update quantity, 4 to delete an item, or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_item(items, num_items);
            break;
        case 2:
            display_items(items, num_items);
            break;
        case 3:
            update_item_quantity(items, num_items);
            break;
        case 4:
            delete_item(items, num_items);
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}