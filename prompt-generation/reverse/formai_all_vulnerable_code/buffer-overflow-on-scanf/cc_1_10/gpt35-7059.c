//FormAI DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int id;
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int numProducts = 0;

void addProduct() {
    if (numProducts == MAX_PRODUCTS) {
        printf("Cannot add more products to inventory.\n");
        return;
    }

    Product p;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product id: ");
    scanf("%d", &p.id);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);

    products[numProducts++] = p;
}

void searchProduct() {
    int id;
    printf("Enter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            printf("Product found!\n");
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: $%.2f\n", products[i].price);
            return;
        }
    }

    printf("Product not found.\n");
}

void updateProduct() {
    int id;
    printf("Enter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &products[i].price);
            printf("Product updated.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void deleteProduct() {
    int id;
    printf("Enter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            // Shift all elements after the deleted element left by one position
            for (int j = i; j < numProducts - 1; j++) {
                products[j] = products[j+1];
            }
            numProducts--;
            printf("Product deleted.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void displayInventory() {
    if (numProducts == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Name\tID\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s\t%d\t%d\t\t$%.2f\n", products[i].name, products[i].id, products[i].quantity, products[i].price);
    }
}

int main() {
    int option;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Search product\n");
        printf("3. Update product\n");
        printf("4. Delete product\n");
        printf("5. Display inventory\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct();
                break;
            case 2:
                searchProduct();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                displayInventory();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option selected.\n");
                break;
        }
    } while (option != 6);

    return 0;
}