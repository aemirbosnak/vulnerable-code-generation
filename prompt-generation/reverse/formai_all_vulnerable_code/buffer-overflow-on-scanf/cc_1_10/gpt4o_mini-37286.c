//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

// Function Prototypes
void addProduct();
void displayProducts();
void updateProduct();
void deleteProduct();
void searchProduct();
void generateReport();

int main() {
    int choice;

    while (1) {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Generate Report\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                generateReport();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product p;
    p.id = productCount + 1;

    printf("Enter product name: ");
    getchar(); // To consume the newline character
    fgets(p.name, NAME_LENGTH, stdin);
    p.name[strcspn(p.name, "\n")] = 0; // Remove the newline character

    printf("Enter quantity: ");
    scanf("%d", &p.quantity);

    printf("Enter price: ");
    scanf("%f", &p.price);

    inventory[productCount] = p;
    productCount++;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Product ID not found!\n");
        return;
    }

    Product *p = &inventory[id - 1];

    printf("Updating product: %s\n", p->name);
    printf("Enter new name (leave blank to keep current): ");
    getchar(); // To consume the newline character
    char newName[NAME_LENGTH];
    fgets(newName, NAME_LENGTH, stdin);
    if (strcmp(newName, "\n") != 0) {
        newName[strcspn(newName, "\n")] = 0; // Remove the newline character
        strcpy(p->name, newName);
    }

    printf("Enter new quantity (current: %d): ", p->quantity);
    scanf("%d", &p->quantity);

    printf("Enter new price (current: %.2f): ", p->price);
    scanf("%f", &p->price);
    
    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Product ID not found!\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    productCount--;
    printf("Product deleted successfully!\n");
}

void searchProduct() {
    char name[NAME_LENGTH];
    printf("Enter product name to search: ");
    getchar(); // To consume the newline character
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove the newline character

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < productCount; i++) {
        if (strcasecmp(inventory[i].name, name) == 0) {
            printf("Found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }

    printf("No matching products found.\n");
}

void generateReport() {
    float totalValue = 0.0;
    printf("\n--- Inventory Report ---\n");
    printf("ID\tName\t\tQuantity\tPrice\tTotal Value\n");
    for (int i = 0; i < productCount; i++) {
        float productValue = inventory[i].quantity * inventory[i].price;
        totalValue += productValue;
        printf("%d\t%s\t%d\t\t%.2f\t%.2f\n", 
            inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price, productValue);
    }
    printf("Total Inventory Value: %.2f\n", totalValue);
}