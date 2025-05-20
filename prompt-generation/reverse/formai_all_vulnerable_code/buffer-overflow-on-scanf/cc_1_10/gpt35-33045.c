//FormAI DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Structure to store product details
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Array to hold inventory
Product inventory[MAX_PRODUCTS];
int numProducts = 0;

// Function to add product to inventory
void addProduct() {
    Product p;

    printf("\nEnter product ID: ");
    scanf("%d", &p.id);
    getchar(); // Ignore newline character

    // Check if product already exists
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == p.id) {
            printf("Product with ID %d already exists!", p.id);
            return;
        }
    }

    printf("Enter product name: ");
    fgets(p.name, 50, stdin);

    printf("Enter quantity: ");
    scanf("%d", &p.quantity);

    printf("Enter price: ");
    scanf("%f", &p.price);

    inventory[numProducts++] = p;

    printf("Product added successfully.\n");
}

// Function to display all products in inventory
void displayInventory() {
    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < numProducts; i++) {
        printf("%-10d %-20s %-10d %-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    printf("------------------------------------------------------\n");
}

// Function to search for a product by ID
void searchProduct() {
    int id;
    printf("\nEnter product ID: ");
    scanf("%d", &id);

    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
            printf("------------------------------------------------------\n");
            printf("%-10d %-20s %-10d %-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            printf("------------------------------------------------------\n");
            return;
        }
    }

    printf("Product not found.\n");
}

// Function to update quantity of a product
void updateQuantity() {
    int id, quantity;
    printf("\nEnter product ID: ");
    scanf("%d", &id);

    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            printf("\nEnter new quantity: ");
            scanf("%d", &quantity);

            inventory[i].quantity = quantity;

            printf("Quantity updated successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

// Function to delete a product from inventory
void deleteProduct() {
    int id;
    printf("\nEnter product ID: ");
    scanf("%d", &id);

    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            // Shift elements after i one position to the left
            for (int j = i; j < numProducts - 1; j++) {
                inventory[j] = inventory[j + 1];
            }

            numProducts--;

            printf("Product deleted successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

int main() {
    int choice;

    do {
        // Display menu
        printf("\n1. Add product\n");
        printf("2. Display inventory\n");
        printf("3. Search for a product\n");
        printf("4. Update quantity\n");
        printf("5. Delete product\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                updateQuantity();
                break;
            case 5:
                deleteProduct();
                break;
            case 6:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}