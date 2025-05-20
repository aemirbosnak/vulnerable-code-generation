//FormAI DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 1000      // Maximum number of products in inventory
#define NAME_LENGTH 50         // Maximum length of product name
#define MAX_SALES 500          // Maximum number of sales in recorded history

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

typedef struct {
    int product_id;
    int quantity;
    float price_sold;
} Sale;

int num_products = 0;
int num_sales = 0;
Product products[MAX_PRODUCTS];
Sale sales[MAX_SALES];

// Function to add a new product to the inventory
void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: inventory is full\n");
        return;
    }

    Product new_product;

    printf("Enter product name: ");
    scanf("%s", new_product.name);

    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);

    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    new_product.id = num_products + 1;
    products[num_products++] = new_product;

    printf("Product added successfully!\n");
}

// Function to remove a product from the inventory
void remove_product() {
    int product_id;
    printf("Enter product id: ");
    scanf("%d", &product_id);

    int product_index = -1;
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == product_id) {
            product_index = i;
            break;
        }
    }

    if (product_index == -1) {
        printf("Error: product not found\n");
        return;
    }

    for (int i = product_index; i < num_products - 1; i++) {
        products[i] = products[i+1];
    }

    num_products--;

    printf("Product removed successfully!\n");
}

// Function to display a list of all products in the inventory
void display_products() {
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

// Function to add a new sale to the recorded history
void add_sale() {
    if (num_sales >= MAX_SALES) {
        printf("Error: sale history is full\n");
        return;
    }

    int product_id, quantity;
    printf("Enter product id: ");
    scanf("%d", &product_id);

    int product_index = -1;
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == product_id) {
            product_index = i;
            break;
        }
    }

    if (product_index == -1) {
        printf("Error: product not found\n");
        return;
    }

    printf("Enter quantity sold: ");
    scanf("%d", &quantity);

    if (quantity > products[product_index].quantity) {
        printf("Error: not enough stock\n");
        return;
    }

    float price_sold = quantity * products[product_index].price;

    Sale new_sale;
    new_sale.product_id = product_id;
    new_sale.quantity = quantity;
    new_sale.price_sold = price_sold;

    sales[num_sales++] = new_sale;

    products[product_index].quantity -= quantity;

    printf("Sale recorded successfully!\n");
}

// Function to display a list of all sales in the recorded history
void display_sales() {
    printf("Product ID\tQuantity\tPrice Sold\n");
    for (int i = 0; i < num_sales; i++) {
        printf("%d\t\t%d\t\t%.2f\n", sales[i].product_id, sales[i].quantity, sales[i].price_sold);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("Product Inventory System\n");
        printf("------------------------\n");
        printf("1. Add a Product\n");
        printf("2. Remove a Product\n");
        printf("3. Display All Products\n");
        printf("4. Add a Sale\n");
        printf("5. Display All Sales\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_products();
                break;
            case 4:
                add_sale();
                break;
            case 5:
                display_sales();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}