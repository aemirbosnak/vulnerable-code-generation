//FormAI DATASET v1.0 Category: Product Inventory System ; Style: active
#include <stdio.h>
#include <string.h>

// Defining product structure
struct Product {
    int ID;
    char name[50];
    float price;
    int quantity;
};

// Defining function prototypes
void addProduct(struct Product products[], int *numProducts);
void removeProduct(struct Product products[], int *numProducts);
void editProduct(struct Product products[], int *numProducts);
void displayInventory(struct Product products[], int numProducts);

int main() {
    struct Product products[100]; // Array of products
    int numProducts = 0; // Number of products currently in inventory
    int choice;
    
    do {
        printf("-- Product Inventory System --\n\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Edit a product\n");
        printf("4. Display inventory\n");
        printf("5. Exit program\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            
            case 2:
                removeProduct(products, &numProducts);
                break;
            
            case 3:
                editProduct(products, &numProducts);
                break;
            
            case 4:
                displayInventory(products, numProducts);
                break;
            
            case 5:
                printf("Exiting program...");
                break;
            
            default:
                printf("Invalid choice.\n");
        }
        
        printf("\n");
    } while(choice != 5);

    return 0;
}

void addProduct(struct Product products[], int *numProducts) {
    // Add product to inventory
    struct Product newProduct;
    printf("\nEnter the product ID: ");
    scanf("%d", &newProduct.ID);
    printf("Enter the product name: ");
    scanf("%s", newProduct.name);
    printf("Enter the product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter the product quantity: ");
    scanf("%d", &newProduct.quantity);
    products[*numProducts] = newProduct;
    *numProducts += 1;
    
    printf("Product added successfully.\n");
}

void removeProduct(struct Product products[], int *numProducts) {
    // Remove product from inventory
    int productID, index = -1;
    printf("\nEnter the product ID to remove: ");
    scanf("%d", &productID);
    for(int i = 0; i < *numProducts; i++) {
        if(products[i].ID == productID) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("Product not found.\n");
        return;
    }
    
    // Shift products left to remove product at index
    for(int i = index + 1; i < *numProducts; i++) {
        products[i-1] = products[i];
    }
    *numProducts -= 1;
    
    printf("Product removed successfully.\n");
}

void editProduct(struct Product products[], int *numProducts) {
    // Edit product in inventory
    int productID, index = -1;
    printf("\nEnter the product ID to edit: ");
    scanf("%d", &productID);
    for(int i = 0; i < *numProducts; i++) {
        if(products[i].ID == productID) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("Product not found.\n");
        return;
    }
    
    struct Product newProduct;
    printf("Enter the new product name (enter '-' to keep existing value): ");
    scanf("%s", newProduct.name);
    if(strcmp(newProduct.name, "-") != 0) {
        // Only update name if '-' not entered
        strcpy(products[index].name, newProduct.name);
    }
    
    printf("Enter the new product price (enter -1 to keep existing value): ");
    scanf("%f", &newProduct.price);
    if(newProduct.price != -1) {
        // Only update price if -1 not entered
        products[index].price = newProduct.price;
    }
    
    printf("Enter the new product quantity (enter -1 to keep existing value): ");
    scanf("%d", &newProduct.quantity);
    if(newProduct.quantity != -1) {
        // Only update quantity if -1 not entered
        products[index].quantity = newProduct.quantity;
    }
    
    printf("Product updated successfully.\n");
}

void displayInventory(struct Product products[], int numProducts) {
    // Display inventory of products
    printf("\nID\tName\tPrice\tQuantity\n");
    for(int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%.2f\t%d\n", products[i].ID, products[i].name, products[i].price, products[i].quantity);
    }
}