//FormAI DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

product inventory[MAX_PRODUCTS];
int numProducts = 0;

void addProduct() {
    if(numProducts >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }

    product newProduct;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);

    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    newProduct.id = numProducts + 1;
    inventory[numProducts] = newProduct;

    printf("Product added. ID: %d\n", newProduct.id);

    numProducts++;
}

void removeProduct() {
    int idToRemove;
    printf("Enter ID of product to remove: ");
    scanf("%d", &idToRemove);

    for(int i = 0; i < numProducts; i++) {
        if(inventory[i].id == idToRemove) {
            for(int j = i; j < (numProducts - 1); j++) {
                inventory[j] = inventory[j + 1];
                inventory[j].id--;
            }

            printf("Product removed.\n");

            numProducts--;
            return;
        }
    }

    printf("Product not found.\n");
}

void printProductDetails(product p) {
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Quantity: %d\n", p.quantity);
    printf("Price: %.2f\n\n", p.price);
}

void printInventory() {
    printf("Inventory:\n");

    for(int i = 0; i < numProducts; i++) {
        printProductDetails(inventory[i]);
    }
}

void getHighestPrice() {
    float highestPrice = inventory[0].price;
    int highestPriceIndex = 0;

    for(int i = 1; i < numProducts; i++) {
        if(inventory[i].price > highestPrice) {
            highestPrice = inventory[i].price;
            highestPriceIndex = i;
        }
    }

    printf("Product with highest price:\n");
    printProductDetails(inventory[highestPriceIndex]);
}

int main() {
    int choice;

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Print inventory\n");
        printf("4. Get highest price\n");
        printf("5. Quit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                printInventory();
                break;
            case 4:
                getHighestPrice();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}