//FormAI DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declare structure for product information
struct Product {
    char name[20];
    int id;
    int quantity;
    float price;
};

int main() {
    //Declare variables
    int choice, i, id, found = 0, numProducts = 0;
    char name[20];
    float price;
    struct Product products[50];

    printf("\n*** Product Management System ***\n");

    do {
        //Display main menu
        printf("\nMain Menu\n");
        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Search Product by ID\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("0. Exit\n");

        //Get user's choice
        printf("\nEnter choice (0-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("\nExiting Program...\n");
                break;
            case 1:
                //Add product
                printf("\nEnter Product Name: ");
                scanf("%s", name);
                printf("Enter Product ID: ");
                scanf("%d", &id);
                printf("Enter Product Quantity: ");
                scanf("%d", &products[numProducts].quantity);
                printf("Enter Product Price: ");
                scanf("%f", &price);

                //Add product to the inventory
                strcpy(products[numProducts].name, name);
                products[numProducts].id = id;
                products[numProducts].price = price;

                numProducts++;

                printf("\nProduct added successfully!\n");
                break;
            case 2:
                //Display all products
                printf("\nProduct List\n");
                printf("%-20s %-10s %-10s %-10s\n", "Name", "ID", "Quantity", "Price");
                for(i=0; i<numProducts; i++) {
                    printf("%-20s %-10d %-10d %-10.2f\n", products[i].name, products[i].id, products[i].quantity, products[i].price);
                }
                break;
            case 3:
                //Search product by ID
                printf("\nEnter Product ID: ");
                scanf("%d", &id);

                for(i=0; i<numProducts; i++) {
                    if(products[i].id == id) {
                        printf("\nProduct Found!\n");
                        printf("Name: %s\nID: %d\nQuantity: %d\nPrice: %.2f\n", products[i].name, products[i].id, products[i].quantity, products[i].price);
                        found = 1;
                    }
                }

                if(!found) {
                    printf("\nProduct not found!\n");
                }
                break;
            case 4:
                //Update product
                printf("\nEnter Product ID: ");
                scanf("%d", &id);

                for(i=0; i<numProducts; i++) {
                    if(products[i].id == id) {
                        printf("\nProduct Found!\n");
                        printf("Name: %s\nID: %d\nQuantity: %d\nPrice: %.2f\n", products[i].name, products[i].id, products[i].quantity, products[i].price);

                        //Modify product information
                        printf("\nEnter New Product Name: ");
                        scanf("%s", products[i].name);
                        printf("Enter New Product Quantity: ");
                        scanf("%d", &products[i].quantity);
                        printf("Enter New Product Price: ");
                        scanf("%f", &products[i].price);

                        printf("\nProduct updated successfully!\n");
                        found = 1;
                    }
                }

                if(!found) {
                    printf("\nProduct not found!\n");
                }
                break;
            case 5:
                //Delete product
                printf("\nEnter Product ID: ");
                scanf("%d", &id);

                for(i=0; i<numProducts; i++) {
                    if(products[i].id == id) {
                        printf("\nProduct Found!\n");
                        printf("Name: %s\nID: %d\nQuantity: %d\nPrice: %.2f\n", products[i].name, products[i].id, products[i].quantity, products[i].price);

                        //Delete product from inventory
                        numProducts--;
                        for(; i<numProducts; i++) {
                            strcpy(products[i].name, products[i+1].name);
                            products[i].id = products[i+1].id;
                            products[i].quantity = products[i+1].quantity;
                            products[i].price = products[i+1].price;
                        }

                        printf("\nProduct deleted successfully!\n");
                        found = 1;
                    }
                }

                if(!found) {
                    printf("\nProduct not found!\n");
                }
                break;
            default:
                printf("\nInvalid Choice! Please choose between 0 to 5.\n");
                break;
        }

    } while(choice != 0);

    return 0;
}