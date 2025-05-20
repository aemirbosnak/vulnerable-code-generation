//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int id;
    int quantity;
    float price;
} Product;

typedef struct {
    Product products[MAX_ITEMS];
    int count;
} Inventory;

void initializeInventory(Inventory* inv) {
    inv->count = 0;
}

int addProduct(Inventory* inv, const char* name, int id, int quantity, float price) {
    if (inv->count >= MAX_ITEMS) {
        printf("Inventory full. Cannot add more products.\n");
        return -1;
    }

    strcpy(inv->products[inv->count].name, name);
    inv->products[inv->count].id = id;
    inv->products[inv->count].quantity = quantity;
    inv->products[inv->count].price = price;
    inv->count++;

    printf("Product added: %s\n", name);
    return 0;
}

void displayInventory(const Inventory* inv) {
    printf("\n--- Inventory List ---\n");
    for (int i = 0; i < inv->count; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n",
               inv->products[i].id, inv->products[i].name,
               inv->products[i].quantity, inv->products[i].price);
    }
    printf("-----------------------\n");
}

int updateProduct(Inventory* inv, int id, int newQuantity) {
    for (int i = 0; i < inv->count; i++) {
        if (inv->products[i].id == id) {
            inv->products[i].quantity = newQuantity;
            printf("Updated product ID %d to new quantity %d.\n", id, newQuantity);
            return 0;
        }
    }
    printf("Product ID %d not found.\n", id);
    return -1;
}

int removeProduct(Inventory* inv, int id) {
    for (int i = 0; i < inv->count; i++) {
        if (inv->products[i].id == id) {
            for (int j = i; j < inv->count - 1; j++) {
                inv->products[j] = inv->products[j + 1];
            }
            inv->count--;
            printf("Removed product ID %d.\n", id);
            return 0;
        }
    }
    printf("Product ID %d not found.\n", id);
    return -1;
}

void saveInventoryToFile(const Inventory* inv, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(inv, sizeof(Inventory), 1, file);
    fclose(file);
    printf("Inventory saved to %s.\n", filename);
}

void loadInventoryFromFile(Inventory* inv, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    fread(inv, sizeof(Inventory), 1, file);
    fclose(file);
    printf("Inventory loaded from %s.\n", filename);
}

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. Update Product Quantity\n");
    printf("3. Remove Product\n");
    printf("4. Display Inventory\n");
    printf("5. Save Inventory to File\n");
    printf("6. Load Inventory from File\n");
    printf("7. Exit\n");
    printf("-------------------------------\n");
    printf("Select an option: ");
}

int main() {
    Inventory inv;
    initializeInventory(&inv);
    
    int choice;
    char filename[50];
    char name[50];
    int id, quantity;
    float price;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                printf("Enter product price: ");
                scanf("%f", &price);
                addProduct(&inv, name, id, quantity, price);
                break;

            case 2:
                printf("Enter product ID to update: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateProduct(&inv, id, quantity);
                break;

            case 3:
                printf("Enter product ID to remove: ");
                scanf("%d", &id);
                removeProduct(&inv, id);
                break;

            case 4:
                displayInventory(&inv);
                break;

            case 5:
                printf("Enter filename to save inventory: ");
                scanf("%s", filename);
                saveInventoryToFile(&inv, filename);
                break;

            case 6:
                printf("Enter filename to load inventory: ");
                scanf("%s", filename);
                loadInventoryFromFile(&inv, filename);
                break;

            case 7:
                printf("Exiting the program.\n");
                exit(0);
                break;

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}