//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {

    struct product inventory[100];
    int numOfProducts = 0;

    int choice = 0;

    do {
        printf("--------- PRODUCT INVENTORY SYSTEM ---------\n");
        printf("1. Add a Product\n");
        printf("2. Display All Products\n");
        printf("3. Search a Product by ID\n");
        printf("4. Update a Product\n");
        printf("5. Remove a Product\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numOfProducts < 100) {
                    struct product newProduct;
                    printf("Enter Product ID: ");
                    scanf("%d", &newProduct.id);
                    printf("Enter Product Name: ");
                    scanf("%s", newProduct.name);
                    printf("Enter Product Quantity: ");
                    scanf("%d", &newProduct.quantity);
                    printf("Enter Product Price: ");
                    scanf("%f", &newProduct.price);

                    inventory[numOfProducts++] = newProduct;
                } else {
                    printf("Cannot add more Products to the Inventory! Maximum Limit Reached!\n");
                }
                break;
            case 2:
                if (numOfProducts == 0) {
                    printf("No Products found in the Inventory!\n");
                } else {
                    printf("-------------- LIST OF PRODUCTS --------------\n");
                    printf("ID \t NAME \t QUANTITY \t PRICE \n");
                    for (int i = 0; i < numOfProducts; i++) {
                        printf("%d \t %s \t %d \t $%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                    }
                    printf("-------------- END OF LIST --------------\n");
                }
                break;
            case 3:
                if (numOfProducts == 0) {
                    printf("No Products found in the Inventory!\n");
                } else {
                    int searchID;
                    printf("Enter Product ID to search: ");
                    scanf("%d", &searchID);
                    int found = 0;
                    for (int i = 0; i < numOfProducts; i++) {
                        if (inventory[i].id == searchID) {
                            printf("Product Found!\n");
                            printf("ID \t NAME \t QUANTITY \t PRICE \n");
                            printf("%d \t %s \t %d \t $%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Product with ID %d not found!\n", searchID);
                    }
                }
                break;
            case 4:
                if (numOfProducts == 0) {
                    printf("No Products found in the Inventory!\n");
                } else {
                    int updateID;
                    printf("Enter Product ID to Update: ");
                    scanf("%d", &updateID);
                    int found = 0;
                    for (int i = 0; i < numOfProducts; i++) {
                        if (inventory[i].id == updateID) {
                            printf("Product Found!\n");
                            printf("Enter New Product Name: ");
                            scanf("%s", inventory[i].name);
                            printf("Enter New Product Quantity: ");
                            scanf("%d", &inventory[i].quantity);
                            printf("Enter New Product Price: ");
                            scanf("%f", &inventory[i].price);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Product with ID %d not found!\n", updateID);
                    }
                }
                break;
            case 5:
                if (numOfProducts == 0) {
                    printf("No Products found in the Inventory!\n");
                } else {
                    int removeID;
                    printf("Enter Product ID to Remove: ");
                    scanf("%d", &removeID);
                    int found = 0;
                    for (int i = 0; i < numOfProducts; i++) {
                        if (inventory[i].id == removeID) {
                            for (int j = i; j < numOfProducts - 1; j++) {
                                inventory[j] = inventory[j+1];
                            }
                            numOfProducts--;
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Product with ID %d not found!\n", removeID);
                    } else {
                        printf("Product Removed Successfully!\n");
                    }
                }
                break;
            case 6:
                printf("Exiting the Program! Goodbye!\n");
                break;
            default:
                printf("Invalid Choice! Try Again!\n");
                break;
        }

    } while (choice != 6);

    return 0;
}