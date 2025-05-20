//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LEN 50
#define CODE_LEN 10

typedef struct {
    char code[CODE_LEN];
    char name[NAME_LEN];
    int quantity;
    float price;
} Product;

void addProduct();
void viewProducts();
void searchProduct();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search Product\n");
        printf("4. Exit\n");
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
                searchProduct();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addProduct() {
    FILE *file = fopen("inventory.txt", "a");
    if (!file) {
        printf("Unable to open file!\n");
        return;
    }

    Product product;
    printf("Enter product code: ");
    scanf("%s", product.code);
    printf("Enter product name: ");
    scanf(" %[^\n]", product.name);
    printf("Enter quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter price: ");
    scanf("%f", &product.price);

    fprintf(file, "%s %s %d %.2f\n", product.code, product.name, product.quantity, product.price);
    fclose(file);
    printf("Product added successfully!\n");
}

void viewProducts() {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("Unable to open file!\n");
        return;
    }

    Product product;
    printf("\n--- Product List ---\n");
    printf("Code\tName\t\tQuantity\tPrice\n");
    printf("-----------------------------------------------\n");
    while (fscanf(file, "%s %s %d %f", product.code, product.name, &product.quantity, &product.price) != EOF) {
        printf("%s\t%s\t\t%d\t\t%.2f\n", product.code, product.name, product.quantity, product.price);
    }
    fclose(file);
}

void searchProduct() {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("Unable to open file!\n");
        return;
    }

    char searchCode[CODE_LEN];
    printf("Enter product code to search: ");
    scanf("%s", searchCode);

    Product product;
    int found = 0;
    while (fscanf(file, "%s %s %d %f", product.code, product.name, &product.quantity, &product.price) != EOF) {
        if (strcmp(product.code, searchCode) == 0) {
            printf("\n--- Product found ---\n");
            printf("Code: %s\nName: %s\nQuantity: %d\nPrice: %.2f\n", product.code, product.name, product.quantity, product.price);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Product with code '%s' not found!\n", searchCode);
    }

    fclose(file);
}