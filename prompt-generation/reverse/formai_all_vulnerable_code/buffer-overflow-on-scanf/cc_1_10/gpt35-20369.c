//FormAI DATASET v1.0 Category: Product Inventory System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 100 //Maximum number of products that can be stored

//Product structure
struct product{
    int id;
    char name[100];
    float price;
    int quantity;
};

//Global variables
struct product products[MAX_PRODUCTS]; //Array to store products
int num_products = 0; //Number of products stored in the array

//Function to print menu
void print_menu(){
    printf("\n----PRODUCT INVENTORY SYSTEM----\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. Delete Product\n");
    printf("4. Search Product\n");
    printf("5. Display All Products\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

//Function to add new product
void add_product(){
    printf("\n----ADD NEW PRODUCT----\n");
    
    //Check if maximum products have been reached
    if(num_products >= MAX_PRODUCTS){
        printf("Error: Maximum products reached.\n");
        return;
    }
    
    //Get product details from user
    struct product p;
    printf("Enter product id: ");
    scanf("%d", &p.id);
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    
    //Add product to array
    products[num_products] = p;
    num_products++;
    
    printf("Product added successfully.\n");
}

//Function to update product
void update_product(){
    printf("\n----UPDATE PRODUCT----\n");
    
    //Get product id from user
    int id;
    printf("Enter product id: ");
    scanf("%d", &id);
    
    //Search for product in array
    for(int i=0; i<num_products; i++){
        if(products[i].id == id){
            //Get updated product details from user
            printf("Enter new product name: ");
            scanf("%s", products[i].name);
            printf("Enter new product price: ");
            scanf("%f", &products[i].price);
            printf("Enter new product quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Product updated successfully.\n");
            return;
        }
    }
    
    printf("Error: Product not found.\n");
}

//Function to delete product
void delete_product(){
    printf("\n----DELETE PRODUCT----\n");
    
    //Get product id from user
    int id;
    printf("Enter product id: ");
    scanf("%d", &id);
    
    //Search for product in array
    for(int i=0; i<num_products; i++){
        if(products[i].id == id){
            //Shift all products after the deleted product by one index
            for(int j=i; j<num_products-1; j++){
                products[j] = products[j+1];
            }
            num_products--;
            printf("Product deleted successfully.\n");
            return;
        }
    }
    
    printf("Error: Product not found.\n");
}

//Function to search product
void search_product(){
    printf("\n----SEARCH PRODUCT----\n");
    
    //Get product id from user
    int id;
    printf("Enter product id: ");
    scanf("%d", &id);
    
    //Search for product in array
    for(int i=0; i<num_products; i++){
        if(products[i].id == id){
            printf("Product found!\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2f\n", products[i].price);
            printf("Quantity: %d\n", products[i].quantity);
            return;
        }
    }
    
    printf("Error: Product not found.\n");
}

//Function to display all products
void display_products(){
    printf("\n----DISPLAY ALL PRODUCTS----\n");
    
    if(num_products == 0){
        printf("No products found.\n");
        return;
    }
    
    printf("ID\tName\tPrice\tQuantity\n");
    for(int i=0; i<num_products; i++){
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

int main(){
    int choice;
    
    do{
        print_menu();
        scanf("%d", &choice);
        
        switch(choice){
            case 1: add_product(); break;
            case 2: update_product(); break;
            case 3: delete_product(); break;
            case 4: search_product(); break;
            case 5: display_products(); break;
            case 6: printf("\nExiting program.\n"); break;
            default: printf("\nError: Invalid choice.\n");
        }
    }while(choice != 6);
    
    return 0;
}