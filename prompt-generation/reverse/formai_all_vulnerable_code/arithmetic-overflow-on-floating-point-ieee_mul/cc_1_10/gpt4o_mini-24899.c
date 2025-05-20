//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define LINE_LENGTH 256

typedef struct {
    char name[50];
    float totalPrice;
    int totalQuantity;
} Product;

void parseLine(char *line, char *productName, float *price, int *quantity) {
    char *token;

    // Parse product name
    token = strtok(line, ",");
    if (token != NULL) {
        strcpy(productName, token);
    }

    // Parse price
    token = strtok(NULL, ",");
    if (token != NULL) {
        *price = atof(token);
    }

    // Parse quantity
    token = strtok(NULL, ",");
    if (token != NULL) {
        *quantity = atoi(token);
    }
}

int main() {
    FILE *file;
    char line[LINE_LENGTH];
    Product products[MAX_PRODUCTS];
    int productCount = 0;

    // Open the CSV file
    file = fopen("sales_data.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    // Read the CSV file line by line
    fgets(line, LINE_LENGTH, file); // Skip header
    while (fgets(line, LINE_LENGTH, file)) {
        char productName[50];
        float price;
        int quantity;

        // Parse the line
        parseLine(line, productName, &price, &quantity);

        // Check if product already exists in the array
        int found = 0;
        for (int i = 0; i < productCount; i++) {
            if (strcmp(products[i].name, productName) == 0) {
                products[i].totalPrice += price * quantity;
                products[i].totalQuantity += quantity;
                found = 1;
                break;
            }
        }

        // If not found, add a new product entry
        if (!found && productCount < MAX_PRODUCTS) {
            strcpy(products[productCount].name, productName);
            products[productCount].totalPrice = price * quantity;
            products[productCount].totalQuantity = quantity;
            productCount++;
        }
    }

    fclose(file);

    // Display the results
    printf("Sales Summary:\n");
    printf("%-20s %-15s %-15s\n", "Product", "Total Price", "Total Quantity");
    for (int i = 0; i < productCount; i++) {
        printf("%-20s $%-14.2f %-15d\n", products[i].name, products[i].totalPrice, products[i].totalQuantity);
    }

    return 0;
}