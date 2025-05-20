//FormAI DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining structs for products and categories
typedef struct category {
    int id;
    char name[50];
} Category;

typedef struct product {
    int id;
    char name[50];
    double price;
    int stock;
    Category category;
} Product;

// function to initialize categories
void initCategories(Category categories[]) {
    categories[0] = (Category){1, "Electronics"};
    categories[1] = (Category){2, "Clothing"};
    categories[2] = (Category){3, "Home Appliances"};
}

// function to add a new product
void addProduct(Product products[], int *count, Category categories[]) {
    Product product;
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product price: ");
    scanf("%lf", &product.price);
    printf("Enter product stock: ");
    scanf("%d", &product.stock);
    printf("Enter product category ID: ");
    int categoryId;
    scanf("%d", &categoryId);
    // finding category by ID
    for (int i = 0; i < 3; i++) {
        if (categories[i].id == categoryId) {
            product.category = categories[i];
            break;
        }
    }
    // adding new product to array
    product.id = *count + 1;
    products[*count] = product;
    *count += 1;
    printf("Product added successfully!\n\n");
}

// function to display all products
void displayProducts(Product products[], int count) {
    if (count == 0) {
        printf("No products to display.\n\n");
        return;
    }
    printf("ID\tNAME\t\tPRICE\tSTOCK\tCATEGORY\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2lf\t%d\t%s\n", products[i].id, products[i].name,
        products[i].price, products[i].stock, products[i].category.name);
    }
    printf("---------------------------------------------------------------\n\n");
}

// function to search products by name
void searchProductByName(Product products[], int count) {
    if (count == 0) {
        printf("No products to search.\n\n");
        return;
    }
    char name[50];
    printf("Enter product name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            found = 1;
            printf("ID\tNAME\t\tPRICE\tSTOCK\tCATEGORY\n");
            printf("---------------------------------------------------------------\n");
            printf("%d\t%s\t\t%.2lf\t%d\t%s\n", products[i].id, products[i].name,
            products[i].price, products[i].stock, products[i].category.name);
            printf("---------------------------------------------------------------\n\n");
            break;
        }
    }
    if (found == 0) {
        printf("No product found with the given name.\n\n");
    }
}

int main() {
    Category categories[3];
    initCategories(categories);
    Product products[50];
    int count = 0;
    int choice;
    do {
        printf("PRODUCT INVENTORY SYSTEM\n");
        printf("1. Add new product\n");
        printf("2. Display all products\n");
        printf("3. Search product by name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct(products, &count, categories);
                break;
            case 2:
                displayProducts(products, count);
                break;
            case 3:
                searchProductByName(products, count);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n\n");
        }
    } while (choice != 4);
    return 0;
}