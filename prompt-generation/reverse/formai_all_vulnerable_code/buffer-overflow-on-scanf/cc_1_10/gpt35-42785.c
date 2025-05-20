//FormAI DATASET v1.0 Category: Product Inventory System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product{
    char name[50];
    int id;
    float price;
    int quantity;
}Product;

void printProduct(Product p){
    printf("\nProduct Name: %s\n", p.name);
    printf("Product ID: %d\n", p.id);
    printf("Product Price: %.2f\n", p.price);
    printf("Product Quantity: %d\n", p.quantity);
}

void printProducts(Product products[], int length){
    printf("Product Inventory:\n");
    for(int i=0; i<length; i++){
        printf("\nProduct #%d:\n", i+1);
        printProduct(products[i]);
    }
}

void addProduct(Product products[], int length){
    printf("\nAdding Product:\n");
    printf("Enter Product Name: ");
    scanf("%s", products[length].name);
    printf("Enter Product ID: ");
    scanf("%d", &products[length].id);
    printf("Enter Product Price: ");
    scanf("%f", &products[length].price);
    printf("Enter Product Quantity: ");
    scanf("%d", &products[length].quantity);
}

void updateProduct(Product products[], int length){
    printf("\nUpdating Product:\n");
    printf("Enter the ID of the Product you want to update: ");
    int id;
    scanf("%d", &id);
    int index = -1;
    for(int i=0; i<length; i++){
        if(products[i].id==id){
            index=i;
            break;
        }
    }
    if(index==-1){
        printf("Product not Found!\n");
    }
    else{
        printf("\nCurrent product details are:\n");
        printProduct(products[index]);
        printf("\nEnter you new values:\n");
        printf("Enter Product Name: ");
        scanf("%s", products[index].name);
        printf("Enter Product ID: ");
        scanf("%d", &products[index].id);
        printf("Enter Product Price: ");
        scanf("%f", &products[index].price);
        printf("Enter Product Quantity: ");
        scanf("%d", &products[index].quantity);
        printf("\nProduct details Updated Successfully!\n");
    }
}

void deleteProduct(Product products[], int length){
    printf("\nDeleting Product:\n");
    printf("Enter the ID of the Product you want to delete: ");
    int id;
    scanf("%d", &id);
    int index = -1;
    for(int i=0; i<length; i++){
        if(products[i].id==id){
            index=i;
            break;
        }
    }
    if(index==-1){
        printf("Product not Found!\n");
    }
    else{
        for(int i=index; i<length-1; i++){
            products[i] = products[i+1];
        }
        printf("\nProduct details Deleted Successfully!\n");
    }
}

int main(){
    Product products[100];
    int count = 0;
    char choice;
    do{
        printf("\nProduct Inventory System\n");
        printf("1. Display All Products\n2. Add New Product\n3. Update Existing Product\n4. Delete Product\n5. Quit\n");
        printf("Enter your choice[1-5]: ");
        scanf(" %c", &choice);
        switch(choice){
            case '1':
                if(count==0){
                    printf("\nNo Products Found!\n");
                }
                else{
                    printProducts(products, count);
                }
                break;
            case '2':
                addProduct(products, count);
                count++;
                break;
            case '3':
                if(count==0){
                    printf("\nNo Products Found!\n");
                }
                else{
                    updateProduct(products, count);
                }
                break;
            case '4':
                if(count==0){
                    printf("\nNo Products Found!\n");
                }
                else{
                    deleteProduct(products, count);
                    count--;
                }
                break;
            case '5':
                printf("\nExiting Product Inventory System!");
                break;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }while(choice!='5');
    return 0;
}