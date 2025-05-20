//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int id;
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int count = 0;

void addProduct() {
    if (count >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    Product newProduct;
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[count] = newProduct;
    count++;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\nInventory:\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", 
                inventory[i].id, 
                inventory[i].name, 
                inventory[i].price, 
                inventory[i].quantity);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Updating product: %s\n", inventory[i].name);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product ID not found.\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product ID not found.\n");
}

void searchProduct() {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Product found:\n");
            printf("ID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n",
                    inventory[i].id,
                    inventory[i].name,
                    inventory[i].price,
                    inventory[i].quantity);
            return;
        }
    }
    printf("Product ID not found.\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}