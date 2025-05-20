//FormAI DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 50

typedef struct product {
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product inventory[], int *count) {
    if(*count < MAX_PRODUCTS) {
        printf("Enter product name: ");
        scanf("%s", inventory[*count].name);
        printf("Enter quantity: ");
        scanf("%d", &inventory[*count].quantity);
        printf("Enter price: ");
        scanf("%f", &inventory[*count].price);
        (*count)++;
    } else {
        printf("Inventory is full!\n");
    }
}

void displayInventory(Product inventory[], int count) {
    printf("Product Inventory:\n");
    for(int i = 0; i < count; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct(Product inventory[], int count) {
    char name[50];
    printf("Enter product name to update: ");
    scanf("%s", name);
    for(int i = 0; i < count; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            break;
        }
    }
}

void deleteProduct(Product inventory[], int* count) {
    char name[50];
    printf("Enter product name to delete: ");
    scanf("%s", name);
    for(int i = 0; i < *count; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            if(i == (*count - 1)) {
                (*count)--;
            } else {
                for(int j = i; j < (*count - 1); j++) {
                    inventory[j] = inventory[j+1];
                }
                (*count)--;
            }
            break;
        }
    }
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int choice, count = 0;
    do {
        printf("\n----- Product Inventory System -----\n");
        printf("1. Add a product\n");
        printf("2. Display inventory\n");
        printf("3. Update a product\n");
        printf("4. Delete a product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addProduct(inventory, &count);
                    break;
            case 2: displayInventory(inventory, count);
                    break;
            case 3: updateProduct(inventory, count);
                    break;
            case 4: deleteProduct(inventory, &count);
                    break;
            case 5: break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);
    return 0;
}