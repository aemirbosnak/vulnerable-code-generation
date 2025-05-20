//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice, num_products = 0, i;
    struct product products[100];

    printf("Welcome to the Product Inventory System!\n\n");

    while(1) {
        printf("What would you like to do?\n1. Add a product\n2. View inventory\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter the product name: ");
            scanf("%s", products[num_products].name);
            printf("Enter the quantity: ");
            scanf("%d", &products[num_products].quantity);
            printf("Enter the price: ");
            scanf("%f", &products[num_products].price);

            num_products++;
            printf("\n%s added to inventory.\n\n", products[num_products-1].name);
        }
        else if(choice == 2) {
            printf("\nCurrent Inventory:\n");
            printf("| %-50s| %-10s| %-10s|\n", "Product Name", "Quantity", "Price");
            printf("|-%-50s+-%-10s+-%-10s|\n", "--------------------------------------------------", "----------", "----------");

            for(i=0; i<num_products; i++) {
                printf("| %-50s| %-10d| $%-9.2f |\n", products[i].name, products[i].quantity, products[i].price);
            }

            printf("\n");
        }
        else if(choice == 3) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}