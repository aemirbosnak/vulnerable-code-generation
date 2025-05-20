//FormAI DATASET v1.0 Category: Product Inventory System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define product structure
struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Define global variables
struct product inventory[100];
int num_of_products = 0;

// Function prototypes
void add_product();
void edit_product();
void delete_product();
void view_inventory();
void save_inventory();

int main() {

    // Load inventory data from file
    FILE *fp;
    fp = fopen("inventory.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
    } else {
        while (!feof(fp)) {
            fscanf(fp, "%d\t%s\t%d\t%f\n", &inventory[num_of_products].id, inventory[num_of_products].name, &inventory[num_of_products].quantity, &inventory[num_of_products].price);
            num_of_products++;
        }
        fclose(fp);
    }

    // Display menu
    int choice;
    do {
        printf("Product Inventory System\n");
        printf("------------------------\n");
        printf("1. Add Product\n");
        printf("2. Edit Product\n");
        printf("3. Delete Product\n");
        printf("4. View Inventory\n");
        printf("0. Save and Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                edit_product();
                break;
            case 3:
                delete_product();
                break;
            case 4:
                view_inventory();
                break;
            case 0:
                save_inventory();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");

    } while (choice != 0);

    return 0;
}

void add_product() {
    // Check if inventory is full
    if (num_of_products >= 100) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    // Get product details from user
    printf("Enter Product Details:\n");
    printf("ID: ");
    scanf("%d", &inventory[num_of_products].id);
    printf("Name: ");
    scanf("%s", inventory[num_of_products].name);
    printf("Quantity: ");
    scanf("%d", &inventory[num_of_products].quantity);
    printf("Price: ");
    scanf("%f", &inventory[num_of_products].price);

    // Increment product count
    num_of_products++;

    printf("Product added successfully.\n");
}

void edit_product() {
    // Get product ID from user
    int id;
    printf("Enter Product ID: ");
    scanf("%d", &id);

    // Find product by ID
    int i;
    for (i = 0; i < num_of_products; i++) {
        if (inventory[i].id == id) {
            break;
        }
    }

    // Check if product was found
    if (i == num_of_products) {
        printf("Product not found.\n");
        return;
    }

    // Edit product details
    printf("Enter new Product Details:\n");
    printf("Name: ");
    scanf("%s", inventory[i].name);
    printf("Quantity: ");
    scanf("%d", &inventory[i].quantity);
    printf("Price: ");
    scanf("%f", &inventory[i].price);

    printf("Product edited successfully.\n");
}

void delete_product() {
    // Get product ID from user
    int id;
    printf("Enter Product ID: ");
    scanf("%d", &id);

    // Find product by ID
    int i;
    for (i = 0; i < num_of_products; i++) {
        if (inventory[i].id == id) {
            break;
        }
    }

    // Check if product was found
    if (i == num_of_products) {
        printf("Product not found.\n");
        return;
    }

    // Remove product from inventory
    for (int j = i; j < num_of_products - 1; j++) {
        inventory[j] = inventory[j+1];
    }
    num_of_products--;

    printf("Product deleted successfully.\n");
}

void view_inventory() {
    // Display inventory details
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_of_products; i++) {
        printf("%-10d %-20s %-10d %-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}

void save_inventory() {
    // Save inventory data to file
    FILE *fp;
    fp = fopen("inventory.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    } else {
        for (int i = 0; i < num_of_products; i++) {
            fprintf(fp, "%d\t%s\t%d\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
        printf("Inventory saved successfully.\n");
        fclose(fp);
    }
}