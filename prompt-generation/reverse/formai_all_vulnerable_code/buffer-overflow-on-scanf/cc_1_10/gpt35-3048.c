//FormAI DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

void addProduct(FILE *fp) {
    Product product;

    printf("Enter product id: ");
    scanf("%d", &product.id);

    printf("Enter product name: ");
    scanf("%s", product.name);

    printf("Enter product price: ");
    scanf("%f", &product.price);

    fseek(fp, 0, SEEK_END);
    fwrite(&product, sizeof(Product), 1, fp);
    printf("\nProduct added successfully!\n");
}

void editProduct(FILE *fp) {
    int id, found = 0;
    Product product;

    printf("Enter product id to edit: ");
    scanf("%d", &id);

    fseek(fp, 0, SEEK_SET);

    while(fread(&product, sizeof(Product), 1, fp)) {
        if(product.id == id) {
            printf("Enter new product name: ");
            scanf("%s", product.name);

            printf("Enter new product price: ");
            scanf("%f", &product.price);

            fseek(fp, -sizeof(Product), SEEK_CUR);
            fwrite(&product, sizeof(Product), 1, fp);
            printf("\nProduct updated successfully!\n");

            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nProduct not found!\n");
    }
}

void deleteProduct(FILE *fp) {
    int id, found = 0;
    Product product, blank = {0, "", 0};

    printf("Enter product id to delete: ");
    scanf("%d", &id);

    fseek(fp, 0, SEEK_SET);

    while(fread(&product, sizeof(Product), 1, fp)) {
        if(product.id == id) {
            fseek(fp, -sizeof(Product), SEEK_CUR);
            fwrite(&blank, sizeof(Product), 1, fp);
            printf("\nProduct deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nProduct not found!\n");
    }
}

void viewProduct(FILE *fp) {
    Product product;

    printf("\n%-10s%-20s%s\n", "ID", "Product Name", "Price");

    fseek(fp, 0, SEEK_SET);

    while(fread(&product, sizeof(Product), 1, fp)) {
        printf("%-10d%-20s%.2f\n", product.id, product.name, product.price);
    }
}

int main() {
    FILE *fp;
    int choice;

    fp = fopen("product.dat", "r+b");

    if(fp == NULL) {
        fp = fopen("product.dat", "w+b");
    }

    if(fp == NULL) {
        printf("Error: Failed to create file!");
        exit(1);
    }

    do {
        printf("\n====== Product Inventory ======\n");
        printf("1. Add Product\n");
        printf("2. Edit Product\n");
        printf("3. Delete Product\n");
        printf("4. View Products\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(fp);
                break;
            case 2:
                editProduct(fp);
                break;
            case 3:
                deleteProduct(fp);
                break;
            case 4:
                viewProduct(fp);
                break;
            case 5:
                printf("\nThank you for using our program!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice != 5);

    fclose(fp);

    return 0;
}