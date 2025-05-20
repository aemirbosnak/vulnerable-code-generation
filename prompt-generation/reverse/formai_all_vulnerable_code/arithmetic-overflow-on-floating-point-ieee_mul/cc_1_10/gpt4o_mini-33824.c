//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_MONTHS 12
#define BUFFER_SIZE 256

typedef struct {
    char product_id[20];
    char product_name[50];
    float price;
    int quantity;
    char date[11]; // Format: YYYY-MM-DD
} SaleRecord;

typedef struct {
    char product_id[20];
    char product_name[50];
    float total_sales;
    int total_quantity;
} ProductSales;

ProductSales products[MAX_PRODUCTS];
int product_count = 0;
int monthly_sales[MAX_MONTHS] = {0};

void read_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    fgets(buffer, sizeof(buffer), file); // Skip header line

    while (fgets(buffer, sizeof(buffer), file)) {
        SaleRecord record;
        sscanf(buffer, "%[^,],%[^,],%f,%d,%s",
               record.product_id, record.product_name, &record.price, 
               &record.quantity, record.date);

        // Process monthly sales
        char *month_str = strtok(record.date, "-");
        month_str = strtok(NULL, "-");
        int month = atoi(month_str);
        if (month >= 1 && month <= MAX_MONTHS) {
            monthly_sales[month - 1] += record.quantity;
        }

        // Process product sales
        int found = 0;
        for (int i = 0; i < product_count; i++) {
            if (strcmp(products[i].product_id, record.product_id) == 0) {
                products[i].total_sales += record.quantity * record.price;
                products[i].total_quantity += record.quantity;
                found = 1;
                break;
            }
        }
        
        if (!found && product_count < MAX_PRODUCTS) {
            strcpy(products[product_count].product_id, record.product_id);
            strcpy(products[product_count].product_name, record.product_name);
            products[product_count].total_sales = record.quantity * record.price;
            products[product_count].total_quantity = record.quantity;
            product_count++;
        }
    }

    fclose(file);
}

void print_report() {
    printf("Monthly Sales Report:\n");
    for (int i = 0; i < MAX_MONTHS; i++) {
        printf("Month %d: %d\n", i + 1, monthly_sales[i]);
    }

    printf("\nProduct Sales Report:\n");
    printf("%-20s %-25s %-12s %-12s\n", "Product ID", "Product Name", "Total Sales", "Total Quantity");
    for (int i = 0; i < product_count; i++) {
        printf("%-20s %-25s $%-11.2f %-12d\n", 
                products[i].product_id, 
                products[i].product_name, 
                products[i].total_sales, 
                products[i].total_quantity);
    }

    // Identify top selling product
    float max_sales = 0;
    char top_product[50];
    for (int i = 0; i < product_count; i++) {
        if (products[i].total_sales > max_sales) {
            max_sales = products[i].total_sales;
            strcpy(top_product, products[i].product_name);
        }
    }
    
    printf("\nTop Selling Product: %s with total sales of $%.2f\n", top_product, max_sales);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <datafile.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_data(argv[1]);
    print_report();
    
    return EXIT_SUCCESS;
}