//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[50];
    int quantity;
    float price;
};

void addProduct(struct product products[], int count) {
    printf("Enter product name: ");
    scanf("%s", products[count].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[count].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[count].price);

    products[count].quantity += 1;
}

void removeProduct(struct product products[], int count) {
    printf("Enter product name: ");
    scanf("%s", products[count].name);

    products[count].quantity -= 1;
}

void displayProducts(struct product products[], int count) {
    printf("\nProduct Inventory:\n");
    printf("--------------------\n");

    int i;
    for (i = 0; i < count; i++) {
        printf("%s\t%d\t$%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    struct product products[MAX_PRODUCTS];
    int count = 0;

    while (count < MAX_PRODUCTS) {
        printf("\nEnter 1 to add product\nEnter 2 to remove product\nEnter 3 to display products\nEnter 4 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addProduct(products, count);
            count++;
            break;
        case 2:
            removeProduct(products, count);
            break;
        case 3:
            displayProducts(products, count);
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}