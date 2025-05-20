//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Structure for menu items
struct menu_item{
    int itemId;
    char itemName[25];
    float itemPrice;
}; 

// Function to display menu and get order details
void getMenu(int n, struct menu_item menu[]){
    printf("\n------------------------MENU-----------------------\n");
    printf("Item ID\tItem Name\t\t\t\tPrice\n");
    printf("----------------------------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%s\t\t\t\t%.2f\n",menu[i].itemId,menu[i].itemName,menu[i].itemPrice);
    }
    printf("\n");
}


int main(){
    // Setting up the menu items
    struct menu_item menu[10] = {{1,'Espresso',2.50},{2,'Cappuccino',3.00},{3,'Americano',2.75},{4,'Latte',3.50},{5,'Mocha',4.00}};
    
    // Initializing the variables
    int itemCode = 0, quantity = 0;
    float amount = 0.0, total_bill = 0.0;
    char option = 'Y';
    
    printf("Welcome to C Cafe!\n");
    
    // Loop for taking multiple orders
    while(option == 'Y' || option == 'y'){
        // Getting the menu
        getMenu(5,menu);
        
        // Getting the order details
        printf("Enter the item code: ");
        scanf("%d",&itemCode);
        printf("Enter the quantity: ");
        scanf("%d",&quantity);
        
        // Checking if the item code exists in the menu
        if(itemCode > 0 && itemCode <= 5){
            amount = (float) quantity * menu[itemCode - 1].itemPrice;
            printf("\n%s\t x %d\t %.2f\n",menu[itemCode - 1].itemName,quantity,amount);
            total_bill += amount;
        }
        else{
            printf("Invalid item code entered.\n");
        }
        
        // Checking if the user wants to enter another order
        printf("\nDo you want to add another item? (Y/N): ");
        scanf(" %c",&option);
    }
    
    // Displaying the total bill
    printf("\nTotal bill: $%.2f\n",total_bill);

    return 0;
}