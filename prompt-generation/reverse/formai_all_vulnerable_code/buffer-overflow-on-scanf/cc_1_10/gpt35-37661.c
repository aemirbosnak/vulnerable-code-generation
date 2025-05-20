//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Menu {
    char itemName[50];
    float itemPrice;
};

struct Order {
    int tableNumber;
    int orderCount;
    struct Menu* orderDetails;
    float totalAmount;
};

void AddOrder(struct Order* orderList, struct Menu* menuList, int menuCount) {
    int tableNumber, orderCount;
    printf("Enter table number: ");
    scanf("%d", &tableNumber);
    printf("\nEnter number of orders: ");
    scanf("%d", &orderCount);
    
    struct Menu* orderDetails = (struct Menu*) malloc(sizeof(struct Menu) * orderCount);
    
    float totalAmount = 0;
    
    for(int i=0; i<orderCount; i++) {
        int menuIndex, menuItemCount; 
        printf("\nEnter Menu Item %d", i+1);
        printf("\nPlease select Menu Item:\n");
        for(int j=0; j<menuCount; j++) {
            printf("%d. %s -- RS %.2f\n", j+1, menuList[j].itemName, menuList[j].itemPrice);
        }
        scanf("%d", &menuIndex);
        printf("\nEnter item count: ");
        scanf("%d", &menuItemCount);
        strcpy(orderDetails[i].itemName, menuList[menuIndex-1].itemName);
        orderDetails[i].itemPrice = menuList[menuIndex-1].itemPrice * menuItemCount;
        totalAmount += orderDetails[i].itemPrice;
    }
    orderList[tableNumber-1].tableNumber = tableNumber;
    orderList[tableNumber-1].orderCount = orderCount;
    orderList[tableNumber-1].orderDetails = orderDetails;
    orderList[tableNumber-1].totalAmount = totalAmount;
}

void DisplayOrder(struct Order* orderList, int tableCount) {
    for(int i=0; i<tableCount; i++) {
        if(orderList[i].tableNumber != 0) {
            printf("\n\n-----------------------------");
            printf("\nTable Number: %d", orderList[i].tableNumber);
            printf("\nTotal Items: %d", orderList[i].orderCount);
            for(int j=0; j<orderList[i].orderCount; j++) {
                printf("\nItem Name: %s -- RS %.2f", orderList[i].orderDetails[j].itemName, orderList[i].orderDetails[j].itemPrice);
            }
            printf("\nTotal Amount: RS %.2f", orderList[i].totalAmount);
            printf("\n-----------------------------");
        }
    }
}

int main() {
    int menuCount;
    printf("Please enter the number of menu items: ");
    scanf("%d", &menuCount);
    
    struct Menu* menuList = (struct Menu*) malloc(sizeof(struct Menu) * menuCount);
    for(int i=0; i<menuCount; i++) {
        printf("\nPlease enter details for Menu Item %d", i+1);
        printf("\nEnter item name: ");
        scanf("%s", &menuList[i].itemName[0]);
        printf("\nEnter item price: ");
        scanf("%f", &menuList[i].itemPrice);
    }
    
    int tableCount;
    printf("\nPlease enter the number of tables: ");
    scanf("%d", &tableCount);
    struct Order* orderList = (struct Order*) malloc(sizeof(struct Order) * tableCount);
    for(int i=0; i<tableCount; i++) {
        orderList[i].tableNumber = 0;
    }
    
    int option;
    do {
        printf("\n\nC Cafe Billing System");
        printf("\n=====================");
        printf("\n1. Add New Order");
        printf("\n2. Display Current Orders");
        printf("\n3. Exit");
        printf("\n\nPlease select an option: ");
        
        scanf("%d", &option);
        printf("\n");
        
        switch(option) {
            case 1:
                AddOrder(orderList, menuList, menuCount);
                break;
            case 2:
                DisplayOrder(orderList, tableCount);
                break;
            case 3:
                printf("Exiting System...");
                break;
            default:
                printf("Invalid Input!");
                break;
        }
    } while(option != 3);
    
    return 0;
}