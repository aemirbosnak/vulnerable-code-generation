//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a product in the inventory
typedef struct {
    char name[100];
    float price;
    int quantity;
} Product;

// Define the structure for the database
typedef struct {
    Product* products;
    int numProducts;
    int capacity;
} Database;

// Function to add a product to the database
void addProduct(Database* db, const char* name, float price, int quantity) {
    if (db->numProducts >= db->capacity) {
        fprintf(stderr, "Database is full\n");
        return;
    }
    Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.price = price;
    newProduct.quantity = quantity;
    db->products[db->numProducts] = newProduct;
    db->numProducts++;
}

// Function to remove a product from the database
void removeProduct(Database* db, const char* name) {
    int i;
    for (i = 0; i < db->numProducts; i++) {
        if (strcmp(db->products[i].name, name) == 0) {
            for (int j = i; j < db->numProducts - 1; j++) {
                db->products[j] = db->products[j + 1];
            }
            db->numProducts--;
            break;
        }
    }
}

// Function to update the price of a product in the database
void updatePrice(Database* db, const char* name, float newPrice) {
    int i;
    for (i = 0; i < db->numProducts; i++) {
        if (strcmp(db->products[i].name, name) == 0) {
            db->products[i].price = newPrice;
            break;
        }
    }
}

// Function to display the current inventory
void displayInventory(const Database* db) {
    int i;
    printf("Current inventory:\n");
    for (i = 0; i < db->numProducts; i++) {
        printf("Product: %s\n", db->products[i].name);
        printf("Price: %.2f\n", db->products[i].price);
        printf("Quantity: %d\n", db->products[i].quantity);
        printf("\n");
    }
}

// Function to create a new database
Database* createDatabase(int capacity) {
    Database* db = malloc(sizeof(Database));
    if (db == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL;
    }
    db->products = malloc(capacity * sizeof(Product));
    if (db->products == NULL) {
        free(db);
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL;
    }
    db->numProducts = 0;
    db->capacity = capacity;
    return db;
}

// Main function
int main() {
    int choice, capacity, numProducts;
    Database* db = NULL;

    printf("Welcome to the Inventory Management System!\n");
    printf("1. Create a new database\n");
    printf("2. Add a product to the database\n");
    printf("3. Remove a product from the database\n");
    printf("4. Update the price of a product in the database\n");
    printf("5. Display the current inventory\n");
    printf("6. Quit\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the capacity of the database: ");
            scanf("%d", &capacity);
            db = createDatabase(capacity);
            if (db == NULL) {
                return 1;
            }
            break;
        case 2:
            printf("Enter the name of the product: ");
            scanf("%s", db->products[db->numProducts].name);
            printf("Enter the price of the product: ");
            scanf("%f", &db->products[db->numProducts].price);
            printf("Enter the quantity of the product: ");
            scanf("%d", &db->products[db->numProducts].quantity);
            db->numProducts++;
            break;
        case 3:
            printf("Enter the name of the product to remove: ");
            scanf("%s", db->products[--db->numProducts].name);
            break;
        case 4:
            printf("Enter the name of the product to update the price: ");
            scanf("%s", db->products[--db->numProducts].name);
            printf("Enter the new price of the product: ");
            scanf("%f", &db->products[--db->numProducts].price);
            break;
        case 5:
            displayInventory(db);
            break;
        case 6:
            free(db->products);
            free(db);
            return 0;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}