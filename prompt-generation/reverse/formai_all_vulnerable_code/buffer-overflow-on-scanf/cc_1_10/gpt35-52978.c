//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include<stdio.h>
#include<string.h>

//Structure definition for the menu items
struct Menu{
    char itemName[50];
    int itemPrice;
};

//Structure definition for the order details
struct Order{
    char itemName[50];
    int itemPrice;
    int itemQuantity;
};

//Function to display the menu
void displayMenu(struct Menu menuList[], int n) {
    printf("********** MENU **********\n");
    for(int i=0;i<n;i++){
        printf("%d. %s - %d\n", i+1, menuList[i].itemName, menuList[i].itemPrice);
    }
    printf("********************\n\n");
}

//Function to place an order
void takeOrder(struct Menu menuList[], struct Order orderList[], int n) {
    char itemName[50];
    int itemQuantity;
    int count=0;
    int totalPrice=0;
    
    printf("Enter the order details:\n");
    printf("Enter 0 to stop ordering.\n");
    
    //Loop to take multiple orders
    while(1){
        printf("\nEnter item name: ");
        scanf("%s", itemName);
        
        //Checking whether to stop taking orders or not
        if(strcmp(itemName, "0")==0){
            break;
        }
        
        printf("Enter quantity: ");
        scanf("%d", &itemQuantity);
        
        //Loop to find the item price and add to the order list
        for(int i=0;i<n;i++){
            if(strcmp(menuList[i].itemName, itemName)==0){
                int price = menuList[i].itemPrice*itemQuantity;
                strcpy(orderList[count].itemName, menuList[i].itemName);
                orderList[count].itemQuantity = itemQuantity;
                orderList[count].itemPrice = price;
                totalPrice += price;
                count++;
                break;
            }
        }
    }
    
    //Printing the order details
    printf("\n********** BILL **********\n");
    printf("Item\t\tQuantity\tPrice\n");
    for(int i=0;i<count;i++){
        printf("%s\t\t%d\t\t%d\n", orderList[i].itemName, orderList[i].itemQuantity, orderList[i].itemPrice);
    }
    printf("\nTotal Price: %d\n", totalPrice);
    printf("********************\n\n");
}

int main(){
    //Defining the menu list
    struct Menu menuList[] = {{"Hot Coffee", 50}, {"Cold Coffee", 70}, {"Tea", 40}, {"Sandwich", 80}, {"Burger", 100}};
    
    //Calculating the number of items in the menu
    int n = sizeof(menuList)/sizeof(menuList[0]);
    
    //Defining the maximum number of orders that can be placed
    int maxOrders = 20;
    
    //Defining the order list
    struct Order orderList[maxOrders];
    
    printf("\nWelcome to the Cafe Billing System!\n\n");
    
    //Loop to take multiple orders
    while(1){
        printf("Enter the choice:\n");
        printf("1. Display the menu\n");
        printf("2. Place an order\n");
        printf("3. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                displayMenu(menuList, n);
                break;
            case 2:
                takeOrder(menuList, orderList, n);
                break;
            case 3:
                printf("\nThank you for using Cafe Billing System!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}