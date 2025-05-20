//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_VENDOR_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char vendor[MAX_VENDOR_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
} item_t;

item_t inventory[MAX_ITEMS];
int num_items = 0;

void add_item(item_t *item) {
    inventory[num_items] = *item;
    num_items++;
}

void print_inventory() {
    printf("Inventory:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - %s - $%s - %d\n", inventory[i].name, inventory[i].vendor, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    item_t new_item;
    int choice;
    char name[MAX_NAME_LEN];
    char vendor[MAX_VENDOR_LEN];
    char price[MAX_PRICE_LEN];

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add new item\n");
        printf("2. Print inventory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name of item: ");
                scanf("%s", name);
                printf("Enter vendor of item: ");
                scanf("%s", vendor);
                printf("Enter price of item: ");
                scanf("%s", price);
                new_item.name[0] = '\0';
                new_item.vendor[0] = '\0';
                new_item.price[0] = '\0';
                strncpy(new_item.name, name, MAX_NAME_LEN);
                strncpy(new_item.vendor, vendor, MAX_VENDOR_LEN);
                strncpy(new_item.price, price, MAX_PRICE_LEN);
                add_item(&new_item);
                break;
            case 2:
                print_inventory();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}