//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to add new products to the warehouse
void add_product(int* p_count, char p_name[][100], int p_quantity[], float p_price[]) {
    char name[100];
    int quantity;
    float price;

    printf("Enter the name of the new product: ");
    scanf("%s", name);

    printf("Enter the quantity of the product: ");
    scanf("%d", &quantity);

    printf("Enter the price of the product: ");
    scanf("%f", &price);

    strcpy(p_name[*p_count], name);
    p_quantity[*p_count] = quantity;
    p_price[*p_count] = price;

    printf("%s added to the warehouse.\n", p_name[*p_count]);
    *p_count += 1;
}

//function to display all the products in the warehouse
void display_products(int count, char p_name[][100], int p_quantity[], float p_price[]) {
    printf("The products in the warehouse are:\n");

    for(int i=0; i<count; i++) {
        printf("Product name: %s\n", p_name[i]);
        printf("Product quantity: %d\n", p_quantity[i]);
        printf("Product price: %.2f\n", p_price[i]);
        printf("\n");
    }
}

//function to search products in the warehouse
void search_product(int count, char p_name[][100], int p_quantity[], float p_price[]) {
    char name[100];

    printf("Enter the name of the product you want to search: ");
    scanf("%s", name);

    int index=-1;
    for(int i=0; i<count; i++) {
        if(strcmp(p_name[i], name) == 0) {
            index = i;
            break;
        }
    }

    if(index != -1) {
        printf("Product name: %s\n", p_name[index]);
        printf("Product quantity: %d\n", p_quantity[index]);
        printf("Product price: %.2f\n", p_price[index]);
    } else {
        printf("Product not found in the warehouse.\n");
    }
}

int main() {
    int count = 0; //variable to keep track of the number of products in the warehouse
    int choice; //variable to store the user's choice
    char p_name[100][100]; //2D array to store the product names
    int p_quantity[100]; //array to store the quantity of the products
    float p_price[100]; //array to store the price of the products

    while(1) {
        printf("\n");
        printf("Warehouse Management System\n");
        printf("===========================\n");
        printf("1. Add new product\n");
        printf("2. Display products\n");
        printf("3. Search for a product\n");
        printf("4. Exit\n");

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n");
                add_product(&count, p_name, p_quantity, p_price);
                break;
            case 2:
                printf("\n");
                display_products(count, p_name, p_quantity, p_price);
                break;
            case 3:
                printf("\n");
                search_product(count, p_name, p_quantity, p_price);
                break;
            case 4:
                printf("\n");
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("\n");
                printf("Invalid choice. Please enter a valid choice (1-4).\n");
        }
    }

    return 0;
}