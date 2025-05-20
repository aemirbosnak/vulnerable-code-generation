//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int id;
    float price;
    int quantity;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    int total_products;
} Store;

void initializeStore(Store *store) {
    store->total_products = 0;
}

void addProduct(Store *store) {
    if (store->total_products >= MAX_PRODUCTS) {
        printf("The shop is a labyrinth with no more room!\n");
        return;
    }
    
    Product newProduct;
    
    printf("Enter product name (Journey through the surreal): ");
    scanf(" %49[^\n]", newProduct.name);
    printf("Enter product ID (A number that dances in your mind): ");
    scanf("%d", &newProduct.id);
    printf("Enter product price (A currency that whispers): ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity (An echo in the chamber of shelves): ");
    scanf("%d", &newProduct.quantity);
    
    store->products[store->total_products++] = newProduct;
    printf("Product added to the dream!\n");
}

void displayProducts(Store *store) {
    if (store->total_products == 0) {
        printf("The shelves are barren and empty.\n");
        return;
    }
    
    printf("\nProducts in the dreamscape:\n");
    for (int i = 0; i < store->total_products; i++) {
        Product *p = &store->products[i];
        printf("ID: %d, Name: \"%s\", Price: $%.2f, Quantity: %d\n", p->id, p->name, p->price, p->quantity);
    }
}

void updateProduct(Store *store) {
    int id, found = 0;
    
    printf("Enter the product ID to update (A number lost in time): ");
    scanf("%d", &id);
    
    for (int i = 0; i < store->total_products; i++) {
        if (store->products[i].id == id) {
            found = 1;
            printf("Updating product \"%s\"\n", store->products[i].name);
            printf("Enter new price (The value in the dream): ");
            scanf("%f", &store->products[i].price);
            printf("Enter new quantity (The whispers of existence): ");
            scanf("%d", &store->products[i].quantity);
            printf("Product updated, a new reality formed!\n");
            break;
        }
    }
    
    if (!found) {
        printf("The product ID wanders without a destination.\n");
    }
}

void deleteProduct(Store *store) {
    int id, found = 0;
    
    printf("Enter the product ID to delete (To vanish in thin air): ");
    scanf("%d", &id);
    
    for (int i = 0; i < store->total_products; i++) {
        if (store->products[i].id == id) {
            found = 1;
            printf("Deleting product \"%s\"\n", store->products[i].name);
            for (int j = i; j < store->total_products - 1; j++) {
                store->products[j] = store->products[j + 1];
            }
            store->total_products--;
            printf("Product deleted, its essence liberated!\n");
            break;
        }
    }
    
    if (!found) {
        printf("The product ID fades into the void.\n");
    }
}

void manageStore(Store *store) {
    int choice;
    
    do {
        printf("\n--- Welcome to the Surreal Medical Store Management System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit (Return to reality)\n");
        printf("Select your choice (A dance of digits): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(store);
                break;
            case 2:
                displayProducts(store);
                break;
            case 3:
                updateProduct(store);
                break;
            case 4:
                deleteProduct(store);
                break;
            case 5:
                printf("Exiting... The surreal journey concludes.\n");
                break;
            default:
                printf("Please choose a logical pathway.\n");
        }
    } while (choice != 5);
}

int main() {
    Store store;
    initializeStore(&store);
    manageStore(&store);
    return 0;
}