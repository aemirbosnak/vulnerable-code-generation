//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    int quantity;
    char name[50];
} Item;

void create_item(Item *item) {
    printf("Enter item ID: ");
    scanf("%d", &item->id);
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);
}

void display_item(Item item) {
    printf("ID: %d\n", item.id);
    printf("Name: %s\n", item.name);
    printf("Quantity: %d\n", item.quantity);
}

int main() {
    Item *items = (Item *)malloc(MAX_SIZE * sizeof(Item));
    int num_items = 0;

    while (num_items < MAX_SIZE) {
        printf("\nEnter 1 to create item, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            create_item(&items[num_items]);
            num_items++;
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\nDisplaying items:\n");

    for (int i = 0; i < num_items; i++) {
        display_item(items[i]);
    }

    free(items);
    return 0;
}