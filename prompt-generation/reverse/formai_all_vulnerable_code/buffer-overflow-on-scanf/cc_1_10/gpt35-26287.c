//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

//Structure to hold information about products in our warehouse
struct product{
    int id;
    char name[50];
    float price;
    int quantity;
};

//Function prototypes
void addProduct();
void searchProduct();
void updateProduct();
void deleteProduct();
void listAllProducts();

//Global variables
struct product products[50];
int numProducts = 0;

//Main function
int main(){

    int choice = 0;

    while(1){ //Infinite loop till user chooses to exit
        
        printf("\n\nWarehouse Management System\n");
        printf("---------------------------\n");
        printf("1. Add a product\n");
        printf("2. Search for a product\n");
        printf("3. Update a product\n");
        printf("4. Delete a product\n");
        printf("5. List all products\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        fflush(stdin);

        switch(choice){
            case 1:
                addProduct();
                break;
            case 2:
                searchProduct();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                listAllProducts();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

//Function to add a product to our warehouse
void addProduct(){
    struct product prod;

    printf("\nEnter product id: ");
    scanf("%d",&prod.id);
    fflush(stdin);

    printf("Enter product name: ");
    fgets(prod.name,50,stdin);
    printf("Enter product price: ");
    scanf("%f",&prod.price);
    printf("Enter product quantity: ");
    scanf("%d",&prod.quantity);

    products[numProducts] = prod;
    numProducts++;

    printf("\nProduct added successfully!\n");
}

//Function to search for a product by id
void searchProduct(){
    int prodId;
    printf("\nEnter product id to search: ");
    scanf("%d",&prodId);
    for(int i=0;i<numProducts;i++){
        if(products[i].id == prodId){
            printf("\nProduct found!\n");
            printf("Id: %d\n",products[i].id);
            printf("Name: %s\n",products[i].name);
            printf("Price: %.2f\n",products[i].price);
            printf("Quantity: %d\n",products[i].quantity);
            return;
        }
    }
    printf("\nProduct not found!\n");
}

//Function to update a product by id
void updateProduct(){
    int prodId;
    printf("\nEnter product id to update: ");
    scanf("%d",&prodId);
    for(int i=0;i<numProducts;i++){
        if(products[i].id == prodId){
            printf("\nEnter new product name: ");
            fgets(products[i].name,50,stdin);
            printf("Enter new product price: ");
            scanf("%f",&products[i].price);
            printf("Enter new product quantity: ");
            scanf("%d",&products[i].quantity);
            printf("\nProduct updated successfully!\n");
            return;
        }
    }
    printf("\nProduct not found!\n");
}

//Function to delete a product by id
void deleteProduct(){
    int prodId;
    printf("\nEnter product id to delete: ");
    scanf("%d",&prodId);
    for(int i=0;i<numProducts;i++){
        if(products[i].id == prodId){
            for(int j=i;j<numProducts-1;j++){
                products[j] = products[j+1];
            }
            numProducts--;
            printf("\nProduct deleted successfully!\n");
            return;
        }
    }
    printf("\nProduct not found!\n");
}

//Function to list all the products in our warehouse
void listAllProducts(){
    if(numProducts == 0){
        printf("\nNo products in warehouse!\n");
        return;
    }
    printf("\nAll products in warehouse:\n");
    for(int i=0;i<numProducts;i++){
            printf("Id: %d\n",products[i].id);
            printf("Name: %s\n",products[i].name);
            printf("Price: %.2f\n",products[i].price);
            printf("Quantity: %d\n",products[i].quantity);
    }
}