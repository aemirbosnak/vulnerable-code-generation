//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

int main() {
    int num_products = 0;
    struct product products[MAX_PRODUCTS];
    char choice;

    do {
        printf("Product Inventory System\n");
        printf("------------------------\n");

        printf("1. Add product\n");
        printf("2. Update product\n");
        printf("3. Delete product\n");
        printf("4. View products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_products >= MAX_PRODUCTS) {
                    printf("Maximum number of products reached.\n");
                } else {
                    printf("Enter product name: ");
                    scanf("%s", products[num_products].name);
                    printf("Enter quantity: ");
                    scanf("%d", &products[num_products].quantity);
                    printf("Enter price: ");
                    scanf("%f", &products[num_products].price);
                    num_products++;
                    printf("Product added successfully.\n");
                }
                break;

            case '2':
                printf("Enter product index: ");
                scanf("%d", &choice);
                if(choice >= 0 && choice < num_products) {
                    printf("Enter new product name: ");
                    scanf("%s", products[choice].name);
                    printf("Enter new quantity: ");
                    scanf("%d", &products[choice].quantity);
                    printf("Enter new price: ");
                    scanf("%f", &products[choice].price);
                } else {
                    printf("Invalid product index.\n");
                }
                break;

            case '3':
                printf("Enter product index: ");
                scanf("%d", &choice);
                if(choice >= 0 && choice < num_products) {
                    num_products--;
                    for(int i=choice; i<num_products; i++) {
                        products[i] = products[i+1];
                    }
                    printf("Product deleted successfully.\n");
                } else {
                    printf("Invalid product index.\n");
                }
                break;

            case '4':
                printf("Product List:\n");
                for(int i=0; i<num_products; i++) {
                    printf("%d. %s - %d units - $%.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
                }
                break;

            case '5':
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '5');

    return 0;
}