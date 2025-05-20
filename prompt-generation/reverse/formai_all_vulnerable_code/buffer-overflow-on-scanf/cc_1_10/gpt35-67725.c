//FormAI DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[50];
    int quantity;
    float price;
};

struct Product products[MAX_PRODUCTS];
int num_products = 0;

// Function to add product to inventory
void addProduct() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Maximum products limit reached!\n");
        return;
    }

    struct Product p;
    printf("Enter product name: ");
    fgets(p.name, sizeof(p.name), stdin);
    printf("Enter quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter price: ");
    scanf("%f", &p.price);
    getchar(); // to consume the newline character left by scanf

    products[num_products] = p;
    num_products++;

    printf("Product added to inventory successfully!\n");
}

// Function to search for a product in inventory
void searchProduct() {
    char name[50];
    printf("Enter product name: ");
    fgets(name, sizeof(name), stdin);

    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Product found at index %d.\n", i);
            printf("Name: %s", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found in inventory!\n");
    }
}

// Function to display all products in inventory
void displayInventory() {
    if (num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("---------------\n");
    printf("Inventory Items\n");
    printf("---------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("Index: %d\n", i);
        printf("Name: %s", products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: %.2f\n", products[i].price);
        printf("---------------\n");
    }
}

// Function to delete a product from inventory
void deleteProduct() {
    int index;
    printf("Enter index of product to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_products) {
        printf("Error: Invalid index!\n");
        return;
    }

    for (int i = index; i < num_products-1; i++) {
        products[i] = products[i+1];
    }
    num_products--;

    printf("Product deleted from inventory successfully!\n");
}

int main() {
    int choice;

    do {
        printf("\n\n---------------\n");
        printf("Product Inventory System\n");
        printf("---------------\n");
        printf("1. Add product to inventory\n");
        printf("2. Search for product in inventory\n");
        printf("3. Display all products in inventory\n");
        printf("4. Delete product from inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character left by scanf

        switch (choice) {
            case 1: addProduct();
                    break;
            case 2: searchProduct();
                    break;
            case 3: displayInventory();
                    break;
            case 4: deleteProduct();
                    break;
            case 5: printf("Exiting program...\n");
                    break;
            default: printf("Invalid choice, please try again!\n");
        }
    } while (choice != 5);

    return 0;
}