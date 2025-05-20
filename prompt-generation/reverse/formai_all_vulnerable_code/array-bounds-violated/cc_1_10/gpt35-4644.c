//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structures to represent Warehouse, Products, and Orders
typedef struct warehouse{
    int id;
    char name[20];
    char address[50];
} Warehouse;

typedef struct product{
    int id;
    char name[20];
    float cost;
    int stock;
} Product;

typedef struct order{
    int id;
    Product product;
    Warehouse warehouse;
    int quantity;
} Order;

//Arrays to hold data for Warehouse and Products
Warehouse warehouses[10];
Product products[10];

//Function to add new warehouse to the system
void addWarehouse(){
    Warehouse newWarehouse;
    printf("Enter Warehouse ID: ");
    scanf("%d", &newWarehouse.id);
    printf("Enter Warehouse Name: ");
    scanf("%s", newWarehouse.name);
    printf("Enter Warehouse Address: ");
    scanf("%s", newWarehouse.address);
    
    //Add newWarehouse to the warehouses array
    warehouses[newWarehouse.id] = newWarehouse;
    printf("Warehouse added successfully!\n");
}

//Function to add new product to the system
void addProduct(){
    Product newProduct;
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter Product Name: ");
    scanf("%s", newProduct.name);
    printf("Enter Product Cost: ");
    scanf("%f", &newProduct.cost);
    printf("Enter Product Stock: ");
    scanf("%d", &newProduct.stock);
    
    //Add newProduct to the products array
    products[newProduct.id] = newProduct;
    printf("Product added successfully!\n");
}

//Function to place a new order
void placeOrder(){
    Order newOrder;
    printf("Enter Order ID: ");
    scanf("%d", &newOrder.id);
    printf("Enter Product ID: ");
    scanf("%d", &newOrder.product.id);
    printf("Enter Warehouse ID: ");
    scanf("%d", &newOrder.warehouse.id);
    printf("Enter Quantity: ");
    scanf("%d", &newOrder.quantity);
    
    //Increase the stock of the product in the warehouse
    products[newOrder.product.id].stock += newOrder.quantity;
    printf("Order placed successfully!\n");
}

//Function to display all products in the system
void displayProducts(){
    printf("----------Products in the System----------\n");
    printf("ID\tNAME\tCOST\tSTOCK\n");
    for(int i=0; i<10; i++){
        if(strlen(products[i].name) > 0){
            printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].cost, products[i].stock);
        }
    }
}

int main(){
    //Initialize the warehouses and products arrays
    memset(warehouses, 0, sizeof(warehouses));
    memset(products, 0, sizeof(products));
    
    //Display the options to the user
    int choice = 0;
    while(choice != 4){
        printf("----------Warehouse Management System----------\n");
        printf("1. Add Warehouse\n");
        printf("2. Add Product\n");
        printf("3. Place Order\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: 
                addWarehouse();
                break;
            case 2: 
                addProduct();
                break;
            case 3: 
                placeOrder();
                break;
            case 4: 
                printf("Exiting...\n");
                break;
            default: 
                printf("Invalid choice, please try again!\n");
                break;
        }
    }
    return 0;
}