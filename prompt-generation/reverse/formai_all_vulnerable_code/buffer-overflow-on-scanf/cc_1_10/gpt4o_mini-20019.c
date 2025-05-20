//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int id;
    int quantity;
    float price;
} Product;

typedef struct {
    Product inventory[MAX_PRODUCTS];
    int totalProducts;
} Inventory;

void addProduct(Inventory* inv, const char* name, int id, int quantity, float price) {
    if (inv->totalProducts < MAX_PRODUCTS) {
        strcpy(inv->inventory[inv->totalProducts].name, name);
        inv->inventory[inv->totalProducts].id = id;
        inv->inventory[inv->totalProducts].quantity = quantity;
        inv->inventory[inv->totalProducts].price = price;
        inv->totalProducts++;
        printf("Product added: %s with ID: %d\n", name, id);
    } else {
        printf("Inventory full. Cannot add more products.\n");
    }
}

void listProducts(const Inventory* inv) {
    printf("\nInventory List:\n");
    for (int i = 0; i < inv->totalProducts; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               inv->inventory[i].id,
               inv->inventory[i].name,
               inv->inventory[i].quantity,
               inv->inventory[i].price);
    }
}

Product* findProductById(const Inventory* inv, int id) {
    for (int i = 0; i < inv->totalProducts; i++) {
        if (inv->inventory[i].id == id) {
            return &inv->inventory[i];
        }
    }
    return NULL;
}

void removeProduct(Inventory* inv, int id) {
    for (int i = 0; i < inv->totalProducts; i++) {
        if (inv->inventory[i].id == id) {
            for (int j = i; j < inv->totalProducts - 1; j++) {
                inv->inventory[j] = inv->inventory[j + 1];
            }
            inv->totalProducts--;
            printf("Product with ID: %d has been removed.\n", id);
            return;
        }
    }
    printf("Product with ID: %d not found.\n", id);
}

void updateProductQuantity(Inventory* inv, int id, int quantity) {
    Product* product = findProductById(inv, id);
    if (product != NULL) {
        product->quantity = quantity;
        printf("Product ID: %d has its quantity updated to %d.\n", id, quantity);
    } else {
        printf("Product with ID: %d not found.\n", id);
    }
}

void displayMenu() {
    printf("\nSherlock Holmes Product Inventory System\n");
    printf("1. Add Product\n");
    printf("2. List Products\n");
    printf("3. Find Product by ID\n");
    printf("4. Remove Product\n");
    printf("5. Update Product Quantity\n");
    printf("6. Exit\n");
}

int main() {
    Inventory myInventory = { .totalProducts = 0 };
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[NAME_LENGTH];
                int id, quantity;
                float price;

                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                printf("Enter product price: ");
                scanf("%f", &price);

                addProduct(&myInventory, name, id, quantity, price);
                break;
            }
            case 2:
                listProducts(&myInventory);
                break;
            case 3: {
                int id;

                printf("Enter product ID to find: ");
                scanf("%d", &id);
                Product* product = findProductById(&myInventory, id);
                if (product) {
                    printf("Found Product - ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                           product->id, product->name, product->quantity, product->price);
                } else {
                    printf("Product with ID: %d not found.\n", id);
                }
                break;
            }
            case 4: {
                int id;
                printf("Enter product ID to remove: ");
                scanf("%d", &id);
                removeProduct(&myInventory, id);
                break;
            }
            case 5: {
                int id, quantity;
                printf("Enter product ID to update quantity: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateProductQuantity(&myInventory, id, quantity);
                break;
            }
            case 6:
                printf("Exiting the system. Until next time, Watson!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}