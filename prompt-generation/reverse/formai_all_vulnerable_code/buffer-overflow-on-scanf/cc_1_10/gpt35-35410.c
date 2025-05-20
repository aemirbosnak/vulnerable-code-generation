//FormAI DATASET v1.0 Category: Product Inventory System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct product products[50];
int num_products = 0;

void add_product() {
    struct product p;
    printf("Enter product id: ");
    scanf("%d", &p.id);
    printf("Enter product name: ");
    scanf("%s", &p.name);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    products[num_products] = p;
    num_products++;
    printf("Product added successfully!\n");
}

void display_product(int index) {
    printf("\nProduct %d:\n", index+1);
    printf("ID: %d\n", products[index].id);
    printf("Name: %s\n", products[index].name);
    printf("Quantity: %d\n", products[index].quantity);
    printf("Price: %.2f\n", products[index].price);
}

void display_inventory() {
    if(num_products == 0) {
        printf("No products in inventory.\n");
        return;
    }
    printf("\nInventory:\n");
    for(int i = 0; i < num_products; i++) {
        display_product(i);
    }
}

void update_product(int index) {
    printf("\nUpdating Product %d:\n", index+1);
    printf("Enter new product id: ");
    scanf("%d", &products[index].id);
    printf("Enter new product name: ");
    scanf("%s", &products[index].name);
    printf("Enter new product quantity: ");
    scanf("%d", &products[index].quantity);
    printf("Enter new product price: ");
    scanf("%f", &products[index].price);
    printf("Product updated successfully!\n");
}

void sell_product(int index) {
    int quantity;
    printf("\nSelling Product %d:\n", index+1);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    if(quantity > products[index].quantity) {
        printf("Not enough inventory.\n");
        return;
    }
    products[index].quantity -= quantity;
    printf("Transaction successful.\n");
}

int main() {
    int choice, product_index;
    while(1) {
        printf("\n---Product Inventory System---\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Product\n");
        printf("4. Sell Product\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                printf("Enter product index: ");
                scanf("%d", &product_index);
                if(product_index < 1 || product_index > num_products) {
                    printf("Invalid index.\n");
                    break;
                }
                update_product(product_index-1);
                break;
            case 4:
                printf("Enter product index: ");
                scanf("%d", &product_index);
                if(product_index < 1 || product_index > num_products) {
                    printf("Invalid index.\n");
                    break;
                }
                sell_product(product_index-1);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }   
    }
    return 0;
}