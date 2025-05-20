//FormAI DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct that will hold product information
typedef struct Product {
    int id; // unique product id
    char name[50]; // product name
    int quantity; // product quantity
    float price; // product price
} Product;

// Function prototypes
void addProduct(Product *inventory, int *numProducts);
void displayInventory(Product *inventory, int numProducts);
void searchById(Product *inventory, int numProducts);
void searchByName(Product *inventory, int numProducts);
void deleteProduct(Product *inventory, int *numProducts);

int main() {
    int choice, numProducts = 0;
    Product *inventory = malloc(sizeof(Product)); // allocate memory for one product

    if (inventory == NULL) { // check if malloc fails
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    while (1) {
        // display menu options
        printf("\nProduct Inventory System\n\n");
        printf("1. Add a product\n");
        printf("2. Display inventory\n");
        printf("3. Search by product ID\n");
        printf("4. Search by product name\n");
        printf("5. Delete a product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                displayInventory(inventory, numProducts);
                break;
            case 3:
                searchById(inventory, numProducts);
                break;
            case 4:
                searchByName(inventory, numProducts);
                break;
            case 5:
                deleteProduct(inventory, &numProducts);
                break;
            case 6:
                free(inventory);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}

// Function to add a new product to the inventory
void addProduct(Product *inventory, int *numProducts) {
    int id, i;
    char name[50];
    float price;
    printf("\nEnter product ID: ");
    scanf("%d", &id);
    for (i = 0; i < *numProducts; i++) { // check if id is already taken
        if (inventory[i].id == id) {
            printf("Product ID already exists. Try again.\n");
            return;
        }
    }
    printf("Enter product name: ");
    scanf(" %[^\n]", name);
    printf("Enter product price: ");
    scanf("%f", &price);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*numProducts].quantity);
    inventory[*numProducts].id = id;
    inventory[*numProducts].price = price;
    strcpy(inventory[*numProducts].name, name);
    (*numProducts)++;
    inventory = realloc(inventory, (*numProducts + 1) * sizeof(Product)); // expand inventory memory
}

// Function to display the entire inventory
void displayInventory(Product *inventory, int numProducts) {
    int i;
    printf("\n%-10s %-30s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
    for (i = 0; i < numProducts; i++) {
        printf("%-10d %-30s $%-10.2f %-10d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Function to search for a product by id
void searchById(Product *inventory, int numProducts) {
    int id, i;
    printf("\nEnter product ID: ");
    scanf("%d", &id);
    for (i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            printf("\n%-10s %-30s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
            printf("%-10d %-30s $%-10.2f %-10d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("Product ID not found.\n");
}

// Function to search for a product by name
void searchByName(Product *inventory, int numProducts) {
    char name[50];
    int i, found = 0;
    printf("\nEnter product name: ");
    scanf(" %[^\n]", name);
    for (i = 0; i < numProducts; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (!found) {
                printf("\n%-10s %-30s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
                found = 1;
            }
            printf("%-10d %-30s $%-10.2f %-10d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
    }
    if (!found) {
        printf("Product name not found.\n");
    }
}

// Function to delete a product from the inventory
void deleteProduct(Product *inventory, int *numProducts) {
    int id, i, found = 0;
    printf("\nEnter product ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < *numProducts; i++) {
        if (inventory[i].id == id) {
            if (i != (*numProducts - 1)) { // if not last product, move last product to current spot
                inventory[i] = inventory[*numProducts - 1];
            }
            (*numProducts)--;
            inventory = realloc(inventory, (*numProducts) * sizeof(Product)); // shrink inventory memory
            printf("Product deleted successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product ID not found.\n");
    }
}