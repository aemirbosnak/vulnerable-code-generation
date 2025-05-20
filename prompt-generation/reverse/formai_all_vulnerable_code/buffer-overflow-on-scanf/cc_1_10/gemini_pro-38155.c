//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[100];
int count = 0;

void addProduct() {
    printf("Enter product ID: ");
    scanf("%d", &inventory[count].id);
    printf("Enter product name: ");
    scanf("%s", inventory[count].name);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[count].quantity);
    printf("Enter product price: ");
    scanf("%f", &inventory[count].price);
    count++;
}

void listProducts() {
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct() {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Product found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Enter new product name: ");
            scanf("%s", inventory[i].name);
            printf("Enter new product quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new product price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
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
            printf("Product deleted successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

int main() {
    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. List Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            listProducts();
            break;
        case 3:
            searchProduct();
            break;
        case 4:
            updateProduct();
            break;
        case 5:
            deleteProduct();
            break;
        case 6:
            printf("Thank you for using the Product Inventory System.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}