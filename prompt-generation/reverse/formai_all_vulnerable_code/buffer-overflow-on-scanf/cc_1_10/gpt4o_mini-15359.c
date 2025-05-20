//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product products[], int *count);
void deleteProduct(Product products[], int *count);
void listProducts(Product products[], int count);
void saveToFile(Product products[], int count, const char *filename);
void loadFromFile(Product products[], int *count, const char *filename);
void sortProducts(Product products[], int count);
void displayStatistics(Product products[], int count);

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;
    const char *filename = "product_inventory.txt";

    // Load existing inventory data from file
    loadFromFile(products, &count, filename);

    while (1) {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. List Products\n");
        printf("4. Save Inventory to File\n");
        printf("5. Display Statistics\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                deleteProduct(products, &count);
                break;
            case 3:
                listProducts(products, count);
                break;
            case 4:
                saveToFile(products, count, filename);
                break;
            case 5:
                displayStatistics(products, count);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
    return 0;
}

void addProduct(Product products[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Error: Inventory full. Cannot add more products.\n");
        return;
    }
    Product newProduct;
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    products[(*count)++] = newProduct;
    printf("Product added successfully.\n");
}

void deleteProduct(Product products[], int *count) {
    int id, i, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++) {
        if (products[i].id == id) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                products[j] = products[j + 1];
            }
            (*count)--;
            printf("Product deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product ID not found.\n");
    }
}

void listProducts(Product products[], int count) {
    if (count == 0) {
        printf("No products to display.\n");
        return;
    }
    printf("\n--- Product List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void saveToFile(Product products[], int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %d %.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
    fclose(file);
    printf("Inventory saved to %s successfully.\n", filename);
}

void loadFromFile(Product products[], int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No existing inventory file found, starting fresh.\n");
        return;
    }
    while (fscanf(file, "%d %s %d %f", &products[*count].id, products[*count].name,
                  &products[*count].quantity, &products[*count].price) != EOF) {
        (*count)++;
    }
    fclose(file);
}

void sortProducts(Product products[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (products[j].id > products[j + 1].id) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void displayStatistics(Product products[], int count) {
    if (count == 0) {
        printf("No products to analyze.\n");
        return;
    }
    float totalValue = 0;
    int totalQuantity = 0;
    for (int i = 0; i < count; i++) {
        totalValue += products[i].price * products[i].quantity;
        totalQuantity += products[i].quantity;
    }
    printf("Total Products Count: %d\n", count);
    printf("Total Quantity in Stock: %d\n", totalQuantity);
    printf("Total Inventory Value: %.2f\n", totalValue);
}