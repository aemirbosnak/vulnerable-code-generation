//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: distributed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct medicine{
    char name[100];
    int quantity;
    float price;
};

int main()
{
    int n, m, i, j, choice, flag=0, qty;
    float total_price=0;
    char name[100];
    struct medicine *medlist1, *medlist2;
    
    printf("Enter the number of medicines in Store 1: ");
    scanf("%d", &n);
    
    medlist1 = (struct medicine*)malloc(n*sizeof(struct medicine));
    
    //Reading the values for Store 1
    for(i=0; i<n; i++){
        printf("\nMedicine %d:\n", i+1);
        printf("Name: ");
        scanf("%s", (medlist1+i)->name);
        printf("Price: ");
        scanf("%f", &(medlist1+i)->price);
        printf("Quantity: ");
        scanf("%d", &(medlist1+i)->quantity);
    }
    
    printf("\nEnter the number of medicines in Store 2: ");
    scanf("%d", &m);
    
    medlist2 = (struct medicine*)malloc(m*sizeof(struct medicine));
    
    //Reading the values for Store 2
    for(i=0; i<m; i++){
        printf("\nMedicine %d:\n", i+1);
        printf("Name: ");
        scanf("%s", (medlist2+i)->name);
        printf("Price: ");
        scanf("%f", &(medlist2+i)->price);
        printf("Quantity: ");
        scanf("%d", &(medlist2+i)->quantity);
    }
    
    //Displaying the menu
    do{
        printf("\n======MENU======\n");
        printf("1. Search a Medicine\n");
        printf("2. Buy Medicines\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("\nEnter the name of medicine to search: ");
                scanf("%s", name);
                flag=0;
                //Searching for the medicine in Store 1
                for(i=0; i<n; i++){
                    if(strcmp((medlist1+i)->name, name)==0){
                        flag=1;
                        printf("\nMedicine found in Store 1\n");
                        printf("Name: %s\n", (medlist1+i)->name);
                        printf("Price: %f\n", (medlist1+i)->price);
                        printf("Quantity: %d\n", (medlist1+i)->quantity);
                        break;
                    }
                }
                //Searching for the medicine in Store 2
                for(i=0; i<m; i++){
                    if(strcmp((medlist2+i)->name, name)==0){
                        flag=1;
                        printf("\nMedicine found in Store 2\n");
                        printf("Name: %s\n", (medlist2+i)->name);
                        printf("Price: %f\n", (medlist2+i)->price);
                        printf("Quantity: %d\n", (medlist2+i)->quantity);
                        break;
                    }
                }
                if(flag==0){
                    printf("\nSorry! Medicine not found in either store\n");
                }
                break;
                
            case 2:
                printf("\nEnter the name of medicine to buy: ");
                scanf("%s", name);
                flag=0;
                //Searching for the medicine in Store 1
                for(i=0; i<n; i++){
                    if(strcmp((medlist1+i)->name, name)==0){
                        flag=1;
                        printf("\nEnter the quantity to buy: ");
                        scanf("%d", &qty);
                        if(qty>(medlist1+i)->quantity){
                            printf("\nInsufficient quantity in Store 1\n");
                            break;
                        }
                        total_price += qty * (medlist1+i)->price;
                        (medlist1+i)->quantity -= qty;
                        printf("\n%d units of %s bought from Store 1\n", qty, (medlist1+i)->name);
                        printf("Total Price: %f\n", total_price);
                        break;
                    }
                }
                //Searching for the medicine in Store 2
                if(flag==0){
                    for(i=0; i<m; i++){
                        if(strcmp((medlist2+i)->name, name)==0){
                            flag=1;
                            printf("\nEnter the quantity to buy: ");
                            scanf("%d", &qty);
                            if(qty>(medlist2+i)->quantity){
                                printf("\nInsufficient quantity in Store 2\n");
                                break;
                            }
                            total_price += qty * (medlist2+i)->price;
                            (medlist2+i)->quantity -= qty;
                            printf("\n%d units of %s bought from Store 2\n", qty, (medlist2+i)->name);
                            printf("Total Price: %f\n", total_price);
                            break;
                        }
                    }
                }
                if(flag==0){
                    printf("\nSorry! Medicine not found in either store\n");
                }
                break;
                
            case 3:
                printf("\nExiting...\n");
                break;
                
            default:
                printf("\nInvalid Choice\n");
        }
    }while(choice!=3);
    
    free(medlist1);
    free(medlist2);
    
    return 0;
}