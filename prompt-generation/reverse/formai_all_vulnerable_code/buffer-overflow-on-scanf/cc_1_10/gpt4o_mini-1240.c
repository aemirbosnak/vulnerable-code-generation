//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    char category[30];
    int quantity;
    float price;
} Product;

void addProduct(Product *inventory, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    Product p;
    p.id = *count + 1; // Assign an id based on current count
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product category: ");
    scanf("%s", p.category);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);

    inventory[*count] = p;
    (*count)++;
    printf("Product added successfully!\n");
}

void listProducts(Product *inventory, int count) {
    printf("\nProduct Inventory:\n");
    printf("ID\tName\tCategory\tQuantity\tPrice\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        Product p = inventory[i];
        printf("%d\t%s\t%s\t%d\t\t%.2f\n", p.id, p.name, p.category, p.quantity, p.price);
    }
}

void updateProduct(Product *inventory, int count) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    if (id <= 0 || id > count) {
        printf("Invalid product ID.\n");
        return;
    }

    Product *p = &inventory[id - 1];
    printf("Updating product: %s\n", p->name);
    printf("Enter new quantity: ");
    scanf("%d", &p->quantity);
    printf("Enter new price: ");
    scanf("%f", &p->price);
    printf("Product updated successfully!\n");
}

void deleteProduct(Product *inventory, int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > *count) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < (*count - 1); i++) {
        inventory[i] = inventory[i + 1];
    }
    (*count)--;
    printf("Product deleted successfully!\n");
}

void searchProduct(Product *inventory, int count) {
    char name[50];
    printf("Enter product name to search: ");
    scanf("%s", name);

    printf("Search results:\n");
    printf("ID\tName\tCategory\tQuantity\tPrice\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (strstr(inventory[i].name, name) != NULL) {
            Product p = inventory[i];
            printf("%d\t%s\t%s\t%d\t\t%.2f\n", p.id, p.name, p.category, p.quantity, p.price);
        }
    }
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. List Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                listProducts(inventory, count);
                break;
            case 3:
                updateProduct(inventory, count);
                break;
            case 4:
                deleteProduct(inventory, &count);
                break;
            case 5:
                searchProduct(inventory, count);
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}