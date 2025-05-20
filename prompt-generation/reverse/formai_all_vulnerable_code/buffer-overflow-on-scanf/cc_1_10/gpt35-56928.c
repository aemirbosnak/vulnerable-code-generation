//FormAI DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

Product products[100];
int count = 0;

void addProduct() {
    Product newProduct;
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter Product Name: ");
    scanf("%s", newProduct.name);
    printf("Enter Product Price: ");
    scanf("%f", &newProduct.price);
    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct.quantity);
    products[count++] = newProduct;
}

void showProducts() {
    printf("\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++){
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

void removeProduct(int id) {
    for (int i = 0; i < count; i++){
        if (products[i].id == id) {
            for (int j = i; j < count - 1; j++){
                products[j] = products[j + 1];
            }
            count--;
            printf("Product with ID %d successfully removed!\n", id);
            return;
        }
    }
    printf("Product with ID %d not found!\n", id);
}

int main() {
    int choice, id;
    while (1) {
        printf("\n");
        printf("1. Add Product\n");
        printf("2. Show Products\n");
        printf("3. Remove Product\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                showProducts();
                break;
            case 3:
                printf("Enter Product ID to remove: ");
                scanf("%d", &id);
                removeProduct(id);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}