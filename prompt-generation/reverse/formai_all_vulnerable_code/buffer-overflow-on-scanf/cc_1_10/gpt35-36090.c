//FormAI DATASET v1.0 Category: Product Inventory System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

// Defining the maximum number of products possible
#define MAX_PRODUCTS 100

// Defining the product structure
struct product{
    char name[20];
    int quantity;
    float price;
};

// Initializing the product array with maximum products and count of products in the array
struct product products[MAX_PRODUCTS];
int count = 0;

// Function to add a new product to the array
void addProduct(){
    struct product newProduct;
    printf("Enter the name of the product: ");
    scanf("%s", newProduct.name);
    printf("Enter the quantity of the product: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter the price of the product: ");
    scanf("%f", &newProduct.price);
    products[count] = newProduct;
    count++;
}

// Function to display all the available products
void displayProducts(){
    printf("\n");
    for(int i=0; i<count; i++){
        printf("Product %d\n", i+1);
        printf("Name: %s\n", products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2f\n", products[i].price);
        printf("\n");
    }
}

// Function to search for a product based on its name
void searchProduct(){
    printf("Enter the name of the product you want to search: ");
    char searchQuery[20];
    scanf("%s", searchQuery);
    int found = 0;
    printf("\n");
    for(int i=0; i<count; i++){
        if(strcmp(searchQuery, products[i].name) == 0){
            found = 1;
            printf("Product %d\n", i+1);
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: $%.2f\n", products[i].price);
            printf("\n");
            break;
        }
    }
    if(!found){
        printf("Product not found\n");
    }
}


int main(){
    int option;
    do{
        printf("\nWelcome to the Product Inventory System!\n");
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Search a product\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                printf("Thanks for using the Product Inventory System!\n");
                exit(0);
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    } while(option != 4);
    return 0;
}