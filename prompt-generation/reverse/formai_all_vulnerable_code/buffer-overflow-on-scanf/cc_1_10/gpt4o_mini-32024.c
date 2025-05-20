//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

void displayMenu() {
    printf("\nWelcome to the Curious Inventory System!\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Remove Product\n");
    printf("4. Exit\n");
    printf("Please choose an option (1-4): ");
}

void addProduct(Product *inventory, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Oh dear! The inventory is full, can't add more products.\n");
        return;
    }
    
    Product newProduct;
    
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    inventory[*count] = newProduct;
    (*count)++;
    
    printf("Huzzah! You've added %s to the inventory.\n", newProduct.name);
}

void viewProducts(Product *inventory, int count) {
    if (count == 0) {
        printf("Oh no! The inventory is empty, just like my hopes and dreams...\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Quantity: %d, Price: $%.2f\n", 
               i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void removeProduct(Product *inventory, int *count) {
    if (*count == 0) {
        printf("Oh dear! No products to remove.\n");
        return;
    }
    
    int index;
    printf("Enter the product number to remove (1-%d): ", *count);
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("That’s an invalid choice! Please try again.\n");
        return;
    }
    
    printf("Are you sure you want to remove %s? (1-Yes, 0-No): ", inventory[index - 1].name);
    int confirmation;
    scanf("%d", &confirmation);
    
    if (confirmation == 1) {
        for (int i = index - 1; i < *count - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        (*count)--;
        printf("Bye bye! %s has been removed from the inventory.\n", inventory[index - 1].name);
    } else {
        printf("Phew! %s is safe for now.\n", inventory[index - 1].name);
    }
}

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                viewProducts(inventory, count);
                break;
            case 3:
                removeProduct(inventory, &count);
                break;
            case 4:
                printf("Thank you for visiting the Curious Inventory System! Farewell!\n");
                exit(0);
            default:
                printf("Oops! That wasn't an option. Try again!\n");
                break;
        }
    }

    return 0;
}