//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

typedef struct{
    char name[20];
    int quantity;
    float price;
}Item;

void addItem(Item items[], int *n){
    printf("\nEnter item name: ");
    scanf("%s",items[*n].name);
    printf("Enter quantity: ");
    scanf("%d",&items[*n].quantity);
    printf("Enter price per unit: ");
    scanf("%f",&items[*n].price);
    (*n)++;
}

void displayItems(Item items[], int n){
    printf("\nItem\tQuantity\tPrice\n");
    for(int i=0; i<n; i++){
        printf("%s\t%d\t%.2f\n",items[i].name,items[i].quantity,items[i].price);
    }
}

void calculateTotal(Item items[], int n, float *total){
    *total=0;
    for(int i=0; i<n; i++){
        *total+=items[i].quantity*items[i].price;
    }
}

int main(){
    char choice;
    Item items[MAX];
    int n=0;
    float total=0;

    do{
        printf("\nWelcome to Cafe Billing System\n");
        printf("1. Add item\n2. Display items\n3. Calculate total\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c",&choice);

        switch(choice){
            case '1':
                addItem(items,&n);
                break;
            case '2':
                displayItems(items,n);
                break;
            case '3':
                calculateTotal(items,n,&total);
                printf("\nTotal amount: %.2f",total);
                break;
            case '4':
                printf("\nThank you for using Cafe Billing System.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter again.\n");
        }
    }while(choice!='4');

    return 0;
}