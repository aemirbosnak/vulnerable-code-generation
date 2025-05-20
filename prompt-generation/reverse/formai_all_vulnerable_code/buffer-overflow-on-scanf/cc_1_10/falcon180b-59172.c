//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char price[MAX_PRICE_LENGTH];
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;
    
    do {
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Search product\n");
        printf("3. Display all products\n");
        printf("4. Exit\n");
        scanf("%c", &choice);
        
        switch(choice) {
            case '1':
                if(num_products >= MAX_PRODUCTS) {
                    printf("Inventory is full.\n");
                } else {
                    printf("Enter product name: ");
                    scanf("%s", products[num_products].name);
                    
                    printf("Enter product description: ");
                    scanf("%s", products[num_products].description);
                    
                    printf("Enter product price: ");
                    scanf("%s", products[num_products].price);
                    
                    num_products++;
                    printf("Product added successfully.\n");
                }
                break;
                
            case '2':
                printf("Enter product name to search: ");
                scanf("%s", products[0].name);
                
                for(int i = 1; i <= num_products; i++) {
                    if(strcmp(products[i].name, products[0].name) == 0) {
                        printf("Product found.\n");
                        printf("Name: %s\n", products[i].name);
                        printf("Description: %s\n", products[i].description);
                        printf("Price: %s\n", products[i].price);
                    }
                }
                break;
                
            case '3':
                for(int i = 0; i < num_products; i++) {
                    printf("Name: %s\n", products[i].name);
                    printf("Description: %s\n", products[i].description);
                    printf("Price: %s\n", products[i].price);
                    printf("\n");
                }
                break;
                
            case '4':
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '4');
    
    return 0;
}