//FormAI DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to represent a product
typedef struct {
    char* name;
    int id;
    float price;
    int quantity;
} Product;

// function to add a product to the inventory system
void add_product(Product*** inventory, int* num_products) {
    // create a new product
    Product* new_product = (Product*) malloc(sizeof(Product));

    // get the product details from user input
    printf("Enter product name: ");
    char name[100];
    scanf("%s", name);
    new_product->name = strdup(name);

    printf("Enter product ID: ");
    scanf("%d", &(new_product->id));

    printf("Enter product price: ");
    scanf("%f", &(new_product->price));

    printf("Enter product quantity: ");
    scanf("%d", &(new_product->quantity));

    // add the product to the inventory
    (*inventory) = (Product**) realloc((*inventory), (*num_products + 1) * sizeof(Product*));
    (*inventory)[(*num_products)] = new_product;

    // update the number of products
    (*num_products)++;
}

// function to remove a product from the inventory system
void remove_product(Product*** inventory, int* num_products, int product_id) {
    int i;
    for (i = 0; i < (*num_products); i++) {
        if ((*inventory)[i]->id == product_id) {
            free((*inventory)[i]->name);
            free((*inventory)[i]);
            (*inventory)[i] = NULL;
            break;
        }
    }

    if (i != (*num_products) - 1) {
        (*inventory)[i] = (*inventory)[(*num_products) - 1];
    }

    (*inventory) = (Product**) realloc((*inventory), (*num_products - 1) * sizeof(Product*));
    (*num_products)--;
}

// function to find a product by its ID
Product* find_product_by_id(Product** inventory, int num_products, int product_id) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (inventory[i]->id == product_id) {
            return inventory[i];
        }
    }

    return NULL;
}

int main() {
    // initialize an empty inventory
    Product** inventory = NULL;
    int num_products = 0;

    // menu loop
    while (1) {
        printf("\n");
        printf("========== PRODUCT INVENTORY SYSTEM ==========\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Find product\n");
        printf("4. Display all products\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(&inventory, &num_products);
                break;

            case 2:
                printf("Enter product ID to remove: ");
                int remove_id;
                scanf("%d", &remove_id);
                remove_product(&inventory, &num_products, remove_id);
                break;

            case 3:
                printf("Enter product ID to find: ");
                int find_id;
                scanf("%d", &find_id);

                Product* found_product = find_product_by_id(inventory, num_products, find_id);
                if (found_product != NULL) {
                    printf("Product found:\n");
                    printf("Name: %s\n", found_product->name);
                    printf("ID: %d\n", found_product->id);
                    printf("Price: %.2f\n", found_product->price);
                    printf("Quantity: %d\n", found_product->quantity);
                } else {
                    printf("Product not found.\n");
                }

                break;

            case 4:
                printf("Product inventory:\n");
                int i;
                for (i = 0; i < num_products; i++) {
                    printf("Product %d:\n", i + 1);
                    printf("Name: %s\n", inventory[i]->name);
                    printf("ID: %d\n", inventory[i]->id);
                    printf("Price: %.2f\n", inventory[i]->price);
                    printf("Quantity: %d\n", inventory[i]->quantity);
                }

                break;

            case 5:
                printf("Exiting.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}