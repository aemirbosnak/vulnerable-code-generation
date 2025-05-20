//FormAI DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCT 10 // Maximum number of products in the inventory

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
} products[MAX_PRODUCT];

int numProducts = 0;

// function to add a product
void addProduct() {
    printf("Enter the details of the product:\n");
    printf("ID: ");
    scanf("%d", &products[numProducts].id);
    printf("Name: ");
    scanf("%s", products[numProducts].name);
    printf("Quantity: ");
    scanf("%d", &products[numProducts].quantity);
    printf("Price: ");
    scanf("%f", &products[numProducts].price);
    
    numProducts++;
    
    printf("Product added successfully!\n");
}

// function to delete a product
void deleteProduct(int id) {
    int i, found = 0;
    
    for(i=0; i<numProducts; i++) {
        if(products[i].id == id) {
            found = 1;
            break;
        }
    }
    
    if(found) {
        for(; i<numProducts-1; i++) {
            products[i] = products[i+1];
        }
        numProducts--;
        printf("Product with ID %d deleted successfully!\n", id);
    } else {
        printf("Product with ID %d not found!\n", id);
    }
}

// function to update a product
void updateProduct(int id) {
    int i, found = 0;
    
    for(i=0; i<numProducts; i++) {
        if(products[i].id == id) {
            found = 1;
            break;
        }
    }
    
    if(found) {
        printf("Enter the new details of the product:\n");
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Quantity: ");
        scanf("%d", &products[i].quantity);
        printf("Price: ");
        scanf("%f", &products[i].price);
        printf("Product with ID %d updated successfully!\n", id);
    } else {
        printf("Product with ID %d not found!\n", id);
    }
}

// function to search for a product
void searchProduct(int id) {
    int i, found = 0;
    
    for(i=0; i<numProducts; i++) {
        if(products[i].id == id) {
            found = 1;
            break;
        }
    }
    
    if(found) {
        printf("Product found!\n");
        printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    } else {
        printf("Product with ID %d not found!\n", id);
    }
}

// function to display all products
void displayProducts() {
    int i;
    if(numProducts == 0) {
        printf("No products in inventory!\n");
    } else {
        printf("Inventory:\n");
        for(i=0; i<numProducts; i++) {
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
        }
    }
}

int main() {
    int choice, id;
    
    do {
        printf("\nChoose an option:\n");
        printf("1. Add a product\n2. Delete a product\n3. Update a product\n4. Search for a product\n5. Display all products\n6. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                printf("Enter the ID of the product you want to delete: ");
                scanf("%d", &id);
                deleteProduct(id);
                break;
            case 3:
                printf("Enter the ID of the product you want to update: ");
                scanf("%d", &id);
                updateProduct(id);
                break;
            case 4:
                printf("Enter the ID of the product you want to search: ");
                scanf("%d", &id);
                searchProduct(id);
                break;
            case 5:
                displayProducts();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}