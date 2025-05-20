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

void addProduct(Product *inventory, int *count);
void viewProducts(Product *inventory, int count);
void searchProduct(Product *inventory, int count);
void totalValue(Product *inventory, int count);

int main() {
    Product inventory[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    printf("Welcome to 'The Heart's Inventory' - A Melody of Products!\n");
    
    while (1) {
        printf("\n1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search for a Product\n");
        printf("4. Total Inventory Value\n");
        printf("5. Exit\n");
        printf("Choose your destiny (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &productCount);
                break;
            case 2:
                viewProducts(inventory, productCount);
                break;
            case 3:
                searchProduct(inventory, productCount);
                break;
            case 4:
                totalValue(inventory, productCount);
                break;
            case 5:
                printf("With a heavy heart, I bid you farewell...\n");
                exit(0);
            default:
                printf("Alas! Choose a valid option, dear heart.\n");
        }
    }

    return 0;
}

void addProduct(Product *inventory, int *count) {
    if (*count < MAX_PRODUCTS) {
        printf("With joy, I add a product to our love story. Please share the name: ");
        scanf("%s", inventory[*count].name);
        printf("How many sweet items do you wish to add?: ");
        scanf("%d", &inventory[*count].quantity);
        printf("And what price shall we place upon this treasure?: ");
        scanf("%f", &inventory[*count].price);
        (*count)++;
        printf("Oh, how delightful! The product has been added to our cherished collection.\n");
    } else {
        printf("My heart weeps, for the inventory is full!\n");
    }
}

void viewProducts(Product *inventory, int count) {
    if (count == 0) {
        printf("Our inventory is but an empty canvas, waiting for loving strokes!\n");
    } else {
        printf("In our inventory of dreams, we have:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s | Quantity: %d | Price: $%.2f\n", 
                    i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

void searchProduct(Product *inventory, int count) {
    char searchName[NAME_LENGTH];
    printf("Seek the name of the product you desire: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Ah! Your heart's desire has been found:\n");
            printf("%s | Quantity: %d | Price: $%.2f\n", 
                    inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Alas! The product is but a whisper in the wind...\n");
}

void totalValue(Product *inventory, int count) {
    if (count == 0) {
        printf("Our inventory has no value, for it stands empty.\n");
    } else {
        float total = 0.0;
        for (int i = 0; i < count; i++) {
            total += inventory[i].quantity * inventory[i].price;
        }
        printf("The total value of our beloved treasures is: $%.2f\n", total);
    }
}