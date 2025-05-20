//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCT_COUNT 100
#define MAX_PRODUCT_NAME_LENGTH 20

typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

void printInventory(Product* inventory, int productCount) {
    for(int i=0; i<productCount; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int searchInventory(Product* inventory, int productCount, char* productName) {
    for(int i=0; i<productCount; i++) {
        if(strcmp(inventory[i].name, productName) == 0) {
            return i;
        }
    }
    return -1;
}

void addProduct(Product* inventory, int* productCount) {
    if(*productCount == MAX_PRODUCT_COUNT) {
        printf("Inventory is full!\n");
        return;
    }

    char name[MAX_PRODUCT_NAME_LENGTH];
    printf("Enter product name: ");
    scanf("%s", name);

    int quantity;
    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    int index = searchInventory(inventory, *productCount, name);
    if(index != -1) {
        inventory[index].quantity += quantity;
    } else {
        Product newProduct;
        strcpy(newProduct.name, name);
        newProduct.quantity = quantity;
        inventory[*productCount] = newProduct;
        (*productCount)++;
    }

    printf("Product added.\n");
}

void removeProduct(Product* inventory, int* productCount) {
    if(*productCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    char name[MAX_PRODUCT_NAME_LENGTH];
    printf("Enter product name: ");
    scanf("%s", name);

    int index = searchInventory(inventory, *productCount, name);
    if(index == -1) {
        printf("Product not found!\n");
    } else {
        int quantity;
        printf("Enter quantity to remove: ");
        scanf("%d", &quantity);

        if(quantity >= inventory[index].quantity) {
            for(int i=index; i<*productCount-1; i++) {
                inventory[i] = inventory[i+1];
            }
            (*productCount)--;
        } else {
            inventory[index].quantity -= quantity;
        }

        printf("Product removed.\n");
    }
}

int main() {
    Product inventory[MAX_PRODUCT_COUNT];
    int productCount = 0;

    char action;
    while(1) {
        printf("Inventory System\n");
        printf("A - Add a product\n");
        printf("R - Remove a product\n");
        printf("P - Print inventory\n");
        printf("Q - Quit\n");
        printf("Enter action: ");
        scanf(" %c", &action);

        switch(action) {
            case 'A':
                addProduct(inventory, &productCount);
                break;
            case 'R':
                removeProduct(inventory, &productCount);
                break;
            case 'P':
                printInventory(inventory, productCount);
                break;
            case 'Q':
                exit(0);
                break;
            default:
                printf("Invalid action!\n");
                break;
        }
    }

    return 0;
}