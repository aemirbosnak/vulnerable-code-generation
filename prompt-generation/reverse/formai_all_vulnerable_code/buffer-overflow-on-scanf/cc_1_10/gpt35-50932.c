//FormAI DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct product products[100]; // assuming maximum 100 products can be added
int count = 0; // to keep track of how many products are in the inventory

void addProduct() {
    if (count == 100) {
        printf("Inventory is full!\n");
        return;
    }
    
    // get product details
    printf("Enter product name: ");
    scanf("%s", products[count].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[count].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[count].price);
    
    // assign a unique id to the product
    products[count].id = count + 1;
    
    printf("Product added successfully!\n");
    count++;
}

void searchProduct() {
    int id;
    printf("Enter product id to search: ");
    scanf("%d", &id);
    
    int i;
    for (i = 0; i < count; i++) {
        if (products[i].id == id) {
            printf("Product found!\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: $%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
            return;
        }
    }
    
    printf("Product not found!\n");
}

void displayInventory() {
    if (count == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    
    int i;
    printf("ID\tNAME\tQUANTITY\tPRICE\n");
    for (i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t$%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n*** PRODUCT INVENTORY SYSTEM ***\n");
        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                searchProduct();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    
    return 0;
}