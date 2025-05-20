//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_WAREHOUSE_SIZE 100

//Structure for products
typedef struct{
    char name[20];   //product name
    int quantity;    //product quantity
    float price;     //product price
}Product; 

//Structure for warehouse
typedef struct{
    Product products[MAX_WAREHOUSE_SIZE]; //array of products
    int num_products;                     //number of products
}Warehouse;

//function to add products to the warehouse
void addProduct(Warehouse* warehouse, Product product){
    if(warehouse->num_products==MAX_WAREHOUSE_SIZE){ //Checking if warehouse is full
        printf("\nWarehouse is full!\n");
        return;
    }
    warehouse->products[warehouse->num_products]=product;
    warehouse->num_products++;
    printf("\nProduct added successfully!\n");
}

//function to remove products from the warehouse
void removeProduct(Warehouse* warehouse, char name[]){
    int i;
    for(i=0;i<warehouse->num_products;i++){
        if(strcmp(warehouse->products[i].name,name)==0){ //Checking if the product name matches
            int j;
            for(j=i;j<warehouse->num_products-1;j++){ 
                warehouse->products[j]=warehouse->products[j+1];
            }
            warehouse->num_products--;
            printf("\nProduct removed successfully!\n");
            return;
        }
    }
    printf("\nProduct not found in warehouse!\n");
}

//function to modify the price of a product in the warehouse
void modifyPrice(Warehouse* warehouse, char name[], float price){
    int i;
    for(i=0;i<warehouse->num_products;i++){
        if(strcmp(warehouse->products[i].name,name)==0){ //Checking if the product name matches
            warehouse->products[i].price=price;
            printf("\nProduct price modified successfully!\n");
            return;
        }
    }
    printf("\nProduct not found in warehouse!\n");
}

//function to display the list of products in the warehouse
void displayProducts(Warehouse* warehouse){
    int i;
    printf("\n%-20s\t%-10s\t%-10s\n","Product Name","Quantity","Price");
    for(i=0;i<warehouse->num_products;i++){
        printf("%-20s\t%-10d\t%-10.2f\n",warehouse->products[i].name,warehouse->products[i].quantity,warehouse->products[i].price);
    }
}

int main(){
    Warehouse warehouse;
    warehouse.num_products=0; //Initialising the number of products in the warehouse to 0

    int choice;
    do{
        printf("\n\n1. Add product\n2. Remove product\n3. Modify price\n4. Display products\n5. Exit\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                Product product;
                printf("\nEnter the name of the product: ");
                scanf("%s",product.name);
                printf("Enter the quantity of the product: ");
                scanf("%d",&product.quantity);
                printf("Enter the price of the product: ");
                scanf("%f",&product.price);

                addProduct(&warehouse,product);
                break;
            }
            case 2:{
                char name[20];
                printf("\nEnter the name of the product to remove: ");
                scanf("%s",name);

                removeProduct(&warehouse,name);
                break;
            }
            case 3:{
                char name[20];
                float price;
                printf("\nEnter the name of the product to modify price: ");
                scanf("%s",name);
                printf("Enter the new price of the product: ");
                scanf("%f",&price);

                modifyPrice(&warehouse,name,price);
                break;
            }
            case 4:{
                displayProducts(&warehouse);
                break;
            }
            case 5:{
                printf("\nExiting the program...\n");
                exit(0);
            }
            default:{
                printf("\nInvalid choice!\n");
            }
        }
    }while(choice!=5);

    return 0;
}