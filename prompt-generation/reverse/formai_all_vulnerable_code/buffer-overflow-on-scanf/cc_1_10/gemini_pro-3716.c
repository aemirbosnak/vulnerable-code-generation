//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

void addProduct(product *products, int *numProducts) {
    printf("Enter product name: ");
    scanf("%s", products[*numProducts].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*numProducts].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*numProducts].price);
    (*numProducts)++;
}

void displayProducts(product *products, int numProducts) {
    for (int i = 0; i < numProducts; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: %s\n", products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: %f\n\n", products[i].price);
    }
}

void searchProduct(product *products, int numProducts) {
    char name[50];
    printf("Enter product name to search for: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Product found:\n");
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %f\n", products[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void deleteProduct(product *products, int *numProducts) {
    char name[50];
    printf("Enter product name to delete: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < *numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < *numProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            (*numProducts)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

int main() {
    product products[100];
    int numProducts = 0;

    int choice;
    do {
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product\n");
        printf("4. Delete product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                displayProducts(products, numProducts);
                break;
            case 3:
                searchProduct(products, numProducts);
                break;
            case 4:
                deleteProduct(products, &numProducts);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    

    return 0;
}