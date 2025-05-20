//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Function to search a product by ID
struct product *searchById(struct product *products, int numProducts, int id) {
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            return &products[i];
        }
    }
    return NULL;
}

// Function to add a new product
void addProduct(struct product *products, int *numProducts) {
    printf("Enter details of new product:\n");
    struct product newProd;
    printf("ID: ");
    scanf("%d", &newProd.id);
    if (searchById(products, *numProducts, newProd.id) != NULL) {
        printf("Product with ID %d already exists.\n", newProd.id);
        return;
    }
    printf("Name: ");
    scanf("%s", newProd.name);
    printf("Price: ");
    scanf("%f", &newProd.price);
    printf("Quantity: ");
    scanf("%d", &newProd.quantity);
    products[*numProducts] = newProd;
    (*numProducts)++;
    printf("Product added successfully!\n");
}

// Function to remove a product
void removeProduct(struct product *products, int *numProducts) {
    int id;
    printf("Enter ID of product to remove: ");
    scanf("%d", &id);
    struct product *prod = searchById(products, *numProducts, id);
    if (prod == NULL) {
        printf("Product with ID %d not found.\n", id);
        return;
    }
    for (int i = prod - products; i < *numProducts - 1; i++) {
        products[i] = products[i+1];
    }
    (*numProducts)--;
    printf("Product removed successfully!\n");
}

// Function to display all products
void displayProducts(struct product *products, int numProducts) {
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
    for (int i = 0; i < numProducts; i++) {
        printf("%-5d %-20s $%-9.2f %-10d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

// Function to sell a product
void sellProduct(struct product *products, int *numProducts) {
    int id, quantity;
    printf("Enter ID of product to sell: ");
    scanf("%d", &id);
    struct product *prod = searchById(products, *numProducts, id);
    if (prod == NULL) {
        printf("Product with ID %d not found.\n", id);
        return;
    }
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    if (quantity > prod->quantity) {
        printf("Insufficient quantity of product!\n");
        return;
    }
    prod->quantity -= quantity;
    printf("Sale successful!\n");
}

int main() {
    struct product products[100];
    int numProducts = 0;
    int choice;

    do {
        printf("\n===== Product Inventory System =====\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display all products\n");
        printf("4. Sell product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                removeProduct(products, &numProducts);
                break;
            case 3:
                displayProducts(products, numProducts);
                break;
            case 4:
                sellProduct(products, &numProducts);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice!");
                break;
        }
    } while (choice != 5);

    return 0;
}