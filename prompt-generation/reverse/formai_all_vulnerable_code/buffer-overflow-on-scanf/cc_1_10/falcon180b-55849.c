//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter quantity: ");
    scanf("%d", &products[num_products].quantity);
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
            strcpy(products[i].name, products[i + 1].name);
            products[i].quantity = products[i + 1].quantity;
            products[i].price = products[i + 1].price;
        }
    } else {
        printf("Invalid product index.\n");
    }
}

void updateProduct() {
    int index;
    printf("Enter product index: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_products) {
        printf("Enter new product name: ");
        scanf("%s", products[index].name);
        printf("Enter new quantity: ");
        scanf("%d", &products[index].quantity);
        printf("Enter new price: ");
        scanf("%f", &products[index].price);
    } else {
        printf("Invalid product index.\n");
    }
}

void searchProduct() {
    char name[MAX_NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Product found: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
        }
    }
}

void displayInventory() {
    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-50s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n2. Remove product\n3. Update product\n4. Search product\n5. Display inventory\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            removeProduct();
            break;
        case 3:
            updateProduct();
            break;
        case 4:
            searchProduct();
            break;
        case 5:
            displayInventory();
            break;
        case 6:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 6);
    return 0;
}