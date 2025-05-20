//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int id;
    char name[50];
    int quantity;
    struct Product *next;
} Product;

Product *head = NULL;

// Function to create a new product
Product* createProduct(int id, const char *name, int quantity) {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    newProduct->id = id;
    strcpy(newProduct->name, name);
    newProduct->quantity = quantity;
    newProduct->next = NULL;
    return newProduct;
}

// Function to add a product to the warehouse
void addProduct(int id, const char *name, int quantity) {
    Product *newProduct = createProduct(id, name, quantity);
    if (head == NULL) {
        head = newProduct;
    } else {
        Product *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newProduct;
    }
    printf("Product added: %s (ID: %d, Quantity: %d)\n", name, id, quantity);
}

// Function to delete a product by ID
void deleteProduct(int id) {
    Product *temp = head;
    Product *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Product with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Product with ID %d deleted.\n", id);
}

// Function to display all products
void displayProducts() {
    Product *temp = head;
    if (temp == NULL) {
        printf("No products in warehouse.\n");
        return;
    }
    printf("Products in Warehouse:\n");
    printf("ID\tName\t\tQuantity\n");
    printf("--------------------------------\n");
    while (temp != NULL) {
        printf("%d\t%s\t\t%d\n", temp->id, temp->name, temp->quantity);
        temp = temp->next;
    }
}

// Function to free all products
void freeProducts() {
    Product *temp = head;
    while (temp != NULL) {
        Product *next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}

// Main function
int main() {
    int choice, id, quantity;
    char name[50];

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Display Products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Product ID: ");
                scanf("%d", &id);
                printf("Enter Product Name: ");
                scanf("%s", name);
                printf("Enter Product Quantity: ");
                scanf("%d", &quantity);
                addProduct(id, name, quantity);
                break;

            case 2:
                printf("Enter Product ID to delete: ");
                scanf("%d", &id);
                deleteProduct(id);
                break;

            case 3:
                displayProducts();
                break;

            case 4:
                freeProducts();
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}