//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
struct product {
    int id;
    char name[50];
    int price;
    int quantity;
} products[100];
int count=0;

// Function to Add a new Product in the Inventory
void add_new_product(){
    printf("Enter the product name: ");
    scanf("%s",products[count].name);
    printf("Enter the product price: ");
    scanf("%d",&products[count].price);
    printf("Enter the product quantity: ");
    scanf("%d",&products[count].quantity);
    products[count].id=count+1;
    printf("Product '%s' added successfully with id '%d'\n",products[count].name,products[count].id);
    count++;
}

// Function to Search for a Product in the Inventory
void search_product(){
    int search_id, i, found = 0;
    printf("Enter the Product ID to search for: ");
    scanf("%d", &search_id);
    for (i = 0; i < count; i++){
        if (products[i].id == search_id){
            printf("ID: %d\nName: %s\nPrice: %d\nQuantity: %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found){
        printf("No Product found with ID '%d'\n", search_id);
    }
}

// Function to Display all the Products in the Inventory
void display_all_products(){
    printf("Product ID\tProduct Name\tProduct Price\tProduct Quantity\n");
    for(int i=0;i<count;i++){
        printf("%d\t\t%s\t\t%d\t\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

// Function to Update a Product in the Inventory
void update_product(){
    int search_id, i, found = 0;
    printf("Enter Product ID to update: ");
    scanf("%d", &search_id);
    for (i = 0; i < count; i++){
        if (products[i].id == search_id){
            printf("Enter new product name: ");
            scanf("%s", products[i].name);
            printf("Enter new product price: ");
            scanf("%d", &products[i].price);
            printf("Enter new product quantity: ");
            scanf("%d", &products[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found){
        printf("No Product found with ID '%d'\n", search_id);
    } else {
        printf("Product '%s' with ID '%d' has been updated successfully!\n", products[i].name, search_id);
    }
}

int main(){
    int choice=0;
    while(1){
        printf("\n\n----- PRODUCT INVENTORY SYSTEM -----\n");
        printf("1. Add New Product\n");
        printf("2. Search Product\n");
        printf("3. Display All Products\n");
        printf("4. Update Product\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                add_new_product();
                break;
            case 2:
                search_product();
                break;
            case 3:
                display_all_products();
                break;
            case 4:
                update_product();
                break;
            case 5:
                printf("\nExiting Product Inventory System...\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Please Try Again\n");
        }
    }
    return 0;
}