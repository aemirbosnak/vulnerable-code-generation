//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: synchronous
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

typedef struct {
    Product products[MAX_PRODUCTS];
    int count;
} Inventory;

void initialize_inventory(Inventory* inventory) {
    inventory->count = 0;
}

int add_product(Inventory* inventory, const char* name, int quantity, float price) {
    if (inventory->count >= MAX_PRODUCTS) {
        return -1;
    }
    Product* new_product = &inventory->products[inventory->count];
    new_product->id = inventory->count + 1; // Simple ID assignment
    strncpy(new_product->name, name, NAME_LENGTH);
    new_product->quantity = quantity;
    new_product->price = price;
    inventory->count++;
    return new_product->id;
}

void display_inventory(const Inventory* inventory) {
    printf("Product Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < inventory->count; i++) {
        Product* p = &inventory->products[i];
        printf("%d\t%-15s\t%d\t\t%.2f\n", p->id, p->name, p->quantity, p->price);
    }
}

Product* find_product_by_id(Inventory* inventory, int id) {
    for (int i = 0; i < inventory->count; i++) {
        if (inventory->products[i].id == id) {
            return &inventory->products[i];
        }
    }
    return NULL;
}

void update_product(Inventory* inventory, int id, int quantity, float price) {
    Product* p = find_product_by_id(inventory, id);
    if (p) {
        p->quantity = quantity;
        p->price = price;
    } else {
        printf("Product with ID %d not found!\n", id);
    }
}

void delete_product(Inventory* inventory, int id) {
    for (int i = 0; i < inventory->count; i++) {
        if (inventory->products[i].id == id) {
            // Shift products to the left
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->products[j] = inventory->products[j + 1];
            }
            inventory->count--;
            printf("Product with ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("Product with ID %d not found!\n", id);
}

int main() {
    Inventory inventory;
    initialize_inventory(&inventory);
    
    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            char name[NAME_LENGTH];
            int quantity;
            float price;
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter price: ");
            scanf("%f", &price);
            int id = add_product(&inventory, name, quantity, price);
            if (id == -1) {
                printf("Inventory is full! Cannot add new product.\n");
            } else {
                printf("Product added with ID: %d\n", id);
            }
        } else if (choice == 2) {
            display_inventory(&inventory);
        } else if (choice == 3) {
            int id, quantity;
            float price;
            printf("Enter product ID to update: ");
            scanf("%d", &id);
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            printf("Enter new price: ");
            scanf("%f", &price);
            update_product(&inventory, id, quantity, price);
        } else if (choice == 4) {
            int id;
            printf("Enter product ID to delete: ");
            scanf("%d", &id);
            delete_product(&inventory, id);
        } else if (choice == 5) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}