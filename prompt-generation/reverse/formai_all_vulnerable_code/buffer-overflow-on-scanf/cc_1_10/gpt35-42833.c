//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 100

struct product {
    char name[50];
    int quantity;
    float price;
};

void addProduct(struct product *list, int *numProducts) {
    if(*numProducts == MAX_PRODUCTS) {
        printf("Error: maximum number of products reached.\n");
        return;
    }

    printf("\nEnter product name: ");
    scanf("%s", list[*numProducts].name);

    printf("Enter product quantity: ");
    scanf("%d", &list[*numProducts].quantity);

    printf("Enter product price: ");
    scanf("%f", &list[*numProducts].price);

    (*numProducts)++;

    printf("Product added successfully!\n");
}

void removeProduct(struct product *list, int *numProducts, char *name) {
    int i, index = -1;

    for(i = 0; i < *numProducts; i++) {
        if(strcmp(list[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Error: product not found.\n");
        return;
    }

    for(i = index; i < *numProducts - 1; i++) {
        list[i] = list[i + 1];
    }

    (*numProducts)--;

    printf("Product removed successfully!\n");
}

void displayProducts(struct product *list, int numProducts) {
    int i;

    if(numProducts == 0) {
        printf("No products to display.\n");
        return;
    }

    printf("\n%-20s %10s %10s\n", "Product Name", "Quantity", "Price");

    for(i = 0; i < numProducts; i++) {
        printf("%-20s %10d %10.2f\n", list[i].name, list[i].quantity, list[i].price);
    }
}

int main() {
    struct product productList[MAX_PRODUCTS];
    int numProducts = 0, choice;
    char productName[50];

    while(1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(productList, &numProducts);
                break;

            case 2:
                printf("\nEnter product name to remove: ");
                scanf("%s", productName);
                removeProduct(productList, &numProducts, productName);
                break;

            case 3:
                displayProducts(productList, numProducts);
                break;

            case 4:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}