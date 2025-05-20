//FormAI DATASET v1.0 Category: Product Inventory System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// structure for individual product
typedef struct {
    int id;
    char name[20];
    int price;
    int stock;
} product;

// function to add a new product to inventory
void addProduct(product inv[], int *count) {
    printf("Enter product id: ");
    scanf("%d", &inv[*count].id);
    printf("Enter product name: ");
    scanf("%s", inv[*count].name);
    printf("Enter product price: ");
    scanf("%d", &inv[*count].price);
    printf("Enter product stock: ");
    scanf("%d", &inv[*count].stock);
    (*count)++;
    printf("Product added successfully!\n");
}

// function to display all products in inventory
void displayInventory(product inv[], int count) {
    printf("\n### PRODUCT INVENTORY ###\n");
    printf("%-5s | %-20s | %-10s | %-10s\n", "ID", "Name", "Price", "Stock");
    printf("----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d | %-20s | %-10d | %-10d\n", inv[i].id, inv[i].name, inv[i].price, inv[i].stock);
    }
    printf("----------------------------------------------\n");
}

// function to search for a product by id
void searchById(product inv[], int count) {
    int id, index = -1;
    printf("Enter product id to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inv[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found!\n");
    } else {
        printf("%-5s | %-20s | %-10s | %-10s\n", "ID", "Name", "Price", "Stock");
        printf("----------------------------------------------\n");
        printf("%-5d | %-20s | %-10d | %-10d\n", inv[index].id, inv[index].name, inv[index].price, inv[index].stock);
        printf("----------------------------------------------\n");
    }
}

// function to update stock of a product by id
void updateStock(product inv[], int count) {
    int id, index = -1, newStock;
    printf("Enter product id to update stock: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inv[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found!\n");
    } else {
        printf("Enter new stock: ");
        scanf("%d", &newStock);
        inv[index].stock = newStock;
        printf("Product stock updated successfully!\n");
    }
}

int main() {
    product inventory[100]; // assuming maximum number of products to be 100
    int count = 0, choice;
    printf("### WELCOME TO PRODUCT INVENTORY SYSTEM ###\n");
    do {
        printf("\n1. Add a new product\n");
        printf("2. Display inventory\n");
        printf("3. Search for a product by id\n");
        printf("4. Update stock of a product by id\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                searchById(inventory, count);
                break;
            case 4:
                updateStock(inventory, count);
                break;
            case 5:
                printf("Thank you for using our product inventory system!\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
    } while (choice != 5);
    return 0;
}