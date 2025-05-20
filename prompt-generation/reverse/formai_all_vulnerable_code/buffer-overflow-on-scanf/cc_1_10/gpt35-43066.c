//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[50];
    int quantity;
    float price;
};

void addProduct(struct Product products[], int *count) {
    printf("Enter product name: ");
    scanf("%s", products[*count].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*count].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*count].price);
    (*count)++;
}

void printInventory(struct Product products[], int count) {
    printf("\n*** Inventory Details ***\n");
    for(int i=0; i<count; i++) {
        printf("Product Name: %s\n", products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2f\n", products[i].price);
        printf("------------------------\n");
    }
}

void updateProduct(struct Product products[], int count) {
    printf("Enter the name of the product to update: ");
    char name[50];
    scanf("%s", name);
    for(int i=0; i<count; i++) {
        if(strcmp(name, products[i].name) == 0) {
            printf("Enter product quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter product price: ");
            scanf("%f", &products[i].price);
            printf("Product details updated!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void deleteProduct(struct Product products[], int *count) {
    printf("Enter the name of the product to delete: ");
    char name[50];
    scanf("%s", name);
    for(int i=0; i<*count; i++) {
        if(strcmp(name, products[i].name) == 0) {
            (*count)--;
            for(int j=i; j<*count; j++) {
                strcpy(products[j].name, products[j+1].name);
                products[j].quantity = products[j+1].quantity;
                products[j].price = products[j+1].price;
            }
            printf("Product successfully deleted!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

int main() {
    int count = 0;
    struct Product products[50];
    int choice;
    do {
        printf("\n*** Product Inventory Management System ***\n");
        printf("1. Add Product\n2. Print Inventory\n3. Update Product\n4. Delete Product\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                printInventory(products, count);
                break;
            case 3:
                updateProduct(products, count);
                break;
            case 4:
                deleteProduct(products, &count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice! Try Again!\n");
        }
    } while(choice != 5);
    return 0;
}