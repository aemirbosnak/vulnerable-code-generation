//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 1000

struct medicine{
    char name[50];
    int price;
    int quantity;
};

void addmedicine(struct medicine *m,int n){
    printf("\nEnter medicine name: ");
    scanf("%s",m[n].name);
    printf("Enter price: ");
    scanf("%d",&m[n].price);
    printf("Enter quantity: ");
    scanf("%d",&m[n].quantity);
}

void displaymedicine(struct medicine m[],int n){
    printf("\n\nMEDICINE LIST\n");
    for(int i=0;i<n;i++){
        printf("\nName: %s\nPrice: %d\nQuantity: %d\n",m[i].name,m[i].price,m[i].quantity);
    }
}

void searchmedicine(struct medicine m[],int n){
    char name[50];
    printf("\nEnter medicine name to search: ");
    scanf("%s",name);
    for(int i=0;i<n;i++){
        if(strcmp(name,m[i].name)==0){
            printf("\n\nMEDICINE DETAILS\n");
            printf("Name: %s\nPrice: %d\nQuantity: %d\n",m[i].name,m[i].price,m[i].quantity);
        }
    }
}

void updatequantity(struct medicine m[],int n){
    int choice,quantity;
    printf("\nEnter 1 to increase quantity, 2 to decrease quantity: ");
    scanf("%d",&choice);
    printf("Enter new quantity: ");
    scanf("%d",&quantity);
    for(int i=0;i<n;i++){
        if(strcmp(m[i].name,choice)==0){
            if(choice==1){
                m[i].quantity+=quantity;
            }
            else if(choice==2){
                m[i].quantity-=quantity;
            }
            else{
                printf("\nInvalid choice!");
            }
        }
    }
}

void main(){
    struct medicine m[MAX];
    int n=0;
    while(n<MAX){
        printf("\nEnter 1 to add medicine, 2 to display medicine list, 3 to search medicine, 4 to update quantity, 0 to exit: ");
        scanf("%d",&n);
        switch(n){
            case 1:
                addmedicine(m,n);
                n++;
                break;
            case 2:
                displaymedicine(m,n);
                break;
            case 3:
                searchmedicine(m,n);
                break;
            case 4:
                updatequantity(m,n);
                break;
            case 0:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
}