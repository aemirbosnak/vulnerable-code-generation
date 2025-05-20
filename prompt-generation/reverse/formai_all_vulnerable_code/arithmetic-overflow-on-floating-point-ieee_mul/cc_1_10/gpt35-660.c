//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>

// Defining global variables
int no_of_products = 0, capacity = 0, filled = 0;
float total_cost = 0.0;
char product_names[50][50];

// Function to add new product
void add_product() {
    printf("\nEnter the product name: ");
    scanf("%s", product_names[no_of_products]);
    printf("Enter the capacity: ");
    scanf("%d", &capacity);
    printf("Enter the filled quantity: ");
    scanf("%d", &filled);
    printf("Enter the cost per unit: ");
    float cost;
    scanf("%f", &cost);
    total_cost += (filled * cost);
    no_of_products++;
}

// Function to display all products
void display_products() {
    if (no_of_products == 0) {
        printf("\nNo products available\n");
        return;
    }
    printf("\nAll Products:\n");
    printf("Name | Capacity | Filled | Cost per unit\n");
    for (int i = 0; i < no_of_products; i++) {
        printf("%s | %d | %d | %.2f\n", product_names[i], capacity, filled, total_cost/filled);
    }
}

int main() {
    int choice;
    do {
        printf("\nWarehouse Management System Menu\n");
        printf("1. Add product\n2. Display all products\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_product();
                    break;
            case 2: display_products();
                    break;
            case 3: printf("\nExiting program...\n");
                    break;
            default: printf("\nInvalid choice, try again\n");
        }
    } while (choice != 3);
    return 0;
}