//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

//structure for the product

struct Product{
    int id;
    char name[20];
    double price;
    int quantity;
};

//global variables

struct Product products[MAX_SIZE];
int count = 0;

//function to add a product

void addProduct(){
    struct Product product;
    printf("Enter Product Name: ");
    scanf("%s", product.name);
    printf("Enter Product Price: ");
    scanf("%lf", &product.price);
    printf("Enter Product Quantity: ");
    scanf("%d", &product.quantity);
    product.id = count + 1;
    products[count++] = product;
    printf("Product Added Successfully!\n");
}

//function to display all products

void displayProducts(){
    if(count == 0){
        printf("No Products Found!");
        return;
    }
    printf("ID\tName\tPrice\tQuantity\n");
    for(int i=0; i<count; i++){
        printf("%d\t%s\t%.2lf\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

//function to search for a product by id

void searchProductById(){
    int id;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    for(int i=0; i<count; i++){
        if(products[i].id == id){
            printf("ID\tName\tPrice\tQuantity\n");
            printf("%d\t%s\t%.2lf\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            return;
        }
    }
    printf("Product not found!");
}

//function to search for a product by name

void searchProductByName(){
    char name[20];
    printf("Enter Product Name: ");
    scanf("%s", name);
    for(int i=0; i<count; i++){
        if(strcmp(products[i].name, name) == 0){
            printf("ID\tName\tPrice\tQuantity\n");
            printf("%d\t%s\t%.2lf\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            return;
        }
    }
    printf("Product not found!");
}

//function to update a product by id

void updateProductById(){
    int id;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    for(int i=0; i<count; i++){
        if(products[i].id == id){
            printf("Enter updated Product Name: ");
            scanf("%s", products[i].name);
            printf("Enter updated Product Price: ");
            scanf("%lf", &products[i].price);
            printf("Enter updated Product Quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Product Updated Successfully!\n");
            return;
        }
    }
    printf("Product not found!");
}

//function to delete a product by id

void deleteProductById(){
    int id;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    for(int i=0; i<count; i++){
        if(products[i].id == id){
            for(int j=i; j<count-1; j++){
                products[j] = products[j+1];
            }
            count--;
            printf("Product Deleted Successfully!\n");
            return;
        }
    }
    printf("Product not found!");
}

//main function

int main(){
    int choice;
    while(1){
        printf("\n---------------------\n");
        printf("Welcome to Warehouse Management System\n");
        printf("---------------------\n");
        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Search Product by ID\n");
        printf("4. Search Product by Name\n");
        printf("5. Update Product by ID\n");
        printf("6. Delete Product by ID\n");
        printf("7. Exit\n");
        printf("Please Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                searchProductById();
                break;
            case 4:
                searchProductByName();
                break;
            case 5:
                updateProductById();
                break;
            case 6:
                deleteProductById();
                break;
            case 7:
                printf("Thank you for using our system!\n");
                return 0;
            default:
                printf("Invalid Choice!");
        }
    }
    return 0;
}