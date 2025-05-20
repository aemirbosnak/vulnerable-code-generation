//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the product inventory item
struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Declare functions for adding and updating items
void addProduct(struct Product* inventory, int size);
void updateProduct(struct Product* inventory, int size);

// Main function
int main() {
    int inventorySize = 0;
    struct Product* inventory = NULL;
    
    // Prompt user to enter the size of the inventory
    printf("Enter the size of the product inventory: ");
    scanf("%d", &inventorySize);
    
    // Allocate memory for the inventory
    inventory = (struct Product*) malloc(inventorySize * sizeof(struct Product));
    
    // Menu system loop
    int choice = 0;
    do {
        printf("\nProduct Inventory System\n");
        printf("-------------------------\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. View Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addProduct(inventory, inventorySize);
                break;
            case 2:
                updateProduct(inventory, inventorySize);
                break;
            case 3:
                printf("\n\n");
                printf("Product ID\tProduct Name\tQuantity\tPrice\n");
                for(int i=0; i<inventorySize; i++) {
                    printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
                printf("\n\n");
                break;
            case 4:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    } while(choice != 4);
    
    // Free memory allocated for inventory
    free(inventory);
    
    return 0;
}

// Function to add a new product to the inventory
void addProduct(struct Product* inventory, int size) {
    int i;
    for(i=0; i<size; i++) {
        if(inventory[i].id == 0) {
            break;
        }
    }
    if(i == size) {
        printf("Inventory is full!\n\n");
        return;
    }
    
    // Prompt user to enter details of the new product
    printf("\nEnter details of new product:\n");
    printf("Product ID: ");
    scanf("%d", &inventory[i].id);
    printf("Product Name: ");
    scanf("%s", inventory[i].name);
    printf("Quantity: ");
    scanf("%d", &inventory[i].quantity);
    printf("Price: ");
    scanf("%f", &inventory[i].price);
    
    printf("\nProduct added successfully!\n\n");
}

// Function to update an existing product in the inventory
void updateProduct(struct Product* inventory, int size) {
    int id, i;
    printf("\nEnter the ID of the product to update: ");
    scanf("%d", &id);
    
    for(i=0; i<size; i++) {
        if(inventory[i].id == id) {
            break;
        }
    }
    if(i == size) {
        printf("ID not found!\n\n");
        return;
    }
    
    // Prompt user to enter updated details of the product
    printf("\nEnter updated details of the product:\n");
    printf("Product Name: ");
    scanf("%s", inventory[i].name);
    printf("Quantity: ");
    scanf("%d", &inventory[i].quantity);
    printf("Price: ");
    scanf("%f", &inventory[i].price);
    
    printf("\nProduct updated successfully!\n\n");
}