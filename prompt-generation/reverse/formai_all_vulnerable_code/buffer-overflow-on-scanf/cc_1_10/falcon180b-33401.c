//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} item;

item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Error: maximum number of items reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);

    num_items++;
    printf("Item added successfully.\n");
}

void view_items() {
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void update_item() {
    printf("Enter item ID: ");
    int id;
    scanf("%d", &id);

    if (id < 0 || id >= num_items) {
        printf("Error: invalid item ID.\n");
        return;
    }

    printf("Enter new item name: ");
    scanf("%s", items[id].name);

    printf("Enter new item quantity: ");
    scanf("%d", &items[id].quantity);

    printf("Enter new item price: ");
    scanf("%f", &items[id].price);

    printf("Item updated successfully.\n");
}

void delete_item() {
    printf("Enter item ID: ");
    int id;
    scanf("%d", &id);

    if (id < 0 || id >= num_items) {
        printf("Error: invalid item ID.\n");
        return;
    }

    num_items--;
    printf("Item deleted successfully.\n");
}

int main() {
    int choice;
    do {
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Update item\n");
        printf("4. Delete item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                view_items();
                break;
            case 3:
                update_item();
                break;
            case 4:
                delete_item();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 5);

    return 0;
}