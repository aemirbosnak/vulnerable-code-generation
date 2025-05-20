//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char item[20];
    int quantity;
    float price;
} Product;

void add_product(Product *warehouse, int *num_products) {
    printf("Enter product name: ");
    scanf("%s", warehouse[*num_products].item);
    printf("Enter product quantity: ");
    scanf("%d", &warehouse[*num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &warehouse[*num_products].price);
    (*num_products)++;
}

void list_products(Product *warehouse, int num_products) {
    printf("Products in warehouse:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d, %.2f\n", i+1, warehouse[i].item, warehouse[i].quantity, warehouse[i].price);
    }
}

float total_value(Product *warehouse, int num_products) {
    float total = 0;
    for (int i = 0; i < num_products; i++) {
        total += warehouse[i].quantity * warehouse[i].price;
    }
    return total;
}

void search_product(Product *warehouse, int num_products) {
    char name[20];
    printf("Enter product name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(warehouse[i].item, name) == 0) {
            printf("%s - %d, %.2f\n", warehouse[i].item, warehouse[i].quantity, warehouse[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

void sell_product(Product *warehouse, int *num_products) {
    char name[20];
    printf("Enter product name to sell: ");
    scanf("%s", name);
    for (int i = 0; i < *num_products; i++) {
        if (strcmp(warehouse[i].item, name) == 0) {
            int quantity;
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            if (quantity > warehouse[i].quantity) {
                printf("Not enough product in stock.\n");
            } else {
                warehouse[i].quantity -= quantity;
                printf("Sold %d of %s\n", quantity, warehouse[i].item);
                if(warehouse[i].quantity == 0){
                    for(int j=i; j<(*num_products)-1; j++){
                        warehouse[j] = warehouse[j+1];
                    }
                    (*num_products)--;
                }
            }
            return;
        }
    }
    printf("Product not found.\n");
}

int main() {
    Product warehouse[50];
    int num_products = 0;
    char choice;
    do {
        printf("\n------- Warehouse Management System --------\n");
        printf("1. Add Product\n");
        printf("2. List Products\n");
        printf("3. Total Value of Products\n");
        printf("4. Search Product by Name\n");
        printf("5. Sell Product by Name\n");
        printf("0. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                add_product(warehouse, &num_products);
                break;
            case '2':
                list_products(warehouse, num_products);
                break;
            case '3':
                printf("Total value of products: %.2f\n", total_value(warehouse, num_products));
                break;
            case '4':
                search_product(warehouse, num_products);
                break;
            case '5':
                sell_product(warehouse, &num_products);
                break;
            case '0':
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != '0');

    return 0;
}