//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 1000
#define MAX_STOCK 10000
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_LOCATION_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int stock;
} product;

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int stock;
    product products[MAX_PRODUCTS];

    int num_products = 0;
    int num_stocks = 0;

    do {
        printf("\nWelcome to the Warehouse Management System!\n");
        printf("What would you like to do?\n");
        printf("1. Add product\n");
        printf("2. View products\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product category: ");
                scanf("%s", category);
                printf("Enter product stock: ");
                scanf("%d", &stock);

                for(int i=0; i<num_products; i++) {
                    if(strcmp(name, products[i].name) == 0) {
                        printf("Product already exists!\n");
                        break;
                    }
                }

                if(num_products == MAX_PRODUCTS) {
                    printf("Maximum number of products reached!\n");
                } else {
                    strcpy(products[num_products].name, name);
                    strcpy(products[num_products].category, category);
                    products[num_products].stock = stock;
                    num_products++;
                }

                break;

            case 2:
                printf("Product Name\tCategory\tStock\n");
                for(int i=0; i<num_products; i++) {
                    printf("%s\t%s\t%d\n", products[i].name, products[i].category, products[i].stock);
                }
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice!= 3);

    return 0;
}