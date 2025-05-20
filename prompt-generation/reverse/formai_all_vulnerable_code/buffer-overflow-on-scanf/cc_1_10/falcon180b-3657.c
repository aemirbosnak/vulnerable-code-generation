//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QTY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int qty;
    float price;
} item_t;

item_t items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].qty);

    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);

    num_items++;
}

void display_items() {
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%d\t\t%.2f\n", items[i].name, items[i].qty, items[i].price);
    }
}

void search_item() {
    printf("Enter item name to search: ");
    char search_name[MAX_NAME_LEN];
    scanf("%s", search_name);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, search_name) == 0) {
            printf("Item found:\n");
            printf("Item Name: %s\n", items[i].name);
            printf("Quantity: %d\n", items[i].qty);
            printf("Price: $.2f\n");
        }
    }
}

void update_item() {
    printf("Enter item name to update: ");
    char search_name[MAX_NAME_LEN];
    scanf("%s", search_name);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, search_name) == 0) {
            printf("Item found:\n");
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].qty);

            printf("Enter new item price: ");
            scanf("%f", &items[i].price);

            printf("Item updated.\n");
        }
    }
}

void delete_item() {
    printf("Enter item name to delete: ");
    char delete_name[MAX_NAME_LEN];
    scanf("%s", delete_name);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, delete_name) == 0) {
            printf("Item found and deleted.\n");
            num_items--;
            break;
        }
    }
}

int main() {
    int choice;

    do {
        printf("Product Inventory System\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Search item\n");
        printf("4. Update item\n");
        printf("5. Delete item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            display_items();
            break;
        case 3:
            search_item();
            break;
        case 4:
            update_item();
            break;
        case 5:
            delete_item();
            break;
        case 6:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 6);

    return 0;
}