//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

//structure for menu items
struct cafeitem{
    int itemno;
    char name[20];
    float price;
};

//function to display menu items
void displayitems(){
    printf("\n%-10s%-30s%-10s","Item No","Name","Price");
    printf("\n%-10d%-30s%-10.2f",1,"Coffee",2.50);
    printf("\n%-10d%-30s%-10.2f",2,"Tea",1.50);
    printf("\n%-10d%-30s%-10.2f",3,"Sandwich",3.00);
    printf("\n%-10d%-30s%-10.2f",4,"Burger",4.50);
}

int main(){
    int choice,quantity;
    float amount,total=0;
    char ans;
    
    //initializing menu items
    struct cafeitem item[4]={{1,"Coffee",2.50},{2,"Tea",1.50},{3,"Sandwich",3.00},{4,"Burger",4.50}};
    
    printf("\n\tC CAFE BILLING SYSTEM");
    printf("\n\t************************");
    
    do{
        //displaying menu items
        displayitems();
        
        //getting user choice
        printf("\n\nEnter item number: ");
        scanf("%d",&choice);
        
        //getting quantity
        printf("\nEnter quantity: ");
        scanf("%d",&quantity);
        
        //computing amount
        amount=item[choice-1].price*quantity;
        
        //printing bill for the item
        printf("\n%-30s%-10d%s%-10.2f%s%-10.2f","-",quantity,item[choice-1].name,item[choice-1].price, "=", amount);
        
        //adding amount to total bill
        total+=amount;
        
        //checking for more items
        printf("\n\nDo you want to add more items (y/n)? ");
        scanf(" %c",&ans);
    }while(ans=='y' || ans=='Y');
    
    //printing total bill
    printf("\n\n%-40s%-10.2f","Total Bill =",total);
    
    return 0;
}