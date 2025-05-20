//FormAI DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <string.h>

struct product {
    char name[20];
    int id;
    float price;
    int quantity;
};

void addProduct(struct product [], int *);
void deleteProduct(struct product [], int *);
void searchProduct(struct product [], int *);
void displayInventory(struct product [], int *);

int main() {
    int option, count;
    struct product inventory[100];
    
    count = 0;
    
    do {
        printf("\nPRODUCT INVENTORY SYSTEM\n");
        printf("1. Add a new product\n");
        printf("2. Delete a product\n");
        printf("3. Search for a product\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");
        printf("Enter your option (1-5): ");
        scanf("%d", &option);
        printf("\n");
        
        switch(option) {
            case 1: addProduct(inventory, &count);
                break;
            case 2: deleteProduct(inventory, &count);
                break;
            case 3: searchProduct(inventory, &count);
                break;
            case 4: displayInventory(inventory, &count);
                break;
            case 5: printf("Exiting program...\n");
                break;
            default: printf("Invalid option\n");
        }
        
    } while(option != 5);
    
    return 0;
}

void addProduct(struct product inventory[], int *count) {
    struct product newProduct;
    
    printf("Enter the name of the product: ");
    scanf("%s", newProduct.name);
    printf("Enter the ID of the product: ");
    scanf("%d", &newProduct.id);
    printf("Enter the price of the product: ");
    scanf("%f", &newProduct.price);
    printf("Enter the quantity of the product: ");
    scanf("%d", &newProduct.quantity);
    
    inventory[*count] = newProduct;
    *count += 1;
    printf("Product added successfully!\n");
}

void deleteProduct(struct product inventory[], int *count) {
    int id, i, found;
    
    printf("Enter the ID of the product to delete: ");
    scanf("%d", &id);
    
    found = 0;
    for(i = 0; i < *count; i++) {
        if(inventory[i].id == id) {
            found = 1;
            break;
        }
    }
    
    if(found) {
        inventory[i] = inventory[*count-1];
        *count -= 1;
        printf("Product deleted successfully!\n");
    } else {
        printf("Product not found\n");
    }
}

void searchProduct(struct product inventory[], int *count) {
    int id, i, found;
    
    printf("Enter the ID of the product to search: ");
    scanf("%d", &id);
    
    found = 0;
    for(i = 0; i < *count; i++) {
        if(inventory[i].id == id) {
            found = 1;
            printf("Product found:\n");
            printf("Name: %s\n", inventory[i].name);
            printf("ID: %d\n", inventory[i].id);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            break;
        }
    }
    
    if(!found) {
        printf("Product not found\n");
    }
}

void displayInventory(struct product inventory[], int *count) {
    int i;
    
    if(*count == 0) {
        printf("Inventory is empty\n");
    } else {
        printf("PRODUCT INVENTORY\n");
        printf("%-20s %-10s %-10s %-10s\n", "Name", "ID", "Price", "Quantity");
        for(i = 0; i < *count; i++) {
            printf("%-20s %-10d %-10.2f %-10d\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity);
        }
    }
}