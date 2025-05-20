//FormAI DATASET v1.0 Category: Product Inventory System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product{
    char name[50];
    int id;
    int quantity;
    float price;
};

void addProduct(struct product products[],int *count){
    printf("\n\n---------------------------------------------\n\n");
    printf("Enter product name: ");
    scanf("%s",products[*count].name);
    printf("Enter product id: ");
    scanf("%d",&products[*count].id);
    printf("Enter product quantity: ");
    scanf("%d",&products[*count].quantity);
    printf("Enter product price: ");
    scanf("%f",&products[*count].price);
    printf("\n\n---------------------------------------------\n\n");
    *count+=1;
}

void searchProduct(struct product products[],int count,int id){
    int flag=0;
    for(int i=0;i<count;i++){
        if(products[i].id==id){
            printf("\n\n---------------------------------------------\n\n");
            printf("Product found!\n");
            printf("Name: %s\n",products[i].name);
            printf("Id: %d\n",products[i].id);
            printf("Quantity: %d\n",products[i].quantity);
            printf("Price: %.2f\n",products[i].price);
            printf("\n\n---------------------------------------------\n\n");
            flag=1;
        }
    }
    if(flag==0){
        printf("\n\n---------------------------------------------\n\n");
        printf("Product not found!\n");
        printf("\n\n---------------------------------------------\n\n");
    }
}

void deleteProduct(struct product products[],int *count,int id){
    int flag=0;
    for(int i=0;i<*count;i++){
        if(products[i].id==id){
            for(int j=i;j<(*count)-1;j++){
                products[j]=products[j+1];
            }
            printf("\n\n---------------------------------------------\n\n");
            printf("Product deleted successfully!\n");
            printf("\n\n---------------------------------------------\n\n");
            *count-=1;
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("\n\n---------------------------------------------\n\n");
        printf("Product not found!\n");
        printf("\n\n---------------------------------------------\n\n");
    }   
    
}

void modifyProduct(struct product products[],int count,int id){
    int flag=0;
    for(int i=0;i<count;i++){
        if(products[i].id==id){
            printf("\n\n---------------------------------------------\n\n");
            printf("Product found!\n");
            printf("\nOld Data:\n");
            printf("Name: %s\n",products[i].name);
            printf("Id: %d\n",products[i].id);
            printf("Quantity: %d\n",products[i].quantity);
            printf("Price: %.2f\n",products[i].price);
            printf("\nEnter new data:\n");
            printf("Enter product name: ");
            scanf("%s",products[i].name);
            printf("Enter product id: ");
            scanf("%d",&products[i].id);
            printf("Enter product quantity: ");
            scanf("%d",&products[i].quantity);
            printf("Enter product price: ");
            scanf("%f",&products[i].price);
            printf("\n\n---------------------------------------------\n\n");
            flag=1;
        }
    }
    if(flag==0){
        printf("\n\n---------------------------------------------\n\n");
        printf("Product not found!\n");
        printf("\n\n---------------------------------------------\n\n");
    }
}

void displayProducts(struct product products[],int count){
    if(count==0){
        printf("\n\n---------------------------------------------\n\n");
        printf("No products found!\n");
        printf("\n\n---------------------------------------------\n\n");
        return;
    }
    printf("\n\n---------------------------------------------\n\n");
    printf("Product Inventory:\n");
    for(int i=0;i<count;i++){
        printf("Name: %s\n",products[i].name);
        printf("Id: %d\n",products[i].id);
        printf("Quantity: %d\n",products[i].quantity);
        printf("Price: %.2f\n",products[i].price);
        printf("\n");
    }
    printf("\n\n---------------------------------------------\n\n");

}

int main(){
    struct product products[100];
    int count=0;
    int choice,searchId,deleteId,modifyId;
    while(1){
        printf("Please select an option:\n");
        printf("1. Add a product\n");
        printf("2. Search a product\n");
        printf("3. Modify a product\n");
        printf("4. Delete a product\n");
        printf("5. Display all products\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addProduct(products,&count);
                break;
            case 2:
                printf("Enter product id: ");
                scanf("%d",&searchId);
                searchProduct(products,count,searchId);
                break;
            case 3:
                printf("Enter product id: ");
                scanf("%d",&modifyId);
                modifyProduct(products,count,modifyId);
                break;
            case 4:
                printf("Enter product id: ");
                scanf("%d",&deleteId);
                deleteProduct(products,&count,deleteId);
                break;
            case 5:
                displayProducts(products,count);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

    }
}