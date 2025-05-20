//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: complete
/*
 * Medical Store Management System
 *
 * This program allows the user to manage a medical store, including
 * inventory management, customer management, and sales management.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Structure to represent a product in the inventory
 */
struct Product {
    char name[50];
    int price;
    int quantity;
};

/*
 * Structure to represent a customer in the customer database
 */
struct Customer {
    char name[50];
    char address[50];
    char phone[20];
    int points;
};

/*
 * Structure to represent a sale in the sales database
 */
struct Sale {
    char product_name[50];
    char customer_name[50];
    int price;
    int quantity;
};

/*
 * Function to add a product to the inventory
 */
void addProduct(struct Product *product) {
    printf("Enter the name of the product: ");
    scanf("%s", product->name);
    printf("Enter the price of the product: ");
    scanf("%d", &product->price);
    printf("Enter the quantity of the product: ");
    scanf("%d", &product->quantity);
}

/*
 * Function to add a customer to the customer database
 */
void addCustomer(struct Customer *customer) {
    printf("Enter the name of the customer: ");
    scanf("%s", customer->name);
    printf("Enter the address of the customer: ");
    scanf("%s", customer->address);
    printf("Enter the phone number of the customer: ");
    scanf("%s", customer->phone);
}

/*
 * Function to add a sale to the sales database
 */
void addSale(struct Sale *sale) {
    printf("Enter the name of the product: ");
    scanf("%s", sale->product_name);
    printf("Enter the name of the customer: ");
    scanf("%s", sale->customer_name);
    printf("Enter the price of the product: ");
    scanf("%d", &sale->price);
    printf("Enter the quantity of the product: ");
    scanf("%d", &sale->quantity);
}

/*
 * Function to display the inventory
 */
void displayInventory(struct Product *products, int num_products) {
    printf("Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s - %d - %d\n", products[i].name, products[i].price, products[i].quantity);
    }
}

/*
 * Function to display the customer database
 */
void displayCustomers(struct Customer *customers, int num_customers) {
    printf("Customer Database:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("%s - %s - %s - %d\n", customers[i].name, customers[i].address, customers[i].phone, customers[i].points);
    }
}

/*
 * Function to display the sales database
 */
void displaySales(struct Sale *sales, int num_sales) {
    printf("Sales Database:\n");
    for (int i = 0; i < num_sales; i++) {
        printf("%s - %s - %d - %d\n", sales[i].product_name, sales[i].customer_name, sales[i].price, sales[i].quantity);
    }
}

/*
 * Main function
 */
int main() {
    // Initialize the inventory
    struct Product products[10];
    int num_products = 0;

    // Initialize the customer database
    struct Customer customers[10];
    int num_customers = 0;

    // Initialize the sales database
    struct Sale sales[10];
    int num_sales = 0;

    // Main menu
    int option;
    do {
        printf("Welcome to the Medical Store Management System\n");
        printf("1. Add a product to the inventory\n");
        printf("2. Add a customer to the customer database\n");
        printf("3. Add a sale to the sales database\n");
        printf("4. Display the inventory\n");
        printf("5. Display the customer database\n");
        printf("6. Display the sales database\n");
        printf("7. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct(&products[num_products]);
                num_products++;
                break;
            case 2:
                addCustomer(&customers[num_customers]);
                num_customers++;
                break;
            case 3:
                addSale(&sales[num_sales]);
                num_sales++;
                break;
            case 4:
                displayInventory(products, num_products);
                break;
            case 5:
                displayCustomers(customers, num_customers);
                break;
            case 6:
                displaySales(sales, num_sales);
                break;
            case 7:
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 7);

    return 0;
}