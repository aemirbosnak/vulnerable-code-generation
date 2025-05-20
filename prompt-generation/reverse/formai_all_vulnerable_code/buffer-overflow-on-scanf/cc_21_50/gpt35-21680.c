//FormAI DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include <stdio.h>

#define MAX_PRODUCTS 100 // Maximum number of products in the inventory

struct Product {
    int id; // Unique product ID
    char name[50]; // Name of the product
    float price; // Price of the product
    int quantity; // Quantity of the product in the inventory
};

int main() {
    struct Product inventory[MAX_PRODUCTS]; // Array to hold the products in inventory
    int numProducts = 0; // Number of products currently in inventory
    
    // Loop to display menu and take user input
    while (1) {
        printf("Menu:\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product\n");
        printf("4. View Inventory\n");
        printf("5. Exit\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        // Switch statement to handle menu choices
        switch(choice) {
            case 1: // Add Product
                if (numProducts == MAX_PRODUCTS) {
                    printf("Inventory is full. Cannot add more products.\n");
                } else {
                    struct Product newProduct;
                    printf("Enter product ID: ");
                    scanf("%d", &newProduct.id);
                    
                    // Check if product ID already exists
                    int exists = 0;
                    for (int i = 0; i < numProducts; i++) {
                        if (inventory[i].id == newProduct.id) {
                            exists = 1;
                            break;
                        }
                    }
                    if (exists) {
                        printf("Product with ID %d already exists.\n", newProduct.id);
                        break;
                    }
                    
                    printf("Enter product name: ");
                    scanf("%s", newProduct.name);
                    printf("Enter product price: ");
                    scanf("%f", &newProduct.price);
                    printf("Enter product quantity: ");
                    scanf("%d", &newProduct.quantity);
                    
                    inventory[numProducts++] = newProduct;
                    printf("Product added to inventory.\n");
                }
                break;
            
            case 2: // Remove Product
                if (numProducts == 0) {
                    printf("Inventory is empty. No products to remove.\n");
                } else {
                    int removeID;
                    printf("Enter product ID to remove: ");
                    scanf("%d", &removeID);
                    
                    // Find product with matching ID and remove it from the inventory
                    int removeIndex = -1;
                    for (int i = 0; i < numProducts; i++) {
                        if (inventory[i].id == removeID) {
                            removeIndex = i;
                            break;
                        }
                    }
                    if (removeIndex == -1) {
                        printf("Product with ID %d not found in inventory.\n", removeID);
                        break;
                    }
                    
                    for (int i = removeIndex; i < numProducts - 1; i++) {
                        inventory[i] = inventory[i+1];
                    }
                    numProducts--;
                    printf("Product with ID %d removed from inventory.\n", removeID);
                }
                break;
            
            case 3: // Update Product
                if (numProducts == 0) {
                    printf("Inventory is empty. No products to update.\n");
                } else {
                    int updateID;
                    printf("Enter product ID to update: ");
                    scanf("%d", &updateID);
                    
                    // Find product with matching ID and update its information
                    int updateIndex = -1;
                    for (int i = 0; i < numProducts; i++) {
                        if (inventory[i].id == updateID) {
                            updateIndex = i;
                            break;
                        }
                    }
                    if (updateIndex == -1) {
                        printf("Product with ID %d not found in inventory.\n", updateID);
                        break;
                    }
                    
                    printf("Enter updated product name (press enter to keep the old name): ");
                    fflush(stdin);
                    fgets(inventory[updateIndex].name, 50, stdin);
                    printf("Enter updated product price (press enter to keep the old price): ");
                    char priceStr[20];
                    fgets(priceStr, 20, stdin);
                    if (priceStr[0] != '\n') {
                        sscanf(priceStr, "%f", &inventory[updateIndex].price);
                    }
                    printf("Enter updated product quantity (press enter to keep the old quantity): ");
                    char quantityStr[10];
                    fgets(quantityStr, 10, stdin);
                    if (quantityStr[0] != '\n') {
                        sscanf(quantityStr, "%d", &inventory[updateIndex].quantity);
                    }
                    printf("Product with ID %d updated.\n", updateID);
                }
                break;
            
            case 4: // View Inventory
                if (numProducts == 0) {
                    printf("Inventory is empty.\n");
                } else {
                    printf("Product ID   Product Name               Price  Quantity\n");
                    printf("----------   ------------               -----  --------\n");
                    for (int i = 0; i < numProducts; i++) {
                        printf("%-12d%-28s$%-7.2f%-8d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
                    }
                }
                break;
            
            case 5: // Exit
                printf("Exiting program.\n");
                return 0;
            
            default:
                printf("Invalid choice. Please choose again.\n");
        }
        
        printf("\n");
    }
}