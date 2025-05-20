//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 100

typedef struct{
    char name[50];
    float price;
    int quantity;
}item;

typedef struct{
    char name[50];
    char address[100];
    int phone;
    float total_bill;
}customer;

void main(){
    int i,j,n,choice;
    float bill=0.0,total=0.0;
    char ch;
    customer c[MAX];
    item it[MAX];
    printf("\nWELCOME TO CAFE BILLING SYSTEM\n");
    printf("\nEnter number of customers: ");
    scanf("%d",&n);
    printf("\nEnter customer details\n");
    for(i=0;i<n;i++){
        printf("\nEnter name: ");
        scanf("%s",c[i].name);
        printf("\nEnter address: ");
        scanf("%s",c[i].address);
        printf("\nEnter phone number: ");
        scanf("%d",&c[i].phone);
    }
    printf("\nEnter number of items: ");
    scanf("%d",&n);
    printf("\nEnter item details\n");
    for(i=0;i<n;i++){
        printf("\nEnter item name: ");
        scanf("%s",it[i].name);
        printf("\nEnter price: ");
        scanf("%f",&it[i].price);
        printf("\nEnter quantity: ");
        scanf("%d",&it[i].quantity);
    }
    printf("\nMENU\n");
    printf("\n1.Bill Generation\n2.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(strcmp(c[i].name,c[j].name)==0){
                        printf("\nCustomer %s already exists",c[i].name);
                        exit(0);
                    }
                }
            }
            for(i=0;i<n;i++){
                printf("\nBill for %s\n",c[i].name);
                for(j=0;j<n;j++){
                    if(strcmp(it[j].name,c[i].name)==0){
                        bill=it[j].price*it[j].quantity;
                        printf("\n%s - Rs.%0.2f\n",it[j].name,bill);
                        total+=bill;
                    }
                }
                printf("\nTotal bill - Rs.%0.2f\n",total);
                printf("\n\n");
            }
            break;
        case 2:
            exit(0);
        default:
            printf("\nInvalid choice");
    }
}