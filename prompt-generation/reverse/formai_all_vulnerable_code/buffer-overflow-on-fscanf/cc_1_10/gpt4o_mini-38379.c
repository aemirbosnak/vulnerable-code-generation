//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int sales;
} Product;

void load_data(Product products[], int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%s %d", products[*count].name, &products[*count].sales) != EOF && *count < MAX_PRODUCTS) {
        (*count)++;
    }
    
    fclose(file);
}

void display_products(Product products[], int count) {
    printf("Product Sales Data:\n");
    printf("----------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %d\n", products[i].name, products[i].sales);
    }
    printf("----------------------\n");
}

void calculate_statistics(Product products[], int count) {
    int total_sales = 0;
    for (int i = 0; i < count; i++) {
        total_sales += products[i].sales;
    }

    double average_sales = (double)total_sales / count;
    
    printf("Total Sales: %d\n", total_sales);
    printf("Average Sales per Product: %.2f\n", average_sales);
}

void find_top_product(Product products[], int count) {
    int max_sales = 0;
    char top_product[MAX_NAME_LENGTH];

    for (int i = 0; i < count; i++) {
        if (products[i].sales > max_sales) {
            max_sales = products[i].sales;
            strcpy(top_product, products[i].name);
        }
    }
    
    printf("Top Product: %s with %d sales\n", top_product, max_sales);
}

void display_menu() {
    printf("Data Mining Menu:\n");
    printf("1. Display Sales Data\n");
    printf("2. Calculate Statistics\n");
    printf("3. Find Top Product\n");
    printf("4. Exit\n");
}

int main() {
    Product products[MAX_PRODUCTS];
    int product_count = 0;
    int choice;
    const char *filename = "sales_data.txt"; // Make sure a valid file exists

    load_data(products, &product_count, filename);

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_products(products, product_count);
                break;
            case 2:
                calculate_statistics(products, product_count);
                break;
            case 3:
                find_top_product(products, product_count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");

    } while (choice != 4);

    return 0;
}