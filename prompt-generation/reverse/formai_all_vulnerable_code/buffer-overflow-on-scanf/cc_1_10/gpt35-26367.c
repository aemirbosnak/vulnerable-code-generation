//FormAI DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define structure for product inventory */
struct Product {
    char prod_name[50];
    int prod_id;
    float prod_price;
    int prod_qty;
};
typedef struct Product Product;

/* Declare global variables */
Product invent[100];
int prod_count = 0;

/* Function declarations */
void addProduct();
void updateProduct();
void deleteProduct();
void searchProduct();
void displayInventory();

/* Main function */
int main() {
    int choice;
    do {
        printf("\nPRODUCT INVENTORY SYSTEM\n");
        printf("1 - Add product\n");
        printf("2 - Update product\n");
        printf("3 - Delete product\n");
        printf("4 - Search product\n");
        printf("5 - Display inventory\n");
        printf("0 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                searchProduct();
                break;
            case 5:
                displayInventory();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}

/* Function to add product to inventory */
void addProduct() {
    if (prod_count < 100) {
        Product new_prod;
        printf("Enter product name: ");
        scanf("%s", &new_prod.prod_name);
        printf("Enter product ID: ");
        scanf("%d", &new_prod.prod_id);
        printf("Enter product price: ");
        scanf("%f", &new_prod.prod_price);
        printf("Enter product quantity: ");
        scanf("%d", &new_prod.prod_qty);
        invent[prod_count] = new_prod;
        prod_count++;
        printf("Product added successfully.\n");
    } else {
        printf("Inventory full. Cannot add more products.\n");
    }
}

/* Function to update product in inventory */
void updateProduct() {
    int search_id, i, found=0;
    printf("Enter product ID to update: ");
    scanf("%d", &search_id);
    for (i=0; i<prod_count; i++) {
        if (invent[i].prod_id == search_id) {
            printf("Enter updated product name: ");
            scanf("%s", &invent[i].prod_name);
            printf("Enter updated product price: ");
            scanf("%f", &invent[i].prod_price);
            printf("Enter updated product quantity: ");
            scanf("%d", &invent[i].prod_qty);
            found = 1;
            printf("Product updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

/* Function to delete product from inventory */
void deleteProduct() {
    int search_id, i, found=0;
    printf("Enter product ID to delete: ");
    scanf("%d", &search_id);
    for (i=0; i<prod_count; i++) {
        if (invent[i].prod_id == search_id) {
            while (i < prod_count-1) {
                invent[i] = invent[i+1];
                i++;
            }
            prod_count--;
            found = 1;
            printf("Product deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

/* Function to search for product in inventory */
void searchProduct() {
    int search_id, i, found=0;
    printf("Enter product ID to search: ");
    scanf("%d", &search_id);
    for (i=0; i<prod_count; i++) {
        if (invent[i].prod_id == search_id) {
            found = 1;
            printf("Product ID: %d\n", invent[i].prod_id);
            printf("Product name: %s\n", invent[i].prod_name);
            printf("Product price: $%.2f\n", invent[i].prod_price);
            printf("Product quantity: %d\n", invent[i].prod_qty);
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

/* Function to display inventory */
void displayInventory() {
    int i;
    printf("| %-4s | %-20s | %-10s | %-8s |\n", "ID", "Name", "Price", "Quantity");
    printf("+------+----------------------+------------+----------+\n");
    for (i=0; i<prod_count; i++) {
        printf("| %-4d | %-20s | $%-8.2f | %-8d |\n", invent[i].prod_id, invent[i].prod_name, invent[i].prod_price, invent[i].prod_qty);
    }
    printf("+------+----------------------+------------+----------+\n");
}