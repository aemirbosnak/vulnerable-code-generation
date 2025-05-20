//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

// Function Prototypes
void addProduct();
void displayInventory();
void updateStock();
void menu();

int main() {
    printf("Welcome to the Enthusiastic Warehouse Management System!\n");
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n========== Main Menu ==========\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Stock\n");
        printf("4. Exit\n");
        printf("Please select an option (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateStock();
                break;
            case 4:
                printf("Thank you for using the Warehouse Management System! Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while(choice != 4);
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Cannot add more products. Inventory full!\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1;

    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount] = newProduct;
    productCount++;
    
    printf("Product added successfully!\n");
}

void displayInventory() {
    if (productCount == 0) {
        printf("Inventory is empty! Add products to see them here.\n");
        return;
    }
    
    printf("\n========= Inventory =========\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n", 
                inventory[i].id, inventory[i].name, 
                inventory[i].quantity, inventory[i].price);
    }
    printf("============================\n");
}

void updateStock() {
    int id, newQuantity;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID! Please try again.\n");
        return;
    }

    printf("Enter new quantity for %s: ", inventory[id - 1].name);
    scanf("%d", &newQuantity);

    inventory[id - 1].quantity = newQuantity;
    printf("Stock updated successfully for %s!\n", inventory[id - 1].name);
}