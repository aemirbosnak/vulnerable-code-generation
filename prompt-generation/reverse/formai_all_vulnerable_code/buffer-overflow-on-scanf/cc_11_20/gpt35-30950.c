//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} product;

int main() {
    int choice, i, n, id, checkid, searchid, quantity;
    float price;
    char name[50];
    product *p;

    printf("Enter the number of products in the warehouse: ");
    scanf("%d", &n);

    // Allocate memory for the products
    p = (product*)malloc(n * sizeof(product));

    // Initialize the products
    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter the name of product %d: ", i+1);
        scanf("%s", p[i].name);
        printf("Enter the price of product %d: ", i+1);
        scanf("%f", &p[i].price);
        printf("Enter the quantity of product %d: ", i+1);
        scanf("%d", &p[i].quantity);
    }

    do {
        printf("\nWarehouse Management System");
        printf("\n1. Add product");
        printf("\n2. Remove product");
        printf("\n3. Search product");
        printf("\n4. Display all products");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add a new product
                printf("\nEnter the name of the product: ");
                scanf("%s", name);
                printf("Enter the price of the product: ");
                scanf("%f", &price);
                printf("Enter the quantity of the product: ");
                scanf("%d", &quantity);

                // Check if the product already exists
                checkid = 0;
                for (i = 0; i < n; i++) {
                    if (strcmp(p[i].name, name) == 0) {
                        printf("\nProduct already exists with ID: %d", p[i].id);
                        checkid = 1;
                        break;
                    }
                }

                if (!checkid) {
                    // Add the new product to the list
                    p = (product*)realloc(p, (n+1) * sizeof(product));
                    p[n].id = n+1;
                    strcpy(p[n].name, name);
                    p[n].price = price;
                    p[n].quantity = quantity;
                    n++;
                    printf("\nProduct successfully added to the warehouse");
                }
                break;

            case 2:
                // Remove a product
                printf("\nEnter the ID of the product to be removed: ");
                scanf("%d", &id);

                for (i = 0; i < n; i++) {
                    if (p[i].id == id) {
                        // Shift the products after the removed product
                        for (; i < n-1; i++)
                            p[i] = p[i+1];

                        // Reallocate memory
                        p = (product*)realloc(p, (n-1) * sizeof(product));
                        n--;
                        printf("\nProduct successfully removed from the warehouse");
                        break;
                    }
                }

                if (i == n)
                    printf("\nProduct not found with ID: %d", id);
                break;

            case 3:
                // Search for a product
                printf("\nEnter the ID of the product to be searched: ");
                scanf("%d", &searchid);

                for (i = 0; i < n; i++) {
                    if (p[i].id == searchid) {
                        printf("\nID: %d", p[i].id);
                        printf("\nName: %s", p[i].name);
                        printf("\nPrice: Rs. %.2f", p[i].price);
                        printf("\nQuantity: %d", p[i].quantity);
                        break;
                    }
                }

                if (i == n)
                    printf("\nProduct not found with ID: %d", searchid);
                break;

            case 4:
                // Display all products
                printf("\nAll Products in the Warehouse");
                printf("\nID\tName\tPrice\tQuantity");

                for (i = 0; i < n; i++) {
                    printf("\n%d\t%s\tRs. %.2f\t%d", p[i].id, p[i].name, p[i].price, p[i].quantity);
                }
                break;

            case 5:
                // Free the memory
                free(p);
                printf("\nThanks for using the Warehouse Management System!");
                break;

            default:
                printf("\nInvalid choice, please try again");
        }
    } while(choice != 5);

    return 0;
}