//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int count;
    float total_sales;
} Product;

Product products[MAX_PRODUCTS];
int product_count = 0;

void load_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char line[100];
    fgets(line, sizeof(line), file); // Skip the header

    while (fgets(line, sizeof(line), file)) {
        char product_name[MAX_NAME_LENGTH];
        float price;

        // Parse the line
        sscanf(line, "%[^,],%f", product_name, &price);

        // Check if product already exists
        int found = 0;
        for (int i = 0; i < product_count; i++) {
            if (strcmp(products[i].name, product_name) == 0) {
                products[i].count++;
                products[i].total_sales += price;
                found = 1;
                break;
            }
        }

        // If product does not exist, add it to the array
        if (!found && product_count < MAX_PRODUCTS) {
            strcpy(products[product_count].name, product_name);
            products[product_count].count = 1;
            products[product_count].total_sales = price;
            product_count++;
        }
    }

    fclose(file);
}

void display_summary() {
    printf("Product Summary:\n");
    printf("Name\t\tCount\tTotal Sales\n");
    printf("-------------------------------------\n");

    for (int i = 0; i < product_count; i++) {
        printf("%-15s %d\t%.2f\n", products[i].name, products[i].count, products[i].total_sales);
    }
}

Product find_most_popular_product() {
    Product most_popular = { "", 0, 0.0 };
    for (int i = 0; i < product_count; i++) {
        if (products[i].count > most_popular.count) {
            most_popular = products[i];
        }
    }
    return most_popular;
}

int main() {
    load_data("purchases.csv");
    display_summary();
    
    Product most_popular = find_most_popular_product();
    printf("\nMost Popular Product: %s\n", most_popular.name);
    printf("Count: %d\n", most_popular.count);
    printf("Total Sales: %.2f\n", most_popular.total_sales);
    
    return 0;
}