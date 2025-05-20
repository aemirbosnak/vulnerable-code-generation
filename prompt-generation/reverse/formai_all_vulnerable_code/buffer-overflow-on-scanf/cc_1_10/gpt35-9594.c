//FormAI DATASET v1.0 Category: Product Inventory System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    int id;
    char name[20];
    int quantity;
    float price;
};

void addProduct(struct product products[], int *size);
void viewInventory(struct product products[], int size);
void removeProduct(struct product products[], int *size);
void updateProduct(struct product products[], int size);

int main() {
    struct product products[MAX_PRODUCTS];
    int size = 0;
    int choice;
    
    do {
        printf("\n******************************\n");
        printf("PRODUCT INVENTORY MANAGEMENT SYSTEM\n");
        printf("******************************\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Remove Product\n");
        printf("4. Update Product\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addProduct(products, &size);
                break;
            case 2:
                viewInventory(products, size);
                break;
            case 3:
                removeProduct(products, &size);
                break;
            case 4:
                updateProduct(products, size);
                break;
            case 5:
                printf("\nExiting Program...");
                break;
            default:
                printf("\nInvalid choice. Try again.");
                break;
        }
    } while(choice != 5);
    
    return 0;
}

void addProduct(struct product products[], int *size) {
    if (*size >= MAX_PRODUCTS) {
        printf("\nInventory is full. Cannot add more products.\n");
        return;
    }
    
    struct product newProduct;
    printf("\nEnter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    newProduct.id = *size + 1;
    products[*size] = newProduct;
    *size += 1;
    
    printf("\nProduct added successfully!\n");
}

void viewInventory(struct product products[], int size) {
    if (size == 0) {
        printf("\nInventory is currently empty.\n");
        return;
    }
    
    printf("\nID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void removeProduct(struct product products[], int *size) {
    if (*size == 0) {
        printf("\nInventory is currently empty.\n");
        return;
    }
    
    int id;
    printf("\nEnter ID of product to remove: ");
    scanf("%d", &id);
    
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\nProduct with ID %d not found.\n", id);
        return;
    }
    
    for (int i = index; i < *size-1; i++) {
        products[i] = products[i+1];
        products[i].id = i+1;
    }
    *size -= 1;
    
    printf("\nProduct removed successfully!\n");
}

void updateProduct(struct product products[], int size) {
    if (size == 0) {
        printf("\nInventory is currently empty.\n");
        return;
    }
    
    int id;
    printf("\nEnter ID of product to update: ");
    scanf("%d", &id);
    
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\nProduct with ID %d not found.\n", id);
        return;
    }
    
    struct product updatedProduct;
    printf("\nEnter updated name or press Enter to keep original name: ");
    fgets(updatedProduct.name, 20, stdin);
    if (strlen(updatedProduct.name) == 1) {
        // fgets() captured only the Enter key, so product name does not need to be updated
        updatedProduct.name[strlen(updatedProduct.name)-1] = '\0';
    } else {
        // Remove newline character from fgets() capture
        updatedProduct.name[strlen(updatedProduct.name)-1] = '\0';
    }
    
    printf("Enter updated quantity or press 0 to keep original quantity: ");
    scanf("%d", &updatedProduct.quantity);
    
    printf("Enter updated price or press 0.00 to keep original price: ");
    scanf("%f", &updatedProduct.price);
    
    if (strlen(updatedProduct.name) > 0) {
        strcpy(products[index].name, updatedProduct.name);
    }
    if (updatedProduct.quantity > 0) {
        products[index].quantity = updatedProduct.quantity;
    }
    if (updatedProduct.price > 0.00) {
        products[index].price = updatedProduct.price;
    }
    
    printf("\nProduct updated successfully!\n");
}