//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

struct item {
    char name[MAX_NAME_LEN];
    int price;
};

typedef struct item item_t;

void display_menu() {
    printf("1. Add item\n2. Delete item\n3. Update item price\n4. Display item list\n5. Exit\n");
}

void add_item(item_t *items, int num_items, char *name, int price) {
    item_t new_item;
    strncpy(new_item.name, name, MAX_NAME_LEN);
    new_item.price = price;
    if (num_items < MAX_ITEMS) {
        items[num_items] = new_item;
    } else {
        printf("Sorry, the maximum number of items is %d.\n", MAX_ITEMS);
    }
}

void delete_item(item_t *items, int num_items, char *name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            for (int j = i; j < num_items - 1; j++) {
                items[j] = items[j + 1];
            }
            num_items--;
            return;
        }
    }
    printf("Item not found.\n");
}

void update_item_price(item_t *items, int num_items, char *name, int new_price) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].price = new_price;
            return;
        }
    }
    printf("Item not found.\n");
}

void display_item_list(item_t *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("Name: %s, Price: %d\n", items[i].name, items[i].price);
    }
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;
    char name[MAX_NAME_LEN], *price_str;
    int price;

    while (1) {
        display_menu();
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter price: ");
                scanf("%s", price_str);
                price = atoi(price_str);
                add_item(items, num_items, name, price);
                break;
            case 2:
                printf("Enter item name to delete: ");
                scanf("%s", name);
                delete_item(items, num_items, name);
                break;
            case 3:
                printf("Enter item name to update price: ");
                scanf("%s", name);
                printf("Enter new price: ");
                scanf("%s", price_str);
                price = atoi(price_str);
                update_item_price(items, num_items, name, price);
                break;
            case 4:
                display_item_list(items, num_items);
                break;
            case 5:
                printf("Thank you for using the Medical Store Management System.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}