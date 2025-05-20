//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product p;
    p.id = product_count + 1; // Simple ID generation based on position

    printf("Enter product name: ");
    scanf(" %[^\n]s", p.name); // Read string with spaces

    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);

    printf("Enter product price: ");
    scanf("%f", &p.price);

    inventory[product_count++] = p;
    printf("Product added successfully!\n");
}

void view_inventory() {
    if (product_count == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    printf("Product Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void update_product() {
    int id, found = 0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Currently updating %s (ID: %d)\n", inventory[i].name, inventory[i].id);

            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);

            printf("Product updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product ID not found!\n");
    }
}

void delete_product() {
    int id, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < product_count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            product_count--;
            printf("Product deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product ID not found!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                view_inventory();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}