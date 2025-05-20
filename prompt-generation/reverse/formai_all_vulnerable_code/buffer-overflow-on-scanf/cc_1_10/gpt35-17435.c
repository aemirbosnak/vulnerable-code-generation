//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: secure
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_LEN 100
#define MAX_PROD 100

// Structure for Product Details
struct Product{
    char P_name[MAX_LEN];
    char P_id[MAX_LEN];
    float P_price;
    int P_quantity;
};

// Global Variables
struct Product products[MAX_PROD];
int currIndex = 0;

// Function to Add a Product
void addProduct(){
    struct Product p;
    printf("Enter Product Name: ");
    scanf("%s",p.P_name);
    printf("Enter Product ID: ");
    scanf("%s",p.P_id);
    printf("Enter Product Price: ");
    scanf("%f",&p.P_price);
    printf("Enter Product Quantity: ");
    scanf("%d",&p.P_quantity);
    products[currIndex++] = p; // Adds new product to products array
    printf("Product added successfully!\n");
    printf("\n");
}

// Function to Search for a Product using Product ID
void searchProduct(){
    char P_id[MAX_LEN];
    printf("Enter Product ID: ");
    scanf("%s",P_id);
    int i;
    for(i=0; i<currIndex; i++){
        if(strcmp(products[i].P_id,P_id)==0){
            printf("Product Name: %s\n",products[i].P_name);
            printf("Product ID: %s\n",products[i].P_id);
            printf("Product Price: %.2f\n",products[i].P_price);
            printf("Product Quantity: %d\n",products[i].P_quantity);
            printf("\n");
            return;
        }
    }
    printf("No product found with the given ID!\n");
    printf("\n");
}

// Function to Display All Products
void display(){
    int i;
    for(i=0; i<currIndex; i++){
        printf("Product Name: %s\n",products[i].P_name);
        printf("Product ID: %s\n",products[i].P_id);
        printf("Product Price: %.2f\n",products[i].P_price);
        printf("Product Quantity: %d\n",products[i].P_quantity);
        printf("\n");
    }
}

// Function to Remove a Product using Product ID
void removeProduct(){
    char P_id[MAX_LEN];
    printf("Enter Product ID: ");
    scanf("%s",P_id);
    int i;
    for(i=0; i<currIndex; i++){
        if(strcmp(products[i].P_id,P_id)==0){
            int j;
            for(j=i; j<currIndex-1; j++){
                products[j] = products[j+1];
            }
            currIndex--; // Current index of products array is decreased as one product is removed
            printf("Product removed successfully!\n");
            printf("\n");
            return;
        }
    }
    printf("No product found with the given ID!\n");
    printf("\n");
}

// Function to Update a Product's Details
void updateProduct(){
    char P_id[MAX_LEN];
    printf("Enter Product ID: ");
    scanf("%s",P_id);
    int i;
    for(i=0; i<currIndex; i++){
        if(strcmp(products[i].P_id,P_id)==0){
            printf("Enter Updated Product Name (Press Enter Key to Skip): ");
            char temp[MAX_LEN];
            fgets(temp,MAX_LEN,stdin); // Clears input buffer
            fgets(products[i].P_name,MAX_LEN,stdin);
            products[i].P_name[strcspn(products[i].P_name,"\n")] = 0; // Removes newline character from input
            printf("Enter Updated Product Price (Press Enter Key to Skip): ");
            char price[MAX_LEN];
            fgets(price,MAX_LEN,stdin);
            if(strcmp(price,"\n")!=0){
                products[i].P_price = atof(price); // Converts string to float
            }
            printf("Enter Updated Product Quantity (Press Enter Key to Skip): ");
            char quantity[MAX_LEN];
            fgets(quantity,MAX_LEN,stdin);
            if(strcmp(quantity,"\n")!=0){
                products[i].P_quantity = atoi(quantity); // Converts string to integer
            }
            printf("Product details updated successfully!\n");
            printf("\n");
            return;
        }
    }
    printf("No product found with the given ID!\n");
    printf("\n");
}

// Function to Display Menu Options
void displayMenu(){
    printf("====== Medical Store Management System ======\n");
    printf("1. Add Product\n");
    printf("2. Search Product\n");
    printf("3. Display Products\n");
    printf("4. Remove Product\n");
    printf("5. Update Product Details\n");
    printf("6. Exit\n");
}

int main(){
    int choice;
    while(1){
        displayMenu();
        printf("Enter your choice (1-6): ");
        scanf("%d",&choice);
        switch(choice){
            case 1: addProduct();
                    break;
            case 2: searchProduct();
                    break;
            case 3: display();
                    break;
            case 4: removeProduct();
                    break;
            case 5: updateProduct();
                    break;
            case 6: exit(0);
            default: printf("Invalid Choice! Try Again.\n");
        }
    }
    return 0;
}