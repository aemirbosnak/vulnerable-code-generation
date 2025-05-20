//FormAI DATASET v1.0 Category: Product Inventory System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[50];
    int id;
    int quantity;
    float price;
};

// Function to add product in the inventory
void addProduct(struct Product* inventory, int* count) {
    printf("\nEnter product details:\n");
    printf("Name: ");
    scanf(" %[^\n]s", inventory[*count].name);
    printf("ID: ");
    scanf("%d", &inventory[*count].id);
    printf("Quantity: ");
    scanf("%d", &inventory[*count].quantity);
    printf("Price: ");
    scanf("%f", &inventory[*count].price);
    *count = *count + 1;
    printf("\nProduct added to inventory successfully!\n\n");
}

// Function to display all products in the inventory
void displayProducts(struct Product* inventory, int count) {
    if(count == 0) {
        printf("\nNo products found in the inventory.\n\n");
        return;
    }
    printf("\nProducts in Inventory:\n");
    printf("Name\t\tID\tQuantity\tPrice\n");
    for(int i=0; i<count; i++) {
        printf("%-15s%d\t%d\t\t%.2f\n", inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}

// Function to search a product in the inventory by name
void searchProduct(struct Product* inventory, int count) {
    if(count == 0) {
        printf("\nNo products found in the inventory.\n\n");
        return;
    }
    char name[50];
    printf("\nEnter name of product to search: ");
    scanf(" %[^\n]s", name);
    for(int i=0; i<count; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("\nProduct found in inventory:\n");
            printf("Name\t\tID\tQuantity\tPrice\n");
            printf("%-15s%d\t%d\t\t%.2f\n\n", inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("\nProduct not found in inventory.\n\n");
}

// Function to delete a product from the inventory by id
void deleteProduct(struct Product* inventory, int* count) {
    if(*count == 0) {
        printf("\nNo products found in the inventory.\n\n");
        return;
    }
    int id;
    printf("\nEnter ID of product to delete: ");
    scanf("%d", &id);
    for(int i=0; i<*count; i++) {
        if(inventory[i].id == id) {
            for(int j=i; j<*count-1; j++) {
                inventory[j] = inventory[j+1];
            }
            *count = *count - 1;
            printf("\nProduct deleted from inventory successfully!\n\n");
            return;
        }
    }
    printf("\nProduct not found in inventory.\n\n");
}

int main() {
    struct Product inventory[100];
    int choice = 0, count = 0;
    
    while(choice != 5) {
        printf("Product Inventory System\n");
        printf("------------------------\n");
        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Search Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayProducts(inventory, count);
                break;
            case 3:
                searchProduct(inventory, count);
                break;
            case 4:
                deleteProduct(inventory, &count);
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n\n");
        }
    }
    
    return 0;
}