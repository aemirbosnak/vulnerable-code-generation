//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

void displayMenu() {
    printf("***********************************\n");
    printf("    Welcome to the Romantic Closet   \n");
    printf("***********************************\n");
    printf("1. Add a new product\n");
    printf("2. View all products\n");
    printf("3. Exit\n");
    printf("***********************************\n");
    printf("Please choose an option: ");
}

void addProduct(Product *products, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Oh dear! The closet is full, we can’t fit any more beautiful garments!\n");
        return;
    }
    
    printf("Enter the name of the product (a symbol of our affection): ");
    scanf(" %[^\n]", products[*count].name);
    
    printf("Enter the quantity available for your heart's desire: ");
    scanf("%d", &products[*count].quantity);
    
    printf("Enter the price of this loving piece: ");
    scanf("%f", &products[*count].price);
    
    (*count)++;
    printf("Oh! A new product has been added to the romantic inventory!\n");
}

void viewProducts(Product *products, int count) {
    if (count == 0) {
        printf("Our romantic closet is empty, with only memories lingering... \n");
        return;
    }
    
    printf("Here are the cherished products in our romantic closet:\n");
    printf("------------------------------------------------------------------\n");
    printf("| %-30s | %-10s | %-10s |\n", "Product Name", "Quantity", "Price");
    printf("------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-30s | %-10d | $%-9.2f |\n", products[i].name, products[i].quantity, products[i].price);
    }
    
    printf("------------------------------------------------------------------\n");
}

int main() {
    Product products[MAX_PRODUCTS];
    int choice;
    int productCount = 0;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(products, &productCount);
                break;
            case 2:
                viewProducts(products, productCount);
                break;
            case 3:
                printf("Leaving the romantic closet brings a tear to my eye, until next time...\n");
                break;
            default:
                printf("Ah, the choice is a riddle yet unsolved, please try again...\n");
        }
    } while (choice != 3);

    return 0;
}