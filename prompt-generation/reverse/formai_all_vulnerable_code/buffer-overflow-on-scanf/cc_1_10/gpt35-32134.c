//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
//C program for a Product Inventory System
#include <stdio.h>
#include <stdlib.h>
#define MAX_PRODUCTS 100

//structure to hold product information
struct product{
    char name[50];
    int id;
    float price;
    int quantity;
};

//function to add new product to inventory
void add_product(struct product *p, int *n){
    if(*n < MAX_PRODUCTS){
        printf("Enter product name: ");
        scanf("%s", p[*n].name);
        printf("Enter product ID: ");
        scanf("%d", &p[*n].id);
        printf("Enter product price: ");
        scanf("%f", &p[*n].price);
        printf("Enter product quantity: ");
        scanf("%d", &p[*n].quantity);
        (*n)++;
        printf("Product added successfully!\n");
    }
    else{
        printf("Inventory is full!\n");
    }
}

//function to search for a product by ID
void search_product(struct product *p, int n){
    int id, flag=0;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    for(int i=0;i<n;i++){
        if(p[i].id == id){
            printf("Name: %s\nID: %d\nPrice: %0.2f\nQuantity: %d\n", p[i].name, p[i].id, p[i].price, p[i].quantity);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Product not found!\n");
    }
}

//function to update a product by ID
void update_product(struct product *p, int n){
    int id, flag=0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    for(int i=0;i<n;i++){
        if(p[i].id == id){
            printf("Enter new product name: ");
            scanf("%s", p[i].name);
            printf("Enter new product ID: ");
            scanf("%d", &p[i].id);
            printf("Enter new product price: ");
            scanf("%f", &p[i].price);
            printf("Enter new product quantity: ");
            scanf("%d", &p[i].quantity);
            flag = 1;
            printf("Product updated successfully!\n");
            break;
        }
    }
    if(flag == 0){
        printf("Product not found!\n");
    }
}

//function to delete a product by ID
void delete_product(struct product *p, int *n){
    int id, flag=0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    for(int i=0;i<*n;i++){
        if(p[i].id == id){
            for(int j=i;j<*n-1;j++){
                p[j] = p[j+1];
            }
            (*n)--;
            flag = 1;
            printf("Product deleted successfully!\n");
            break;
        }
    }
    if(flag == 0){
        printf("Product not found!\n");
    }
}

//function to display all products in inventory
void display_products(struct product *p, int n){
    for(int i=0;i<n;i++){
        printf("Name: %s\nID: %d\nPrice: %0.2f\nQuantity: %d\n\n", p[i].name, p[i].id, p[i].price, p[i].quantity);
    }
}

//main function
int main(){
    struct product inventory[MAX_PRODUCTS];
    int n=0, choice;

    //menu
    do{
        printf("\n********** Product Inventory System **********\n");
        printf("1. Add new product\n");
        printf("2. Search product by ID\n");
        printf("3. Update product by ID\n");
        printf("4. Delete product by ID\n");
        printf("5. Display all products\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: add_product(inventory, &n); break;
            case 2: search_product(inventory, n); break;
            case 3: update_product(inventory, n); break;
            case 4: delete_product(inventory, &n); break;
            case 5: display_products(inventory, n); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }while(choice != 6);

    return 0;
}