//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char input[100];
    int choice;

    do {
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Update product quantity\n");
        printf("4. Delete product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                    printf("%s\t\t%d\t\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
                }
                break;
            case 3:
                printf("Enter product name: ");
                scanf("%s", input);
                for(int i=0; i<num_products; i++) {
                    if(strcmp(input, products[i].name) == 0) {
                        printf("Enter new quantity: ");
                        scanf("%d", &products[i].quantity);
                        break;
                    }
                }
                break;
            case 4:
                printf("Enter product name: ");
                scanf("%s", input);
                for(int i=0; i<num_products; i++) {
                    if(strcmp(input, products[i].name) == 0) {
                        num_products--;
                        for(int j=i; j<num_products; j++) {
                            products[j] = products[j+1];
                        }
                        break;
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(1);

    return 0;
}