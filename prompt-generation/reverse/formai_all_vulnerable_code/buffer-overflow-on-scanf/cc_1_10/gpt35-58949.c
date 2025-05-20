//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 100

typedef struct {
    int productID;
    char name[50];
    float price;
    int quantity;
} Product;

void initialize(Product *p);
void addProduct(Product *p, int *numProducts);
void displayInventory(Product *p, int numProducts);
void searchProduct(Product *p, int numProducts);
void sortProducts(Product *p, int numProducts);

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0, choice;

    printf("PRODUCT INVENTORY SYSTEM\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add product\n");
        printf("2. Display inventory\n");
        printf("3. Search for a product\n");
        printf("4. Sort products by price\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(&products[numProducts], &numProducts);
                break;
            case 2:
                displayInventory(products, numProducts);
                break;
            case 3:
                searchProduct(products, numProducts);
                break;
            case 4:
                sortProducts(products, numProducts);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 5);

    return 0;
}

void initialize(Product *p) {
    p->productID = 0;
    strcpy(p->name, "");
    p->price = 0.0;
    p->quantity = 0;
}

void addProduct(Product *p, int *numProducts) {
    printf("Enter product ID: ");
    scanf("%d", &p->productID);
    fflush(stdin);

    printf("Enter product name: ");
    fgets(p->name, 50, stdin);
    p->name[strcspn(p->name, "\n")] = 0;

    printf("Enter product price: ");
    scanf("%f", &p->price);

    printf("Enter product quantity: ");
    scanf("%d", &p->quantity);

    (*numProducts)++;
}

void displayInventory(Product *p, int numProducts) {
    printf("\nProduct Inventory:\n");
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Product Name", "Price", " Quantity");
    for(int i = 0; i < numProducts; i++) {
        printf("%-10d %-20s $%-9.2f %-10d\n", p[i].productID, p[i].name, p[i].price, p[i].quantity);
    }
}

void searchProduct(Product *p, int numProducts) {
    int targetID, found = 0;
    printf("Enter the product ID: ");
    scanf("%d", &targetID);

    for(int i = 0; i < numProducts; i++) {
        if(p[i].productID == targetID) {
            printf("Product found!\n");
            printf("%-10s %-20s %-10s %-10s\n", "ID", "Product Name", "Price", " Quantity");
            printf("%-10d %-20s $%-9.2f %-10d\n", p[i].productID, p[i].name, p[i].price, p[i].quantity);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Product not found.\n");
    }
}

void sortProducts(Product *p, int numProducts) {
    Product tempProduct;

    for(int i = 0; i < numProducts - 1; i++) {
        for(int j = 0; j < numProducts - i - 1; j++) {
            if(p[j].price > p[j+1].price) {
                tempProduct = p[j];
                p[j] = p[j+1];
                p[j+1] = tempProduct;
            }
        }
    }

    printf("Products sorted by price.\n");
}