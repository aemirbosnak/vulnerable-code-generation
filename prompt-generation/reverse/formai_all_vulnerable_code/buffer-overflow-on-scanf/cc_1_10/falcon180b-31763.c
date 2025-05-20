//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>

// Define the structure of a product
typedef struct {
    char name[50];
    int quantity;
    double price;
} Product;

int main() {
    // Initialize the product inventory
    Product inventory[100];
    int numProducts = 0;

    // Loop until the user wants to exit
    while(1) {
        printf("Enter 1 to add a product, 2 to remove a product, or 3 to exit:\n");
        int choice;
        scanf("%d", &choice);

        // Exit the program
        if(choice == 3) {
            break;
        }

        // Add a product
        if(choice == 1) {
            printf("Enter the name of the product:\n");
            scanf("%s", inventory[numProducts].name);
            printf("Enter the quantity of the product:\n");
            scanf("%d", &inventory[numProducts].quantity);
            printf("Enter the price of the product:\n");
            scanf("%lf", &inventory[numProducts].price);
            numProducts++;
            printf("Product added successfully.\n");
        }

        // Remove a product
        if(choice == 2) {
            printf("Enter the name of the product to remove:\n");
            scanf("%s", inventory[numProducts-1].name);
            printf("Product removed successfully.\n");
            numProducts--;
        }
    }

    // Print the final inventory
    printf("Final Inventory:\n");
    for(int i=0; i<numProducts; i++) {
        printf("Name: %s\nQuantity: %d\nPrice: $%.2lf\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    return 0;
}