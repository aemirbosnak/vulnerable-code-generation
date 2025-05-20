//FormAI DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000

typedef struct {
    int product_id;
    char name[50];
    int quantity;
    float price;
} Product;

int menu_choice();
void add_product(Product *inventory, int *num_products);
void remove_product(Product *inventory, int *num_products);
void view_inventory(Product *inventory, int num_products);
void save_inventory(Product *inventory, int num_products);

int main() {
    Product inventory[MAX_PRODUCTS];
    int num_products = 0;
    int choice;
    
    while (1) {
        choice = menu_choice();
        switch (choice) {
            case 1:
                add_product(inventory, &num_products);
                break;
            case 2:
                remove_product(inventory, &num_products);
                break;
            case 3:
                view_inventory(inventory, num_products);
                break;
            case 4:
                save_inventory(inventory, num_products);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

int menu_choice() {
    int choice;
    printf("\nProduct Inventory System\n");
    printf("========================\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. View Inventory\n");
    printf("4. Save and Quit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void add_product(Product *inventory, int *num_products) {
    if (*num_products == MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    
    Product new_product;
    printf("\nAdd Product\n");
    printf("============\n");
    printf("Product ID: ");
    scanf("%d", &new_product.product_id);
    printf("Name: ");
    scanf("%s", new_product.name);
    printf("Quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Price: ");
    scanf("%f", &new_product.price);
    
    inventory[*num_products] = new_product;
    (*num_products)++;
    printf("\nProduct added successfully.\n");
}

void remove_product(Product *inventory, int *num_products) {
    int product_id;
    printf("\nRemove Product\n");
    printf("===============\n");
    printf("Product ID: ");
    scanf("%d", &product_id);
    
    int found = 0;
    for (int i = 0; i < *num_products; i++) {
        if (inventory[i].product_id == product_id) {
            found = 1;
            for (int j = i; j < *num_products-1; j++) {
                inventory[j] = inventory[j+1];
            }
            (*num_products)--;
            printf("\nProduct removed successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("\nProduct not found. Please try again.\n");
    }
}

void view_inventory(Product *inventory, int num_products) {
    printf("\nView Inventory\n");
    printf("===============\n");
    printf("Product ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-15d%-20s%-15d$%.2f\n", inventory[i].product_id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void save_inventory(Product *inventory, int num_products) {
    char filename[100];
    printf("\nEnter filename to save inventory: ");
    scanf("%s", filename);
    
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    fwrite(&num_products, sizeof(int), 1, fp);
    fwrite(inventory, sizeof(Product), num_products, fp);
    
    printf("Inventory saved successfully to %s.\n", filename);
    fclose(fp);
}