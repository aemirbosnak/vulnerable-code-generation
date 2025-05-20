//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define structures to store information about products and customers
typedef struct product {
    char name[50];
    int price;
    int quantity;
} product_t;

typedef struct customer {
    char name[50];
    int phone;
} customer_t;

// Define global variables
product_t products[10];
customer_t customers[10];
int num_products = 0;
int num_customers = 0;

int main() {
    int choice, i, j;

    // Initialize global variables
    for (i = 0; i < 10; i++) {
        products[i].name[0] = '\0';
        products[i].price = 0;
        products[i].quantity = 0;
    }
    for (i = 0; i < 10; i++) {
        customers[i].name[0] = '\0';
        customers[i].phone = 0;
    }
    num_products = 0;
    num_customers = 0;

    // Display menu
    printf("Medical Store Management System\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. Delete Product\n");
    printf("4. Search Product\n");
    printf("5. Add Customer\n");
    printf("6. Update Customer\n");
    printf("7. Delete Customer\n");
    printf("8. Search Customer\n");
    printf("9. Display Products\n");
    printf("10. Display Customers\n");
    printf("11. Quit\n");
    printf("Enter your choice: ");

    // Get user input and perform corresponding action
    choice = getchar();

    switch (choice) {
        case 1:
            // Add product
            printf("Enter product name: ");
            gets(products[num_products].name);
            printf("Enter product price: ");
            scanf("%d", &products[num_products].price);
            printf("Enter product quantity: ");
            scanf("%d", &products[num_products].quantity);
            num_products++;
            break;
        case 2:
            // Update product
            printf("Enter product name: ");
            gets(products[num_products].name);
            printf("Enter new product price: ");
            scanf("%d", &products[num_products].price);
            printf("Enter new product quantity: ");
            scanf("%d", &products[num_products].quantity);
            break;
        case 3:
            // Delete product
            printf("Enter product name: ");
            gets(products[num_products].name);
            for (i = 0; i < num_products; i++) {
                if (strcmp(products[i].name, products[num_products].name) == 0) {
                    for (j = i; j < num_products - 1; j++) {
                        products[j] = products[j + 1];
                    }
                    num_products--;
                    break;
                }
            }
            break;
        case 4:
            // Search product
            printf("Enter product name: ");
            gets(products[num_products].name);
            for (i = 0; i < num_products; i++) {
                if (strcmp(products[i].name, products[num_products].name) == 0) {
                    printf("Product found!\n");
                    printf("Product Name: %s\n", products[i].name);
                    printf("Product Price: %d\n", products[i].price);
                    printf("Product Quantity: %d\n", products[i].quantity);
                    break;
                }
            }
            break;
        case 5:
            // Add customer
            printf("Enter customer name: ");
            gets(customers[num_customers].name);
            printf("Enter customer phone: ");
            scanf("%d", &customers[num_customers].phone);
            num_customers++;
            break;
        case 6:
            // Update customer
            printf("Enter customer name: ");
            gets(customers[num_customers].name);
            printf("Enter new customer phone: ");
            scanf("%d", &customers[num_customers].phone);
            break;
        case 7:
            // Delete customer
            printf("Enter customer name: ");
            gets(customers[num_customers].name);
            for (i = 0; i < num_customers; i++) {
                if (strcmp(customers[i].name, customers[num_customers].name) == 0) {
                    for (j = i; j < num_customers - 1; j++) {
                        customers[j] = customers[j + 1];
                    }
                    num_customers--;
                    break;
                }
            }
            break;
        case 8:
            // Search customer
            printf("Enter customer name: ");
            gets(customers[num_customers].name);
            for (i = 0; i < num_customers; i++) {
                if (strcmp(customers[i].name, customers[num_customers].name) == 0) {
                    printf("Customer found!\n");
                    printf("Customer Name: %s\n", customers[i].name);
                    printf("Customer Phone: %d\n", customers[i].phone);
                    break;
                }
            }
            break;
        case 9:
            // Display products
            for (i = 0; i < num_products; i++) {
                printf("Product Name: %s\n", products[i].name);
                printf("Product Price: %d\n", products[i].price);
                printf("Product Quantity: %d\n", products[i].quantity);
            }
            break;
        case 10:
            // Display customers
            for (i = 0; i < num_customers; i++) {
                printf("Customer Name: %s\n", customers[i].name);
                printf("Customer Phone: %d\n", customers[i].phone);
            }
            break;
        case 11:
            // Quit
            printf("Exiting program...\n");
            return 0;
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}