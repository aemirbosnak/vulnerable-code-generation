//FormAI DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>

// Declare product structure
struct product {
    int id;
    char name[20];
    float price;
    int quantity;
};

// Declare function to add new product to inventory
void add_product(int *num_products, struct product inventory[]) {
    printf("Enter product name: ");
    scanf("%s", inventory[*num_products].name);
    printf("Enter product price: ");
    scanf("%f", &inventory[*num_products].price);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*num_products].quantity);
    inventory[*num_products].id = *num_products + 1;
    *num_products += 1;
    printf("Product added to inventory.\n");
}

// Declare function to search for a product by id
void search_product_by_id(int num_products, struct product inventory[]) {
    int search_id;
    printf("Enter product id: ");
    scanf("%d", &search_id);
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == search_id) {
            printf("Product found: %s\n", inventory[i].name);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            return;
        }
    }
    printf("No product found with that id.\n");
}

// Declare function to search for a product by name
void search_product_by_name(int num_products, struct product inventory[]) {
    char search_name[20];
    printf("Enter product name: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, search_name) == 0) {
            printf("Product found: %s\n", inventory[i].name);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            return;
        }
    }
    printf("No product found with that name.\n");
}

// Declare function to display all products in inventory
void display_inventory(int num_products, struct product inventory[]) {
    printf("Product Inventory:\n");
    printf("%-5s%-20s%-10s%-10s\n", "ID", "Name", "Price", "Quantity");
    for (int i = 0; i < num_products; i++) {
        printf("%-5d%-20s%-10.2f%-10d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Main function
int main() {
    struct product inventory[50];
    int num_products = 0;
    int choice;
    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add new product\n");
        printf("2. Search for product by id\n");
        printf("3. Search for product by name\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(&num_products, inventory);
                break;
            case 2:
                search_product_by_id(num_products, inventory);
                break;
            case 3:
                search_product_by_name(num_products, inventory);
                break;
            case 4:
                display_inventory(num_products, inventory);
                break;
            case 5:
                printf("Thank you for using the Product Inventory System!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}