//FormAI DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

// struct to store product details
typedef struct {
    int id;
    char name[20];
    float price;
    int quantity;
} Product;

int numProducts = 0; // global variable to keep track of number of products
Product inventory[MAX_SIZE]; // global array to store all the products

// function to add a new product to the inventory
void addProduct() {
    if (numProducts == MAX_SIZE) {
        printf("Inventory is full.\n");
        return;
    }

    Product newProduct;

    printf("Enter id: ");
    scanf("%d", &newProduct.id);

    printf("Enter name: ");
    scanf("%s", newProduct.name);

    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[numProducts++] = newProduct;
    printf("Product added successfully!\n");
}

// function to display all the products in the inventory
void displayInventory() {
    printf("\n--- Inventory ---\n");
    printf("ID\tName\tPrice\tQuantity\n");

    for (int i = 0; i < numProducts; i++) {
        Product currentProduct = inventory[i];
        printf("%d\t%s\t%.2f\t%d\n", currentProduct.id, currentProduct.name, currentProduct.price, currentProduct.quantity);
    }
    printf("-----------------\n");
}

// function to search for a product by id and return its index in the inventory array
int searchProduct(int id) {
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }
    return -1;
}

// function to update the quantity of a product in the inventory
void updateQuantity() {
    int id, quantity;
    printf("Enter the id of the product you want to update: ");
    scanf("%d", &id);

    int index = searchProduct(id);
    if (index == -1) {
        printf("Product with id=%d does not exist in inventory.\n", id);
        return;
    }

    printf("Enter the new quantity: ");
    scanf("%d", &quantity);

    inventory[index].quantity = quantity;
    printf("Product quantity updated successfully!\n");
}

// function to delete a product from the inventory
void deleteProduct() {
    int id;
    printf("Enter the id of the product you want to delete: ");
    scanf("%d", &id);

    int index = searchProduct(id);
    if (index == -1) {
        printf("Product with id=%d does not exist in inventory.\n", id);
        return;
    }

    for (int i = index; i < numProducts-1; i++) {
        inventory[i] = inventory[i+1];
    }
    numProducts--;
    printf("Product with id=%d deleted successfully!\n", id);
}

// main function to display menu and handle user input
int main() {
    int choice;
    bool exit = false;
    printf("\nWelcome to the Product Inventory System!\n");

    while (!exit) {
        printf("\nMenu:\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Quantity\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                exit = true;
                printf("Thank you for using the Product Inventory System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}