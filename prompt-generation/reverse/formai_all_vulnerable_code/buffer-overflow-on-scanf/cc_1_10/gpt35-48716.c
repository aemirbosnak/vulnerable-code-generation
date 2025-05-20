//FormAI DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 100

typedef struct Product{
    int id, quantity;
    char name[50];
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct(){
    Product newProduct;
    printf("Enter product id: ");
    scanf("%d", &newProduct.id);
    getchar(); // clear input buffer
    printf("Enter product name: ");
    fgets(newProduct.name, 50, stdin);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    getchar(); // clear input buffer
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    if(productCount >= MAX_PRODUCTS) {
        printf("Error: Maximum capacity reached. Could not add product.\n");
        return;
    }
    inventory[productCount++] = newProduct;
    printf("Product added successfully.\n\n");
}

void printInventory(){
    printf("**********************************************************************\n");
    printf("ID\tProduct Name\tPrice\tQuantity\n");
    printf("**********************************************************************\n");
    for(int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("\n");
}

int searchProductById(int id){
    for(int i = 0; i < productCount; i++) {
        if(inventory[i].id == id){
            return i;
        }
    }
    return -1;
}

void updateProduct(){
    int productId, index;
    printf("Enter product id to update: ");
    scanf("%d", &productId);
    index = searchProductById(productId);
    if(index == -1){
        printf("Error: Product with id %d not found.\n\n", productId);
        return;
    }
    Product updatedProduct;
    printf("Enter updated product name (Press enter to leave unchanged): ");
    fgets(updatedProduct.name, 50, stdin);
    if(updatedProduct.name[0] != '\n'){
        updatedProduct.name[strcspn(updatedProduct.name, "\n")] = 0;
        strcpy(inventory[index].name, updatedProduct.name);
    }

    printf("Enter updated product price (Press enter to leave unchanged): ");
    char priceString[10];
    fgets(priceString, 10, stdin);
    if(priceString[0] != '\n'){
        sscanf(priceString, "%f", &updatedProduct.price);
        inventory[index].price = updatedProduct.price;
    }

    printf("Enter updated product quantity (Press enter to leave unchanged): ");
    char quantityString[10];
    fgets(quantityString, 10, stdin);
    if(quantityString[0] != '\n'){
        sscanf(quantityString, "%d", &updatedProduct.quantity);
        inventory[index].quantity = updatedProduct.quantity;
    }

    printf("Product with id %d updated successfully.\n\n", productId);
}

void deleteProduct(){
    int productId, index;
    printf("Enter product id to delete: ");
    scanf("%d", &productId);
    index = searchProductById(productId);
    if(index == -1){
        printf("Error: Product with id %d not found.\n\n", productId);
        return;
    }
    for(int i = index; i < productCount - 1; i++){
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product with id %d deleted successfully.\n\n", productId);
}

int main(){
    while(1){
        printf("Welcome to the Product Inventory System.\n");
        printf("Please select an option:\n");
        printf("1. Add a new product\n");
        printf("2. Print the inventory\n");
        printf("3. Update a product\n");
        printf("4. Delete a product\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1: addProduct(); break;
            case 2: printInventory(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: printf("Exiting program..."); return 0;
            default: printf("Invalid choice. Please select again.\n\n");
        }
    }
    return 0;
}