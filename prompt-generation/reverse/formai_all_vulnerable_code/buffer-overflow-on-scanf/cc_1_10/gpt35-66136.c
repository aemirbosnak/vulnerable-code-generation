//FormAI DATASET v1.0 Category: Product Inventory System ; Style: mind-bending
#include<stdio.h>
#include<string.h>

struct product{
    char name[30];
    int quantity;
    float price;
};

void displayMenu(){
    printf("\n####### PRODUCT INVENTORY SYSTEM #######\n");
    printf("1. Add Product\n");
    printf("2. Display Product\n");
    printf("3. Remove Product\n");
    printf("4. Update Product Quantity\n");
    printf("5. Exit\n");
    printf("########################################\n");
    printf("Enter your choice: ");
}

int main(){
    struct product p[100];
    int i=0;
    int choice,flag=0,count=0;
    float totalPrice=0;

    do{
        displayMenu();
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("\nEnter Product Details:\n");
                printf("Name: ");
                scanf("%s",&p[i].name);
                printf("Quantity: ");
                scanf("%d",&p[i].quantity);
                printf("Price: ");
                scanf("%f",&p[i].price);
                count++;
                i++;
                printf("\nProduct Added Successfully!\n");
                break;

            case 2:
                if(count==0){
                    printf("\nInventory is Empty!\n");
                    break;
                }
                printf("\nDISPLAYING PRODUCTS:\n");
                for(int j=0;j<count;j++){
                    printf("Product %d\nName: %s\nQuantity: %d\nPrice: $%.2f\n",j+1,p[j].name,p[j].quantity,p[j].price);
                    totalPrice+=p[j].price*p[j].quantity;
                }
                printf("\nTotal Inventory Value: $%.2f\n",totalPrice);
                totalPrice=0;
                break;

            case 3:
                if(count==0){
                    printf("\nInventory is Empty!\n");
                    break;
                }
                char remove[30];
                printf("\nEnter the name of the Product to be removed: ");
                scanf("%s",&remove);
                for(int j=0;j<count;j++){
                    if(strcmp(remove,p[j].name)==0){
                        printf("\nProduct %s removed successfully!\n",p[j].name);
                        for(int k=j;k<count-1;k++){
                            p[j]=p[j+1];
                        }
                        count--;
                        flag=1;
                    }
                }
                if(flag==0){
                    printf("\nProduct not found!\n");
                }
                break;

            case 4:
                if(count==0){
                    printf("\nInventory is Empty!\n");
                    break;
                }
                char update[30];
                int newQuantity;
                printf("\nEnter the name of the Product: ");
                scanf("%s",&update);
                for(int j=0;j<count;j++){
                    if(strcmp(update,p[j].name)==0){
                        printf("\nCurrent Quantity of %s is %d\nEnter the new Quantity: ",p[j].name,p[j].quantity);
                        scanf("%d",&newQuantity);
                        p[j].quantity=newQuantity;
                        flag=1;
                    }
                }
                if(flag==0){
                    printf("\nProduct not found!\n");
                }
                else{
                    flag=0;
                    printf("\nQuantity updated successfully!\n");
                }
                break;

            case 5:
                printf("\nExiting the Program...\n");
                break;

            default:
                printf("\nINVALID CHOICE!!\n");
        }

    }while(choice!=5);

    return 0;
}