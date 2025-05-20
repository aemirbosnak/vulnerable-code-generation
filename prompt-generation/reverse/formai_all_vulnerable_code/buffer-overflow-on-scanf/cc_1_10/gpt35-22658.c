//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[50];
    int quantity;
    float price;
};

struct Warehouse {
    struct Product products[MAX_PRODUCTS];
    int count;
};

void display_menu() {
    printf("==== Warehouse Management System ====\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update product quantity\n");
    printf("4. Update product price\n");
    printf("5. Display all products\n");
    printf("6. Exit\n");
}

void add_product(struct Warehouse *w) {
    if (w->count >= MAX_PRODUCTS) {
        printf("Error: warehouse is full\n");
        return;
    }
    
    struct Product new_product;
    printf("Enter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);
    
    w->products[w->count] = new_product;
    w->count++;
    
    printf("Product added successfully\n");
}

void remove_product(struct Warehouse *w) {
    char product_name[50];
    int found = 0;
    
    printf("Enter product name to remove: ");
    scanf("%s", product_name);
    
    for (int i = 0; i < w->count; i++) {
        if (strcmp(w->products[i].name, product_name) == 0) {
            found = 1;
            w->count--;
            w->products[i] = w->products[w->count];
            printf("Product removed successfully\n");
            break;
        }
    }
    
    if (!found) {
        printf("Error: product not found\n");
    }
}

void update_product_quantity(struct Warehouse *w) {
    char product_name[50];
    int new_quantity, found = 0;
    
    printf("Enter product name to update quantity: ");
    scanf("%s", product_name);
    
    for (int i = 0; i < w->count; i++) {
        if (strcmp(w->products[i].name, product_name) == 0) {
            found = 1;
            printf("Enter new quantity: ");
            scanf("%d", &new_quantity);
            w->products[i].quantity = new_quantity;
            printf("Product quantity updated successfully\n");
            break;
        }
    }
    
    if (!found) {
        printf("Error: product not found\n");
    }
}

void update_product_price(struct Warehouse *w) {
    char product_name[50];
    float new_price;
    int found = 0;
    
    printf("Enter product name to update price: ");
    scanf("%s", product_name);
    
    for (int i = 0; i < w->count; i++) {
        if (strcmp(w->products[i].name, product_name) == 0) {
            found = 1;
            printf("Enter new price: ");
            scanf("%f", &new_price);
            w->products[i].price = new_price;
            printf("Product price updated successfully\n");
            break;
        }
    }
    
    if (!found) {
        printf("Error: product not found\n");
    }
}

void display_products(struct Warehouse w) {
    printf("==== Products ====\n");
    for (int i = 0; i < w.count; i++) {
        printf("%s: %d units, $%.2f each\n", w.products[i].name, w.products[i].quantity, w.products[i].price);
    }
}

int main() {
    struct Warehouse warehouse;
    warehouse.count = 0;
    
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_product(&warehouse);
                break;
            case 2:
                remove_product(&warehouse);
                break;
            case 3:
                update_product_quantity(&warehouse);
                break;
            case 4:
                update_product_price(&warehouse);
                break;
            case 5:
                display_products(warehouse);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}