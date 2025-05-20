//FormAI DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

void addProduct(product **inventory, int *n);
void displayInventory(product *inventory, int n);
void updateProduct(product *inventory, int n);
void deleteProduct(product **inventory, int *n);

int main() {
    int choice, n = 0;
    product *inventory = NULL;

    do {
        printf("\n\nPRODUCT INVENTORY SYSTEM\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(&inventory, &n);
                break;
            case 2:
                displayInventory(inventory, n);
                break;
            case 3:
                updateProduct(inventory, n);
                break;
            case 4:
                deleteProduct(&inventory, &n);
                break;
            case 5:
                printf("\nInventory System Closing...\n");
                break;
            default:
                printf("\nInvalid Choice! Try Again!\n\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

void addProduct(product **inventory, int *n) {
    *inventory = (product*) realloc(*inventory, (*n+1) * sizeof(product));
    if(*inventory == NULL) {
        printf("\nUnable to allocate memory!\n");
        return;
    }

    product new_product;

    printf("\nEnter Product Name: ");
    scanf("%s", new_product.name);
    printf("Enter Product Quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter Product Price: ");
    scanf("%f", &new_product.price);

    (*inventory)[*n] = new_product;
    (*n)++;

    printf("\nProduct added successfully!\n");
}

void displayInventory(product *inventory, int n) {
    if(n == 0) {
        printf("\nInventory is empty!\n");
        return;
    }

    printf("\n%-10s %-10s %-10s\n", "Name", "Quantity", "Price");

    for(int i=0; i<n; i++) {
        printf("%-10s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct(product *inventory, int n) {
    if(n == 0) {
        printf("\nInventory is empty!\n");
        return;
    }

    char search_name[50];
    int product_found = 0;

    printf("\nEnter Product Name to Update: ");
    scanf("%s", search_name);

    for(int i=0; i<n; i++) {
        if(strcmp(inventory[i].name, search_name) == 0) {
            printf("\nEnter new Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new Price: ");
            scanf("%f", &inventory[i].price);

            product_found = 1;
            printf("\nProduct updated successfully!\n");
            break;
        }
    }

    if(!product_found) {
        printf("\nProduct Not Found!\n");
    }
}

void deleteProduct(product **inventory, int *n) {
    if(*n == 0) {
        printf("\nInventory is empty!\n");
        return;
    }

    char search_name[50];
    int product_found = 0;

    printf("\nEnter Product Name to Delete: ");
    scanf("%s", search_name);

    for(int i=0; i<*n; i++) {
        if(strcmp((*inventory)[i].name, search_name) == 0) {
            for(int j=i; j<(*n)-1; j++) {
                (*inventory)[j] = (*inventory)[j+1];
            }

            *inventory = (product*) realloc(*inventory, (*n-1) * sizeof(product));
            (*n)--;

            product_found = 1;
            printf("\nProduct deleted successfully!\n");
            break;
        }
    }

    if(!product_found) {
        printf("\nProduct Not Found!\n");
    }
}