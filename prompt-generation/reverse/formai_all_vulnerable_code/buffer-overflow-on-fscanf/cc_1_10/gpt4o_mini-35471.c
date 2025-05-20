//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} SalesData;

void initialize_sales_data(SalesData *data) {
    data->count = 0;
}

void add_product(SalesData *data, const char *name, int quantity, float price) {
    if (data->count < MAX_PRODUCTS) {
        strcpy(data->products[data->count].name, name);
        data->products[data->count].quantity = quantity;
        data->products[data->count].price = price;
        data->count++;
    } else {
        printf("Max products limit reached!\n");
    }
}

void read_sales_data(SalesData *data, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;

    while (fscanf(file, "%49s %d %f", name, &quantity, &price) == 3) {
        add_product(data, name, quantity, price);
    }
    
    fclose(file);
}

float calculate_total_sales(SalesData *data) {
    float total = 0.0;
    for (int i = 0; i < data->count; i++) {
        total += data->products[i].quantity * data->products[i].price;
    }
    return total;
}

void print_sales_report(SalesData *data) {
    printf("\n=== Sales Report ===\n");
    printf("Product Name\tQuantity\tPrice\tTotal Sales\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < data->count; i++) {
        float total_product_sales = data->products[i].quantity * data->products[i].price;
        printf("%s\t\t%d\t\t%.2f\t%.2f\n", data->products[i].name, data->products[i].quantity, data->products[i].price, total_product_sales);
    }
    printf("----------------------------------------------------\n");
    printf("Total Revenue: %.2f\n", calculate_total_sales(data));
}

void find_top_product(SalesData *data) {
    if (data->count == 0) return;

    float highest_total = 0.0;
    Product top_product;

    for (int i = 0; i < data->count; i++) {
        float total_product_sales = data->products[i].quantity * data->products[i].price;
        if (total_product_sales > highest_total) {
            highest_total = total_product_sales;
            top_product = data->products[i];
        }
    }

    printf("\nTop Product: %s with total sales of %.2f\n", top_product.name, highest_total);
}

int main() {
    SalesData sales_data;
    initialize_sales_data(&sales_data);

    const char *filename = "sales_data.txt"; // Input file with sales data
    read_sales_data(&sales_data, filename);
    print_sales_report(&sales_data);
    find_top_product(&sales_data);

    return 0;
}