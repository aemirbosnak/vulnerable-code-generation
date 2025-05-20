//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int product_count = 0;

void add_product();
void display_products();
void update_product();
void delete_product();
void exit_program();

void clear_stdin() {
    while (getchar() != '\n');
}

void menu() {
    int choice;
    do {
        printf("\n----- Product Inventory System -----\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_stdin();

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                exit_program();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Cannot add more products. Inventory is full.\n");
        return;
    }

    Product p;
    p.id = product_count + 1;

    printf("Enter product name: ");
    fgets(p.name, NAME_LENGTH, stdin);
    strtok(p.name, "\n"); // Remove newline character

    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    clear_stdin();

    products[product_count] = p;
    product_count++;
    printf("Product added successfully!\n");
}

void display_products() {
    if (product_count == 0) {
        printf("No products available in the inventory.\n");
        return;
    }

    printf("\n----- Product List -----\n");
    for (int i = 0; i < product_count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               products[i].id, products[i].name,
               products[i].quantity, products[i].price);
    }
}

void update_product() {
    int id, found = 0;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);
    clear_stdin();

    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            found = 1;
            printf("Updating product: %s\n", products[i].name);

            printf("Enter new name (or '-' to keep unchanged): ");
            char new_name[NAME_LENGTH];
            fgets(new_name, NAME_LENGTH, stdin);
            if (strcmp(new_name, "-\n") != 0) {
                strtok(new_name, "\n");
                strcpy(products[i].name, new_name);
            }

            printf("Enter new quantity (or -1 to keep unchanged): ");
            int new_quantity;
            scanf("%d", &new_quantity);
            clear_stdin();
            if (new_quantity != -1) {
                products[i].quantity = new_quantity;
            }

            printf("Enter new price (or -1 to keep unchanged): ");
            float new_price;
            scanf("%f", &new_price);
            clear_stdin();
            if (new_price != -1) {
                products[i].price = new_price;
            }

            printf("Product updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product ID not found.\n");
    }
}

void delete_product() {
    int id, found = 0;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);
    clear_stdin();

    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) {
            found = 1;
            printf("Deleting product: %s\n", products[i].name);
            for (int j = i; j < product_count - 1; j++) {
                products[j] = products[j + 1];
            }
            product_count--;
            printf("Product deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product ID not found.\n");
    }
}

void exit_program() {
    printf("Exiting the program. Thank you!\n");
    exit(0);
}

int main() {
    menu();
    return 0;
}