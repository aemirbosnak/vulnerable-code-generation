//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include <stdio.h>

// struct to hold information about a product
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// function to add a new product to the warehouse
void addProduct(struct Product* products, int* numProducts) {
    printf("Enter product details:\n");
    printf("ID: ");
    scanf("%d", &(products[*numProducts].id));
    printf("Name: ");
    scanf("%s", products[*numProducts].name);
    printf("Price: ");
    scanf("%f", &(products[*numProducts].price));
    printf("Quantity: ");
    scanf("%d", &(products[*numProducts].quantity));
    
    (*numProducts)++; // increment number of products in warehouse
    printf("Product added successfully.\n");
}

// function to search for a product by name
void searchProduct(struct Product* products, int numProducts) {
    char name[50];
    printf("Enter product name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Product found:\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2f\n", products[i].price);
            printf("Quantity: %d\n", products[i].quantity);
            return;
        }
    }
    
    printf("Product not found.\n");
}

int main() {
    struct Product products[100]; // array to hold products in warehouse
    int numProducts = 0;
    int choice;
    
    do {
        printf("Warehouse Management System\n");
        printf("==========================\n");
        printf("1. Add product\n");
        printf("2. Search product\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                searchProduct(products, numProducts);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        
    } while (choice != 3);
    
    return 0;
}