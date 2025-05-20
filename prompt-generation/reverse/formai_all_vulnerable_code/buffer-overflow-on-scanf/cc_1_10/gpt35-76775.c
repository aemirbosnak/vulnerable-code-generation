//FormAI DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_PRODUCTS 1000

struct product{
    char name[50];
    float price;
    int quantity;
};

int numProducts = 0;
struct product inventory[MAX_PRODUCTS];

//Function to display all products in the inventory
void displayProductDetails(){
    printf("Name\t\tPrice\t\tQuantity\n");
    printf("---------------------------------------\n");
    for(int i=0;i<numProducts;i++){
        printf("%s\t\t%.2f\t\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("---------------------------------------\n");
}

//Function to add a new product to the inventory
void addNewProduct(){
    if(numProducts<MAX_PRODUCTS){
        printf("Enter product name: ");
        scanf("%s", inventory[numProducts].name);
        printf("Enter product price: ");
        scanf("%f", &inventory[numProducts].price);
        printf("Enter product quantity: ");
        scanf("%d", &inventory[numProducts].quantity);
        numProducts++;
        printf("Product added successfully!\n");
    }
    else{
        printf("Inventory full. Cannot add any more products.\n");
    }
}

//Function to search for a product in the inventory by name
void searchProductByName(){
    char searchName[50];
    printf("Enter product name to search: ");
    scanf("%s", searchName);
    for(int i=0;i<numProducts;i++){
        if(strcmp(inventory[i].name, searchName)==0){
            printf("Name\t\tPrice\t\tQuantity\n");
            printf("---------------------------------------\n");
            printf("%s\t\t%.2f\t\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("Product not found.\n");
}

//Function to search for a product in the inventory by price range
void searchProductByPrice(){
    float minPrice, maxPrice;
    printf("Enter minimum price: ");
    scanf("%f", &minPrice);
    printf("Enter maximum price: ");
    scanf("%f", &maxPrice);
    printf("Name\t\tPrice\t\tQuantity\n");
    printf("---------------------------------------\n");
    for(int i=0;i<numProducts;i++){
        if(inventory[i].price>=minPrice && inventory[i].price<=maxPrice){
            printf("%s\t\t%.2f\t\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
    }
    printf("---------------------------------------\n");
}

int main(){
    int choice;
    do{
        printf("\n");
        printf("Product Inventory Management \n");
        printf("-----------------------------\n");
        printf("1. Add a new product \n");
        printf("2. Search for a product by name \n");
        printf("3. Search for a product by price range \n");
        printf("4. Display all products \n");
        printf("5. Exit \n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");

        scanf("%d",&choice);

        switch (choice){
            case 1:
                addNewProduct();
                break;
            case 2:
                searchProductByName();
                break;
            case 3:
                searchProductByPrice();
                break;
            case 4:
                displayProductDetails();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid input. Please enter a valid option.\n");
        }
    }while(1);

    return 0;
}