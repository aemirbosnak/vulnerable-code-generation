//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Cryptic
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#define MAX 100 

struct Medicine 
{ 
    char name[50]; 
    int quantity; 
    float price; 
}med[MAX]; 

void inputMedicine(int n) 
{ 
    int i; 

    for(i=0; i<n; i++) 
    {      
        printf("\nEnter medicine name :- "); scanf("%s",med[i].name); 

        printf("\nEnter cost in tk :- "); scanf("%f",&med[i].price); 

        printf("\nEnter quantity :- "); scanf("%d",&med[i].quantity); 
    } 
} 

void displayLowStock(int n) 
{ 
    int i,flag=0; 

    printf("\n Medicines with low stock \n"); 

    for(i=0; i<n; i++) 
    { 
        if(med[i].quantity<=10) 
        { 
            flag=1; 
            printf("\nName :- %s",med[i].name); 
            printf("\nPrice :- %f",med[i].price); 
            printf("\nQuantity :- %d",med[i].quantity); 
        } 
    } 

    if(flag==0) printf("\nNo medicine with low stock \n");     
} 

void displayMedicine(int n) 
{ 
    int i; 

    printf("\nName\tPrice\tQuantity\n"); 

    for(i=0; i<n; i++) 
    { 
        printf("%s\t%f\t%d\n",med[i].name,med[i].price,med[i].quantity); 
    } 
} 

int checkAvailability(char* name,int n) 
{ 
    int i; 

    for(i=0; i<n; i++) 
    { 
        if(strcmp(name,med[i].name)==0) 
            return i; 
    } 

    return -1; 
} 

void purchaseMedicine(int n) 
{ 
    char name[50]; 
    int quantity,index; 

    printf("\nEnter medicine name you want to purchase :- "); 
    scanf("%s",name); 

    index=checkAvailability(name,n); 

    if(index!=-1) 
    { 
        printf("\nMedicine available \n"); 

        printf("\nName :- %s",med[index].name); 

        printf("\nPrice :- %f",med[index].price); 

        printf("\nQuantity available :- %d",med[index].quantity); 

        printf("\nEnter quantity required :- "); scanf("%d",&quantity); 

        if(med[index].quantity>=quantity) 
        { 
            printf("\nTotal amount :- %f",med[index].price*quantity); 

            med[index].quantity-=quantity; 
        } 

        else printf("\nInsufficient quantity \n"); 
    } 

    else printf("\nMedicine not available \n"); 
} 

int menu() 
{ 
    int choice; 

    printf("\n1.Enter medicine\n2.Display medicines\n3.Check available stock\n4.Purchase medicine\n5.Exit\n"); 

    printf("\nEnter choice :- "); scanf("%d",&choice); 

    return choice; 
} 

void main() 
{ 
    int n,i,choice; 

    printf("\nEnter number of medicines :- "); scanf("%d",&n); 

    inputMedicine(n); 

    while(1) 
    { 
        choice=menu(); 

        switch(choice) 
        { 
            case 1: inputMedicine(1); break; 

            case 2: displayMedicine(n); break; 

            case 3: displayLowStock(n); break; 

            case 4: purchaseMedicine(n); break; 

            case 5: exit(0); 
        } 
    } 
}