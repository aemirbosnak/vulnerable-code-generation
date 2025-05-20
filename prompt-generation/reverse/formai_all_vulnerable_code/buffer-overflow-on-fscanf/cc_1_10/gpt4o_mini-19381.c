//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: scientific
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

void addProduct() {
    if(productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    getchar(); // consume newline
    
    printf("Enter Product Name: ");
    fgets(newProduct.name, sizeof(newProduct.name), stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline
    
    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter Product Price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount++] = newProduct;
    
    printf("Product added successfully!\n");
}

void viewProducts() {
    if(productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    
    for(int i = 0; i < productCount; i++) {
        printf("%d\t%-10s\t%d\t\t%.2f\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
}

void updateProduct() {
    int id, found = 0;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    for(int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Updating Product: %s\n", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }

    if(!found) {
        printf("Product with ID %d not found!\n", id);
    }
}

void deleteProduct() {
    int id, found = 0;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for(int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product with ID %d deleted successfully!\n", id);
            break;
        }
    }

    if(!found) {
        printf("Product with ID %d not found!\n", id);
    }
}

void searchProduct() {
    char name[NAME_LENGTH];
    printf("Enter Product Name to search: ");
    getchar(); // consume newline
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    int found = 0;
    printf("Search Results:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");

    for(int i = 0; i < productCount; i++) {
        if (strstr(inventory[i].name, name) != NULL) {
            printf("%d\t%-10s\t%d\t\t%.2f\n", 
                   inventory[i].id, 
                   inventory[i].name, 
                   inventory[i].quantity, 
                   inventory[i].price);
            found = 1;
        }
    }

    if(!found) {
        printf("No products found with the name %s.\n", name);
    }
}

void saveInventoryToFile() {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for(int i = 0; i < productCount; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", 
                inventory[i].id, 
                inventory[i].name, 
                inventory[i].quantity, 
                inventory[i].price);
    }
    
    fclose(file);
    printf("Inventory saved to inventory.txt successfully!\n");
}

void loadInventoryFromFile() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading! Starting with an empty inventory.\n");
        return;
    }

    while(fscanf(file, "%d,%49[^,],%d,%f", 
                 &inventory[productCount].id, 
                 inventory[productCount].name, 
                 &inventory[productCount].quantity, 
                 &inventory[productCount].price) == 4) {
        productCount++;
        if(productCount >= MAX_PRODUCTS) break;
    }
    
    fclose(file);
    printf("Inventory loaded from inventory.txt successfully!\n");
}

int main() {
    loadInventoryFromFile();
    int choice;
    
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Save Inventory\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addProduct(); 
                break;
            case 2: 
                viewProducts(); 
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
                saveInventoryToFile(); 
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 7);

    return 0;
}