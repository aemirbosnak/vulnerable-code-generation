//FormAI DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Product{
    char name[20];
    int id;
    float price;
};

void addProduct(struct Product *p, int n){
    for(int i=0;i<n;i++){
        printf("\nEnter product name: ");
        scanf("%s",p[i].name);
        printf("Enter product ID: ");
        scanf("%d",&p[i].id);
        printf("Enter product price: ");
        scanf("%f",&p[i].price);
    }
    printf("\n-----Products added successfully-----\n");
}

void displayProduct(struct Product *p, int n){
    if(n==0){
        printf("\n-----No products to display-----\n");
        return;
    }
    printf("\n------PRODUCTS------\n");
    for(int i=0;i<n;i++){
        printf("\nProduct %d:\n",i+1);
        printf("Name: %s\n",p[i].name);
        printf("ID: %d\n",p[i].id);
        printf("Price: $%.2f\n",p[i].price);
    }
}

int searchProduct(struct Product *p, int n, char *name){
    for(int i=0;i<n;i++){
        if(strcmp(p[i].name,name)==0){
            return i+1;
        }
    }
    return 0;
}

void updateProduct(struct Product *p, int n, char *name){
    int prod_index=searchProduct(p,n,name);
    if(prod_index==0){
        printf("\n-----Product not found-----\n");
        return;
    }
    printf("\nEnter updated product name: ");
    scanf("%s",p[prod_index-1].name);
    printf("Enter updated product ID: ");
    scanf("%d",&p[prod_index-1].id);
    printf("Enter updated product price: ");
    scanf("%f",&p[prod_index-1].price);
    printf("\n-----Product updated successfully-----\n");
}

void deleteProduct(struct Product *p, int *n, char *name){
    int prod_index=searchProduct(p,*n,name);
    if(prod_index==0){
        printf("\n-----Product not found-----\n");
        return;
    }
    for(int i=prod_index-1;i<*n-1;i++){
        strcpy(p[i].name,p[i+1].name);
        p[i].id=p[i+1].id;
        p[i].price=p[i+1].price;
    }
    (*n)--;
    printf("\n-----Product deleted successfully-----\n");
}

int main(){
    int option=0,n=0;
    char name[20];
    struct Product *p=(struct Product *)malloc(n*sizeof(struct Product));
    while(option!=5){
        printf("\n----PRODUCT INVENTORY SYSTEM----\n");
        printf("\n1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("\nEnter number of products to add: ");
                scanf("%d",&n);
                p=(struct Product *)realloc(p,n*sizeof(struct Product));
                addProduct(p,n);
                break;
            case 2:
                displayProduct(p,n);
                break;
            case 3:
                printf("\nEnter product name: ");
                scanf("%s",name);
                updateProduct(p,n,name);
                break;
            case 4:
                printf("\nEnter product name: ");
                scanf("%s",name);
                deleteProduct(p,&n,name);
                p=(struct Product *)realloc(p,n*sizeof(struct Product));
                break;
            case 5:
                printf("\n-----Thank you for using the system-----\n");
                free(p);
                break;
            default:
                printf("\n-----Invalid option, please try again-----\n");
        }
    }
    return 0;
}