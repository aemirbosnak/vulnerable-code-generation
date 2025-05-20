//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

int main() {
    int option, i, num_products = 0;
    Product products[100];
    
    while(1) {
        printf("Welcome to the Product Database Simulation!\n");
        printf("1. Add Product.\n");
        printf("2. View All Products.\n");
        printf("3. Search for Product.\n");
        printf("4. Edit Product.\n");
        printf("5. Delete Product.\n");
        printf("6. Exit.\n");
        printf("What would you like to do? ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                if(num_products == 100) {
                    printf("Database is full. Please delete a product before adding another.\n");
                } else {
                    printf("Enter product ID: ");
                    scanf("%d", &products[num_products].id);
                    printf("Enter product name: ");
                    getchar();
                    fgets(products[num_products].name, 50, stdin);
                    printf("Enter product price: ");
                    scanf("%f", &products[num_products].price);
                    num_products++;
                    printf("Product added successfully!\n");
                }
                break;
            case 2:
                if(num_products == 0) {
                    printf("Database is empty. Please add a product first.\n");
                } else {
                    printf("ID | Name | Price\n");
                    for(i = 0; i < num_products; i++) {
                        printf("%d | %s | $%.2f\n", products[i].id, products[i].name, products[i].price);
                    }
                }
                break;
            case 3:
                if(num_products == 0) {
                    printf("Database is empty. Please add a product first.\n");
                } else {
                    int search_id;
                    printf("Enter the ID of the product you would like to search for: ");
                    scanf("%d", &search_id);
                    for(i = 0; i < num_products; i++) {
                        if(products[i].id == search_id) {
                            printf("Product found!\n");
                            printf("ID | Name | Price\n");
                            printf("%d | %s | $%.2f\n", products[i].id, products[i].name, products[i].price);
                            break;
                        }
                    }
                    if(i == num_products) {
                        printf("Product not found.\n");
                    }
                }
                break;
            case 4:
                if(num_products == 0) {
                    printf("Database is empty. Please add a product first.\n");
                } else {
                    int edit_id;
                    printf("Enter the ID of the product you would like to edit: ");
                    scanf("%d", &edit_id);
                    for(i = 0; i < num_products; i++) {
                        if(products[i].id == edit_id) {
                            printf("Product found! Enter the new values:\n");
                            printf("Enter product name: ");
                            getchar();
                            fgets(products[i].name, 50, stdin);
                            printf("Enter product price: ");
                            scanf("%f", &products[i].price);
                            printf("Product edited successfully!\n");
                            break;
                        }
                    }
                    if(i == num_products) {
                        printf("Product not found.\n");
                    }
                }
                break;
            case 5:
                if(num_products == 0) {
                    printf("Database is empty. Please add a product first.\n");
                } else {
                    int delete_id, delete_index;
                    printf("Enter the ID of the product you would like to delete: ");
                    scanf("%d", &delete_id);
                    for(i = 0; i < num_products; i++) {
                        if(products[i].id == delete_id) {
                            delete_index = i;
                            break;
                        }
                    }
                    if(i == num_products) {
                        printf("Product not found.\n");
                    } else {
                        for(i = delete_index; i < num_products - 1; i++) {
                            products[i] = products[i + 1];
                        }
                        num_products--;
                        printf("Product deleted successfully!\n");
                    }
                }
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid option. Please enter a number from 1-6.\n");
        }
        
        printf("\n");
    }
}