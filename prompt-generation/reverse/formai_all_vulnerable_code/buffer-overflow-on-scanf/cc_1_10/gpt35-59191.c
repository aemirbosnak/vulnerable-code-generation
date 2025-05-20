//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define a structure for product details
struct product {
    char name[50];
    int id;
    float price;
    int quantity;
};

//function declarations
void addProduct(struct product *p, int *numProducts);
void viewProduct(struct product *p, int numProducts);
void searchProduct(struct product *p, int numProducts);

int main() {

    struct product prod[100];
    int numProducts = 0;

    //display menu
    int choice = 0;
    while (choice != 4) {
        printf("\n\nC Product Inventory System\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search for Product\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&prod[numProducts], &numProducts);
                break;
            case 2:
                viewProduct(prod, numProducts);
                break;
            case 3:
                searchProduct(prod, numProducts);
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please choose again!");
        }
    }
    return 0;
}

//function to add product to inventory
void addProduct(struct product *p, int *numProducts) {
    printf("Enter name of product: ");
    scanf("%s", p->name);

    printf("Enter product id: ");
    scanf("%d", &p->id);

    printf("Enter product price: ");
    scanf("%f", &p->price);

    printf("Enter product quantity: ");
    scanf("%d", &p->quantity);

    printf("Product added successfully!");

    (*numProducts)++;
}

//function to view all products in inventory
void viewProduct(struct product *p, int numProducts) {
    printf("\n\n List of products \n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product %d: \n", i+1);
        printf(" Name: %s\n", p[i].name);
        printf(" ID: %d\n", p[i].id);
        printf(" Price: %.2f\n", p[i].price);
        printf(" Quantity: %d\n", p[i].quantity);
    }
}

//function to search for product by ID
void searchProduct(struct product *p, int numProducts) {
    int searchId = 0;
    printf("Enter product ID to search for: ");
    scanf("%d", &searchId);

    for (int i = 0; i < numProducts; i++) {
        if (p[i].id == searchId) {
            printf("Product found! \n");
            printf(" Name: %s\n", p[i].name);
            printf(" ID: %d\n", p[i].id);
            printf(" Price: %.2f\n", p[i].price);
            printf(" Quantity: %d\n", p[i].quantity);
            return;
        }
    }

    printf("Product not found with ID: %d", searchId);
}