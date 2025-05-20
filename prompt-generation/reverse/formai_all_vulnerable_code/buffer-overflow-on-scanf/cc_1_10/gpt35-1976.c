//FormAI DATASET v1.0 Category: Product Inventory System ; Style: curious
#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 50

typedef struct {
    char name[50];
    float price;
    int quantity;
} product;

int menu() {
    int ch;
    printf("\n\nWELCOME TO THE PRODUCT INVENTORY SYSTEM!");
    printf("\n1. Add Product");
    printf("\n2. Search Product");
    printf("\n3. Update Product");
    printf("\n4. Display All Products");
    printf("\n5. Exit");
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &ch);
    return ch;
}

void addProduct(product inventory[MAX_PRODUCTS], int *counter) {
    if(*counter >= MAX_PRODUCTS) {
        printf("\nCannot add more products. Maximum limit reached.");
        return;
    }
    printf("\nEnter Product Name: ");
    scanf("%s", inventory[*counter].name);
    printf("Enter Price: ");
    scanf("%f", &inventory[*counter].price);
    printf("Enter Quantity: ");
    scanf("%d", &inventory[*counter].quantity);
    printf("\nProduct added successfully!");
    (*counter)++;
}

void searchProduct(product inventory[MAX_PRODUCTS], int counter) {
    char name[50];
    printf("\nEnter Product Name to Search: ");
    scanf("%s", name);
    for(int i=0; i<counter; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("\nProduct Found!");
            printf("\nName: %s", inventory[i].name);
            printf("\nPrice: %.2f", inventory[i].price);
            printf("\nQuantity: %d", inventory[i].quantity);
            return;
        }
    }
    printf("\nProduct not found!");
}

void updateProduct(product inventory[MAX_PRODUCTS], int counter) {
    char name[50];
    printf("\nEnter Product Name to Update: ");
    scanf("%s", name);
    for(int i=0; i<counter; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("\nEnter New Product Name: ");
            scanf("%s", inventory[i].name);
            printf("Enter New Price: ");
            scanf("%f", &inventory[i].price);
            printf("Enter New Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("\nProduct updated successfully!");
            return;
        }
    }
    printf("\nProduct not found!");
}

void displayAllProducts(product inventory[MAX_PRODUCTS], int counter) {
    if(counter == 0) {
        printf("\nNo products found in inventory!");
        return;
    }
    printf("\n-----------------PRODUCTS IN INVENTORY-----------------\n");
    printf("%-20s| %-10s| %-10s", "Name", "Price", "Quantity");
    printf("\n--------------------------------------------------------\n");
    for(int i=0; i<counter; i++) {
        printf("%-20s| %-10.2f| %-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    product inventory[MAX_PRODUCTS];
    int counter = 0;
    int choice;

    do {
        choice = menu();
        switch(choice) {
            case 1:
                addProduct(inventory, &counter);
                break;
            case 2:
                searchProduct(inventory, counter);
                break;
            case 3:
                updateProduct(inventory, counter);
                break;
            case 4:
                displayAllProducts(inventory, counter);
                break;
            case 5:
                printf("\nThank you for using the Product Inventory System!");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice.");
        }
    } while(choice != 5);

    return 0;
}