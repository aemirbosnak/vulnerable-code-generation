//FormAI DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define struct for products
struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Define global variables
int num_products = 0;
struct Product products[100];

// Define function prototypes
void add_product();
void update_product();
void delete_product();
void display_products();

int main() {
    int choice;
    printf("Welcome to the Product Inventory System!\n");

    // Display menu and take user input until they choose to exit
    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a product\n");
        printf("2. Update a product\n");
        printf("3. Delete a product\n");
        printf("4. Display all products\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                update_product();
                break;
            case 3:
                delete_product();
                break;
            case 4:
                display_products();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}

void add_product() {
    struct Product p;
    p.id = num_products + 1;

    printf("\nEnter product name: ");
    scanf("%s", &p.name);

    printf("Enter quantity: ");
    scanf("%d", &p.quantity);

    printf("Enter price: ");
    scanf("%f", &p.price);

    products[num_products] = p;
    num_products++;

    printf("\nProduct added successfully.\n");
}

void update_product() {
    int id;
    int found = 0;

    printf("\nEnter product ID to update: ");
    scanf("%d", &id);

    // Find product with matching ID
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            printf("\nEnter new product name: ");
            scanf("%s", &products[i].name);

            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);

            printf("Enter new price: ");
            scanf("%f", &products[i].price);

            printf("\nProduct updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

void delete_product() {
    int id;
    int found = 0;

    printf("\nEnter product ID to delete: ");
    scanf("%d", &id);

    // Find product with matching ID and remove it from the array
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            for (int j = i; j < num_products - 1; j++) {
                products[j] = products[j+1];
            }

            num_products--;
            printf("\nProduct deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

void display_products() {
    printf("\n%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");

    for (int i = 0; i < num_products; i++) {
        printf("%-5d %-20s %-10d $%-9.2f\n",
               products[i].id, products[i].name,
               products[i].quantity, products[i].price);
    }
}