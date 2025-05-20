//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct product {
    char name[20];
    int quantity;
};

void add_product(struct product* products, int n, char* product_name, int quantity) {
    products[n].quantity = quantity;
    strcpy(products[n].name, product_name);
}

void print_products(struct product* products, int n) {
    for(int i = 0; i < n; i++) {
        printf("Product: %s, Quantity: %d\n", products[i].name, products[i].quantity);
    }
}

void update_product(struct product* products, int n, char* product_name, int quantity) {
    for(int i = 0; i < n; i++) {
        if(strcmp(products[i].name, product_name) == 0) {
            products[i].quantity = quantity;
            break;
        }
    }
}

void remove_product(struct product* products, int n, char* product_name) {
    for(int i = 0; i < n; i++) {
        if(strcmp(products[i].name, product_name) == 0) {
            for(int j = i; j < n-1; j++) {
                products[j] = products[j+1];
            }
            n--;
            break;
        }
    }
}

int main() {
    struct product products[100];
    int n = 0;

    printf("Product Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Print Products\n");
    printf("3. Update Product\n");
    printf("4. Remove Product\n");
    printf("5. Exit\n");

    int choice;
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter product name: ");
                scanf("%s", products[n].name);
                printf("Enter product quantity: ");
                scanf("%d", &products[n].quantity);
                add_product(products, n, products[n].name, products[n].quantity);
                break;
            }
            case 2: {
                print_products(products, n);
                break;
            }
            case 3: {
                printf("Enter product name: ");
                scanf("%s", products[n].name);
                printf("Enter updated quantity: ");
                scanf("%d", &products[n].quantity);
                update_product(products, n, products[n].name, products[n].quantity);
                break;
            }
            case 4: {
                printf("Enter product name: ");
                scanf("%s", products[n].name);
                remove_product(products, n, products[n].name);
                break;
            }
            case 5: {
                printf("Exiting...\n");
                return 0;
            }
            default: {
                printf("Invalid Choice. Please try again\n");
                break;
            }
        }
    }

    return 0;
}