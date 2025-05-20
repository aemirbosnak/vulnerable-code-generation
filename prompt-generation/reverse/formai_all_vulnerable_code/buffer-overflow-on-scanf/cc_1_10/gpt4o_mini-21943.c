//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define FILENAME "inventory.txt"

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void add_product();
void view_products();
void delete_product();
void search_product();
void load_inventory(Product products[], int *count);
void save_inventory(Product products[], int count);

int main() {
    int choice;

    do {
        printf("\n=== Product Inventory System ===\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Delete Product\n");
        printf("4. Search Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                view_products();
                break;
            case 3:
                delete_product();
                break;
            case 4:
                search_product();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void add_product() {
    Product new_product;
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter product name: ");
    scanf(" %[^\n]", new_product.name);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    fwrite(&new_product, sizeof(Product), 1, file);
    fclose(file);
    printf("Product added successfully!\n");
}

void view_products() {
    Product products[MAX_PRODUCTS];
    int count = 0;

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No products available.\n");
        return;
    }

    printf("\n=== Product List ===\n");
    while (fread(&products[count], sizeof(Product), 1, file)) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               products[count].id, products[count].name,
               products[count].quantity, products[count].price);
        count++;
    }
    fclose(file);
}

void delete_product() {
    Product products[MAX_PRODUCTS];
    int count = 0, idToDelete, i;
    int found = 0;
    
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No products available to delete.\n");
        return;
    }

    while (fread(&products[count], sizeof(Product), 1, file)) {
        count++;
    }
    fclose(file);

    printf("Enter product ID to delete: ");
    scanf("%d", &idToDelete);

    for (i = 0; i < count; i++) {
        if (products[i].id == idToDelete) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < count - 1; j++) {
            products[j] = products[j + 1];
        }
        count--;

        file = fopen(FILENAME, "w");
        for (i = 0; i < count; i++) {
            fwrite(&products[i], sizeof(Product), 1, file);
        }
        fclose(file);
        printf("Product deleted successfully!\n");
    } else {
        printf("Product with ID %d not found!\n", idToDelete);
    }
}

void search_product() {
    Product products[MAX_PRODUCTS];
    int count = 0, idToSearch;
    int found = 0;

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No products available to search.\n");
        return;
    }

    while (fread(&products[count], sizeof(Product), 1, file)) {
        count++;
    }
    fclose(file);

    printf("Enter product ID to search: ");
    scanf("%d", &idToSearch);

    for (int i = 0; i < count; i++) {
        if (products[i].id == idToSearch) {
            found = 1;
            printf("Product Found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   products[i].id, products[i].name, 
                   products[i].quantity, products[i].price);
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found!\n", idToSearch);
    }
}