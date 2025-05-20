//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

int num_products = 0;
//Product data structure
typedef struct Product{
    int product_id;
    char product_name[30];
    int product_quantity;
    float product_cost;
    float product_discount;
} product;

//An array to store all the products
product all_products[MAX_SIZE];

//create a function to add a product to the data structure
void add_product(){
    product new_product;
    printf("Enter product ID: ");
    scanf("%d", &new_product.product_id);
    printf("Enter product name: ");
    scanf("%s", &new_product.product_name);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.product_quantity);
    printf("Enter product cost: ");
    scanf("%f", &new_product.product_cost);
    printf("Enter product discount: ");
    scanf("%f", &new_product.product_discount);

    all_products[num_products] = new_product;
    num_products++;
    printf("Product added successfully!\n");
}

//function to display all products
void display_all_products(){
    if(num_products == 0){
        printf("No products found!\n");
        return;
    }
    printf("Product ID\tProduct Name\tProduct Quantity\tProduct Cost\tProduct Discount\n");
    for(int i=0;i<num_products;i++){
        product current_product = all_products[i];
        printf("%d\t\t%s\t%d\t\t%.2f\t\t%.2f\n", current_product.product_id, current_product.product_name, current_product.product_quantity, current_product.product_cost, current_product.product_discount);
    }
}

//function to search for a product by its ID
void search_product_by_id(){
    int product_id;
    printf("Enter product ID: ");
    scanf("%d", &product_id);

    for(int i=0;i<num_products;i++){
        product current_product = all_products[i];
        if(current_product.product_id == product_id){
            printf("Product ID\tProduct Name\tProduct Quantity\tProduct Cost\tProduct Discount\n");
            printf("%d\t\t%s\t%d\t\t%.2f\t\t%.2f\n", current_product.product_id, current_product.product_name, current_product.product_quantity, current_product.product_cost, current_product.product_discount);
            return;
        }
    }
    printf("Product not found!\n");
}

//function to search for a product by its name
void search_product_by_name(){
    char product_name[30];
    printf("Enter product name: ");
    scanf("%s", &product_name);

    for(int i=0;i<num_products;i++){
        product current_product = all_products[i];
        if(strcmp(current_product.product_name, product_name) == 0){
            printf("Product ID\tProduct Name\tProduct Quantity\tProduct Cost\tProduct Discount\n");
            printf("%d\t\t%s\t%d\t\t%.2f\t\t%.2f\n", current_product.product_id, current_product.product_name, current_product.product_quantity, current_product.product_cost, current_product.product_discount);
            return;
        }
    }
    printf("Product not found!\n");
}

int main(){
    int choice;
    while(1){
        printf("Welcome to the Medical Store Management System!\n");
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Search for a product by ID\n");
        printf("4. Search for a product by name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_product();
                break;
            case 2:
                display_all_products();
                break;
            case 3:
                search_product_by_id();
                break;
            case 4:
                search_product_by_name();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}