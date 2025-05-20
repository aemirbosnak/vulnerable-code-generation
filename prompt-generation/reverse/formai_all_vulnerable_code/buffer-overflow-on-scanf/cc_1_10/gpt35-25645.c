//FormAI DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct Product{
    char name[50];
    int quantity;
    float price;
};

struct Product product_storage[MAX_SIZE];

int current_size = 0;

void add_product(){
    if(current_size == MAX_SIZE){
        printf("The inventory is already full!\n");
        return;
    }

    struct Product new_product;

    printf("\nAdding a new product.\n");

    printf("Enter the name of the new product:\n");
    scanf("%s", new_product.name);

    printf("Enter the quantity of the new product:\n");
    scanf("%d", &new_product.quantity);

    printf("Enter the price of the new product:\n");
    scanf("%f", &new_product.price);

    product_storage[current_size++] = new_product;

    printf("\nProduct added successfully!\n");
}

void update_product(){
    if(current_size == 0){
        printf("\nThere are no products in the inventory!\n");
        return;
    }

    printf("\nUpdating an existing product.");

    printf("\nEnter the name of the product you want to update:\n");
    char product_name[50];
    scanf("%s", product_name);

    int product_index = -1;

    for(int i=0; i<current_size; i++){
        if(strcmp(product_storage[i].name, product_name) == 0){
            product_index = i;
            break;
        }
    }

    if(product_index == -1){
        printf("\nThe product you entered does not exist!\n");
        return;
    }

    printf("Enter the new quantity of the product:\n");
    scanf("%d", &product_storage[product_index].quantity);

    printf("Enter the new price of the product:\n");
    scanf("%f", &product_storage[product_index].price);

    printf("\nProduct updated successfully!\n");
}

void delete_product(){
    if(current_size == 0){
        printf("\nThere are no products in the inventory!\n");
        return;
    }

    printf("\nDeleting an existing product.");

    printf("\nEnter the name of the product you want to delete:\n");
    char product_name[50];
    scanf("%s", product_name);

    int product_index = -1;

    for(int i=0; i<current_size; i++){
        if(strcmp(product_storage[i].name, product_name) == 0){
            product_index = i;
            break;
        }
    }

    if(product_index == -1){
        printf("\nThe product you entered does not exist!\n");
        return;
    }

    for(int i=product_index; i<current_size-1; i++){
        product_storage[i] = product_storage[i+1];
    }

    current_size--;

    printf("\nProduct deleted successfully!\n");
}

void display_inventory(){
    if(current_size == 0){
        printf("\nThere are no products in the inventory!\n");
        return;
    }

    printf("\nCurrent Inventory consists of: \n");

    printf("%-20s%-10s%-10s\n", "Product Name", "Quantity", "Price");

    for(int i=0; i<current_size; i++){
        printf("%-20s%-10d%-10.2f\n", product_storage[i].name, product_storage[i].quantity, product_storage[i].price);
    }
}

void recursive_menu();
void recursive_process_input(int);

void recursive_menu(){
    printf("\n\n----- Product Inventory Menu -----\n\n");
    printf("1. Add a new product.\n");
    printf("2. Update an existing product.\n");
    printf("3. Delete an existing product.\n");
    printf("4. Display the current inventory.\n");
    printf("5. Exit the program.\n");

    int menu_choice;
    printf("\nEnter your choice:\n");
    scanf("%d", &menu_choice);

    recursive_process_input(menu_choice);

}

void recursive_process_input(int choice){
    switch(choice){
        case 1:
            add_product();
            recursive_menu();
            break;
        case 2:
            update_product();
            recursive_menu();
            break;
        case 3:
            delete_product();
            recursive_menu();
            break;
        case 4:
            display_inventory();
            recursive_menu();
            break;
        case 5:
            printf("\nExiting program.\n\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice!\n");
            recursive_menu();
            break;
    }
}

int main(){
    recursive_menu();
    return 0;
}