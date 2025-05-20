//FormAI DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

int main() {
    int choice, num_products = 0;
    Product products[50];

    do {
        printf("\n1. Add Product\n2. View Inventory\n3. Update Product\n4. Remove Product\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter the product name: ");
                scanf("%s", products[num_products].name);
                printf("Enter the quantity: ");
                scanf("%d", &products[num_products].quantity);
                printf("Enter the price: ");
                scanf("%f", &products[num_products].price);
                num_products++;
                break;
            }
            case 2: {
                printf("\n%-30s %-10s %-10s\n", "Product Name", "Quantity", "Price");
                for(int i=0; i<num_products; i++) {
                    printf("%-30s %-10d %-10.2f\n", products[i].name, products[i].quantity, products[i].price);
                }
                break;
            }
            case 3: {
                char search_name[50];
                printf("Enter the product name to update: ");
                scanf("%s", search_name);

                int found = 0;
                for(int i=0; i<num_products; i++) {
                    if(strcmp(products[i].name, search_name) == 0) {
                        printf("Enter the new quantity: ");
                        scanf("%d", &products[i].quantity);
                        printf("Enter the new price: ");
                        scanf("%f", &products[i].price);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Product not found!\n");
                }
                break;
            }
            case 4: {
                char search_name[50];
                printf("Enter the product name to remove: ");
                scanf("%s", search_name);

                int found = 0;
                for(int i=0; i<num_products; i++) {
                    if(strcmp(products[i].name, search_name) == 0) {
                        for(int j=i; j<num_products-1; j++) {
                            products[j] = products[j+1];
                        }
                        num_products--;
                        printf("Product removed successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Product not found!\n");
                }
                break;
            }
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}