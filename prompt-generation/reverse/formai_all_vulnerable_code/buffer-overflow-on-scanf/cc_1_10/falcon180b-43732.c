//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product products[], int *size) {
    printf("Enter product ID: ");
    scanf("%d", &products[*size].id);

    printf("Enter product name: ");
    scanf("%s", products[*size].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[*size].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[*size].price);

    (*size)++;
}

void displayProducts(Product products[], int size) {
    printf("\nProduct List:\n");
    printf("ID\tName\tQuantity\tPrice\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%d\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void searchProduct(Product products[], int size) {
    int id;

    printf("\nEnter product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
        if (products[i].id == id) {
            printf("\nProduct found:\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
        }
    }
}

void updateProduct(Product products[], int size) {
    int id;

    printf("\nEnter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
        if (products[i].id == id) {
            printf("\nEnter new product name: ");
            scanf("%s", products[i].name);

            printf("Enter new product quantity: ");
            scanf("%d", &products[i].quantity);

            printf("Enter new product price: ");
            scanf("%f", &products[i].price);
        }
    }
}

void deleteProduct(Product products[], int *size) {
    int id;

    printf("\nEnter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *size; i++) {
        if (products[i].id == id) {
            for (int j = i; j < *size - 1; j++) {
                products[j] = products[j + 1];
            }
            (*size)--;
            break;
        }
    }
}

int main() {
    Product products[100];
    int size = 0;

    while (1) {
        printf("\n1. Add product\n2. Display products\n3. Search product\n4. Update product\n5. Delete product\n6. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addProduct(products, &size);
            break;
        case 2:
            displayProducts(products, size);
            break;
        case 3:
            searchProduct(products, size);
            break;
        case 4:
            updateProduct(products, size);
            break;
        case 5:
            deleteProduct(products, &size);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}