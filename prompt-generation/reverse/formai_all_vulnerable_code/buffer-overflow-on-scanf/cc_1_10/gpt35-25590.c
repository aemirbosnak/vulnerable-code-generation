//FormAI DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <string.h>

// Define maximum size of products array
#define MAX_SIZE 100

// Structure to hold product details
struct product {
    int id;
    char name[20];
    float price;
    int quantity;
};

// Declare global products array
struct product products[MAX_SIZE];

// Declare global inventory count
int count = 0;

// Function to add a new product
void addProduct() {
    struct product p;
    printf("\nEnter product id: ");
    scanf("%d", &p.id);
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    products[count++] = p;
    printf("\nProduct added successfully!\n\n");
}

// Function to delete a product
void deleteProduct() {
    int id, i, j;
    printf("\nEnter product id to delete: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (products[i].id == id) {
            for (j = i; j < count - 1; j++)
                products[j] = products[j + 1];
            count--;
            printf("\nProduct deleted successfully!\n\n");
            return;
        }
    }
    printf("\nProduct not found! Please try again.\n\n");
}

// Function to search for a product
void searchProduct() {
    int id, i;
    printf("\nEnter product id to search: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (products[i].id == id) {
            printf("\nProduct details:\n");
            printf("ID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n\n",
                   products[i].id, products[i].name, products[i].price, products[i].quantity);
            return;
        }
    }
    printf("\nProduct not found! Please try again.\n\n");
}

// Function to display all products
void displayProducts() {
    int i;
    if (count == 0) {
        printf("\nInventory is empty!\n\n");
        return;
    }
    printf("\nInventory details:\n");
    for (i = 0; i < count; i++) {
        printf("ID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n\n",
               products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    int choice;
    do {
        // Display menu
        printf("Product Inventory System\n");
        printf("1. Add a product\n");
        printf("2. Delete a product\n");
        printf("3. Search for a product\n");
        printf("4. Display all products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                deleteProduct();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                displayProducts();
                break;
            case 5:
                printf("\nExiting program... Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n\n");
        }
    } while (choice != 5);

    return 0;
}