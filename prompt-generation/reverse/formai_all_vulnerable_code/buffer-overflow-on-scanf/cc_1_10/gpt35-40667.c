//FormAI DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCT_NAME_LENGTH 50

// struct for each product
typedef struct Product{
    char name[MAX_PRODUCT_NAME_LENGTH];
    int ID;
    int quantity;
    float price;
}Product;

// function to display menu
void display_menu(){
    printf("Welcome to the Product Inventory System\n");
    printf("1. Add a new product\n");
    printf("2. Remove a product\n");
    printf("3. Edit a product\n");
    printf("4. Display all products\n");
    printf("5. Search by name\n");
    printf("6. Search by ID\n");
    printf("7. Exit the program\n");
    printf("\n");
}

// function to add a new product
void add_new_product(Product *inventory, int *num_products){
    printf("Enter the name of the new product (50 characters max):\n");
    scanf("%s", inventory[*num_products].name);
    printf("Enter the ID of the new product:\n");
    scanf("%d", &inventory[*num_products].ID);
    printf("Enter the quantity of the new product:\n");
    scanf("%d", &inventory[*num_products].quantity);
    printf("Enter the price of the new product:\n");
    scanf("%f", &inventory[*num_products].price);
    (*num_products)++;
}

// function to remove a product
void remove_product(Product *inventory, int *num_products){
    int ID_to_remove;
    printf("Enter the ID of the product to remove:\n");
    scanf("%d", &ID_to_remove);
    for(int i = 0; i < *num_products; i++){
        if(inventory[i].ID == ID_to_remove){
            for(int j = i; j < *num_products - 1; j++){
                inventory[j] = inventory[j+1];
            }
            (*num_products)--;
            printf("Product removed successfully!\n");
            return;
        }
    }
    printf("Error: Product not found.\n");
}

// function to edit a product
void edit_product(Product *inventory, int num_products){
    int ID_to_edit;
    printf("Enter the ID of the product to edit:\n");
    scanf("%d", &ID_to_edit);
    for(int i = 0; i < num_products; i++){
        if(inventory[i].ID == ID_to_edit){
            printf("Enter the new name of the product (50 characters max):\n");
            scanf("%s", inventory[i].name);
            printf("Enter the new quantity of the product:\n");
            scanf("%d", &inventory[i].quantity);
            printf("Enter the new price of the product:\n");
            scanf("%f", &inventory[i].price);
            printf("Product edited successfully!\n");
            return;
        }
    }
    printf("Error: Product not found.\n");
}

// function to display all products
void display_all_products(Product *inventory, int num_products){
    printf("Name\tID\tQuantity\tPrice\n");
    for(int i = 0; i < num_products; i++){
        printf("%s\t%d\t%d\t\t%.2f\n", inventory[i].name, inventory[i].ID, inventory[i].quantity, inventory[i].price);
    }
}

// function to search for a product by name
void search_by_name(Product *inventory, int num_products){
    char name_to_search[MAX_PRODUCT_NAME_LENGTH];
    printf("Enter the name of the product to search:\n");
    scanf("%s", name_to_search);
    printf("Name\tID\tQuantity\tPrice\n");
    for(int i = 0; i < num_products; i++){
        if(strcmp(inventory[i].name, name_to_search) == 0){
            printf("%s\t%d\t%d\t\t%.2f\n", inventory[i].name, inventory[i].ID, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Error: Product not found.\n");
}

// function to search for a product by ID
void search_by_ID(Product *inventory, int num_products){
    int ID_to_search;
    printf("Enter the ID of the product to search:\n");
    scanf("%d", &ID_to_search);
    printf("Name\tID\tQuantity\tPrice\n");
    for(int i = 0; i < num_products; i++){
        if(inventory[i].ID == ID_to_search){
            printf("%s\t%d\t%d\t\t%.2f\n", inventory[i].name, inventory[i].ID, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Error: Product not found.\n");
}

int main(){
    Product inventory[100];
    int num_products = 0;
    int selection;
    while(1){
        display_menu();
        printf("Enter your selection (1-7):\n");
        scanf("%d", &selection);
        switch(selection){
            case 1:
                if(num_products < 100){
                    add_new_product(inventory, &num_products);
                }
                else{
                    printf("Error: Maximum number of products already reached.\n");
                }
                break;
            case 2:
                remove_product(inventory, &num_products);
                break;
            case 3:
                edit_product(inventory, num_products);
                break;
            case 4:
                display_all_products(inventory, num_products);
                break;
            case 5:
                search_by_name(inventory, num_products);
                break;
            case 6:
                search_by_ID(inventory, num_products);
                break;
            case 7:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid input. Please enter a number from 1-7.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}