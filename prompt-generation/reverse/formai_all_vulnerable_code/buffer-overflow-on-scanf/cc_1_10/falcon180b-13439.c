//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_CATEGORIES 100
#define MAX_SUPPLIERS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
    int category_id;
    int supplier_id;
} Product;

typedef struct {
    char name[50];
    int category_id;
    float discount;
} Category;

typedef struct {
    char name[50];
    int id;
} Supplier;

int main() {
    FILE *fp;
    char filename[50];
    int choice;
    Product products[MAX_PRODUCTS];
    Category categories[MAX_CATEGORIES];
    Supplier suppliers[MAX_SUPPLIERS];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fscanf(fp, "%d", &choice);
    while (choice!= 0) {
        switch (choice) {
            case 1:
                fscanf(fp, "%s %d %d %d %f", products[0].name, &products[0].quantity, &products[0].price, &products[0].category_id, &products[0].supplier_id);
                printf("Product added: %s\n", products[0].name);
                break;
            case 2:
                fscanf(fp, "%s %d %f", categories[0].name, &categories[0].category_id, &categories[0].discount);
                printf("Category added: %s\n", categories[0].name);
                break;
            case 3:
                fscanf(fp, "%s %d", suppliers[0].name, &suppliers[0].id);
                printf("Supplier added: %s\n", suppliers[0].name);
                break;
            default:
                printf("Invalid choice\n");
        }
        fscanf(fp, "%d", &choice);
    }

    fclose(fp);

    return 0;
}