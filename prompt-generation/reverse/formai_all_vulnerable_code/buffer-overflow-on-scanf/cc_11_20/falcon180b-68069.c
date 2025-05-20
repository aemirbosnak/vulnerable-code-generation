//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;
    do {
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. View products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                if(num_products >= MAX_PRODUCTS) {
                    printf("Maximum number of products reached.\n");
                } else {
                    printf("Enter product ID: ");
                    int id;
                    scanf("%d", &id);
                    printf("Enter product name: ");
                    scanf(" %[^\n]", products[num_products].name);
                    printf("Enter product description: ");
                    scanf(" %[^\n]", products[num_products].description);
                    printf("Enter product quantity: ");
                    scanf("%d", &products[num_products].quantity);
                    printf("Enter product price: ");
                    scanf("%f", &products[num_products].price);
                    num_products++;
                }
                break;
            case '2':
                printf("Enter product ID to remove: ");
                int remove_id;
                scanf("%d", &remove_id);
                for(int i=0; i<num_products; i++) {
                    if(products[i].id == remove_id) {
                        for(int j=i; j<num_products-1; j++) {
                            products[j] = products[j+1];
                        }
                        num_products--;
                        break;
                    }
                }
                break;
            case '3':
                printf("Enter product ID to update: ");
                int update_id;
                scanf("%d", &update_id);
                for(int i=0; i<num_products; i++) {
                    if(products[i].id == update_id) {
                        printf("Enter new product name: ");
                        scanf(" %[^\n]", products[i].name);
                        printf("Enter new product description: ");
                        scanf(" %[^\n]", products[i].description);
                        printf("Enter new product quantity: ");
                        scanf("%d", &products[i].quantity);
                        printf("Enter new product price: ");
                        scanf("%f", &products[i].price);
                    }
                }
                break;
            case '4':
                printf("Product List:\n");
                for(int i=0; i<num_products; i++) {
                    printf("%d. %s - %s - %d units - $%.2f\n", i+1, products[i].name, products[i].description, products[i].quantity, products[i].price);
                }
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '5');

    return 0;
}