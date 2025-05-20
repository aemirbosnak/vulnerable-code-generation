//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;
pthread_mutex_t inventoryMutex;

void* addProduct(void* arg) {
    Product* newProduct = (Product*)arg;

    pthread_mutex_lock(&inventoryMutex);
    if (productCount < MAX_PRODUCTS) {
        inventory[productCount] = *newProduct;
        productCount++;
        printf("Added product: %s, Quantity: %d\n", newProduct->name, newProduct->quantity);
    } else {
        printf("Inventory is full! Cannot add more products.\n");
    }
    pthread_mutex_unlock(&inventoryMutex);
    
    return NULL;
}

void* removeProduct(void* arg) {
    char* productName = (char*)arg;
    
    pthread_mutex_lock(&inventoryMutex);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            printf("Removed product: %s, Quantity: %d\n", inventory[i].name, inventory[i].quantity);
            // Shift the products left
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            break;
        }
    }
    pthread_mutex_unlock(&inventoryMutex);
    
    return NULL;
}

void* viewInventory(void* arg) {
    pthread_mutex_lock(&inventoryMutex);
    printf("Current Inventory:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Product: %s, Quantity: %d\n", inventory[i].name, inventory[i].quantity);
    }
    pthread_mutex_unlock(&inventoryMutex);
    
    return NULL;
}

int main() {
    pthread_mutex_init(&inventoryMutex, NULL);
    pthread_t threads[100];
    int choice;
    
    while (1) {
        printf("\n1. Add Product\n2. Remove Product\n3. View Inventory\n4. Exit\nChoose an action: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            Product* newProduct = malloc(sizeof(Product));
            printf("Enter product name: ");
            scanf("%s", newProduct->name);
            printf("Enter product quantity: ");
            scanf("%d", &(newProduct->quantity));
            pthread_create(&threads[productCount], NULL, addProduct, (void*)newProduct);
        } else if (choice == 2) {
            char* productName = malloc(MAX_NAME_LEN);
            printf("Enter product name to remove: ");
            scanf("%s", productName);
            pthread_create(&threads[productCount], NULL, removeProduct, (void*)productName);
        } else if (choice == 3) {
            pthread_create(&threads[productCount], NULL, viewInventory, NULL);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
        
        for (int i = 0; i < productCount; i++) {
            pthread_join(threads[i], NULL);
        }
    }
    
    pthread_mutex_destroy(&inventoryMutex);
    return 0;
}