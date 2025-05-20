//FormAI DATASET v1.0 Category: Product Inventory System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 100

typedef struct product {
    char name[50];
    double price;
    int quantity;
} Product;

int totalProducts;

Product products[MAX_PRODUCTS];

int menu();
void addProduct();
void viewInventory();
void searchProduct();
void sellProduct();

int main() {

    int choice;
    totalProducts = 0;

    while(1) {

        choice = menu();

        switch(choice) {
            case 1:
                addProduct();
                break;

            case 2:
                viewInventory();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                sellProduct();
                break;

            case 5:
                return 0;
        }
    }

    return 0;
}

int menu() {
    int choice;

    printf("Welcome to the Product Inventory System!\n");
    printf("1) Add Product\n");
    printf("2) View Inventory\n");
    printf("3) Search Product\n");
    printf("4) Sell Product\n");
    printf("5) Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    return choice;
}

void addProduct() {
    if(totalProducts >= MAX_PRODUCTS) {
        printf("Inventory is full.\n");
    } else {
        printf("Enter name of product: ");
        scanf("%s", products[totalProducts].name);
        printf("Enter price of product: ");
        scanf("%lf", &products[totalProducts].price);
        printf("Enter quantity of product: ");
        scanf("%d", &products[totalProducts].quantity);

        totalProducts++;
    }
}

void viewInventory() {
    if(totalProducts == 0) {
        printf("Inventory is empty.\n");
    } else {
        printf("%-30s %-15s %-10s\n", "Name", "Price", "Quantity");
        for(int i = 0; i < totalProducts; i++) {
            printf("%-30s %-15.2lf %-10d\n", products[i].name, products[i].price, products[i].quantity);
        }
    }
}

void searchProduct() {
    char name[50];
    int found = 0;

    printf("Enter name of product: ");
    scanf("%s", name);

    for(int i = 0; i < totalProducts; i++) {
        if(strcmp(name, products[i].name) == 0) {
            found = 1;
            printf("%-30s %-15s %-10s\n", "Name", "Price", "Quantity");
            printf("%-30s %-15.2lf %-10d\n", products[i].name, products[i].price, products[i].quantity);
            break;
        }
    }

    if(!found) {
        printf("Product not found.\n");
    }
}

void sellProduct() {
    char name[50];
    int quantity;
    int index = -1;

    printf("Enter name of product: ");
    scanf("%s", name);

    for(int i = 0; i < totalProducts; i++) {
        if(strcmp(name, products[i].name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Product not found.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    if(quantity > products[index].quantity) {
        printf("Insufficient quantity.\n");
        return;
    }

    products[index].quantity -= quantity;
    printf("%d units of %s sold for a total of %.2lf dollars.\n", quantity, name, (quantity * products[index].price));
}