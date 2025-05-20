//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
};

int main() {
    int choice, numProducts = 0;
    struct product products[50];
    
    // main program loop
    while (1) {
        printf("Menu:\n1. Add product\n2. Update product\n3. Display products\n4. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // add product
                if (numProducts >= 50) {
                    printf("Warehouse is full, cannot add more products.\n");
                } else {
                    printf("Enter product name: ");
                    scanf("%s", products[numProducts].name);
                    printf("Enter product quantity: ");
                    scanf("%d", &products[numProducts].quantity);
                    products[numProducts].id = numProducts + 1;
                    numProducts++;
                    printf("Product added successfully.\n");
                }
                break;
            case 2: // update product
                if (numProducts == 0) {
                    printf("Warehouse is empty, no products to update.\n");
                } else {
                    int id;
                    printf("Enter product ID to update: ");
                    scanf("%d", &id);
                    int found = 0;
                    for (int i = 0; i < numProducts; i++) {
                        if (products[i].id == id) {
                            found = 1;
                            printf("Enter new product name: ");
                            scanf("%s", products[i].name);
                            printf("Enter new product quantity: ");
                            scanf("%d", &products[i].quantity);
                            printf("Product updated successfully.\n");
                            break;
                        }
                    }
                    if (!found) {
                        printf("Product with ID %d not found.\n", id);
                    }
                }
                break;
            case 3: // display products
                if (numProducts == 0) {
                    printf("Warehouse is empty, no products to display.\n");
                } else {
                    printf("ID\tName\t\tQuantity\n");
                    for (int i = 0; i < numProducts; i++) {
                        printf("%d\t%s\t\t%d\n", products[i].id, products[i].name, products[i].quantity);
                    }
                }
                break;
            case 4: // exit program
                printf("Exiting program.\n");
                exit(0);
            default: // invalid input
                printf("Invalid input, please try again.\n");
                break;
        }
    }
    
    return 0;
}