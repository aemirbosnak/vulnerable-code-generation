//FormAI DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

int main() {
    Product inventory[MAX_PRODUCTS];
    int num_products = 0;
    char input[50];

    while(1) {
        printf("Enter a command (add, remove, list, exit): ");
        scanf("%s", input);

        if(strcmp(input, "add") == 0) {
            if(num_products >= MAX_PRODUCTS) {
                printf("Inventory is full!\n");
                continue;
            }

            Product new_product;

            printf("Enter product name: ");
            scanf("%s", new_product.name);

            printf("Enter quantity: ");
            scanf("%d", &new_product.quantity);

            printf("Enter price: ");
            scanf("%f", &new_product.price);

            inventory[num_products] = new_product;
            num_products++;
            printf("Product added successfully!\n");
        }
        else if(strcmp(input, "remove") == 0) {
            char name[50];

            printf("Enter product name to remove: ");
            scanf("%s", name);

            int i;
            int found = 0;

            for(i=0; i<num_products; i++) {
                if(strcmp(inventory[i].name, name) == 0) {
                    found = 1;
                    printf("Product removed successfully!\n");

                    // Shift all products after this one back by one index
                    int j;
                    for(j=i; j<num_products-1; j++) {
                        inventory[j] = inventory[j+1];
                    }

                    num_products--;
                    break;
                }
            }

            if(!found) {
                printf("Product not found!\n");
            }
        }
        else if(strcmp(input, "list") == 0) {
            printf("\nProduct Inventory:\n\n");
            printf("%-30s %-10s %-10s\n", "Product Name", "Quantity", "Price");

            int i;

            for(i=0; i<num_products; i++) {
                printf("%-30s %-10d $%-9.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            }

            printf("\n");
        }
        else if(strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}