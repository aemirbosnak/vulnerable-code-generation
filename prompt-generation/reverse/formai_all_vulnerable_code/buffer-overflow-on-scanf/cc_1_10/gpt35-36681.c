//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for products
struct product {
    int id;
    char name[50];
    int quantity;
};

// Function prototypes
void addProduct(struct product* store, int* count);
void removeProduct(struct product* store, int* count);
void displayProducts(struct product* store, int count);

int main() {
    int option, count = 0;
    // Allocate memory for 100 products
    struct product* store = (struct product*)malloc(sizeof(struct product) * 100);
    
    // Menu loop
    do {
        printf("\n======Warehouse Management System======\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display all products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                addProduct(store, &count);
                break;
            case 2:
                removeProduct(store, &count);
                break;
            case 3:
                displayProducts(store, count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while(option != 4);
    
    free(store); // Free up memory
    return 0;
}

void addProduct(struct product* store, int* count) {
    struct product newProduct;
    printf("Enter the product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter the product name: ");
    scanf("%s", newProduct.name);
    printf("Enter the product quantity: ");
    scanf("%d", &newProduct.quantity);
    store[*count] = newProduct;
    (*count)++;
    printf("Product added successfully!\n");
}

void removeProduct(struct product* store, int* count) {
    int id, found = 0, index = -1;
    printf("Enter the product ID to remove: ");
    scanf("%d", &id);
    for(int i = 0; i < *count; i++) {
        if(store[i].id == id) {
            found = 1;
            index = i;
            break;
        }
    }
    if(found) {
        // Shifting products to the left
        for(int i = index; i < (*count - 1); i++) {
            store[i] = store[i + 1];
        }
        (*count)--;
        printf("Product removed successfully!\n");
    } else {
        printf("Product not found.\n");
    }
}

void displayProducts(struct product* store, int count) {
    printf("\n===================\n");
    printf("Warehouse Inventory:\n");
    printf("===================\n");
    printf("ID\tName\tQuantity\n");
    for(int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", store[i].id, store[i].name, store[i].quantity);
    }
    printf("===================\n");
}