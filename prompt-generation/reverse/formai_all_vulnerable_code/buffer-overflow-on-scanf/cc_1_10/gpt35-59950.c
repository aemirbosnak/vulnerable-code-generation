//FormAI DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void display_menu();
void add_product(Product *products, int *no_of_products);
void display_products(Product *products, int no_of_products);
void search_product(Product *products, int no_of_products);
void update_product(Product *products, int no_of_products);

int main()
{
    int choice, no_of_products = 0;
    Product *products = NULL;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_product(products, &no_of_products);
                break;
            case 2:
                display_products(products, no_of_products);
                break;
            case 3:
                search_product(products, no_of_products);
                break;
            case 4:
                update_product(products, no_of_products);
                break;
            case 5:
                printf("Exiting the program...");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
        printf("\n");
    } while(choice != 5);
    
    free(products);
    return 0;
}

void display_menu()
{
    printf("Menu:\n");
    printf("1. Add product\n");
    printf("2. Display products\n");
    printf("3. Search product\n");
    printf("4. Update product\n");
    printf("5. Exit\n");
}

void add_product(Product *products, int *no_of_products)
{
    (*no_of_products)++;
    products = realloc(products, (*no_of_products) * sizeof(Product));
    Product new_product;
    
    printf("Enter product details:\n");
    printf("ID: ");
    scanf("%d", &new_product.id);
    printf("Name: ");
    scanf("%s", &new_product.name);
    printf("Quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Price: ");
    scanf("%f", &new_product.price);
    
    products[(*no_of_products) - 1] = new_product;
}

void display_products(Product *products, int no_of_products)
{
    if(no_of_products == 0) {
        printf("No products in inventory.\n");
    } else {
        printf("Product Inventory:\n");
        printf("ID\tName\tQuantity\tPrice\n");
        for(int i = 0; i < no_of_products; i++) {
            printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
        }
    }
}

void search_product(Product *products, int no_of_products)
{
    if(no_of_products == 0) {
        printf("No products in inventory.\n");
    } else {
        int search_id, found = 0;
        printf("Enter ID of product to search: ");
        scanf("%d", &search_id);
        
        for(int i = 0; i < no_of_products; i++) {
            if(products[i].id == search_id) {
                printf("Product found:\n");
                printf("ID\tName\tQuantity\tPrice\n");
                printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
                found = 1;
                break;
            }
        }
        
        if(found == 0) {
            printf("Product not found.\n");
        }
    }
}

void update_product(Product *products, int no_of_products)
{
    if(no_of_products == 0) {
        printf("No products in inventory.\n");
    } else {
        int update_id, found = 0, choice;
        printf("Enter ID of product to update: ");
        scanf("%d", &update_id);
        
        for(int i = 0; i < no_of_products; i++) {
            if(products[i].id == update_id) {
                found = 1;
                printf("Product found:\n");
                printf("ID\tName\tQuantity\tPrice\n");
                printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
                
                printf("Select field to update:\n");
                printf("1. ID\n");
                printf("2. Name\n");
                printf("3. Quantity\n");
                printf("4. Price\n");
                printf("5. Cancel update\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch(choice) {
                    case 1:
                        printf("Enter new ID: ");
                        scanf("%d", &products[i].id);
                        break;
                    case 2:
                        printf("Enter new name: ");
                        scanf("%s", &products[i].name);
                        break;
                    case 3:
                        printf("Enter new quantity: ");
                        scanf("%d", &products[i].quantity);
                        break;
                    case 4:
                        printf("Enter new price: ");
                        scanf("%f", &products[i].price);
                        break;
                    case 5:
                        printf("Cancelling update...\n");
                        break;
                    default:
                        printf("Invalid choice! Cancelling update...\n");
                }
                
                break;
            }
        }
        
        if(found == 0) {
            printf("Product not found.\n");
        }
    }
}