//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    int price;
} Product;

Product products[100];
int productCount = 0;

void addProduct() {
    char name[50];
    int quantity, price;

    printf("Enter the name of the product: ");
    scanf("%s", name);

    printf("Enter the quantity of the product: ");
    scanf("%d", &quantity);

    printf("Enter the price of the product: ");
    scanf("%d", &price);

    Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;
    newProduct.price = price;

    products[productCount] = newProduct;
    productCount++;
}

void displayProducts() {
    int i;

    printf("\nProduct Inventory System\n");
    printf("----------------------------\n");
    printf("Name | Quantity | Price\n");
    printf("----------------------------\n");

    for (i = 0; i < productCount; i++) {
        printf("%s | %d | %d\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void updateQuantity() {
    int productID, newQuantity;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &productID);

    if (productID < productCount) {
        printf("Enter the new quantity: ");
        scanf("%d", &newQuantity);

        products[productID].quantity = newQuantity;
    } else {
        printf("Invalid product ID\n");
    }
}

void updatePrice() {
    int productID, newPrice;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &productID);

    if (productID < productCount) {
        printf("Enter the new price: ");
        scanf("%d", &newPrice);

        products[productID].price = newPrice;
    } else {
        printf("Invalid product ID\n");
    }
}

void deleteProduct() {
    int productID;
    printf("Enter the ID of the product to delete: ");
    scanf("%d", &productID);

    if (productID < productCount) {
        memmove(products, products + 1, (productCount - productID) * sizeof(Product));
        productCount--;
    } else {
        printf("Invalid product ID\n");
    }
}

void main() {
    int choice, i;

    printf("Welcome to the Product Inventory System!\n");
    printf("----------------------------\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Update Quantity\n");
    printf("4. Update Price\n");
    printf("5. Delete Product\n");
    printf("6. Exit\n");
    printf("----------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            displayProducts();
            break;
        case 3:
            updateQuantity();
            break;
        case 4:
            updatePrice();
            break;
        case 5:
            deleteProduct();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
    }
}