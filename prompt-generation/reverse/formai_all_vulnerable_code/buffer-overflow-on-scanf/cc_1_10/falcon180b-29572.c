//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000.00

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

int main() {
    FILE *fp;
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char filename[100];
    int choice;

    printf("Welcome to the Product Inventory System!\n");
    printf("Enter the name of the product file (including extension): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %d %f\n", products[num_products].name, products[num_products].description, &products[num_products].quantity, &products[num_products].price)!= EOF) {
        num_products++;
    }

    fclose(fp);

    printf("\nProduct List:\n");
    printf("----------------\n");
    printf("Name\t\tDescription\t\tQuantity\t\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%s\t\t%d\t\t$%.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. View product details\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Add product
            break;
        case 2:
            // Remove product
            break;
        case 3:
            // Update product
            break;
        case 4:
            // View product details
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}