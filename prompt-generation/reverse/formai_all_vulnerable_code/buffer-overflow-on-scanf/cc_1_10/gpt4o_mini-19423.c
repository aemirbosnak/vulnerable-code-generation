//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

void add_product();
void view_inventory();
void update_product();
void delete_product();
void search_product();

int main() {
    int choice;

    do {
        printf("\n--- Warehouse Management System ---\n");
        printf("1. Add Product\n2. View Inventory\n3. Update Product\n4. Delete Product\n5. Search Product\n6. Exit\n");
        printf("Choose an option: ");
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
                search_product();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while (choice != 6);

    return 0;
}

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }

    Product new_product;
    printf("Enter product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter product name: ");
    getchar(); // Consume newline
    fgets(new_product.name, MAX_NAME_LEN, stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0; // Remove newline
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);

    inventory[product_count++] = new_product;
    printf("Product added successfully!\n");
}

void view_inventory() {
    if (product_count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\n--- Inventory ---\n");
    printf("ID\tName\tQuantity\n");
    for (int i = 0; i < product_count; ++i) {
        printf("%d\t%s\t%d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
}

void update_product() {
    int id, found = 0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; ++i) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Current Name: %s, Current Quantity: %d\n", inventory[i].name, inventory[i].quantity);
            printf("Enter new name: ");
            getchar(); // Consume newline
            fgets(inventory[i].name, MAX_NAME_LEN, stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = 0; // Remove newline
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Product updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void delete_product() {
    int id, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; ++i) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < product_count - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            product_count--;
            printf("Product deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void search_product() {
    int id, found = 0;
    printf("Enter product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < product_count; ++i) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Product found!\nID: %d\nName: %s\nQuantity: %d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}