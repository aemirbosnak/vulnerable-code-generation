//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct warehouse{
    char item[20];
    int quantity;
    float price;
};

void main(){
    int choice,i,n;
    char ch;
    struct warehouse w1[MAX];
    FILE *fp;

    printf("\nWelcome to the Romeo and Juliet Warehouse Management System\n");
    printf("---------------------------------------------\n");

    do{
        printf("\n1. Add Item\n2. Update Item\n3. Delete Item\n4. Display Items\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter the name of the item: ");
                scanf("%s",w1[n].item);
                printf("Enter the quantity of the item: ");
                scanf("%d",&w1[n].quantity);
                printf("Enter the price of the item: ");
                scanf("%f",&w1[n].price);
                printf("\nItem added successfully.\n");
                break;

            case 2:
                printf("\nEnter the name of the item to be updated: ");
                scanf("%s",ch);
                for(i=0;i<n;i++){
                    if(strcmp(w1[i].item,ch)==0){
                        printf("\nEnter the new quantity of the item: ");
                        scanf("%d",&w1[i].quantity);
                        printf("Enter the new price of the item: ");
                        scanf("%f",&w1[i].price);
                        printf("\nItem updated successfully.\n");
                        break;
                    }
                }
                if(i==n){
                    printf("\nItem not found.\n");
                }
                break;

            case 3:
                printf("\nEnter the name of the item to be deleted: ");
                scanf("%s",ch);
                for(i=0;i<n;i++){
                    if(strcmp(w1[i].item,ch)==0){
                        w1[i]=w1[n-1];
                        n--;
                        printf("\nItem deleted successfully.\n");
                        break;
                    }
                }
                if(i==n){
                    printf("\nItem not found.\n");
                }
                break;

            case 4:
                printf("\nItem Name\tQuantity\tPrice\n");
                for(i=0;i<n;i++){
                    printf("%s\t\t%d\t\t%.2f\n",w1[i].item,w1[i].quantity,w1[i].price);
                }
                break;

            case 5:
                printf("\nThank you for using the Romeo and Juliet Warehouse Management System.\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }while(1);
}