//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    
    Product new_product;
    new_product.id = product_count + 1; // Simple ID assignment
    printf("Enter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    
    inventory[product_count++] = new_product;
    printf("Product added successfully!\n");
}

void display_products() {
    if (product_count == 0) {
        printf("No products in the inventory.\n");
        return;
    }
    
    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void update_product() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > product_count) {
        printf("Invalid product ID.\n");
        return;
    }
    
    Product *product = &inventory[id - 1];
    printf("Updating product: %s\n", product->name);
    printf("Enter new product name (or press Enter to keep current): ");
    char new_name[50];
    fgets(new_name, sizeof(new_name), stdin); // To consume new line
    fgets(new_name, sizeof(new_name), stdin);
    if (strlen(new_name) > 1) { // If a new name is provided
        new_name[strcspn(new_name, "\n")] = 0; // Remove newline
        strcpy(product->name, new_name);
    }
    
    printf("Enter new price (or -1 to keep current): ");
    float new_price;
    scanf("%f", &new_price);
    if (new_price >= 0) {
        product->price = new_price;
    }
    
    printf("Enter new quantity (or -1 to keep current): ");
    int new_quantity;
    scanf("%d", &new_quantity);
    if (new_quantity >= 0) {
        product->quantity = new_quantity;
    }
    
    printf("Product updated successfully!\n");
}

void delete_product() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > product_count) {
        printf("Invalid product ID.\n");
        return;
    }
    
    for (int i = id - 1; i < product_count - 1; i++) {
        inventory[i] = inventory[i + 1]; // Shift products left
    }
    product_count--;
    printf("Product deleted successfully!\n");
}

void search_product() {
    char search_name[50];
    printf("Enter product name to search: ");
    scanf("%s", search_name);

    int found = 0;
    printf("\nSearch Results:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        if (strcmp(inventory[i].name, search_name) == 0) {
            printf("%d\t%s\t\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("No products found with the name \"%s\".\n", search_name);
    }
}

void menu() {
    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
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
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}