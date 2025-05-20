//FormAI DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h> 

// Define the struct for the product
typedef struct product {
    char name[50];
    int quantity;
    double price;
} Product;

// Declare the array of products
Product products[100];

// Declare the current number of products
int num_products = 0;

// Function to add a product
void add_product() {
    printf("Enter the product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter the product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter the product price: ");
    scanf("%lf", &products[num_products].price);
    num_products++;
    printf("Product added successfully!\n");
}

// Function to remove a product
void remove_product() {
    int index;
    printf("Enter the index of the product to remove: ");
    scanf("%d", &index);
    if (index >= num_products) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }
    num_products--;
    printf("Product removed successfully!\n");
}

// Function to display the inventory
void display_inventory() {
    printf("Product Inventory:\n");
    printf("==================\n");
    for (int i = 0; i < num_products; i++) {
        printf("Product Name: %s\n", products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2lf\n", products[i].price);
        printf("==================\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("Product Inventory System\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display the inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}