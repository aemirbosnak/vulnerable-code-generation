//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int total_products = 0;

void add_product() {
    if(total_products >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product p;
    p.id = total_products + 1;

    printf("Enter product name: ");
    scanf(" %[^\n]s", p.name);
    
    printf("Enter product price: ");
    scanf("%f", &p.price);
    
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    
    inventory[total_products] = p;
    total_products++;
    printf("Product added successfully!\n");
}

void view_products() {
    if(total_products == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("\nInventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("-----------------------------------------\n");
    
    for(int i = 0; i < total_products; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("-----------------------------------------\n");
}

void update_product() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    if(id < 1 || id > total_products) {
        printf("Invalid product ID.\n");
        return;
    }
    
    Product* p = &inventory[id - 1];
    printf("Updating product: %s\n", p->name);
    
    printf("Enter new name (press Enter to keep current): ");
    char new_name[NAME_LENGTH];
    scanf(" %[^\n]s", new_name);
    if(strlen(new_name) > 0) {
        strcpy(p->name, new_name);
    }

    printf("Enter new price (enter -1 to keep current): ");
    float new_price;
    scanf("%f", &new_price);
    if(new_price >= 0) {
        p->price = new_price;
    }
    
    printf("Enter new quantity (enter -1 to keep current): ");
    int new_quantity;
    scanf("%d", &new_quantity);
    if(new_quantity >= 0) {
        p->quantity = new_quantity;
    }

    printf("Product updated successfully!\n");
}

void delete_product() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    if(id < 1 || id > total_products) {
        printf("Invalid product ID.\n");
        return;
    }

    for(int i = id - 1; i < total_products - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    total_products--;
    printf("Product deleted successfully!\n");
}

void save_inventory(const char* filename) {
    FILE* file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for(int i = 0; i < total_products; i++) {
        fprintf(file, "%d,%s,%.2f,%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    
    fclose(file);
    printf("Inventory saved to %s\n", filename);
}

void load_inventory(const char* filename) {
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    
    total_products = 0;
    while(fscanf(file, "%d,%49[^,],%f,%d\n", &inventory[total_products].id, inventory[total_products].name, &inventory[total_products].price, &inventory[total_products].quantity) == 4) {
        total_products++;
        if(total_products >= MAX_PRODUCTS) {
            break;
        }
    }
    
    fclose(file);
    printf("Inventory loaded from %s\n", filename);
}

int main() {
    int choice;
    const char* filename = "inventory.txt";

    load_inventory(filename);

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Save Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                view_products();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                save_inventory(filename);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}