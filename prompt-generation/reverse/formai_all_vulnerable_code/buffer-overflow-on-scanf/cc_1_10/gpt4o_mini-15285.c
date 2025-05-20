//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_SIZE 50

typedef struct {
    int id;
    char name[NAME_SIZE];
    int quantity;
    float price;
} Product;

void addProduct(Product *products, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = *count + 1;

    printf("Enter product name: ");
    getchar(); // to consume any leftover newline character
    fgets(newProduct.name, NAME_SIZE, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline character

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    products[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");
}

void displayProducts(Product *products, int count) {
    if (count == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("\n%-5s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-30s %-10d $%-9.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void updateProduct(Product *products, int count) {
    int id;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > count) {
        printf("Invalid product ID!\n");
        return;
    }

    Product *product = &products[id - 1];
    printf("Updating product: %s\n", product->name);
    printf("Enter new quantity: ");
    scanf("%d", &product->quantity);
    printf("Enter new price: ");
    scanf("%f", &product->price);

    printf("Product updated successfully!\n");
}

void removeProduct(Product *products, int *count) {
    int id;
    printf("Enter the ID of the product to remove: ");
    scanf("%d", &id);

    if (id < 1 || id > *count) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        products[i] = products[i + 1];
    }
    (*count)--;
    printf("Product removed successfully!\n");
}

void saveToFile(Product *products, int count) {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }

    fclose(file);
    printf("Inventory saved to inventory.txt successfully!\n");
}

void loadFromFile(Product *products, int *count) {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading. Starting with an empty inventory.\n");
        return;
    }

    while (fscanf(file, "%d,%49[^,],%d,%f\n", &products[*count].id, products[*count].name, &products[*count].quantity, &products[*count].price) != EOF) {
        (*count)++;
    }

    fclose(file);
    printf("Inventory loaded from inventory.txt successfully!\n");
}

void menu() {
    printf("\n------ Inventory Management System ------\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Update Product\n");
    printf("4. Remove Product\n");
    printf("5. Save Inventory to File\n");
    printf("6. Load Inventory from File\n");
    printf("7. Exit\n");
    printf("------------------------------------------\n");
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;

    loadFromFile(products, &count);
    
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                displayProducts(products, count);
                break;
            case 3:
                updateProduct(products, count);
                break;
            case 4:
                removeProduct(products, &count);
                break;
            case 5:
                saveToFile(products, count);
                break;
            case 6:
                loadFromFile(products, &count);
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
    } while (choice != 7);

    return 0;
}