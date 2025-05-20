//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LEN 50
#define FILE_NAME "inventory.txt"

typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
    float price;
} Product;

void loadInventory(Product products[], int *count);
void saveInventory(Product products[], int count);
void addProduct(Product products[], int *count);
void viewInventory(const Product products[], int count);
void modifyProduct(Product products[], int count);
void deleteProduct(Product products[], int *count);

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;

    loadInventory(products, &count);

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Modify Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                viewInventory(products, count);
                break;
            case 3:
                modifyProduct(products, count);
                break;
            case 4:
                deleteProduct(products, &count);
                break;
            case 5:
                saveInventory(products, count);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 5);

    return 0;
}

void loadInventory(Product products[], int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    while (fscanf(file, "%d %49s %d %f", &products[*count].id, products[*count].name, &products[*count].quantity, &products[*count].price) == 4) {
        (*count)++;
    }

    fclose(file);
}

void saveInventory(Product products[], int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %d %.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }

    fclose(file);
}

void addProduct(Product products[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = *count + 1; // Simple ID assignment
    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LEN, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = '\0'; // Remove newline
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    getchar(); // Consume newline

    products[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");
}

void viewInventory(const Product products[], int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("\nID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void modifyProduct(Product products[], int count) {
    int id;
    printf("Enter product ID to modify: ");
    scanf("%d", &id);
    getchar(); // Consume newline

    if (id < 1 || id > count) {
        printf("Invalid product ID!\n");
        return;
    }

    Product *product = &products[id - 1];
    printf("Modifying product: %s\n", product->name);
    printf("Enter new name (leave empty for no change): ");
    char newName[NAME_LEN];
    fgets(newName, NAME_LEN, stdin);
    newName[strcspn(newName, "\n")] = '\0';
    if (strlen(newName) > 0) {
        strcpy(product->name, newName);
    }
    printf("Enter new quantity (current: %d): ", product->quantity);
    scanf("%d", &product->quantity);
    printf("Enter new price (current: %.2f): ", product->price);
    scanf("%f", &product->price);
    getchar(); // Consume newline

    printf("Product modified successfully!\n");
}

void deleteProduct(Product products[], int *count) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    getchar(); // Consume newline

    if (id < 1 || id > *count) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        products[i] = products[i + 1];
    }
    (*count)--;
    printf("Product deleted successfully!\n");
}