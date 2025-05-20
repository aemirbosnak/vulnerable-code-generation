//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 100 // maximum number of products

typedef struct{
    int id;
    char name[50];
    float price;
    int quantity;
} PRODUCT; // structure to hold product information

PRODUCT inventory[MAX_PRODUCTS]; // array to hold products

int numProducts = 0; // number of products currently in inventory

// function to add a product to inventory
void addProduct(){
    if(numProducts == MAX_PRODUCTS){
        printf("Inventory full. Cannot add more products.\n");
        return;
    }
    printf("Enter product details: \n");
    printf("ID: ");
    scanf("%d", &inventory[numProducts].id);
    printf("Name: ");
    scanf("%s", inventory[numProducts].name);
    printf("Price: ");
    scanf("%f", &inventory[numProducts].price);
    printf("Quantity: ");
    scanf("%d", &inventory[numProducts].quantity);
    numProducts++;
}

// function to display all products in inventory
void displayProducts(){
    if(numProducts == 0){
        printf("No products in inventory.\n");
        return;
    }
    printf("ID\tName\tPrice\tQuantity\n");
    for(int i=0; i<numProducts; i++){
        printf("%d\t%s\t$%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// function to search for a product in inventory by name
void searchByName(){
    char name[50];
    printf("Enter product name to search for: ");
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<numProducts; i++){
        if(strcmp(inventory[i].name, name) == 0){
            printf("ID\tName\tPrice\tQuantity\n");
            printf("%d\t%s\t$%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Product not found in inventory.\n");
    }
}

// function to search for a product in inventory by ID
void searchById(){
    int id;
    printf("Enter product ID to search for: ");
    scanf("%d", &id);
    int found = 0;
    for(int i=0; i<numProducts; i++){
        if(inventory[i].id == id){
            printf("ID\tName\tPrice\tQuantity\n");
            printf("%d\t%s\t$%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Product not found in inventory.\n");
    }
}

int main(){
    int choice;
    do{
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Display all products\n");
        printf("3. Search by name\n");
        printf("4. Search by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                searchByName();
                break;
            case 4:
                searchById();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }while(choice != 5);
    
    return 0;
}