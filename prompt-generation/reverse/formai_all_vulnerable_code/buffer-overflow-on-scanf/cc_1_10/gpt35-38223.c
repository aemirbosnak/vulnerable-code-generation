//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50

typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

void add_product(Product products[], int *count) {
    Product p;
    printf("\nEnter ID: ");
    scanf("%d", &p.id);
    getchar();
    printf("Enter Name: ");
    fgets(p.name, 50, stdin);
    printf("Enter Price: ");
    scanf("%f", &p.price);
    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    products[*count] = p;
    *count += 1;
}

void view_products(Product products[], int count) {
    printf("\n----- Products -----\n");
    printf("| ID | Name                     | Price | Quantity |\n");
    for(int i = 0; i < count; i++) {
        printf("| %-2d | %-23s | %.2f | %-2d |\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("----------------------\n");
}

int find_product(Product products[], int count, int id) {
    for(int i = 0; i < count; i++) {
        if(products[i].id == id) {
            return i;
        }
    }
    return -1;
}

void update_product(Product products[], int count) {
    int id, index;
    printf("\nEnter ID to update: ");
    scanf("%d", &id);
    getchar();
    index = find_product(products, count, id);
    if(index == -1) {
        printf("Product not found!\n");
        return;
    }
    Product p;
    printf("Enter Name: ");
    fgets(p.name, 50, stdin);
    printf("Enter Price: ");
    scanf("%f", &p.price);
    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    products[index] = p;
}

void delete_product(Product products[], int *count) {
    int id, index;
    printf("\nEnter ID to delete: ");
    scanf("%d", &id);
    index = find_product(products, *count, id);
    if(index == -1) {
        printf("Product not found!\n");
        return;
    }
    for(int i = index; i < *count - 1; i++) {
        products[i] = products[i + 1];
    }
    *count -= 1;
}

void print_menu() {
    printf("\n===== Product Inventory System =====\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
}

int main() {
    int choice, count = 0;
    Product products[MAX_PRODUCTS];
    while(1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_product(products, &count);
                    break;
            case 2: view_products(products, count);
                    break;
            case 3: update_product(products, count);
                    break;
            case 4: delete_product(products, &count);
                    break;
            case 5: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}