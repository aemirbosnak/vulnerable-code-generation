//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

void displayProducts(Product products[], int count);
void addProduct(Product products[], int *count);
void updateProduct(Product products[], int count);
void deleteProduct(Product products[], int *count);
void searchProduct(Product products[], int count);
void saveProducts(Product products[], int count);
void loadProducts(Product products[], int *count);

int main() {
    Product products[MAX_ITEMS];
    int count = 0;
    int choice;

    loadProducts(products, &count);

    while (1) {
        printf("\n=== Product Inventory System ===\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. Display Products\n");
        printf("5. Search Product\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                updateProduct(products, count);
                break;
            case 3:
                deleteProduct(products, &count);
                break;
            case 4:
                displayProducts(products, count);
                break;
            case 5:
                searchProduct(products, count);
                break;
            case 6:
                saveProducts(products, count);
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void displayProducts(Product products[], int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\n---- Product List ----\n");
    for (int i = 0; i < count; i++) {
        printf(" %d. Name: %s, Quantity: %d, Price: %.2f\n", 
            i + 1, products[i].name, products[i].quantity, products[i].price);
    }
}

void addProduct(Product products[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory full, cannot add more products.\n");
        return;
    }
    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    products[*count] = newProduct;
    (*count)++;
    printf("Product added successfully.\n");
}

void updateProduct(Product products[], int count) {
    if (count == 0) {
        printf("No products to update.\n");
        return;
    }
    int index;
    printf("Enter product number to update: ");
    scanf("%d", &index);
    index--; // Adjusting for 0-based index

    if (index < 0 || index >= count) {
        printf("Invalid product number.\n");
        return;
    }
    
    printf("Updating product: %s\n", products[index].name);
    printf("Enter new quantity: ");
    scanf("%d", &products[index].quantity);
    printf("Enter new price: ");
    scanf("%f", &products[index].price);
    printf("Product updated successfully.\n");
}

void deleteProduct(Product products[], int *count) {
    if (*count == 0) {
        printf("No products to delete.\n");
        return;
    }
    int index;
    printf("Enter product number to delete: ");
    scanf("%d", &index);
    index--; // Adjust for 0-based index

    if (index < 0 || index >= *count) {
        printf("Invalid product number.\n");
        return;
    }
    
    for (int i = index; i < *count - 1; i++) {
        products[i] = products[i + 1];
    }
    (*count)--;
    printf("Product deleted successfully.\n");
}

void searchProduct(Product products[], int count) {
    if (count == 0) {
        printf("No products to search.\n");
        return;
    }
    char searchName[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", searchName);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            printf("Found: Name: %s, Quantity: %d, Price: %.2f\n", 
                products[i].name, products[i].quantity, products[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void saveProducts(Product products[], int count) {
    FILE *file = fopen("products.txt", "w");
    if (file == NULL) {
        printf("Error saving products.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
    fclose(file);
    printf("Products saved successfully!\n");
}

void loadProducts(Product products[], int *count) {
    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("No previous inventory found, starting fresh.\n");
        return;
    }
    while (fscanf(file, "%s %d %f", 
        products[*count].name, &products[*count].quantity, &products[*count].price) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Previous inventory loaded successfully.\n");
}