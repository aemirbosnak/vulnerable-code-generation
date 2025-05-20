//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    double price;
    int quantity;
};

struct Product products[MAX_PRODUCTS]; //creating an array of products
int numProducts = 0; //initializing the number of products to 0

//function prototypes
void addProduct();
void deleteProduct();
void searchProduct();
void displayInventory();

int main() {
    int choice;

    while(1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Search Product\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;

            case 2:
                deleteProduct();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                displayInventory();
                break;

            case 5:
                exit(0); //exiting the program if user chooses to terminate
                break;

            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}

void addProduct() {
    if(numProducts == MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    struct Product product;

    printf("\nEnter product details:\n");

    printf("ID: ");
    scanf("%d", &product.id);

    printf("Name: ");
    scanf("%s", product.name);

    printf("Price: ");
    scanf("%lf", &product.price);

    printf("Quantity: ");
    scanf("%d", &product.quantity);

    products[numProducts++] = product; //adding product to the array
    printf("%s added to inventory.\n", product.name);
}

void deleteProduct() {
    int id, i, flag = 0;

    printf("Enter product id to delete: ");
    scanf("%d", &id);

    for(i = 0; i < numProducts; i++) {
        if(products[i].id == id) {
            flag = 1;
            break;
        }
    }

    if(flag) { //if product id exists, remove from the array
        printf("%s deleted from inventory.\n", products[i].name);
        for(int j = i; j < numProducts - 1; j++) {
            products[j] = products[j+1];
        }
        numProducts--;
    }

    else {
        printf("Product not found in inventory.\n");
    }
}

void searchProduct() {
    int id, i, flag = 0;

    printf("Enter product id to search: ");
    scanf("%d", &id);

    for(i = 0; i < numProducts; i++) {
        if(products[i].id == id) {
            flag = 1;
            break;
        }
    }

    if(flag) { //if product id exists, display its details
        printf("Product Found!\n");
        printf("ID: %d\n", products[i].id);
        printf("Name: %s\n", products[i].name);
        printf("Price: $%.2lf\n", products[i].price);
        printf("Quantity: %d\n", products[i].quantity);
    }

    else {
        printf("Product not found in inventory.\n");
    }
}

void displayInventory() {
    if(numProducts == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("\nProduct Inventory\n");
    printf("-----------------\n");
    printf("ID\tName\t\tPrice\t\tQuantity\n");
    for(int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t\t$%.2lf\t\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}