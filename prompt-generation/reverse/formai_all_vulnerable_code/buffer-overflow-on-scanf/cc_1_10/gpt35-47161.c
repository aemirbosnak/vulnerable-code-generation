//FormAI DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 100

typedef struct product {
    int product_id;
    char product_name[100];
    float product_price;
    int product_quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    Product new_product;
    printf("Enter new product details:\n");
    printf("ID: ");
    scanf("%d", &new_product.product_id);
    printf("Name: ");
    scanf("%s", new_product.product_name);
    printf("Price: ");
    scanf("%f", &new_product.product_price);
    printf("Quantity: ");
    scanf("%d", &new_product.product_quantity);
    inventory[num_products++] = new_product;
    printf("Product added successfully!\n");
}

void display_all_products() {
    if(num_products == 0) {
        printf("No products in inventory!\n");
        return;
    }
    printf("Product Inventory:\n");
    printf("-------------------\n");
    printf("%-5s | %-20s | %-10s | %-10s\n", "ID", "Name", "Price", "Quantity");
    for(int i=0; i<num_products; i++) {
        printf("%-5d | %-20s | $%-9.2f | %-10d\n", 
        inventory[i].product_id, inventory[i].product_name, inventory[i].product_price, inventory[i].product_quantity);
    }
}

void search_product_by_id() {
    int search_id;
    printf("Enter product ID to search: ");
    scanf("%d", &search_id);
    for(int i=0; i<num_products; i++) {
        if(inventory[i].product_id == search_id) {
            printf("%-5s | %-20s | %-10s | %-10s\n", "ID", "Name", "Price", "Quantity");
            printf("%-5d | %-20s | $%-9.2f | %-10d\n", 
            inventory[i].product_id, inventory[i].product_name, inventory[i].product_price, inventory[i].product_quantity);
            return;
        }
    }
    printf("Product not found!\n");
}

void update_product() {
    int update_id, choice;
    printf("Enter product ID to update: ");
    scanf("%d", &update_id);
    for(int i=0; i<num_products; i++) {
        if(inventory[i].product_id == update_id) {
            printf("Enter the field to update:\n");
            printf("1. Name\n2. Price\n3. Quantity\n");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", inventory[i].product_name);
                    break;
                case 2:
                    printf("Enter new price: ");
                    scanf("%f", &inventory[i].product_price);
                    break;
                case 3:
                    printf("Enter new quantity: ");
                    scanf("%d", &inventory[i].product_quantity);
                    break;
                default:
                    printf("Invalid choice!\n");
                    return;
            }
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void delete_product() {
    int delete_id;
    printf("Enter product ID to delete: ");
    scanf("%d", &delete_id);
    for(int i=0; i<num_products; i++) {
        if(inventory[i].product_id == delete_id) {
            for(int j=i; j<num_products-1; j++) {
                inventory[j] = inventory[j+1];
            }
            num_products--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void menu() {
    printf("Product Inventory System\n");
    printf("------------------------\n");
    printf("1. Add Product\n2. Display All Products\n3. Search Product by ID\n4. Update Product\n5. Delete Product\n6. Exit\n");
}

int main() {
    int choice;
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_all_products();
                break;
            case 3:
                search_product_by_id();
                break;
            case 4:
                update_product();
                break;
            case 5:
                delete_product();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 6);
    return 0;
}