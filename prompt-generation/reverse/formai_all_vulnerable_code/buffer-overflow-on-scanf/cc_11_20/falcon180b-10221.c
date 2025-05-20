//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice, num_products = 0;
    struct product products[MAX_PRODUCTS];

    memset(products, 0, sizeof(products));

    while(1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n2. Display products\n3. Update product\n4. Delete product\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", products[num_products].name);
                printf("Enter product quantity: ");
                scanf("%d", &products[num_products].quantity);
                printf("Enter product price: ");
                scanf("%f", &products[num_products].price);
                num_products++;
                break;

            case 2:
                printf("Product Name\tQuantity\tPrice\n");
                for(int i=0; i<num_products; i++) {
                    printf("%s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
                }
                break;

            case 3:
                printf("Enter product index: ");
                scanf("%d", &choice);
                if(choice >= 0 && choice < num_products) {
                    printf("Enter updated product name: ");
                    scanf("%s", products[choice].name);
                    printf("Enter updated product quantity: ");
                    scanf("%d", &products[choice].quantity);
                    printf("Enter updated product price: ");
                    scanf("%f", &products[choice].price);
                }
                break;

            case 4:
                printf("Enter product index: ");
                scanf("%d", &choice);
                if(choice >= 0 && choice < num_products) {
                    memset(&products[choice], 0, sizeof(products[choice]));
                    num_products--;
                }
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}