//FormAI DATASET v1.0 Category: Product Inventory System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[50];
    int id;
    double price;
    int quantity;
};

struct inventory {
    struct product items[MAX_PRODUCTS];
    int count;
};

void addProduct(struct inventory *inv);
void displayInventory(struct inventory *inv);
void updateQuantity(struct inventory *inv, int id, int qty);
void deleteProduct(struct inventory *inv, int id);

int main() {
    struct inventory inv;
    inv.count = 0;
    
    int choice = 0;
    do {
        printf("Welcome to the Product Inventory System!\n");
        printf("Choose an option:\n");
        printf("1. Add a new product\n");
        printf("2. Display current inventory\n");
        printf("3. Update product quantity\n");
        printf("4. Delete a product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addProduct(&inv);
                    break;
            case 2: displayInventory(&inv);
                    break;
            case 3: {
                        int id, qty;
                        printf("Enter the product ID: ");
                        scanf("%d", &id);
                        printf("Enter the new quantity: ");
                        scanf("%d", &qty);
                        updateQuantity(&inv, id, qty);
                        break;
                    }
            case 4: {
                        int id;
                        printf("Enter the product ID to delete: ");
                        scanf("%d", &id);
                        deleteProduct(&inv, id);
                        break;
                    }
            case 5: printf("Exiting program...\n");
                    break;
            default: printf("Invalid choice, please try again.\n");
        }
        
        printf("\n");
    } while(choice != 5);
    
    return 0;
}

void addProduct(struct inventory *inv) {
    if(inv->count >= MAX_PRODUCTS) {
        printf("Inventory is full, cannot add more products.\n");
        return;
    }
    
    // Read product details and add to inventory
    struct product p;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product ID: ");
    scanf("%d", &p.id);
    printf("Enter product price: ");
    scanf("%lf", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    
    inv->items[inv->count] = p;
    inv->count++;
    
    printf("Product added successfully.\n");
}

void displayInventory(struct inventory *inv) {
    printf("Product inventory:\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "ID", "Price", "Qty");
    for(int i=0; i<inv->count; i++) {
        printf("%-20s %-10d %-10.2lf %-10d\n", inv->items[i].name, inv->items[i].id, inv->items[i].price, inv->items[i].quantity);
    }
}

void updateQuantity(struct inventory *inv, int id, int qty) {
    for(int i=0; i<inv->count; i++) {
        if(inv->items[i].id == id) {
            inv->items[i].quantity = qty;
            printf("Quantity updated successfully.\n");
            return;
        }
    }
    
    printf("Product not found with ID %d.\n", id);
}

void deleteProduct(struct inventory *inv, int id) {
    for(int i=0; i<inv->count; i++) {
        if(inv->items[i].id == id) {
            // Delete product by shifting all elements after it to the left
            for(int j=i; j<inv->count-1; j++) {
                inv->items[j] = inv->items[j+1];
            }
            
            inv->count--;
            printf("Product with ID %d has been deleted.\n", id);
            return;
        }
    }
    
    printf("Product not found with ID %d.\n", id);
}