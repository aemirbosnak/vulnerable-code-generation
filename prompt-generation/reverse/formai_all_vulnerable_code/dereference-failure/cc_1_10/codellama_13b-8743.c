//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: shocked
// C Product Inventory System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Product {
    char name[20];
    float price;
    int quantity;
};

void addProduct(struct Product products[], int *count) {
    printf("Enter the name of the product: ");
    fgets(products[*count].name, sizeof(products[*count].name), stdin);
    products[*count].name[strlen(products[*count].name) - 1] = '\0';
    printf("Enter the price of the product: ");
    scanf("%f", &products[*count].price);
    printf("Enter the quantity of the product: ");
    scanf("%d", &products[*count].quantity);
    (*count)++;
}

void removeProduct(struct Product products[], int *count) {
    printf("Enter the name of the product to remove: ");
    fgets(products[*count].name, sizeof(products[*count].name), stdin);
    products[*count].name[strlen(products[*count].name) - 1] = '\0';
    (*count)--;
}

void printProducts(struct Product products[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f x %d = $%.2f\n", i + 1, products[i].name, products[i].price, products[i].quantity, products[i].price * products[i].quantity);
    }
}

int main() {
    struct Product products[100];
    int count = 0;
    char choice;
    do {
        printf("1. Add Product\n2. Remove Product\n3. Print Products\n4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                addProduct(products, &count);
                break;
            case '2':
                removeProduct(products, &count);
                break;
            case '3':
                printProducts(products, count);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != '4');
    return 0;
}