//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product{
    int id;
    char name[50];
    int quantity;
    float price;
};

void addProduct(struct product *p){
    printf("Enter the product id: ");
    scanf("%d",&p->id);
    printf("Enter the product name: ");
    scanf("%s",p->name);
    printf("Enter the product quantity: ");
    scanf("%d",&p->quantity);
    printf("Enter the product price: ");
    scanf("%f",&p->price);
}

void displayProduct(struct product p){
    printf("Product ID: %d\n", p.id);
    printf("Product Name: %s\n", p.name);
    printf("Product Quantity: %d\n", p.quantity);
    printf("Product Price: %.2f\n\n", p.price);
}

void searchProduct(struct product p[], int n){
    int id, i;
    printf("Enter the product ID to search: ");
    scanf("%d", &id);
    for(i = 0; i < n; i++){
        if(p[i].id == id){
            displayProduct(p[i]);
            return;
        }
    }
    printf("Product not found!\n");
}

void updateProduct(struct product *p){
    printf("Enter the new product name: ");
    scanf("%s",p->name);
    printf("Enter the new product quantity: ");
    scanf("%d",&p->quantity);
    printf("Enter the new product price: ");
    scanf("%f",&p->price);
    printf("Product info updated successfully!\n\n");
}

void deleteProduct(struct product *p){
    p->id = -1;
    printf("Product deleted!\n\n");
}

int main(){
    int n, i, choice, id;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    struct product *products = (struct product*)malloc(n*sizeof(struct product));
    for(i = 0; i < n; i++){
        printf("\nEnter the details of product %d:\n", i+1);
        addProduct(&products[i]);
    }
    while(1){
        printf("\nEnter 1 to display a product\n");
        printf("Enter 2 to search for a product\n");
        printf("Enter 3 to update a product\n");
        printf("Enter 4 to delete a product\n");
        printf("Enter 5 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter the product ID to display: ");
                scanf("%d", &id);
                for(i = 0; i < n; i++){
                    if(products[i].id == id){
                        displayProduct(products[i]);
                        break;
                    }
                }
                if(i == n){
                    printf("Product not found!\n");
                }
                break;
            case 2:
                searchProduct(products, n);
                break;
            case 3:
                printf("\nEnter the product ID to update: ");
                scanf("%d", &id);
                for(i = 0; i < n; i++){
                    if(products[i].id == id){
                        updateProduct(&products[i]);
                        break;
                    }
                }
                if(i == n){
                    printf("Product not found!\n");
                }
                break;
            case 4:
                printf("\nEnter the product ID to delete: ");
                scanf("%d", &id);
                for(i = 0; i < n; i++){
                    if(products[i].id == id){
                        deleteProduct(&products[i]);
                        break;
                    }
                }
                if(i == n){
                    printf("Product not found!\n");
                }
                break;
            case 5:
                printf("\nExiting the program!\n");
                free(products);
                return 0;
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n\n");
        }
    }
    return 0;
}