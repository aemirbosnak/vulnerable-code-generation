//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

int main() {
    // Declare variables
    char product[50];
    int quantity[5];
    float price[5];
    int total_price = 0;
    int selected_item = 0;
    int customer_id = 0;
    char customer_name[50];
    
    // Prompt user for customer ID and name
    printf("Enter customer ID: ");
    scanf("%d", &customer_id);
    printf("Enter customer name: ");
    scanf("%s", customer_name);
    
    // Prompt user for product selection
    printf("Select product: ");
    scanf("%s", product);
    
    // Loop through products and prompt user for quantity and price
    for (int i = 0; i < 5; i++) {
        if (strcmp(product, product[i]) == 0) {
            printf("Enter quantity for %s: ", product[i]);
            scanf("%d", &quantity[i]);
            printf("Enter price for %s: ", product[i]);
            scanf("%f", &price[i]);
            selected_item = i;
            break;
        }
    }
    
    // Calculate total price
    for (int i = 0; i < 5; i++) {
        total_price += quantity[i] * price[i];
    }
    
    // Print receipt
    printf("Customer ID: %d\n", customer_id);
    printf("Customer Name: %s\n", customer_name);
    printf("Product: %s\n", product);
    printf("Quantity: %d\n", quantity[selected_item]);
    printf("Price: %.2f\n", price[selected_item]);
    printf("Total Price: %.2f\n", total_price);
    
    return 0;
}