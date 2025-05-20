//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_STOCK 1000

typedef struct {
    char name[50];
    int stock;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter stock: ");
    scanf("%d", &products[num_products].stock);
    printf("Enter price: ");
    scanf("%f", &products[num_products].price);
    num_products++;
}

void removeProduct() {
    int index;
    printf("Enter product index: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_products) {
        num_products--;
        for (int i = index; i < num_products; i++) {
            strcpy(products[i].name, products[i+1].name);
            products[i].stock = products[i+1].stock;
            products[i].price = products[i+1].price;
        }
    } else {
        printf("Invalid index.\n");
    }
}

void updateStock() {
    int index;
    printf("Enter product index: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_products) {
        printf("Enter new stock: ");
        scanf("%d", &products[index].stock);
    } else {
        printf("Invalid index.\n");
    }
}

void printProducts() {
    printf("\nProduct List:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s - %d in stock - $%.2f\n", products[i].name, products[i].stock, products[i].price);
    }
}

int main() {
    printf("Welcome to the Retro Warehouse Management System!\n");
    printf("Please choose an option:\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update stock\n");
    printf("4. Print product list\n");
    printf("5. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            removeProduct();
            break;
        case 3:
            updateStock();
            break;
        case 4:
            printProducts();
            break;
        case 5:
            printf("Thank you for using the Retro Warehouse Management System!\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}