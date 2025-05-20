//FormAI DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct product {
    int id;
    char name[50];
    double price;
    int quantity;
};

struct product inventory[MAX_ITEMS];

int num_items = 0;

void add_item() {
    if (num_items == MAX_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", inventory[num_items].name);

    printf("Enter product price: ");
    scanf("%lf", &inventory[num_items].price);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[num_items].quantity);

    inventory[num_items].id = num_items + 1;

    printf("%s added to inventory with ID %d.\n", inventory[num_items].name, inventory[num_items].id);

    num_items++;
}

void remove_item() {
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < num_items; i++) {
        if (inventory[i].id == id) {
            printf("%s removed from inventory.\n", inventory[i].name);

            for (int j = i; j < num_items - 1; j++) {
                inventory[j] = inventory[j + 1];
                inventory[j].id = j + 1;
            }

            num_items--;
            return;
        }
    }

    printf("Product with ID %d was not found in inventory.\n", id);
}

void display_inventory() {
    printf("ID\tNAME\t\tPRICE\tQUANTITY\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t%.2lf\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void menu() {
    int choice;
    do {
        printf("\n1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    printf("Welcome to the Product Inventory System.\n");
    menu();
    return 0;
}