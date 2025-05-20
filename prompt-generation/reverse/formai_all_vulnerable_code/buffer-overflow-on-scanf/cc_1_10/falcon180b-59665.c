//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    num_products++;
}

void display_products() {
    printf("Product Name\tQuantity\n");
    for(int i=0; i<num_products; i++) {
        printf("%s\t\t%d\n", products[i].name, products[i].quantity);
    }
}

void search_product() {
    printf("Enter product name to search: ");
    char search_name[MAX_NAME_LENGTH];
    scanf("%s", search_name);
    int found = 0;
    for(int i=0; i<num_products; i++) {
        if(strcmp(products[i].name, search_name) == 0) {
            printf("Product found: %s\n", products[i].name);
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("Product not found.\n");
    }
}

void update_quantity() {
    printf("Enter product name to update quantity: ");
    char search_name[MAX_NAME_LENGTH];
    scanf("%s", search_name);
    int found = 0;
    for(int i=0; i<num_products; i++) {
        if(strcmp(products[i].name, search_name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("Product not found.\n");
    }
}

void delete_product() {
    printf("Enter product name to delete: ");
    char search_name[MAX_NAME_LENGTH];
    scanf("%s", search_name);
    int found = 0;
    for(int i=0; i<num_products; i++) {
        if(strcmp(products[i].name, search_name) == 0) {
            for(int j=i; j<num_products-1; j++) {
                products[j] = products[j+1];
            }
            num_products--;
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("Product not found.\n");
    }
}

int main() {
    printf("Welcome to the Product Inventory System.\n");
    while(1) {
        printf("What would you like to do?\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product\n");
        printf("4. Update quantity\n");
        printf("5. Delete product\n");
        printf("6. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                update_quantity();
                break;
            case 5:
                delete_product();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}