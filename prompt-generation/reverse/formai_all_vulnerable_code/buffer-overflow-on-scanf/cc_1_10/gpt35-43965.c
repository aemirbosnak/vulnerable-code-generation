//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>

#define MAX_PRODUCTS 100

struct product {
    int id;
    char name[32];
    float price;
    int quantity;
};

int num_products = 0;
struct product inventory[MAX_PRODUCTS];

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: inventory full\n");
        return;
    }

    struct product p;
    printf("Enter product id: ");
    scanf("%d", &p.id);
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);

    inventory[num_products++] = p;
    printf("Product added successfully!\n");
}

void remove_product() {
    int id, i, index = -1;
    printf("Enter product id to remove: ");
    scanf("%d", &id);

    for (i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: product not found\n");
    } else {
        for (i = index; i < num_products - 1; i++) {
            inventory[i] = inventory[i+1];
        }
        num_products--;
        printf("Product removed successfully!\n");
    }
}

void print_inventory() {
    int i;
    printf("%-10s%-30s%-10s%-10s\n", "ID", "Name", "Price", "Quantity");
    for (i = 0; i < num_products; i++) {
        printf("%-10d%-30s%-10.2f%-10d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add product\n2. Remove product\n3. Print inventory\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_product(); break;
            case 2: remove_product(); break;
            case 3: print_inventory(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}