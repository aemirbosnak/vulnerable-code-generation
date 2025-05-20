//FormAI DATASET v1.0 Category: Product Inventory System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Inventory {
    struct Product products[MAX_PRODUCTS];
    int count;
};

// function prototypes
void addProduct(struct Inventory* inventory);
void removeProduct(struct Inventory* inventory, int productId);
void updateProduct(struct Inventory* inventory, int productId);
void displayInventory(struct Inventory* inventory);
bool isProductIdExists(struct Inventory* inventory, int productId);

int main() {
    struct Inventory inventory;
    inventory.count = 0;
    int choice;

    do {
        printf("\nInventory Management System\n");
        printf("------------------------------------\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Update a product\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                if(inventory.count == 0) {
                    printf("Inventory is empty!\n");
                } else {
                    int productId;
                    printf("\nEnter product id to remove: ");
                    scanf("%d", &productId);

                    if(isProductIdExists(&inventory, productId)) {
                        removeProduct(&inventory, productId);
                    } else {
                        printf("Product id not found!\n");
                    }
                }
                break;
            case 3:
                if(inventory.count == 0) {
                    printf("Inventory is empty!\n");
                } else {
                    int productId;
                    printf("\nEnter product id to update: ");
                    scanf("%d", &productId);

                    if(isProductIdExists(&inventory, productId)) {
                        updateProduct(&inventory, productId);
                    } else {
                        printf("Product id not found!\n");
                    }
                }
                break;
            case 4:
                displayInventory(&inventory);
                break;
            case 5:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("\nInvalid choice. Please enter valid choice.\n");
        }
    } while(choice != 5);

    return 0;
}

void addProduct(struct Inventory* inventory) {
    if(inventory->count == MAX_PRODUCTS) {
        printf("Inventory is full!\n");
    } else {
        struct Product product;
        printf("\nEnter product details:\n");
        printf("Product Id: ");
        scanf("%d", &product.id);

        if(isProductIdExists(inventory, product.id)) {
            printf("Product Id already exists!\n");
            return;
        }

        printf("Product Name: ");
        scanf("%s", product.name);

        printf("Product Price: ");
        scanf("%f", &product.price);

        printf("Product Quantity: ");
        scanf("%d", &product.quantity);

        inventory->products[inventory->count] = product;
        inventory->count++;
        printf("\nProduct added successfully!\n");
    }
}

void removeProduct(struct Inventory* inventory, int productId) {
    int i, index = -1;

    for(i = 0; i < inventory->count; i++) {
        if(inventory->products[i].id == productId) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Product id not found!\n");
    } else {
        for(i = index; i < inventory->count - 1; i++) {
            inventory->products[i] = inventory->products[i + 1];
        }

        inventory->count--;
        printf("\nProduct removed successfully!\n");
    }
}

void updateProduct(struct Inventory* inventory, int productId) {
    int i, index = -1;

    for(i = 0; i < inventory->count; i++) {
        if(inventory->products[i].id == productId) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Product id not found!\n");
    } else {
        struct Product product;
        printf("\nEnter updated product details:\n");
        printf("Product Name: ");
        scanf("%s", product.name);

        printf("Product Price: ");
        scanf("%f", &product.price);

        printf("Product Quantity: ");
        scanf("%d", &product.quantity);

        inventory->products[index] = product;
        printf("\nProduct updated successfully!\n");
    }
}

void displayInventory(struct Inventory* inventory) {
    if(inventory->count == 0) {
        printf("\nInventory is empty!\n");
    } else {
        int i;
        printf("\n%-10s %-20s %-10s %-10s\n", "Id", "Name", "Price", "Quantity");
        printf("-------------------------------------------------------------\n");

        for(i = 0; i < inventory->count; i++) {
            struct Product product = inventory->products[i];
            printf("%-10d %-20s %-10.2f %-10d\n", product.id, product.name, product.price, product.quantity);
        }
    }
}

bool isProductIdExists(struct Inventory* inventory, int productId) {
    int i;

    for(i = 0; i < inventory->count; i++) {
        if(inventory->products[i].id == productId) {
            return true;
        }
    }

    return false;
}