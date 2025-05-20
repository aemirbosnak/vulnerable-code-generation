//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Product inventory[MAX_PRODUCTS];
int num_products = 0;

void addProduct() {
    if (num_products == MAX_PRODUCTS) {
        printf("Maximum number of products reached.\n");
        return;
    }

    struct Product p;

    printf("Enter product name: ");
    scanf("%s", p.name);

    printf("Enter product price: ");
    scanf("%f", &p.price);

    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);

    p.id = num_products + 1;

    inventory[num_products] = p;
    num_products++;

    printf("Product %s added successfully.\n", p.name);
}

void removeProduct() {
    int id;

    printf("Enter the ID of the product you want to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            printf("Removing product %s.\n", inventory[i].name);
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            num_products--;
            return;
        }
    }

    printf("Product with ID %d not found.\n", id);
}

void listProducts() {
    if (num_products == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void searchProduct() {
    char keyword[50];

    printf("Enter a keyword to search for: ");
    scanf("%s", keyword);

    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        if (strstr(inventory[i].name, keyword) != NULL) {
            printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the inventory system.\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. List products\n");
        printf("4. Search products\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                listProducts();
                break;
            case 4:
                searchProduct();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}