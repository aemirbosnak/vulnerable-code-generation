//FormAI DATASET v1.0 Category: Product Inventory System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100 // maximum number of products allowed in the inventory

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products < MAX_PRODUCTS) {
        struct product new_product;
        new_product.id = num_products + 1;
        printf("Enter product name: ");
        scanf("%s", new_product.name);
        printf("Enter quantity: ");
        scanf("%d", &new_product.quantity);
        printf("Enter price: ");
        scanf("%f", &new_product.price);
        inventory[num_products] = new_product;
        num_products++;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory full! No more products can be added.\n");
    }
}

void remove_product() {
    int id;
    printf("Enter product id to remove: ");
    scanf("%d", &id);
    if (id < 1 || id > num_products) {
        printf("Invalid product id!\n");
    } else {
        for (int i = id - 1; i < num_products - 1; i++) {
            inventory[i] = inventory[i + 1];
            inventory[i].id--;
        }
        num_products--;
        printf("Product removed successfully!\n");
    }
}

void display_inventory() {
    printf("Product Inventory\n");
    printf("-----------------\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void print_menu() {
    printf("Product Inventory System\n");
    printf("------------------------\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Display inventory\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

int main() {
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product(); break;
            case 2:
                remove_product(); break;
            case 3:
                display_inventory(); break;
            case 4:
                printf("Exiting..."); break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}